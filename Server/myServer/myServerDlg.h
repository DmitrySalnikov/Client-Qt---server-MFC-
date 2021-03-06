
// myServerDlg.h : файл заголовка
//

#pragma once
#include "sock.h"

// диалоговое окно CmyServerDlg
class CmyServerDlg : public CDialogEx
{
// Создание
	CServer m_server;
public:
	CmyServerDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
