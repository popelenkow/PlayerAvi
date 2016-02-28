
// PlayerAviDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "PlayerAviApp.h"
#include "PlayerAviDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CPlayerAviDlg



CPlayerAviDlg::CPlayerAviDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerAviDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayerAviDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_FRAME, frame_wnd);
	DDX_Control(pDX, IDC_SLIDER_SPEED, m_SliderSpeed);
	DDX_Control(pDX, IDC_EDIT_SPEED, m_EditSpeed);
	DDX_Control(pDX, IDC_SPIN_SPEED, m_SpinSpeed);
	DDX_Control(pDX, IDC_SLIDER_FRAME, m_SliderFrame);
	DDX_Control(pDX, IDC_SPIN_NUMBER_FRAME, m_SpinNumFrame);
	DDX_Control(pDX, IDC_EDIT_NUMBER_FRAME, m_EditNumFrame);
}

BEGIN_MESSAGE_MAP(CPlayerAviDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

//	ON_WM_HSCROLL()
	ON_WM_TIMER()

//	ON_WM_HSCROLLCLIPBOARD()
ON_WM_VSCROLL()
ON_EN_CHANGE(IDC_EDIT_READER, &CPlayerAviDlg::OnEnChangeEditSpeed)
ON_EN_KILLFOCUS(IDC_EDIT_READER, &CPlayerAviDlg::OnEnKillfocusEditSpeed)
ON_WM_HSCROLL()
ON_BN_CLICKED(IDC_BUTTON_PLAYER_STOP, &CPlayerAviDlg::OnBnClickedButtonPlayerStop)
ON_BN_CLICKED(IDC_BUTTON_PLAYER_PAUSE, &CPlayerAviDlg::OnBnClickedButtonPlayerPause)
ON_BN_CLICKED(IDC_BUTTON_PLAYER_PLAY, &CPlayerAviDlg::OnBnClickedButtonPlayerPlay)
ON_WM_CLOSE()
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NUMBER_FRAME, &CPlayerAviDlg::OnDeltaposSpinNumberFrame)
ON_BN_CLICKED(IDC_BUTTON_OPEN, &CPlayerAviDlg::OnBnClickedButtonOpen)
ON_EN_CHANGE(IDC_EDIT_NUMBER_FRAME, &CPlayerAviDlg::OnEnChangeEditNumberFrame)
END_MESSAGE_MAP()


// обработчики сообщений CPlayerAviDlg





BOOL CPlayerAviDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	CRect rc;
	GetClientRect(rc);
	//int w = rc.Width();
	
	
	int w = 256;
	int h = 256;
	//int w = bmp_info.biWidth;
	//int h = bmp_info.biHeight;

	frame_manager = new FrameManager(w, h);
	player = new Player(frame_manager, &file_manager);
	decompressor = new Decompressor(frame_manager, &file_manager);
	frame_wnd.initialize(frame_manager);

	short max = 1000;
	short nPos = 100;
	m_SpinSpeed.SetBuddy(&m_EditSpeed);
	m_SliderSpeed.SetRange(10, max);
	m_SpinSpeed.SetRange(10, max);
	m_SliderSpeed.SetPos(nPos);
	m_SpinSpeed.SetPos(nPos);


	m_SpinNumFrame.SetBuddy(&m_EditNumFrame);


	


	SetTimer(ID_timer_update_window, 21, NULL);
	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CPlayerAviDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPlayerAviDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}



// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CPlayerAviDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPlayerAviDlg::OnBnClickedButtonPlayerStop()
{
	player->stop();
}


void CPlayerAviDlg::OnBnClickedButtonPlayerPause()
{
	player->pause();
}


void CPlayerAviDlg::OnBnClickedButtonPlayerPlay()
{
	player->play();
}

void CPlayerAviDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (ID_timer_update_window == nIDEvent)
	{
		std::size_t pos = frame_manager->get_pos_display();
		m_SliderFrame.SetPos(pos);
		m_SpinNumFrame.SetPos(pos);
		frame_wnd.Invalidate();
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CPlayerAviDlg::OnEnChangeEditSpeed()
{
	m_SliderSpeed.SetPos(m_SpinSpeed.GetPos());
	player->update_speed(m_SpinSpeed.GetPos());
}


void CPlayerAviDlg::OnEnKillfocusEditSpeed()
{
	m_SpinSpeed.SetPos(m_SpinSpeed.GetPos());
	player->update_speed(m_SpinSpeed.GetPos());
}

void CPlayerAviDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (pScrollBar->m_hWnd == m_SliderSpeed.m_hWnd)
	{
		m_SpinSpeed.SetPos(m_SliderSpeed.GetPos());
		player->update_speed(m_SpinSpeed.GetPos());
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CPlayerAviDlg::change_num_frame()
{
	if (is_dlg_change) frame_manager->update_pos_dec(m_SpinNumFrame.GetPos());
}

void CPlayerAviDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (pScrollBar->m_hWnd == m_SliderFrame.m_hWnd)
	{
		is_dlg_change = true;
		m_SpinNumFrame.SetPos(m_SliderFrame.GetPos());
		change_num_frame();
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPlayerAviDlg::OnDeltaposSpinNumberFrame(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	is_dlg_change = true;
	*pResult = 0;
}

void CPlayerAviDlg::OnEnChangeEditNumberFrame()
{
	change_num_frame();
}

void CPlayerAviDlg::OnClose()
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (player != nullptr) delete player;
	if (decompressor != nullptr) delete decompressor;
	if (frame_manager != nullptr) delete frame_manager;
	CDialogEx::OnClose();
}

void CPlayerAviDlg::OnBnClickedButtonOpen()
{
	player->pause();
	CFileDialog fileDlg(true, L"avi", L"*.avi",
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, L"Avi Files (*.avi)|*.avi|All Files (*.*)|*.*||", this);

	if (fileDlg.DoModal() == IDOK)
	{
		player->stop();
		decompressor->stop();


		CString atl_str = fileDlg.GetPathName();
		std::wstring ws(atl_str);
		std::string s(ws.begin(), ws.end());
		const char* str = s.c_str();
		

		bool is_stopped;
		do
		{
			is_stopped = player->did_this_stop();
			is_stopped &= decompressor->did_this_stop();
		} while (!is_stopped);

		Err err = file_manager.open_file(str);

		if (err == Err::ok)
		{
			std::size_t length = file_manager.get_stream_header(0).dwLength;
			std::size_t pos = frame_manager->get_pos_display();
			m_SliderFrame.SetRange(0, length - 1);
			m_SliderFrame.SetPos(pos);
			m_SpinNumFrame.SetRange(0, length - 1);
			m_SpinNumFrame.SetPos(pos);
			player->rebuild();
			decompressor->decompress();
		}
		else
		{
			this->Invalidate();
			MessageBox(CreateStrErr(err), L"Err");
		}
	}
}



