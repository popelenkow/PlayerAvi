
#include "stdafx.h"

#include "CWriter.h"
#include <cassert>

unsigned _stdcall threadPvoc(void *pData)
{
	CWriter* c_writer = (CWriter*)pData;
	c_writer->run();
	return 0;
}

CWriter::CWriter()
{
	thread = (HANDLE)_beginthreadex(NULL, 0, &threadPvoc, this, 0, &threadID);
}

CWriter::~CWriter()
{
	::SetEvent(event_exit);
	::WaitForSingleObject(thread, INFINITE);
	::CloseHandle(thread);
	::CloseHandle(event_exit);
}

void CWriter::run()
{
	while (writer == nullptr) Sleep(30);
	while (::WaitForSingleObject(event_exit, time) != WAIT_OBJECT_0)
	{	
		fill();
		writer->inc();
	}
}

void CWriter::fill()
{
	Image* im = writer->get();
	my_avi->get_frame(pos, im, false);
	writer->ready();
	pos++;
}