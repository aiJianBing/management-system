// Deleqy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Deleqy.h"
#include "MyApp.h"


// CDeleqy �Ի���

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


// CDeleqy ��Ϣ�������

BOOL CDeleqy::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString sql=L"select * from quyao";
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset_Edit(_bstr_t(sql));
	ShowData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	try{
		pRecordset->MovePrevious();
		ShowData();
	}catch(_com_error e)
	{
		AfxMessageBox(L"�Ѿ�����ǰ����");
	}

}

void CDeleqy::OnBnClickedButton2()
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

void CDeleqy::OnBnClickedOk()
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

	//OnOK();
}

void CDeleqy::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		AfxMessageBox(L"�޸ĳɹ���");
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CDeleqy::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(pRecordset!=NULL&&pRecordset->State==adStateOpen)
		pRecordset->Close();
	OnCancel();
}
