#pragma once
#include "Image.h"
#include <vector>
#include <memory>

class IReader
{
protected:
	IReader()
	{
	}
	virtual MyPicture* get_for_reader() = 0;
	virtual void ready_for_reader() = 0;
public:
	MyPicture* get()
	{
		return get_for_reader();
	}
	void ready()
	{
		ready_for_reader();
	}
};


class CMyFrameWnd : public CWnd
{
	DECLARE_DYNAMIC(CMyFrameWnd)
public:
	CMyFrameWnd();
	virtual ~CMyFrameWnd(){}
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	//IReader* reader = nullptr;
	Image* image = nullptr;
public:
	void initialize(Image* _image)
	{
		image = _image;
	}
	/*
	void set_reader(IReader* _reader)
	{
		reader = _reader;
	}
	*/
};







