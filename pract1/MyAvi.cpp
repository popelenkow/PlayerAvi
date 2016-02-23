#include "stdafx.h"
#include "MyAvi.h"
 
MyAvi::MyAvi()
{
	{
		HRESULT hr;
		hr = pAVI.CoCreateInstance(CLSID_GetAVIInfo);
		ATLASSERT(S_OK == hr);
		pAVI.
		hr = pAVI->Load(L"donkey.avi");
		ATLASSERT(S_OK == hr);
	}
	//file
	{
		errno_t err = fopen_s(&file, "donkey.avi", "rb");
		ATLASSERT(err == 0);
	}
	//BITMAPINFO
	{
		long size;
		HRESULT hr = pAVI->GetVideoFormatInfo(0, (BYTE*)&bmp_info_file, sizeof(bmp_info_file), &size);
		ATLASSERT(S_OK == hr);
	}

	int w = bmp_info_file.bmiHeader.biWidth;
	int h = bmp_info_file.bmiHeader.biHeight;
	Image image(w, h);

	hic = ICOpen(ICTYPE_VIDEO, bmp_info_file.bmiHeader.biCompression, ICMODE_DECOMPRESS);
	ATLASSERT(hic != 0);


	DWORD err = ICDecompressQuery(hic, &bmp_info_file, &image.get_bmp_info());
	ATLASSERT(err == ICERR_OK);

	err = ICDecompressBegin(hic, &bmp_info_file, &image.get_bmp_info());
	ATLASSERT(err == ICERR_OK);
}

void MyAvi::get_frame(int i, Image* image, bool is_broken)// = false)
{

	ULONG size_frame;
	_int64 offset;
	int iter = i;
	if (is_broken)
	{
		long hi_offset;
		ULONG low_offset;
		HRESULT hr;
		ULONG flag = 0;
		iter++;
		do
		{
			iter--;
			hr = pAVI->GetVideoFrameInfo2(0, iter, &hi_offset, &low_offset, &size_frame, &flag);
			ATLASSERT(S_OK == hr);
		} while (flag != 16);
	}

	for (; iter <= i; iter++)
	{
		{
			long hi_offset;
			ULONG low_offset;
			HRESULT hr;
			hr = pAVI->GetVideoFrameInfo(0, iter, &hi_offset, &low_offset, &size_frame);
			ATLASSERT(S_OK == hr);
			offset = (_int64(hi_offset) << 32) + _int64(low_offset);
		}

		char* data = nullptr;
		{
			FILE* p_file = file;
			errno_t err = _fseeki64(p_file, offset, SEEK_SET);
			ATLASSERT(err == ICERR_OK);
			data = new char[size_frame];
			fread(data, 1, size_frame, p_file);
		}

			{
				bmp_info_file.bmiHeader.biSizeImage = size_frame;

				DWORD err = ICDecompress(hic, ICDECOMPRESS_NOTKEYFRAME, &bmp_info_file.bmiHeader, (void*)data, &image->get_bmp_info_header(), (void*)(image->get_data()));
				ATLASSERT(err == ICERR_OK);
			}
			delete[] data;
	}
}