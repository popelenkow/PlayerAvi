#include "CMyFrameWnd.h"
#include "MyAvi.h"

class MyPlayerAvi
{
	MyAvi* my_avi;
	CMyFrameWnd* frame_wnd;
public:
	MyPlayerAvi(CMyFrameWnd* f);
	~MyPlayerAvi();
private:
	enum State
	{
		s_exit = 0,
		s_play = 1,
		s_pause = 2,
		s_stop = 3
	};
	State state;
	double speed;
	DWORD time_pause;
	double time;

	Image* image;
	bool is_broken;
	int pos;
	void show_frame();
	void next_frame();

	HANDLE player_event;
	//thread
	HANDLE thread;
	unsigned threadID;
	friend unsigned _stdcall threadPvoc(void *);
	void run();
public:
	void update_speed(int s);
	void update_pos(int p);
	int get_pos();
	int get_length();
private:
	void change_state(State s);
public:
	void play();
	void pause();
	void stop();
	void show();
};