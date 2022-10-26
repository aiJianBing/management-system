// MainWnd.cpp : 实现文件
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


// CMainWnd 消息处理程序

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	menu.LoadMenuW((LPCTSTR)IDR_MENU1);
	this->SetMenu(&menu);



	return 0;
}

void CMainWnd::OnExit()
{
	AfxGetApp()->PostThreadMessage(WM_QUIT,0,0);
	// TODO: 在此添加命令处理程序代码
}

void CMainWnd::OnAddstu()
{
	CAddStu mDlg;
	mDlg.DoModal();
	
	/*CString sql = L"insert into student values('17110107”,'马奇','男','1998-11-2',1.78)"; 
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql,&v))
	{
		CString s;
	//s.Format(L"%d",v.intVal); 
		AfxMessageBox(CAdoDB::toString(v));

	// TODO: 在此添加命令处理程序代码
	}
	*/
}

void CMainWnd::OnAddstu1()
{
	CAddStu1 mDlg;
	mDlg.DoModal();

	// TODO: 在此添加命令处理程序代码
}

void CMainWnd::OnAddstu2()
{
	CAddStu2 mDlg;
	mDlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}



void CMainWnd::OnModistu()
{
	CDelStu mDlg;
	mDlg.DoModal();

	// TODO: 在此添加命令处理程序代码
}

void CMainWnd::OnQuerystu()
{
	// TODO: 在此添加命令处理程序代码
	CQueryStu mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQuerystu1()
{
	// TODO: 在此添加命令处理程序代码
	CQuerySte1 mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQuerystu2()
{
	// TODO: 在此添加命令处理程序代码
	CQuerySte2 mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnModistu1()
{
	// TODO: 在此添加命令处理程序代码
	CDeleRK mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnModistu2()
{
	// TODO: 在此添加命令处理程序代码
	DeleCK mDlg;
	mDlg.DoModal();
}

void CMainWnd::Onaddqy()
{
	// TODO: 在此添加命令处理程序代码
	CAddQY mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnDeleqy()
{
	// TODO: 在此添加命令处理程序代码
	CDeleqy mDlg;
	mDlg.DoModal();
}

void CMainWnd::OnQueryqy()
{
	// TODO: 在此添加命令处理程序代码
	CQueryqy mDlg;
	mDlg.DoModal();
}
