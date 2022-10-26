// QueryStu.cpp : 实现文件
//

#include "stdafx.h"
#include "QueryStu.h"
#include "MyApp.h"


// CQueryStu 对话框

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


// CQueryStu 消息处理程序

BOOL CQueryStu::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	mlist.SetExtendedStyle(mlist.GetExtendedStyle()|
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	mlist.InsertColumn(0,L"药品编号",LVCFMT_CENTER,100);
	mlist.InsertColumn(1,L"名称",LVCFMT_CENTER,100);
	mlist.InsertColumn(2,L"药剂",LVCFMT_CENTER,100);
	mlist.InsertColumn(3,L"售价",LVCFMT_CENTER,100);
	mlist.InsertColumn(4,L"有效期",LVCFMT_CENTER,100);
	mlist.InsertColumn(5,L"说明",LVCFMT_CENTER,100);
	ShowData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	if(sid==L""){
		AfxMessageBox(L"没选择要删除的工资信息！");
			return;
	}
	if(MessageBox(L"确定要删除该工资的信息吗？",L"请确认",MB_YESNO)!=IDYES)
		return;
	CString sql;
	sql.Format(L"delete from salary where id='%s'",sid);
	//执行SQL语句
	_variant_t n;
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL(_bstr_t(sql),&n))
	{
	AfxMessageBox(L"成功删除了一条记录");
	ShowData();
	}
}

}*/

