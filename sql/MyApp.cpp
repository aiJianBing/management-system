// MyApp.cpp : 实现文件
//

#include "stdafx.h"

#include "MyApp.h"

#include "MainWnd.h"

// CMyApp

IMPLEMENT_DYNCREATE(CMyApp, CWinApp)

CMyApp::CMyApp()
{
}

CMyApp::~CMyApp()
{
}

BOOL CMyApp::InitInstance()
{
	//CAdoDB mDB;
	if(!mDB.OpenDB())
	{
		
		AfxMessageBox(L"打开数据库失败");
		return false;
	}
	
	CMainWnd *pWnd;//定义一个指针变量
	pWnd = new CMainWnd();//创建对象
	pWnd->Create(0,L"数据库应用系统设计-周好琦");//创建窗口对象
	this->m_pMainWnd = pWnd;//将主窗口与应用对象关联
	pWnd->ShowWindow(this->m_nCmdShow);
	/*::CoInitialize(NULL);
    //② 定义智能指针变量
	_ConnectionPtr pConn;
	//③ 创建连接对象实例
	pConn.CreateInstance(L"ADODB.Connection");//__uuidof(Connection)
	//④ 和MySQL数据库建立连接
	try{
	pConn->Open(L"Driver={MySQL ODBC 5.3 Unicode Driver};Server=localhost;Database=devmng",
		L"root",L"lsm147013",adModeUnknown);
	    //AfxMessageBox(L"连接到数据库服务器");
	}catch(_com_error e){
		AfxMessageBox(e.Description());
		return false;
    
	
	}*/	

	return TRUE;
}

int CMyApp::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	::CoUninitialize();


	return CWinApp::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
END_MESSAGE_MAP()


// CMyApp 消息处理程序
CMyApp mApp;