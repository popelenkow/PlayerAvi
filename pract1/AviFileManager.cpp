#include "stdafx.h"
#include "AviFileManager.h"
#include <string>

CString CreateStrErr(Err e)
{
	CString s;
	if (e == open) s = L"Did not open";
	else if (e == header) s = L"File broken";
	else if (e == type) s = L"Format is not supported";
	return s;
}


AviFileManager::AviFileManager()
{
	{
		HRESULT hr;
		hr = pAVI.CoCreateInstance(CLSID_GetAVIInfo);
		ATLASSERT(S_OK == hr);
	}
	ready = false;
}

AviFileManager::~AviFileManager()
{
	delete[] buf;
	clear();
}

void AviFileManager::clear()
{
	pre_pos = -2;
	ZeroMemory(&bmp_info_file, sizeof(bmp_info_file));
	if (file != nullptr)
	{
		fclose(file);
		file = nullptr;
		if (hic != 0)
		{
			if (ready) ICDecompressEnd(hic);
			ICClose(hic);
			hic = 0;
		}
	}
	ready = false;
}


Err AviFileManager::open_file(const char* file_name)
{
	clear();
	{
		HRESULT hr;
		std::string s(file_name);
		std::wstring ws(s.begin(), s.end());
		hr = pAVI->Load((BSTR)ws.c_str());
		if (S_OK != hr) return Err::open;
	}
	//file
	{
		errno_t err = fopen_s(&file, file_name, "rb");
		if (err != 0) return Err::open;
	}
	//BITMAPINFO
	{
		long size;
		HRESULT hr = pAVI->GetVideoFormatInfo(0, (BYTE*)&bmp_info_file, sizeof(bmp_info_file), &size);
		if (S_OK != hr) Err::header;
	}

	int w = bmp_info_file.bmiHeader.biWidth;
	int h = bmp_info_file.bmiHeader.biHeight;
	Frame frame(w, h);

	hic = ICOpen(ICTYPE_VIDEO, bmp_info_file.bmiHeader.biCompression, ICMODE_DECOMPRESS);
	if (hic == 0) return Err::type;


	DWORD err = ICDecompressQuery(hic, &bmp_info_file, &frame.bmp_info);
	if (err != ICERR_OK) return Err::type;

	err = ICDecompressBegin(hic, &bmp_info_file, &frame.bmp_info);
	if (err != ICERR_OK) return Err::type;
	ready = true;
	return Err::ok;
}
void AviFileManager::get_frame(Frame* frame)
{

	ULONG size_frame;
	_int64 offset;
	int iter = frame->index;
	//if ((frame->index + 1 != pre_pos) && (frame->index != pre_pos))
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
		} while (flag != AVIIF_KEYFRAME);
	}

	for (; iter <= frame->index; iter++)
	{
		ULONG flag = 0;
		{
			long hi_offset;
			ULONG low_offset;
			HRESULT hr;
			hr = pAVI->GetVideoFrameInfo2(0, iter, &hi_offset, &low_offset, &size_frame, &flag);
			ATLASSERT(S_OK == hr);
			if (size_buf < size_frame)
			{
				delete[] buf;
				buf = new char[size_frame];
				size_buf = size_frame;
			}
			offset = (_int64(hi_offset) << 32) + _int64(low_offset);
		}

		{
			FILE* p_file = file;
			errno_t err = _fseeki64(p_file, offset, SEEK_SET);
			ATLASSERT(err == ICERR_OK);
			fread(buf, 1, size_frame, p_file);
		}

		{
			bmp_info_file.bmiHeader.biSizeImage = size_frame;
			DWORD ICDec;
			if (flag & AVIIF_KEYFRAME) ICDec = 0;
			else ICDec = ICDECOMPRESS_NOTKEYFRAME;
			DWORD err = ICDecompress(hic, ICDec, &bmp_info_file.bmiHeader, (void*)buf, &frame->get_bmp_info_header(), (void*)(frame->data));
			ATLASSERT(err == ICERR_OK);
		}
		pre_pos = frame->index;
	}
}

BITMAPINFOHEADER AviFileManager::get_bmp_info()
{
	return bmp_info_file.bmiHeader;
}
AVIStreamHeader AviFileManager::get_stream_header(int i)
{
	AVIStreamHeader stream_header;
	long size;
	HRESULT hr = pAVI->GetVideoStreamInfo(i, (BYTE*)&stream_header, sizeof(stream_header), &size, nullptr, nullptr);
	ATLASSERT(S_OK == hr);
	return stream_header;
}