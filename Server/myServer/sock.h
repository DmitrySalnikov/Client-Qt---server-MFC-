#pragma once
#include "stdafx.h"
#include <random>
#include <Windows.h>

class CChildView;

class CServer : public CSocket {

public:
	virtual void OnAccept(int nErrorCode);
	friend class CMainFrame;

private:
	CChildView* cv;

};

class CSrvClt : public CSocket {

public:
	friend class CChildView;
	CSrvClt() { off = 0; }
	virtual void OnReceive(int nErrorCode);

	struct { int i[6]; } param;
	int off;
	std::random_device g;

};