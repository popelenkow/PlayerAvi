#include "stdafx.h"
#include "MyPlayerAvi.h"


unsigned _stdcall threadPvoc(void *pData)
{
	MyPlayerAvi* player = (MyPlayerAvi*)pData;
	player->run();
	return 0;
}

MyPlayerAvi::MyPlayerAvi(CMyFrameWnd* f)
{
	frame_wnd = f;

	my_avi = new MyAvi();
	BITMAPINFOHEADER bmp_info = my_avi->get_bmp_info();
	int w = bmp_info.biWidth;
	int h = bmp_info.biHeight;

	image = new Image(w, h);
	is_broken = true;
	pos = 0;

	frame_wnd->initialize(image);

	AVIStreamHeader s_head;
	s_head = my_avi->get_stream_header(0);
	time = double(s_head.dwScale)*1000 / s_head.dwRate;
	speed = 1;
	time_pause = INFINITE;
	state = s_stop;

	player_event = CreateEvent(NULL, FALSE, FALSE, NULL);
	threadID = 55;
	thread = (HANDLE)_beginthreadex(NULL, 0, &threadPvoc, this, 0, &threadID);
}

MyPlayerAvi::~MyPlayerAvi()
{
	state = s_exit;
	::SetEvent(player_event);
	::WaitForSingleObject(thread, INFINITE);
	::CloseHandle(thread);
	::CloseHandle(player_event);
	if (my_avi != nullptr) delete my_avi;
	if (image != nullptr) delete image;
}

void MyPlayerAvi::run()
{
	while (true)
	{
		if (::WaitForSingleObject(player_event, time*time_pause / speed) == WAIT_OBJECT_0)
		{
			if (state == s_play) time_pause = 1;
			else if (state == s_exit)	break;
			else if (state == s_pause) time_pause = INFINITE;
			else if (state = s_stop)
			{
				state = s_pause;
				time_pause = INFINITE;
				update_pos(0);
			}
			show_frame();
		}
		else
		{
			next_frame();
		}
	}
}

void MyPlayerAvi::show_frame()
{
	my_avi->get_frame(pos, image, is_broken);
	is_broken = false;
	frame_wnd->Invalidate();
}
void MyPlayerAvi::next_frame()
{
	pos++;
	if (pos == my_avi->get_stream_header(0).dwLength)
	{
		state = s_stop;
		::SetEvent(player_event);
		return;
	}
	show_frame();
}

void MyPlayerAvi::update_pos(int p)
{
	pos = p;
	is_broken = true;
	show();
}
int MyPlayerAvi::get_pos()
{
	return pos;
}
int MyPlayerAvi::get_length()
{
	return my_avi->get_stream_header(0).dwLength;
}

void MyPlayerAvi::update_speed(int s)
{
	speed = double(s) / 100;
}

void MyPlayerAvi::change_state(State s)
{
	state = s;
	::SetEvent(player_event);
}

void MyPlayerAvi::play()
{
	change_state(s_play);
}
void MyPlayerAvi::pause()
{
	change_state(s_pause);
}
void MyPlayerAvi::stop()
{
	change_state(s_stop);
}
void MyPlayerAvi::show()
{
	::SetEvent(player_event);
}