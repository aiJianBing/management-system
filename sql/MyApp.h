#pragma once

#include "AdoDB.h"

// CMyApp

class CMyApp : public CWinApp
{
	DECLARE_DYNCREATE(CMyApp)

public:
	CMyApp();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyApp();
	CAdoDB mDB;
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


