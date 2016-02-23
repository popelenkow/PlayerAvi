#pragma once
//#include "PlayerAvi.h"

class Image
{
protected:
	COLORREF* data;
	BITMAPINFO m_bmpInfo;
	
public:
	Image(unsigned width, unsigned height, COLORREF* _data = nullptr)
	{
		if (_data == nullptr)
		{
			data = new COLORREF[width*height];
		}
		else
		{
			data = _data;
		}
		ZeroMemory(&m_bmpInfo, sizeof(m_bmpInfo));
		m_bmpInfo.bmiHeader.biSize = sizeof(m_bmpInfo);
		m_bmpInfo.bmiHeader.biPlanes = 1;
		m_bmpInfo.bmiHeader.biWidth = width;
		m_bmpInfo.bmiHeader.biHeight = height;
		m_bmpInfo.bmiHeader.biBitCount = 32;
	}
	~Image()
	{
		delete[] data;
	}
	virtual void fill_background(COLORREF c)
	{
		BYTE red = (BYTE)(c >> 24);
		BYTE green = (BYTE)(c >> 16);
		BYTE blue = (BYTE)(c >> 8);
		BYTE weignt = (BYTE)(c);
		int h = m_bmpInfo.bmiHeader.biHeight;
		int w = m_bmpInfo.bmiHeader.biWidth;
		for (int y = 0; y < h*w; y++)
		{
			*(data + y) = c;
		}
	}

	COLORREF* get_data()
	{
		return data;
	}
	BITMAPINFO get_bmp_info()
	{
		return m_bmpInfo;
	}
	BITMAPINFOHEADER get_bmp_info_header()
	{
		return m_bmpInfo.bmiHeader;
	}
};

class MyPicture : public Image
{
public:
	MyPicture(unsigned width, unsigned height, COLORREF* _data = nullptr) : Image(width, height, _data)
	{
	}
	~MyPicture()
	{
	}
	void fill_line(COLORREF c, int pos, int size = 1)
	{
		int h = m_bmpInfo.bmiHeader.biHeight;
		int w = m_bmpInfo.bmiHeader.biWidth;
		for (int y = 0; y < h; y++)
		{
			for (int x = pos; x < pos + size; x++)
			{
				*(data + w * y + x) = c;
			}
		}
	}
};

class ImageForStatistics : public Image
{
public:
	ImageForStatistics(unsigned width, unsigned height, COLORREF* _data = nullptr) : Image(width, height, _data)
	{
	}
	~ImageForStatistics()
	{
	}
protected:
	void _draw(int left, double right, COLORREF c1, COLORREF c2)
	{
		int h = m_bmpInfo.bmiHeader.biHeight;
		int w = m_bmpInfo.bmiHeader.biWidth;
		for (int y = 0; y < h; y++)
		{
			int x;
			for (x = left; x != right; x = (x + 1) % w)
			{
				if ((x + y) % 20 < 10) *(data + y*w + x) = c1;
				else *(data + y*w + x) = c2;
			}
			if ((x + y) % 20 < 10) *(data + y*w + x) = c1;
			else *(data + y*w + x) = c2;
		}
	}

	void draw_err(int left, double right)
	{
		_draw(left, right, RGB(0, 0, 255), RGB(0, 0, 255));
	}

	void draw_fill(int left, double right)
	{
		_draw(left, right, RGB(0, 0, 0), RGB(0, 255, 255));
	}

public:
	void fill_line_for_statistics(double pos_reader, double pos_writer, double dist_p)
	{
		int w = m_bmpInfo.bmiHeader.biWidth;
		int p_r = int(pos_reader*(w - 1));
		int p_w = int(pos_writer*(w - 1));
		if (dist_p >= 2)
		{
			draw_err(0, w - 1);
		}
		else if (dist_p >= 1)
		{
			draw_fill(0, w - 1);
			draw_err(p_r, p_w);
		}
		else
		{
			draw_fill(p_r, p_w);
		}
	}
};





