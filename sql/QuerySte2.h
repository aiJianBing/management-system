#pragma once
#include "afxcmn.h"


// CQuerySte2 �Ի���

class CQuerySte2 : public CDialog
{
	DECLARE_DYNAMIC(CQuerySte2)

public:
	CQuerySte2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQuerySte2();

// �Ի�������
	enum { IDD = IDD_CK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mlist2;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	
	CString sno2;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedd1();
	afx_msg void OnBnClickedCancel();
};
