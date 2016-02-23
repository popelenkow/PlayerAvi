#pragma once


// CFifoStatistics

class CFifoStatistics : public CWnd
{
	DECLARE_DYNAMIC(CFifoStatistics)
	const int width = 256;
	const int height = 30;
	ImageForStatistics* im = new ImageForStatistics(width, height);
	FlipFlop* flip_flop = nullptr;
public:
	CFifoStatistics();
	virtual ~CFifoStatistics();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void set_flip_flop(FlipFlop* f)
	{
		flip_flop = f;
	}
};


