// MainWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainWnd.h"
#include "MyApp.h"
#include "AddStu.h"
#include "AddStu1.h"
#include "AddStu2.h"
#include "AddQY.h"
#include "DelStu.h"
#include "DeleRK.h"
#include "DeleCK.h"
#include "Deleqy.h"
#include "QueryStu.h"
#include "Queryqy.h"
#include "QuerySte1.h"
#include "QuerySte2.h"
// CMainWnd

IMPLEMENT_DYNCREATE(CMainWnd, CFrameWnd)

CMainWnd::CMainWnd()
{

}

CMainWnd::~CMainWnd()
{
}


BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_EXIT, &CMainWnd::OnExit)
	ON_COMMAND(ID_ADDSTU, &CMainWnd::OnAddstu)
	ON_COMMAND(ID_ADDSTU1, &CMainWnd::OnAddstu1)
	ON_COMMAND(ID_ADDSTU2, &CMainWnd::OnAddstu2)
	
	ON_COMMAND(IDM_MODISTU, &CMainWnd::OnModistu)
	ON_COMMAND(IDM_QUERYSTU, &CMainWnd::OnQuerystu)
	ON_COMMAND(IDM_QUERYSTU1, &CMainWnd::OnQuerystu1)
	ON_COMMAND(IDM_QUERYSTU2, &CMainWnd::OnQuerystu2)
	ON_COMMAND(IDM_MODISTU1, &CMainWnd::OnModistu1)
	ON_COMMAND(IDM_MODISTU2, &CMainWnd::OnModistu2)
	ON_COMMAND(ID_addQY, &CMainWnd::Onaddqy)
	ON_COMMAND(ID_DeleQY, &CMainWnd::OnDeleqy)
	ON_COMMAND(ID_QueryQY, &CMainWnd::OnQueryqy)
END_MESSAGE_MAP()


// CMainWnd ��Ϣ�������

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	menu.LoadMenuW((LPCTSTR)IDR_MENU1);
	this->SetMenu(&menu);



	return 0;
}

void CMainWnd::OnExit()
{
	AfxGetApp()->PostThreadMessage(WM_QUIT,0,0);
	// TODO: �ڴ���������������
}

void CMainWnd::OnAddstu()
{
	CAddStu mDlg;
	mDlg.DoModal();
	
	/*CString sql = L"insert into student values('17110107��,'����','��','1998-11-2',1.78)"; 
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql,&v))
	{
		CString s;
	//s.Format(L"%d",v.intVal); 
		AfxMessageBox(CAdoDB::toString(v));

	// TODO: �ڴ���������������
	}
	*/
}

void CMainWnd::OnAddstu1()
{
	CAddStu1 mDlg;
	mDlg.DoModal();

	// TODO: �ڴ���������������
}

void CMainWnd::OnAddstu2()
{
	CAddStu2 mDlg;
	mDlg.DoModal();
	// TODO: �ڴ���������������
}



void CMainWnd::OnModistu()
{
	CDelStu mDlg;
	mDlg.DoModal();

	// TODO: �ڴ���������������
}

void CMainWnd::OnQuerystu()
{
	// TODO: �ڴ���������������
	CQueryStu mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQuerystu1()
{
	// TODO: �ڴ���������������
	CQuerySte1 mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQuerystu2()
{
	// TODO: �ڴ���������������
	CQuerySte2 mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnModistu1()
{
	// TODO: �ڴ���������������
	CDeleRK mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnModistu2()
{
	// TODO: �ڴ���������������
	DeleCK mDlg;
	mDlg.DoModal();
}

void CMainWnd::Onaddqy()
{
	// TODO: �ڴ���������������
	CAddQY mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnDeleqy()
{
	// TODO: �ڴ���������������
	CDeleqy mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQueryqy()
{
	// TODO: �ڴ���������������
	CQueryqy mDlg;
	mDlg.DoModal();
}
