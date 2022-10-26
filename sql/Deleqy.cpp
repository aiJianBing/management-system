// Deleqy.cpp : 实现文件
//

#include "stdafx.h"
#include "Deleqy.h"
#include "MyApp.h"


// CDeleqy 对话框

IMPLEMENT_DYNAMIC(CDeleqy, CDialog)

CDeleqy::CDeleqy(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleqy::IDD, pParent)
	, mSoffice(_T(""))
	, mSsid(_T(""))
	, mSdoc(_T(""))
	, mSpatient(_T(""))
	, mSqy(_T(""))
	, mStime(_T(""))
{

}

CDeleqy::~CDeleqy()
{
}

void CDeleqy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mSoffice);
	DDX_Text(pDX, IDC_EDIT8, mSsid);
	DDX_Text(pDX, IDC_EDIT9, mSdoc);
	DDX_Text(pDX, IDC_EDIT10, mSpatient);
	DDX_Text(pDX, IDC_EDIT11, mSqy);
	DDX_Text(pDX, IDC_EDIT2, mStime);
}


BEGIN_MESSAGE_MAP(CDeleqy, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleqy::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleqy::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CDeleqy::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleqy::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &CDeleqy::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDeleqy 消息处理程序

BOOL CDeleqy::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString sql=L"select * from quyao";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDeleqy::ShowData(void)
{
	if(pRecordset==NULL||pRecordset->State==adStateOpen||pRecordset->adoEOF)
	mSoffice=CAdoDB::toString(pRecordset->GetCollect(L"office")); 
	mSsid=CAdoDB::toString(pRecordset->GetCollect(L"sid")); 
	mSdoc=CAdoDB::toString(pRecordset->GetCollect(L"doc")); 
	mSpatient=CAdoDB::toString(pRecordset->GetCollect(L"patient")); 
	mStime=CAdoDB::toString(pRecordset->GetCollect(L"time")); 
	mSqy=CAdoDB::toString(pRecordset->GetCollect(L"qy")); 
	UpdateData(false);
}

void CDeleqy::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	try{
		pRecordset->MovePrevious();
		ShowData();
	}catch(_com_error e)
	{
		AfxMessageBox(L"已经到最前面了");
	}

}

void CDeleqy::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	try
	{
		pRecordset->MoveNext();
		ShowData();
		
	}catch(_com_error e)
	{

		AfxMessageBox(L"已经是最后面了");
	}
}

void CDeleqy::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	try{
		pRecordset->Delete(adAffectCurrent);
		pRecordset->Update();
        pRecordset->Requery(adAsyncFetch);
		ShowData();
		AfxMessageBox(L"删除成功了");
		}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}

	//OnOK();
}

void CDeleqy::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	try{
		pRecordset->PutCollect(L"office",(_variant_t(mSoffice)));
		pRecordset->PutCollect(L"sid",(_variant_t(mSsid)));
		pRecordset->PutCollect(L"doc",(_variant_t(mSdoc)));
		pRecordset->PutCollect(L"patient",(_variant_t(mSpatient)));
		pRecordset->PutCollect(L"time",(_variant_t(mStime)));
		pRecordset->PutCollect(L"qy",(_variant_t(mSqy)));
		pRecordset->Update();
		pRecordset->Requery(adAsyncFetch);
		ShowData();
		AfxMessageBox(L"修改成功了");
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CDeleqy::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(pRecordset!=NULL&&pRecordset->State==adStateOpen)
		pRecordset->Close();
	OnCancel();
}
