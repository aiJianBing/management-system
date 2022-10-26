// DeleRK.cpp : 实现文件
//

#include "stdafx.h"
#include "DeleRK.h"
#include "MyApp.h"


// CDeleRK 对话框

IMPLEMENT_DYNAMIC(CDeleRK, CDialog)

CDeleRK::CDeleRK(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleRK::IDD, pParent)
	, mSsid(_T(""))
	, mSname(_T(""))
	, mStime(_T(""))
	, mSnum(_T(""))
	, mSover(_T(""))
{

}

CDeleRK::~CDeleRK()
{
}

void CDeleRK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mSsid);
	DDX_Text(pDX, IDC_EDIT8, mSname);
	DDX_Text(pDX, IDC_EDIT9, mStime);
	DDX_Text(pDX, IDC_EDIT10, mSnum);
	DDX_Text(pDX, IDC_EDIT11, mSover);
}


BEGIN_MESSAGE_MAP(CDeleRK, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleRK::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleRK::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CDeleRK::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CDeleRK::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL, &CDeleRK::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDeleRK 消息处理程序

BOOL CDeleRK::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString sql=L"select * from instr";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDeleRK::ShowData(void)
{
	if(pRecordset==NULL||pRecordset->State==adStateOpen||pRecordset->adoEOF)
	mSsid=CAdoDB::toString(pRecordset->GetCollect(L"sid")); 
	mSname=CAdoDB::toString(pRecordset->GetCollect(L"name")); 
	mStime=CAdoDB::toString(pRecordset->GetCollect(L"time")); 
	mSnum=CAdoDB::toString(pRecordset->GetCollect(L"num")); 
	mSover=CAdoDB::toString(pRecordset->GetCollect(L"over")); 
	UpdateData(false);
}

void CDeleRK::OnBnClickedButton2()
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

void CDeleRK::OnBnClickedButton3()
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

void CDeleRK::OnBnClickedOk()//删除
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

void CDeleRK::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	try{
		pRecordset->PutCollect(L"sid",(_variant_t(mSsid)));
		pRecordset->PutCollect(L"name",(_variant_t(mSname)));
		pRecordset->PutCollect(L"time",(_variant_t(mStime)));
		pRecordset->PutCollect(L"num",(_variant_t(mSnum)));
		pRecordset->PutCollect(L"over",(_variant_t(mSover)));
		pRecordset->Update();
		pRecordset->Requery(adAsyncFetch);
		ShowData();
		AfxMessageBox(L"修改成功了");
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CDeleRK::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(pRecordset!=NULL&&pRecordset->State==adStateOpen)
		pRecordset->Close();
	OnCancel();
}
