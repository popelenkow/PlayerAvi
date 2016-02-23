// FifoStatistics.cpp: файл реализации
//

#include "stdafx.h"
#include "PlayerAvi.h"
#include "FifoStatistics.h"


// CFifoStatistics

IMPLEMENT_DYNAMIC(CFifoStatistics, CWnd)

CFifoStatistics::CFifoStatistics()
{
}

CFifoStatistics::~CFifoStatistics()
{
	delete im;
}


BEGIN_MESSAGE_MAP(CFifoStatistics, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// обработчики сообщений CFifoStatistics




void CFifoStatistics::OnPaint()
{
	
	while (flip_flop == nullptr) Sleep(1);
	im->fill_background(RGB(100, 100, 100));

	double d_w, d_r, d_p;
	d_r = double(flip_flop->p_read) / (flip_flop->memory-1);
	d_w = double(flip_flop->p_write) / (flip_flop->memory-1);
	d_p = double(flip_flop->count_ready) / flip_flop->memory;
	im->fill_line_for_statistics(d_r, d_w, d_p);
	
	CPaintDC dc = CPaintDC(this);
	::SetDIBitsToDevice(dc, 0, 0, width, height, 0, 0, 0, height, im->get_data(), (BITMAPINFO*)&(im->get_bmpInfo()), 0);
		
	
}
