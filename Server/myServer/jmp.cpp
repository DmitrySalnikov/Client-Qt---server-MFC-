#include "stdafx.h"
#include "jmp.h"

const int ST_SIZE = 24 * 1024;
typedef long* PJMPBUF;
const int _ebp = 0, _esp = 4, _reg = 6;

void LongJmp(int* buf, int a)
{
	_asm
	{
		mov         edx, buf
		mov         ebx, dword ptr[edx + 4]
			mov         edi, dword ptr[edx + 8]
			mov         esi, dword ptr[edx + 0Ch]
			mov         eax, a
			mov         ebp, dword ptr[edx]
			mov         esp, dword ptr[edx + 10h]
			add         esp, 4
			jmp         dword ptr[edx + 14h]
	}
}


bool operator < (CSimEvent e1, CSimEvent e2)
{
	return e1.m_Time>e2.m_Time;
}

void CSimTimer::Run()
{
	for (;;)
	{
		while (!QNew.empty())
		{
			CurThread = QNew.front();
			QNew.pop_front();
			CurThread->Run();
		}
		CurThread = CheckResources();
		if (!CurThread)
		{
			if (QWait.empty()) break;
			CurTime = QWait.top().m_Time;
			CurThread = QWait.top().m_pThread;
			QWait.pop();
		}
		CurThread->Resume();
		if (exit_code == 3) delete CurThread;
	}
}

CSimThread*  CSimTimer::CheckResources()
{
	for (deque<CSimRes*>::iterator r = QRes.begin(); r != QRes.end(); r++)
	{
		if ((**r).resource != 0 && !(**r).QThread.empty())
		{
			(**r).resource--;
			CSimThread* t = (**r).QThread.front();
			(**r).QThread.pop_front();
			return t;
		}
	}
	return 0;
}


CSimThread::CSimThread(CSimTimer* pTimer)
{
	m_pTimer = pTimer;
	m_Stack = new char[ST_SIZE];
	m_pTimer->QNew.push_back(this);
}

void CSimThread::Run()
{
	if (setjmp(m_Addr) == 0)
	{
		PJMPBUF _jb = (PJMPBUF)m_Addr;

		unsigned bp_sp = _jb[_ebp] - _jb[_esp],
			sp_size = bp_sp + 20;
		char *end = (char*)m_Stack + ST_SIZE - sp_size;

		memcpy(end, (void*)_jb[_esp], sp_size);

		_jb[_esp] = (unsigned)end;
		_jb[_ebp] = _jb[_esp] + bp_sp;

		m_pTimer->QWait.push(CSimEvent(this, m_pTimer->CurTime));
	}
	else
	{
		Main();
		ExitSimThread();
	}
}

void CSimThread::Suspend()
{
	if (setjmp(m_Addr) == 0)
	{
		LongJmp(m_pTimer->jb, 1);
	}
}

void CSimThread::Resume()
{
	int res = setjmp(m_pTimer->jb);
	if (res == 0)
		LongJmp(m_Addr, 1);
	else m_pTimer->exit_code = res;
}

void CSimThread::Wait(long t)
{
	m_pTimer->QWait.push(CSimEvent(this, m_pTimer->CurTime + t));
	Suspend();
}

void CSimThread::ExitSimThread()
{
	LongJmp(m_pTimer->jb, 2);
}

void CSimThread::DeleteSimThread()
{
	LongJmp(m_pTimer->jb, 3);
}


CSimRes::CSimRes(CSimTimer* timer, int r)
	: resource(r)
{
	Timer = timer;
	Timer->QRes.push_back(this);
}

void CSimRes::Enter()
{
	if (resource != 0) resource--;
	else
	{
		QThread.push_back(Timer->CurThread);
		Timer->CurThread->Suspend();
	}
}
