// CodeTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SingleObj.h"
#include "SingleLockObj.h"

const CSingleObj* CSingleObj::m_Singleobj = new CSingleObj;
CSingleLockObj *CSingleLockObj::m_SingleLockobj = NULL;
CLock CSingleLockObj::m_Lock;

int _tmain(int argc, _TCHAR* argv[])
{
	const CSingleObj* obj = CSingleObj::GetInstance();
	CSingleLockObj* lockobj = CSingleLockObj::GetInstance();
	return 0;
}

