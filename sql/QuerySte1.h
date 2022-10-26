#pragma once
#include "afxcmn.h"


// CQuerySte1 对话框

class CQuerySte1 : public CDialog
{
	DECLARE_DYNAMIC(CQuerySte1)

public:
	CQuerySte1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQuerySte1();

// 对话框数据
	enum { IDD = IDD_RK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mlist1;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedDl();
	CString sno1;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedD11();
	afx_msg void OnBnClickedCancel();
};
