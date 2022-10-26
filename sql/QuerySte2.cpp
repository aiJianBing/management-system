// QuerySte2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QuerySte2.h"
#include "MyApp.h"

// CQuerySte2 �Ի���

IMPLEMENT_DYNAMIC(CQuerySte2, CDialog)

CQuerySte2::CQuerySte2(CWnd* pParent /*=NULL*/)
	: CDialog(CQuerySte2::IDD, pParent)
	, sno2(_T(""))
{

}

CQuerySte2::~CQuerySte2()
{
}

void CQuerySte2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mlist2);
}


BEGIN_MESSAGE_MAP(CQuerySte2, CDialog)
	
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CQuerySte2::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_d1, &CQuerySte2::OnBnClickedd1)
	
END_MESSAGE_MAP()


// CQuerySte2 ��Ϣ�������

BOOL CQuerySte2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	mlist2.SetExtendedStyle(mlist2.GetExtendedStyle()|
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	mlist2.InsertColumn(0,L"ҩƷ���",LVCFMT_CENTER,100);
	mlist2.InsertColumn(1,L"����",LVCFMT_CENTER,100);
	mlist2.InsertColumn(2,L"����ʱ��",LVCFMT_CENTER,100);
	mlist2.InsertColumn(3,L"��������",LVCFMT_CENTER,100);
	mlist2.InsertColumn(4,L"�������",LVCFMT_CENTER,100);
	//mlist1.InsertColumn(5,L"˵��",LVCFMT_CENTER,100);
	ShowData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CQuerySte2::ShowData(void)
{
	
	_RecordsetPtr pRecordset;
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset(L"select * from outstr");
mlist2.DeleteAllItems();
	int nItem;
	while(!pRecordset->adoEOF)
	{
		nItem = mlist2.GetItemCount();
		CString str;
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"sid"));
		mlist2.InsertItem(nItem,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"name"));
		mlist2.SetItemText(nItem,1,str);
		str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		mlist2.SetItemText(nItem,2,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"num"));
		mlist2.SetItemText(nItem,3,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"over"));
		mlist2.SetItemText(nItem,4,str);
		//str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"expln"));
		//mlist1.SetItemText(nItem,5,str);
		//str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		//mlist.SetItemText(nItem,6,str);
		

		pRecordset->MoveNext();
	}
	pRecordset->Close();
}
void CQuerySte2::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = mlist2.GetFirstSelectedItemPosition();
	if(pos == NULL)
		TRACE0("NO item were select!\n");
	else
	{
		int nItem = mlist2.GetNextSelectedItem(pos);
		sno2 = mlist2.GetItemText(nItem,0);
		//AfxMessageBox(pno);
	}
	*pResult = 0;
	
	
}

void CQuerySte2::OnBnClickedd1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(sno2==L""){
		AfxMessageBox(L"ûѡ��Ҫɾ���ĳ�����Ϣ��");
			return;
	}
	if(MessageBox(L"ȷ��Ҫɾ���ó������Ϣ��",L"��ȷ��",MB_YESNO)!=IDYES)
		return;
	CString sql;
	sql.Format(L"delete from outstr where sid='%s'",sno2);
	//ִ��SQL���
	_variant_t n;
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL(_bstr_t(sql),&n))
	{
	AfxMessageBox(L"�ɹ�ɾ����һ����¼");
	ShowData();
	}

}


