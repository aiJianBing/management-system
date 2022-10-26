#pragma once
#include "afxcmn.h"


// CQueryStu 对话框

class CQueryStu : public CDialog
{
	DECLARE_DYNAMIC(CQueryStu)

public:
	CQueryStu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQueryStu();

// 对话框数据
	enum { IDD = IDD_QUERYSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mlist;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedCancel();
};
