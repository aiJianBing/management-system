#pragma once


// DeleCK 对话框

class DeleCK : public CDialog
{
	DECLARE_DYNAMIC(DeleCK)

public:
	DeleCK(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DeleCK();

// 对话框数据
	enum { IDD = IDD_CKdele };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
