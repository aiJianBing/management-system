#pragma once

#include "AdoDB.h"

// CMyApp

class CMyApp : public CWinApp
{
	DECLARE_DYNCREATE(CMyApp)

public:
	CMyApp();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyApp();
	CAdoDB mDB;
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


