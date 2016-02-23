#pragma once
#include "CWriter.h"
#include "CMyFrameWnd.h"
#include <atomic>


class FlipFlop : public IReader, public IWriter
{
	const int memory = 4;
	std::vector<MyPicture*> images;
	int p_write = 0;
	int p_read = 0;
	std::atomic<int> count_ready = 0;
	CCriticalSection cs_atomic_image;
	CCriticalSection cs_pos_writer;
	bool is_lock = false;

	friend class CFifoStatistics;
public:
	FlipFlop()
	{

	}
	~FlipFlop()
	{
		for (int i = 0; i < memory; i++)
		{
			delete images[i];
		}
	}
	void initialize(int weight, int height)
	{
		for (int i = 0; i < memory; i++)
		{
			images.push_back(new MyPicture(weight, height));
		}
	}
protected:
	virtual Image* get_for_writer()
	{
		
		Image* im = images[p_write];
		if (count_ready == memory)
		{
			cs_atomic_image.Lock();
			is_lock = true;
			if (!(count_ready == memory))
			{
				cs_atomic_image.Unlock();
				is_lock = false;
			}
		}
		return im;
	}
	virtual void ready_for_writer()
	{
		if (is_lock == true)
		{
			is_lock = false;
			cs_atomic_image.Unlock();
		}
	}
	virtual void inc_for_writer()
	{
		cs_pos_writer.Lock();
		count_ready++;
		p_write = (p_write + 1) % memory;
		cs_pos_writer.Unlock();
	}
	virtual void recalc_pos_reader()
	{
		cs_pos_writer.Lock();
		int d1 = count_ready - memory + 1;
		count_ready -= d1;
		p_read = (p_read + d1) % memory;
		cs_pos_writer.Unlock();
	}
	virtual MyPicture* get_for_reader()
	{
		cs_atomic_image.Lock();
		if (count_ready == 0)
		{
			return nullptr;
		}
		else if (count_ready > memory)
		{
			recalc_pos_reader();
		}
		MyPicture* im = images[p_read];
		return im;
	}
	virtual void ready_for_reader()
	{
		cs_atomic_image.Unlock();
	}
public:
	virtual void inc_for_reader()
	{
		if (count_ready < 2)
		{
			return;
		}
		else if (count_ready > memory)
		{
			recalc_pos_reader();
		}
		else
		{
			p_read = (p_read + 1) % memory;
			count_ready--;
		}
	}
};