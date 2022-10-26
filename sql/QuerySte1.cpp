// QuerySte1.cpp : 实现文件
//

#include "stdafx.h"
#include "QuerySte1.h"
#include "MyApp.h"

// CQuerySte1 对话框

IMPLEMENT_DYNAMIC(CQuerySte1, CDialog)

CQuerySte1::CQuerySte1(CWnd* pParent /*=NULL*/)
	: CDialog(CQuerySte1::IDD, pParent)
	, sno1(_T(""))
{

}

CQuerySte1::~CQuerySte1()
{
}

void CQuerySte1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mlist1);
}


BEGIN_MESSAGE_MAP(CQuerySte1, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CQuerySte1::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_D11, &CQuerySte1::OnBnClickedD11)
	
END_MESSAGE_MAP()


// CQuerySte1 消息处理程序

BOOL CQuerySte1::OnInitDialog()
{
	CDialog::OnInitDialog();
	mlist1.SetExtendedStyle(mlist1.GetExtendedStyle()|
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	mlist1.InsertColumn(0,L"药品编号",LVCFMT_CENTER,100);
	mlist1.InsertColumn(1,L"名称",LVCFMT_CENTER,100);
	mlist1.InsertColumn(2,L"入库时间",LVCFMT_CENTER,100);
	mlist1.InsertColumn(3,L"入库数量",LVCFMT_CENTER,100);
	mlist1.InsertColumn(4,L"库存数量",LVCFMT_CENTER,100);
	//mlist1.InsertColumn(5,L"说明",LVCFMT_CENTER,100);
	ShowData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CQuerySte1::ShowData(void)
{
	_RecordsetPtr pRecordset;
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset(L"select * from instr");
mlist1.DeleteAllItems();
	int nItem;
	while(!pRecordset->adoEOF)
	{
		nItem = mlist1.GetItemCount();
		CString str;
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"sid"));
		mlist1.InsertItem(nItem,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"name"));
		mlist1.SetItemText(nItem,1,str);
		str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		mlist1.SetItemText(nItem,2,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"num"));
		mlist1.SetItemText(nItem,3,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"over"));
		mlist1.SetItemText(nItem,4,str);
		//str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"expln"));
		//mlist1.SetItemText(nItem,5,str);
		//str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		//mlist.SetItemText(nItem,6,str);
		

		pRecordset->MoveNext();
	}
	pRecordset->Close();
}


void CQuerySte1::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	POSITION pos = mlist1.GetFirstSelectedItemPosition();
	if(pos == NULL)
		TRACE0("NO item were select!\n");
	else
	{
		int nItem = mlist1.GetNextSelectedItem(pos);
		sno1 = mlist1.GetItemText(nItem,0);
		//AfxMessageBox(pno);
	}
	*pResult = 0;
	
}

void CQuerySte1::OnBnClickedD11()
{
	// TODO: 在此添加控件通知处理程序代码
	if(sno1==L""){
		AfxMessageBox(L"没选择要删除的入库信息！");
			return;
	}
	if(MessageBox(L"确定要删除该入库的信息吗？",L"请确认",MB_YESNO)!=IDYES)
		return;
	CString sql;
	sql.Format(L"delete from instr where sid='%s'",sno1);
	//执行SQL语句
	_variant_t n;
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL(_bstr_t(sql),&n))
	{
	AfxMessageBox(L"成功删除了一条记录");
	ShowData();
	}
}


