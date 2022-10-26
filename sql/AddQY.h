#pragma once


// CAddQY 对话框

class CAddQY : public CDialog
{
	DECLARE_DYNAMIC(CAddQY)

public:
	CAddQY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddQY();

// 对话框数据
	enum { IDD = IDD_ADDQY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
