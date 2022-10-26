// AddStu2.cpp : 实现文件
//

#include "stdafx.h"
#include "AddStu2.h"
#include "MyApp.h"


// CAddStu2 对话框

IMPLEMENT_DYNAMIC(CAddStu2, CDialog)

CAddStu2::CAddStu2(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStu2::IDD, pParent)
	, mSno2(_T(""))
	, mName2(_T(""))
	, mTime2(_T(""))
	, mNum3(_T(""))
	, mNum4(_T(""))
{

}

CAddStu2::~CAddStu2()
{
}

void CAddStu2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SNO2, mSno2);
	DDV_MaxChars(pDX, mSno2, 14);
	DDX_Text(pDX, IDC_SNAME2, mName2);
	DDV_MaxChars(pDX, mName2, 10);
	DDX_Text(pDX, IDC_TIME2, mTime2);
	DDV_MaxChars(pDX, mTime2, 10);
	DDX_Text(pDX, IDC_NUMBER3, mNum3);
	DDV_MaxChars(pDX, mNum3, 10);
	DDX_Text(pDX, IDC_NUMBER4, mNum4);
	DDV_MaxChars(pDX, mNum4, 10);
}


BEGIN_MESSAGE_MAP(CAddStu2, CDialog)
	ON_BN_CLICKED(IDOK, &CAddStu2::OnBnClickedOk)

END_MESSAGE_MAP()


// CAddStu2 消息处理程序

void CAddStu2::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	UpdateData(true);

	CString sql2;
	sql2.Format(L"insert into outstr values('%s','%s','%s','%s','%s')",
	 mSno2,mName2,mTime2,mNum3,mNum4);
	
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql2,&v))
	{
		CString s;
		AfxMessageBox(L"成功地加入了"+CAdoDB::toString(v)+L"个出库信息");
	}
}

