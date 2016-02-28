#include "stdafx.h"
#include "Player.h"


unsigned _stdcall threadPvocP(void *pData)
{
	Player* player = (Player*)pData;
	player->run();
	return 0;
}

void Player::run()
{
	while (true)
	{
		if (::WaitForSingleObject(player_event, time*time_pause / speed) == WAIT_OBJECT_0)
		{
			if (state == s_exit)	break;
			else if (state == s_play)
			{
				time_pause = 1;
				is_stopped = false;
			}
			else
			{
				if (state == s_stop)
				{
					frame_manager->reset();
					is_stopped = true;
					state = s_pause;
				}
				time_pause = INFINITE;
				
				ATLASSERT(state == s_pause);
			}

		}
		else
		{
			draw_next_frame();
		}
	}
}


void Player::draw_next_frame()
{
	int pos = 1 + frame_manager->get_pos_display();
	if (pos == file_manager->get_stream_header(0).dwLength)
	{
		state = s_stop;
		::SetEvent(player_event);
		return;
	}
	frame_manager->inc_display_frame();
}

void Player::change_state(State s)
{
	state = s;
	::SetEvent(player_event);
}

void Player::play()
{
	change_state(s_play);
}
void Player::pause()
{
	change_state(s_pause);
}
void Player::stop()
{
	change_state(s_stop);
}

bool Player::did_this_stop()
{
	return is_stopped;
}


void Player::update_speed(int s)
{
	speed = double(s) / 100;
}

Player::Player(PlayerFrameManager* f, AviFileManager* a)
{
	frame_manager = f;
	file_manager = a;

	time = 1;
	speed = 1;
	player_event = CreateEvent(NULL, FALSE, FALSE, NULL);
	time_pause = INFINITE;
	pause();

	
	threadID = 55;
	thread = (HANDLE)_beginthreadex(NULL, 0, &threadPvocP, this, 0, &threadID);
}

Player::~Player()
{
	change_state(s_exit);
	::WaitForSingleObject(thread, INFINITE);
	::CloseHandle(thread);
	::CloseHandle(player_event);
}

void Player::rebuild()
{
	AVIStreamHeader s_head;
	s_head = file_manager->get_stream_header(0);
	time = double(s_head.dwScale) * 1000 / s_head.dwRate;
	pause();
}