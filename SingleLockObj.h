#pragma once
#include <windows.h>
class CLock
{
public:
	CLock() { InitializeCriticalSection(&m_CS); }
	~CLock() { DeleteCriticalSection(&m_CS); }
	void EnterLock() { EnterCriticalSection(&m_CS); }		
	void LeaveLock() { LeaveCriticalSection(&m_CS); }
private:
	CRITICAL_SECTION m_CS;
};

class CAutoLock
{
public:
	CAutoLock(CLock& lock) : m_lock(lock) { m_lock.EnterLock(); }
	~CAutoLock() { m_lock.LeaveLock(); }
private:
	CLock& m_lock;
};

class CSingleLockObj
{
private:
	CSingleLockObj(void);
	static CSingleLockObj *m_SingleLockobj;
	static CLock m_Lock;
public:
	~CSingleLockObj(void);

	static CSingleLockObj* GetInstance(){
		CAutoLock autolock(m_Lock);
		if (!m_SingleLockobj)
		{
			m_SingleLockobj = new CSingleLockObj;
		}
		return m_SingleLockobj;
	}
};
