#pragma once


// DeleCK �Ի���

class DeleCK : public CDialog
{
	DECLARE_DYNAMIC(DeleCK)

public:
	DeleCK(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DeleCK();

// �Ի�������
	enum { IDD = IDD_CKdele };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString mSsid1;
	CString mSname1;
	CString mStime;
	CString mSnum1;
	CString mSover1;
	_RecordsetPtr pRecordset;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCancel();
};
