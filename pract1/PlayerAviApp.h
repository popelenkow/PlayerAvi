
// PlayerAvi.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CPlayerAviApp:
// � ���������� ������� ������ ��. PlayerAvi.cpp
//

class CPlayerAviApp : public CWinApp
{
public:
	CPlayerAviApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CPlayerAviApp theApp;