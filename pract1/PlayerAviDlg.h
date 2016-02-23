#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyPlayerAvi.h"



class CPlayerAviDlg : public CDialogEx
{
public:
	CPlayerAviDlg(CWnd* pParent = NULL);	// стандартный конструктор
	~CPlayerAviDlg()
	{
		
	}

// Данные диалогового окна
	enum { IDD = IDD_PRACT1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV



protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnChangeEditSpeed();
	afx_msg void OnEnKillfocusEditSpeed();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()


	
	
	const UINT_PTR ID_timer_slider_frame = 99;
	void change_speed_player()
	{
		player_avi->update_speed(m_SpinSpeed.GetPos());
	}
	void change_pos_player()
	{
		player_avi->update_pos(m_SpinNumFrame.GetPos());
	}
public:
	CEdit m_EditSpeed;
	CSliderCtrl m_SliderSpeed;
	CSpinButtonCtrl m_SpinSpeed;

	CSliderCtrl m_SliderFrame;
	CMyFrameWnd frame_wnd;
	MyPlayerAvi* player_avi = nullptr;
	afx_msg void OnBnClickedButtonPlayerStop();
	afx_msg void OnBnClickedButtonPlayerPause();
	afx_msg void OnBnClickedButtonPlayerPlay();
	afx_msg void OnEnChangeEditNumberFrame();
	CSpinButtonCtrl m_SpinNumFrame;
	CEdit m_EditNumFrame;
	afx_msg void OnClose();
};
