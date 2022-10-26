// DeleCK.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeleCK.h"
#include "MyApp.h"

// DeleCK �Ի���

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


// DeleCK ��Ϣ�������

BOOL DeleCK::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString sql=L"select * from outstr";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	try{
		pRecordset->MovePrevious();
		ShowData();
	}catch(_com_error e)
	{
		AfxMessageBox(L"�Ѿ�����ǰ����");
	}
}

void DeleCK::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	try
	{
		pRecordset->MoveNext();
		ShowData();
		
	}catch(_com_error e)
	{

		AfxMessageBox(L"�Ѿ����������");
	}
}

void DeleCK::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	try{
		pRecordset->Delete(adAffectCurrent);
		pRecordset->Update();
        pRecordset->Requery(adAsyncFetch);
		ShowData();
		AfxMessageBox(L"ɾ���ɹ���");
		}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void DeleCK::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		AfxMessageBox(L"�޸ĳɹ���");
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void DeleCK::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(pRecordset!=NULL&&pRecordset->State==adStateOpen)
		pRecordset->Close();
	OnCancel();
}
