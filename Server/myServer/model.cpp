#include "stdafx.h"
#include <Windows.h>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "Resource.h"

#include "sock.h"
#include "RAND.H"
#include "model.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Ship::Main() {
	while (true) {
		Wait(rcome());
		long t0 = CurTime();
		m_pModel->m_pDevice->Enter();
		if (CurTime() > m_pModel->days) {
			m_pModel->m_pDevice->Leave();
			break;
		}
		m_pModel->wait_in_que.push_back(CurTime() - t0);
		Wait(rserv());
		m_pModel->m_pDevice->Leave();
	}
}

UINT Simulation(LPVOID srv) {
	CSrvClt * sr = (CSrvClt *)srv;
	
	CMyModel model(sr->param.i[0], sr->param.i[5]);
	model.Run();
	int ws = *max_element(model.wait_in_que.begin(), model.wait_in_que.end()) + 1;
	vector<int> wait(ws, 0);
	for (auto p = model.wait_in_que.begin(); p != model.wait_in_que.end(); ++p)
		++wait[*p];
	
	stringstream ss;
	ss << ws << ' ';
	for (auto p = wait.begin(); p != wait.end(); ++p)
		ss << *p << ' ';
	ss << '*';
	string ss1 = ss.str();
	char const * str = ss1.c_str();
	int size = ss1.size();	
	
	sr->off = 0;
	int n = sr->Send(str + sr->off, size - sr->off);
	if (n <= 0)
		return 1;
	sr->off += n;
	while (sr->off < size) {
		n = sr->Send(str + sr->off, size - sr->off);
		if (n <= 0)
			return 1;
		sr->off += n;
	}
	sr->off = 0;

	AfxGetMainWnd()->PostMessage(WM_COMMAND, (WPARAM)CM_DELETE, (LPARAM)sr);
}