#pragma once


// CDeleqy 对话框

class CDeleqy : public CDialog
{
	DECLARE_DYNAMIC(CDeleqy)

public:
	CDeleqy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleqy();

// 对话框数据
	enum { IDD = IDD_QYdele };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
