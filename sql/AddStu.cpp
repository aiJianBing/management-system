// AddStu.cpp : 实现文件
//

#include "stdafx.h"
#include "AddStu.h"
#include "MyApp.h"


// CAddStu 对话框

IMPLEMENT_DYNAMIC(CAddStu, CDialog)

CAddStu::CAddStu(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStu::IDD, pParent)
	, mSno(_T(""))
	, mSname(_T(""))
	, mSTYBE(_T(""))
	, mSPRICE(0)
	, mSVALIDITY(_T(""))
	, mSEXPLAIN(_T(""))
	
{

}

CAddStu::~CAddStu()
{
}

void CAddStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SNO, mSno);
	DDV_MaxChars(pDX, mSno, 14);
	DDX_Text(pDX, IDC_SNAME, mSname);
	DDV_MaxChars(pDX, mSname, 20);
	DDX_Text(pDX, IDC_STYBE, mSTYBE);
	DDV_MaxChars(pDX, mSTYBE, 10);
	DDX_Text(pDX, IDC_SPRICE, mSPRICE);
	DDV_MinMaxFloat(pDX, mSPRICE, 0, 10000);
	DDX_Text(pDX, IDC_SVALIDITY, mSVALIDITY);
	DDV_MaxChars(pDX, mSVALIDITY, 10);
	DDX_Text(pDX, IDC_SEXPLAIN, mSEXPLAIN);
	DDV_MaxChars(pDX, mSEXPLAIN, 100);
	
}


BEGIN_MESSAGE_MAP(CAddStu, CDialog)
	ON_BN_CLICKED(IDOK, &CAddStu::OnBnClickedOk)

END_MESSAGE_MAP()


// CAddStu 消息处理程序

void CAddStu::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	UpdateData(true);

	CString sql;
	sql.Format(L"insert into news values('%s','%s','%s','%f','%s','%s')",
	mSno,mSname, mSTYBE, mSPRICE, mSVALIDITY, mSEXPLAIN);
	
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql,&v))
	{
		CString s;
		AfxMessageBox(L"成功地加入了"+CAdoDB::toString(v)+L"个药品信息");

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
}


