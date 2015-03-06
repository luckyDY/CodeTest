#pragma once

class CSingleObj
{
private:
	CSingleObj(void);
	static const CSingleObj * m_Singleobj;
public:
	~CSingleObj(void);

	static const CSingleObj* GetInstance(){ return m_Singleobj;}
	static void DestoryInstance(){}
};
