#pragma once
#include "afxcmn.h"


// CQueryStu �Ի���

class CQueryStu : public CDialog
{
	DECLARE_DYNAMIC(CQueryStu)

public:
	CQueryStu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQueryStu();

// �Ի�������
	enum { IDD = IDD_QUERYSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mlist;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedCancel();
};
