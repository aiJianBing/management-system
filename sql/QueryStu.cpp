// QueryStu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QueryStu.h"
#include "MyApp.h"


// CQueryStu �Ի���

IMPLEMENT_DYNAMIC(CQueryStu, CDialog)

CQueryStu::CQueryStu(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryStu::IDD, pParent)
{

}

CQueryStu::~CQueryStu()
{
}

void CQueryStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, mlist);
}


BEGIN_MESSAGE_MAP(CQueryStu, CDialog)
	
END_MESSAGE_MAP()


// CQueryStu ��Ϣ�������

BOOL CQueryStu::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	mlist.SetExtendedStyle(mlist.GetExtendedStyle()|
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	mlist.InsertColumn(0,L"ҩƷ���",LVCFMT_CENTER,100);
	mlist.InsertColumn(1,L"����",LVCFMT_CENTER,100);
	mlist.InsertColumn(2,L"ҩ��",LVCFMT_CENTER,100);
	mlist.InsertColumn(3,L"�ۼ�",LVCFMT_CENTER,100);
	mlist.InsertColumn(4,L"��Ч��",LVCFMT_CENTER,100);
	mlist.InsertColumn(5,L"˵��",LVCFMT_CENTER,100);
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CQueryStu::ShowData(void)
{
	_RecordsetPtr pRecordset;
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset(L"select * from news");
mlist.DeleteAllItems();
	int nItem;
	while(!pRecordset->adoEOF)
	{
		nItem = mlist.GetItemCount();
		CString str;
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"sid"));
		mlist.InsertItem(nItem,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"name"));
		mlist.SetItemText(nItem,1,str);
		str = CAdoDB::toString(pRecordset->GetCollect(L"type"));
		mlist.SetItemText(nItem,2,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"price"));
		mlist.SetItemText(nItem,3,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"data"));
		mlist.SetItemText(nItem,4,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"expln"));
		mlist.SetItemText(nItem,5,str);
		//str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		//mlist.SetItemText(nItem,6,str);
		

		pRecordset->MoveNext();
	}
	pRecordset->Close();

}

/*void CQuerrysalary::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		POSITION pos = mlist.GetFirstSelectedItemPosition();
	if(pos == NULL)
		TRACE0("NO item were select!\n");
	else
	{
		int nItem = mlist.GetNextSelectedItem(pos);
		sid = mlist.GetItemText(nItem,0);
		//AfxMessageBox(pno);
	}
	*pResult = 0;
}

void CQuerrysalary::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(sid==L""){
		AfxMessageBox(L"ûѡ��Ҫɾ���Ĺ�����Ϣ��");
			return;
	}
	if(MessageBox(L"ȷ��Ҫɾ���ù��ʵ���Ϣ��",L"��ȷ��",MB_YESNO)!=IDYES)
		return;
	CString sql;
	sql.Format(L"delete from salary where id='%s'",sid);
	//ִ��SQL���
	_variant_t n;
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL(_bstr_t(sql),&n))
	{
	AfxMessageBox(L"�ɹ�ɾ����һ����¼");
	ShowData();
	}
}

}*/

