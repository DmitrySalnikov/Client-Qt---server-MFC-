#pragma once

#include "jmp.h"
#include <vector>

class CMyModel;

class Ship : public CSimThread {

public:
	void Main();
	Ship(CMyModel * pModel) : CSimThread((CSimTimer*)pModel) { m_pModel = pModel; }

private:
	CMyModel * m_pModel;

};

class Base : public CSimRes {

public:
	Base(CMyModel* pModel) : CSimRes((CSimTimer*)pModel) {}

};

class CMyModel : public CSimTimer {

public:
	CMyModel(int a, int b) : tank(a), days(b), m_pDevice(new Base(this)) {
		for (int i = 0; i < tank; ++i) 
			ship.push_back(new Ship(this));
	}
	~CMyModel() {
		delete m_pDevice;
		for (int i = 0; i < tank; ++i)
			delete ship[i];
	}

	Base * m_pDevice;
	vector<long> wait_in_que;
	int days;

private:
	int tank;
	vector<Ship *> ship;

};

