#pragma once


// CDeleqy �Ի���

class CDeleqy : public CDialog
{
	DECLARE_DYNAMIC(CDeleqy)

public:
	CDeleqy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleqy();

// �Ի�������
	enum { IDD = IDD_QYdele };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString mSoffice;
	CString mSsid;
	CString mSdoc;
	CString mSpatient;
	CString mSqy;
	_RecordsetPtr pRecordset;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	CString mStime;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCancel();
};
