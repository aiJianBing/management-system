#pragma once


// CAddStu1 对话框

class CAddStu1 : public CDialog
{
	DECLARE_DYNAMIC(CAddStu1)

public:
	CAddStu1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddStu1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	CString mSno1;
	CString mName1;
	CString mTime1;
	CString mNum1;
	CString mNum2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
