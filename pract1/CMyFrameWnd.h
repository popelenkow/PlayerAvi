#pragma once
#include <vector>
#include <memory>

class WndFrameManager
{
public:
	virtual const Frame* get_display_frame() = 0;
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
	WndFrameManager* frame_manager = nullptr;
public:
	void initialize(WndFrameManager* f)
	{
		frame_manager = f;
	}
};







