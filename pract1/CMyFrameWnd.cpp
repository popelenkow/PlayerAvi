#include "stdafx.h"
#include "CMyFrameWnd.h"


IMPLEMENT_DYNAMIC(CMyFrameWnd, CWnd)


BEGIN_MESSAGE_MAP(CMyFrameWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


CMyFrameWnd::CMyFrameWnd()
{
	
}

void CMyFrameWnd::OnPaint()
{
	CPaintDC dc = CPaintDC(this);
	//MyPicture* im = reader->get();
	if (image != nullptr)
	{
		BITMAPINFO* info = &image->get_bmp_info();
		int w = info->bmiHeader.biWidth;
		int h = info->bmiHeader.biHeight;
		::SetDIBitsToDevice(dc, 0, 0, w, h, 0, 0, 0, w, image->get_data(), info, 0);
		
	}
	//reader->ready();
}



