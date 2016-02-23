#pragma once
#include "GetAVIInfo_i.c"
#include "GetAVIInfo.h"

class MyAvi
{
	CComPtr<IGetAVIInfo> pAVI;
	FILE* file;
	HIC hic;
	BITMAPINFO bmp_info_file;
public:
	MyAvi();
	~MyAvi()
	{
		ICDecompressEnd(hic);
		ICClose(hic);
		fclose(file);
	}
public:
	void get_frame(int i, Image* image, bool is_broken);
	virtual BITMAPINFOHEADER get_bmp_info()
	{
		return bmp_info_file.bmiHeader;
	}
	virtual AVIStreamHeader get_stream_header(int i)
	{
		AVIStreamHeader stream_header;
		long size;
		HRESULT hr = pAVI->GetVideoStreamInfo(i, (BYTE*)&stream_header, sizeof(stream_header), &size, nullptr, nullptr);
		ATLASSERT(S_OK == hr);
		return stream_header;
	}

};