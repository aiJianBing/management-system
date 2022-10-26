// MyApp.cpp : ʵ���ļ�
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
		
		AfxMessageBox(L"�����ݿ�ʧ��");
		return false;
	}
	
	CMainWnd *pWnd;//����һ��ָ�����
	pWnd = new CMainWnd();//��������
	pWnd->Create(0,L"���ݿ�Ӧ��ϵͳ���-�ܺ���");//�������ڶ���
	this->m_pMainWnd = pWnd;//����������Ӧ�ö������
	pWnd->ShowWindow(this->m_nCmdShow);
	/*::CoInitialize(NULL);
    //�� ��������ָ�����
	_ConnectionPtr pConn;
	//�� �������Ӷ���ʵ��
	pConn.CreateInstance(L"ADODB.Connection");//__uuidof(Connection)
	//�� ��MySQL���ݿ⽨������
	try{
	pConn->Open(L"Driver={MySQL ODBC 5.3 Unicode Driver};Server=localhost;Database=devmng",
		L"root",L"lsm147013",adModeUnknown);
	    //AfxMessageBox(L"���ӵ����ݿ������");
	}catch(_com_error e){
		AfxMessageBox(e.Description());
		return false;
    
	
	}*/	

	return TRUE;
}

int CMyApp::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	::CoUninitialize();


	return CWinApp::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
END_MESSAGE_MAP()


// CMyApp ��Ϣ�������
CMyApp mApp;