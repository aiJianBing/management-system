#pragma once


// CAddQY �Ի���

class CAddQY : public CDialog
{
	DECLARE_DYNAMIC(CAddQY)

public:
	CAddQY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddQY();

// �Ի�������
	enum { IDD = IDD_ADDQY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString mSoffice;
	CString mSsid;
	CString mSdoc;
	CString mSpatient;
	CString mStime;
	CString mSqy;
	afx_msg void OnBnClickedOk();
};
