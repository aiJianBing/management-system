// DeleCK.cpp : 实现文件
//

#include "stdafx.h"
#include "DeleCK.h"
#include "MyApp.h"

// DeleCK 对话框

IMPLEMENT_DYNAMIC(DeleCK, CDialog)

DeleCK::DeleCK(CWnd* pParent /*=NULL*/)
	: CDialog(DeleCK::IDD, pParent)
	, mSsid1(_T(""))
	, mSname1(_T(""))
	, mStime(_T(""))
	, mSnum1(_T(""))
	, mSover1(_T(""))
{

}

DeleCK::~DeleCK()
{
}

void DeleCK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mSsid1);
	DDX_Text(pDX, IDC_EDIT8, mSname1);
	DDX_Text(pDX, IDC_EDIT9, mStime);
	DDX_Text(pDX, IDC_EDIT10, mSnum1);
	DDV_MaxChars(pDX, mSnum1, 10);
	DDV_MaxChars(pDX, mSname1, 10);
	DDV_MaxChars(pDX, mSsid1, 14);
	DDX_Text(pDX, IDC_EDIT11, mSover1);
	DDV_MaxChars(pDX, mStime, 10);
}


BEGIN_MESSAGE_MAP(DeleCK, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleCK::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DeleCK::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &DeleCK::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &DeleCK::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL, &DeleCK::OnBnClickedCancel)
END_MESSAGE_MAP()


// DeleCK 消息处理程序

BOOL DeleCK::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString sql=L"select * from outstr";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void DeleCK::ShowData(void)
{
	if(pRecordset==NULL||pRecordset->State==adStateOpen||pRecordset->adoEOF)
	mSsid1=CAdoDB::toString(pRecordset->GetCollect(L"sid")); 
	mSname1=CAdoDB::toString(pRecordset->GetCollect(L"name")); 
	mStime=CAdoDB::toString(pRecordset->GetCollect(L"time")); 
	mSnum1=CAdoDB::toString(pRecordset->GetCollect(L"num")); 
	mSover1=CAdoDB::toString(pRecordset->GetCollect(L"over")); 
	UpdateData(false);
}

void DeleCK::OnBnClickedButton2()
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

void DeleCK::OnBnClickedButton3()
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

void DeleCK::OnBnClickedButton5()
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
}

void DeleCK::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	try{
		pRecordset->PutCollect(L"sid",(_variant_t(mSsid1)));
		pRecordset->PutCollect(L"name",(_variant_t(mSname1)));
		pRecordset->PutCollect(L"time",(_variant_t(mStime)));
		pRecordset->PutCollect(L"num",(_variant_t(mSnum1)));
		pRecordset->PutCollect(L"over",(_variant_t(mSover1)));
		pRecordset->Update();
		pRecordset->Requery(adAsyncFetch);
		ShowData();
		AfxMessageBox(L"修改成功了");
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void DeleCK::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(pRecordset!=NULL&&pRecordset->State==adStateOpen)
		pRecordset->Close();
	OnCancel();
}
