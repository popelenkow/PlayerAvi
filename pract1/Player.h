#pragma once
#include "AviFileManager.h"

class PlayerFrameManager
{
public:
	virtual int get_pos_display() = 0;
	virtual void inc_display_frame() = 0;
	virtual void reset() = 0;
};


class Player
{
	void run();
	void draw_next_frame();

	HANDLE thread;
	unsigned threadID;
	friend unsigned _stdcall threadPvocP(void *);

	enum State
	{
		s_exit = 0,
		s_play = 1,
		s_pause = 2,
		s_stop = 3
	};
	HANDLE player_event;
	bool is_stopped;
	State state;

	void change_state(State s);
public:
	void play();
	void pause();
	void stop();

	bool did_this_stop();
private:
	double time;
	double speed;
	DWORD time_pause;
public:
	void update_speed(int s);
private:
	AviFileManager* file_manager;
	PlayerFrameManager* frame_manager;
public:
	Player(PlayerFrameManager* f, AviFileManager* a);
	~Player();
	void rebuild();
};