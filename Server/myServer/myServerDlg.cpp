
// myServerDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "myServer.h"
#include "myServerDlg.h"
#include "afxdialogex.h"
#include "Resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma once

// диалоговое окно CmyServerDlg



CmyServerDlg::CmyServerDlg(CWnd* pParent /*=NULL*/) : CDialogEx(IDD_MYSERVER_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void  CmyServerDlg::DoDataExchange(CDataExchange *pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmyServerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CmyServerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CmyServerDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// обработчики сообщений CmyServerDlg



BOOL CmyServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CmyServerDlg::OnPaint() {
	if (IsIconic()) {
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
	} else {
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CmyServerDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}



void CmyServerDlg::OnBnClickedOk() {
	// TODO: добавьте свой код обработчика уведомлений
	//CDialogEx::OnOK();
	char str[3];
	GetDlgItemText(IDOK, _T(str), 4);
	if (str[2] == 'a') {
		m_server.Create(10000);
		m_server.Listen();
		SetDlgItemText(IDOK, _T("Stop"));
	}
	else {
		m_server.Close();
		SetDlgItemText(IDOK, _T("Start"));
	}
}


void CmyServerDlg::OnBnClickedButton1() {
	// TODO: добавьте свой код обработчика уведомлений
}


void CmyServerDlg::OnBnClickedCancel() {
	// TODO: добавьте свой код обработчика уведомлений
	m_server.Close();
	CDialogEx::OnCancel(); 
}


BOOL CmyServerDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (wParam == CM_DELETE) {
		((CSrvClt *)lParam)->Close();
		delete ((CSrvClt *)lParam);
		return 1;
	}

	return CDialogEx::OnCommand(wParam, lParam);
}
