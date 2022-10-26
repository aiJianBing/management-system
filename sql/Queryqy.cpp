// Queryqy.cpp : 实现文件
//

#include "stdafx.h"
#include "Queryqy.h"
#include "MyApp.h"

// CQueryqy 对话框

IMPLEMENT_DYNAMIC(CQueryqy, CDialog)

CQueryqy::CQueryqy(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryqy::IDD, pParent)
{

}

CQueryqy::~CQueryqy()
{
}

void CQueryqy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, mlist11);
}


BEGIN_MESSAGE_MAP(CQueryqy, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CQueryqy::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CQueryqy::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// CQueryqy 消息处理程序

BOOL CQueryqy::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	mlist11.SetExtendedStyle(mlist11.GetExtendedStyle()|
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	mlist11.InsertColumn(0,L"科室",LVCFMT_CENTER,100);
	mlist11.InsertColumn(1,L"职工号",LVCFMT_CENTER,100);
	mlist11.InsertColumn(2,L"主治医生",LVCFMT_CENTER,100);
	mlist11.InsertColumn(3,L"病人",LVCFMT_CENTER,100);
	mlist11.InsertColumn(4,L"取药时间",LVCFMT_CENTER,100);
	mlist11.InsertColumn(5,L"取药记录",LVCFMT_CENTER,100);
	ShowData();


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CQueryqy::ShowData(void)
{
	_RecordsetPtr pRecordset;
	pRecordset=((CMyApp*)AfxGetApp())->mDB.GetRecordset(L"select * from quyao");
mlist11.DeleteAllItems();
	int nItem;
	while(!pRecordset->adoEOF)
	{
		nItem = mlist11.GetItemCount();
		CString str;
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"office"));
		mlist11.InsertItem(nItem,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"sid"));
		mlist11.SetItemText(nItem,1,str);
		str = CAdoDB::toString(pRecordset->GetCollect(L"doc"));
		mlist11.SetItemText(nItem,2,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"patient"));
		mlist11.SetItemText(nItem,3,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"time"));
		mlist11.SetItemText(nItem,4,str);
		str = (LPCTSTR)_bstr_t(pRecordset->GetCollect(L"qy"));
		mlist11.SetItemText(nItem,5,str);
		//str = CAdoDB::toString(pRecordset->GetCollect(L"time"));
		//mlist.SetItemText(nItem,6,str);
		

		pRecordset->MoveNext();
	}
	pRecordset->Close();
}
void CQueryqy::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//*pResult = 0;
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	POSITION pos = mlist11.GetFirstSelectedItemPosition();
	if(pos == NULL)
		TRACE0("NO item were select!\n");
	else
	{
		int nItem = mlist11.GetNextSelectedItem(pos);
		sno11 = mlist11.GetItemText(nItem,0);
		//AfxMessageBox(pno);
	}
	*pResult = 0;
}


void CQueryqy::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(sno11==L""){
		AfxMessageBox(L"没选择要删除的取药信息！");
			return;
	}
	if(MessageBox(L"确定要删除该取药的信息吗？",L"请确认",MB_YESNO)!=IDYES)
		return;
	CString sql;
	sql.Format(L"delete from instr where office='%s'",sno11);
	//执行SQL语句
	_variant_t n;
	if(((CMyApp*)AfxGetApp())->mDB.ExecuteSQL(_bstr_t(sql),&n))
	{
	AfxMessageBox(L"成功删除了一条记录");
	ShowData();
	}

}

