// AddQY.cpp : 实现文件
//

#include "stdafx.h"
#include "AddQY.h"
#include "MyApp.h"


// CAddQY 对话框

IMPLEMENT_DYNAMIC(CAddQY, CDialog)

CAddQY::CAddQY(CWnd* pParent /*=NULL*/)
	: CDialog(CAddQY::IDD, pParent)
	, mSoffice(_T(""))
	, mSsid(_T(""))
	, mSdoc(_T(""))
	, mSpatient(_T(""))
	, mStime(_T(""))
	, mSqy(_T(""))
{

}

CAddQY::~CAddQY()
{
}

void CAddQY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mSoffice);
	DDV_MaxChars(pDX, mSoffice, 10);
	DDX_Text(pDX, IDC_EDIT8, mSsid);
	DDV_MaxChars(pDX, mSsid, 14);
	DDX_Text(pDX, IDC_EDIT9, mSdoc);
	DDV_MaxChars(pDX, mSdoc, 10);
	DDX_Text(pDX, IDC_EDIT10, mSpatient);
	DDV_MaxChars(pDX, mSpatient, 10);
	DDX_Text(pDX, IDC_EDIT2, mStime);
	DDV_MaxChars(pDX, mStime, 10);
	DDX_Text(pDX, IDC_EDIT11, mSqy);
	DDV_MaxChars(pDX, mSqy, 100);
}


BEGIN_MESSAGE_MAP(CAddQY, CDialog)
	ON_BN_CLICKED(IDOK, &CAddQY::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddQY 消息处理程序

void CAddQY::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	CString sql;
	sql.Format(L"insert into quyao values('%s','%s','%s','%s','%s','%s')",
	mSoffice,mSsid, mSdoc, mSpatient, mStime, mSqy);
	
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql,&v))
	{
		CString s;  
		AfxMessageBox(L"成功地加入了"+CAdoDB::toString(v)+L"个取药信息");

	/*CString sql = L"insert into student values('17110107”,'马奇','男','1998-11-2',1.78)"; 
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql,&v))
	{
	OnOK();*/
	}
}
