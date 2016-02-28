#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "FrameManager.h"



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
	DECLARE_MESSAGE_MAP()


	const UINT_PTR ID_timer_update_window = 98;
public:
	AviFileManager file_manager;
	FrameManager* frame_manager = nullptr;
	CMyFrameWnd frame_wnd;
	Player* player = nullptr;
	Decompressor* decompressor = nullptr;

	afx_msg void OnBnClickedButtonPlayerStop();
	afx_msg void OnBnClickedButtonPlayerPause();
	afx_msg void OnBnClickedButtonPlayerPlay();

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CEdit m_EditSpeed;
	CSliderCtrl m_SliderSpeed;
	CSpinButtonCtrl m_SpinSpeed;
	afx_msg void OnEnChangeEditSpeed();
	afx_msg void OnEnKillfocusEditSpeed();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	bool is_dlg_change = false;
	CEdit m_EditNumFrame;
	CSliderCtrl m_SliderFrame;
	CSpinButtonCtrl m_SpinNumFrame;
	void change_num_frame();
	afx_msg void OnEnChangeEditNumberFrame();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposSpinNumberFrame(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonOpen();

};
