#pragma once
#include "afxcmn.h"


// CQueryqy �Ի���

class CQueryqy : public CDialog
{
	DECLARE_DYNAMIC(CQueryqy)

public:
	CQueryqy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQueryqy();

// �Ի�������
	enum { IDD = IDD_Qqy };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mlist11;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedButton1();
	CString sno11;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};
