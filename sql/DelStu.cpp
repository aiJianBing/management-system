// DelStu.cpp : 实现文件
//

#include "stdafx.h"
#include "DelStu.h"
#include "MyApp.h"


// CDelStu 对话框

IMPLEMENT_DYNAMIC(CDelStu, CDialog)

CDelStu::CDelStu(CWnd* pParent /*=NULL*/)
	: CDialog(CDelStu::IDD, pParent)
	, mSno(_T(""))
	, mSname(_T(""))
	, mSTYBE(_T(""))
	, mSPRICE(_T(""))
	, mSVALIDITY(_T(""))
	, mSEXOLAIN(_T(""))
{

}

CDelStu::~CDelStu()
{
}

void CDelStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, mSno);
	DDV_MaxChars(pDX, mSno, 14);
	DDX_Text(pDX, IDC_EDIT3, mSname);
	DDV_MaxChars(pDX, mSname, 10);
	DDX_Text(pDX, IDC_EDIT4, mSTYBE);
	DDV_MaxChars(pDX, mSTYBE, 10);
	DDX_Text(pDX, IDC_EDIT5, mSPRICE);
	DDV_MaxChars(pDX, mSPRICE, 10);
	DDX_Text(pDX, IDC_EDIT6, mSVALIDITY);
	DDV_MaxChars(pDX, mSVALIDITY, 10);
	DDX_Text(pDX, IDC_EDIT7, mSEXOLAIN);
	DDV_MaxChars(pDX, mSEXOLAIN, 100);
}


BEGIN_MESSAGE_MAP(CDelStu, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelStu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelStu::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CDelStu::OnBnClickedOk)
	ON_BN_CLICKED(IDC_xiu, &CDelStu::OnBnClickedxiu)
END_MESSAGE_MAP()


// CDelStu 消息处理程序

BOOL CDelStu::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString sql=L"select * from news";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDelStu::ShowData(void)
{
	if(pRecordset==NULL||pRecordset->State==adStateOpen||pRecordset->adoEOF)
	mSno=CAdoDB::toString(pRecordset->GetCollect(L"sid")); 
	mSname=CAdoDB::toString(pRecordset->GetCollect(L"name")); 
	mSTYBE=CAdoDB::toString(pRecordset->GetCollect(L"type")); 
	mSPRICE=CAdoDB::toString(pRecordset->GetCollect(L"price")); 
	mSVALIDITY=CAdoDB::toString(pRecordset->GetCollect(L"data")); 
	mSEXOLAIN=CAdoDB::toString(pRecordset->GetCollect(L"expln")); 
	UpdateData(false);
}

void CDelStu::OnBnClickedButton1()
{
	try{
		pRecordset->MovePrevious();
		ShowData();
	}catch(_com_error e)
	{
		AfxMessageBox(L"已经到最前面了");
	}
	
	// TODO: 在此添加控件通知处理程序代码
}

void CDelStu::OnBnClickedButton2()
{

	// TODO: 在此添加控件通知处理程序代码
	//if(!(pRecordset->adoEOF))
	try
	{
		pRecordset->MoveNext();
		ShowData();
		
	}catch(_com_error e)
	{

		AfxMessageBox(L"已经是最后面了");
	}
	
}

void CDelStu::OnBnClickedOk()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	try{
		pRecordset->Delete(adAffectCurrent);
		pRecordset->Update();
        pRecordset->Requery(adAsyncFetch);
		ShowData();
	
		}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CDelStu::OnBnClickedxiu()
{

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	try{
		pRecordset->PutCollect(L"sid",(_variant_t(mSno)));
		pRecordset->PutCollect(L"name",(_variant_t(mSname)));
		pRecordset->PutCollect(L"type",(_variant_t(mSTYBE)));
		pRecordset->PutCollect(L"price",(_variant_t(mSPRICE)));
		pRecordset->PutCollect(L"data",(_variant_t(mSVALIDITY)));
		pRecordset->PutCollect(L"expln",(_variant_t(mSEXOLAIN)));
		pRecordset->Update();
		pRecordset->Requery(adAsyncFetch);
		ShowData();
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}


