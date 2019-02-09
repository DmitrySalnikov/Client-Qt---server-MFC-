#pragma once
#include <setjmp.h>
#include <queue>
#include <deque>
using namespace std;

typedef long SimTime;

class CSimThread;
class CSimRes;

struct CSimEvent
{
	long m_Time;
	CSimThread* m_pThread;
	CSimEvent(CSimThread* thread, long time) : m_pThread(thread), m_Time(time) {}

};

class CSimTimer
{
	jmp_buf jb;
	
	deque<CSimThread*>        QNew;
	int exit_code;
public:
	priority_queue<CSimEvent> QWait;
	CSimThread* CurThread;
	deque<CSimRes*>           QRes;
	long CurTime;
	CSimTimer() { CurTime = 0; }
	void Run();
	CSimThread* CheckResources();
	friend class CSimThread;
};

class CSimThread
{
	jmp_buf m_Addr;
	void*  m_Stack;
	void ExitSimThread();
	void Run();
public:
	CSimTimer* m_pTimer;
	CSimThread(CSimTimer* pTimer);
	~CSimThread() { delete m_Stack; }

	SimTime CurTime() { return m_pTimer->CurTime; }
	void Suspend();
	void Resume();
	void Wait(long time);
	void DeleteSimThread();
	virtual void Main() {};
	friend class CSimTimer;
};

class CSimRes
{
	int resource;
	deque<CSimThread*> QThread;
	CSimTimer* Timer;
public:
	CSimRes(CSimTimer* timer, int r = 1);
	void Enter();
	void Leave() { resource++; }
	bool Available() { return resource>0; }

	friend class CSimTimer;
	friend class CSimThread;
};
