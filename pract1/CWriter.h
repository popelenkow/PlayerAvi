#pragma once

#include "MyAvi.h"

class IWriter
{
protected:
	IWriter()
	{
	}
	virtual Image* get_for_writer() = 0;
	virtual void ready_for_writer() = 0;
	virtual void inc_for_writer() = 0;
public:
	Image* get()
	{
		return get_for_writer();
	}
	void ready()
	{
		ready_for_writer();
	}
	void inc()
	{
		inc_for_writer();
	}
};


class CWriter
{
	int time = 30;
	volatile bool is_work = false;
	HANDLE event_exit = CreateEvent(NULL, FALSE, FALSE, NULL);
	//thread
	HANDLE thread;
	unsigned threadID;
public:
	friend unsigned _stdcall threadPvoc(void *);
	CWriter();
	~CWriter();
	//внутренний поток
protected:

	void fill();

	void run();
	

protected:
	int pos = 0;
	IWriter* writer = nullptr; 
	MyAvi* my_avi = nullptr;
public:
	void initialize(IWriter* _writer, MyAvi* _my_avi)
	{
		my_avi = _my_avi;
		writer = _writer;
	}
	void change_timer(int _time)
	{
		time = _time;
	}
};

