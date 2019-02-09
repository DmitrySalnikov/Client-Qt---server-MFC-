#include "stdafx.h"
#include "sock.h"
#include <Windows.h>
#include <string>
#include "model.h"
#include "RAND.H"

using namespace std;

UINT Simulation(LPVOID srv);

void CSrvClt::OnReceive(int nErrorCode) {
	char * buf = (char *)&param;
	int size = sizeof(param);
	int n = Receive(buf + off, size - off);
	if (n <= 0)
		return;
	off += n;
	while (off < size) {
		n = Receive(buf + off, size - off);
		if (n <= 0)
			return;
		off += n;
	}
	off = 0;

	rcomeinit(param.i[1], param.i[2]);
	rservinit(param.i[3], param.i[4]);
		
	AfxBeginThread(Simulation, (LPVOID)this);
		
	CSocket::OnReceive(nErrorCode);
}

void CServer::OnAccept(int nErrorCode) {
	CSrvClt *clt = new CSrvClt();
	Accept(*clt);
	CSocket::OnAccept(nErrorCode);
}