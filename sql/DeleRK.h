#pragma once


// CDeleRK �Ի���

class CDeleRK : public CDialog
{
	DECLARE_DYNAMIC(CDeleRK)

public:
	CDeleRK(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleRK();

// �Ի�������
	enum { IDD = IDD_RKde };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString mSsid;
	CString mSname;
	CString mStime;
	CString mSnum;
	CString mSover;
	_RecordsetPtr pRecordset;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCancel();
};
