// AddStu1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AddStu1.h"
#include "MyApp.h"

// CAddStu1 �Ի���

IMPLEMENT_DYNAMIC(CAddStu1, CDialog)

CAddStu1::CAddStu1(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStu1::IDD, pParent)
	
	, mSno1(_T(""))
	
	, mName1(_T(""))
	, mTime1(_T(""))
	, mNum1(_T(""))
	, mNum2(_T(""))
{

}

CAddStu1::~CAddStu1()
{
}

void CAddStu1::DoDataExchange(CDataExchange* pDX)
{


	DDX_Text(pDX, IDC_SNO1, mSno1);
	DDV_MaxChars(pDX, mSno1, 14);

	DDX_Text(pDX, IDC_SNAME1, mName1);
	DDV_MaxChars(pDX, mName1, 10);
	DDX_Text(pDX, IDC_TIME1, mTime1);
	DDV_MaxChars(pDX, mTime1, 10);
	DDX_Text(pDX, IDC_NUMBER1, mNum1);
	DDX_Text(pDX, IDC_NUMBER2, mNum2);
	DDV_MaxChars(pDX, mNum2, 10);
}


BEGIN_MESSAGE_MAP(CAddStu1, CDialog)
	ON_BN_CLICKED(IDOK, &CAddStu1::OnBnClickedOk)

END_MESSAGE_MAP()


// CAddStu1 ��Ϣ�������

void CAddStu1::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	UpdateData(true);

	CString sql1;
	sql1.Format(L"insert into instr values('%s','%s','%s','%s','%s')",
	 mSno1,mName1,mTime1,mNum1,mNum2);
	
	_variant_t v; 
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL((_bstr_t)sql1,&v))
	{
		CString s;
		AfxMessageBox(L"�ɹ��ؼ�����"+CAdoDB::toString(v)+L"�������Ϣ");
	}
}


