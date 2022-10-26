#pragma once


// CAddStu2 对话框

class CAddStu2 : public CDialog
{
	DECLARE_DYNAMIC(CAddStu2)

public:
	CAddStu2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddStu2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString mSno2;
	CString mName2;
	CString mTime2;
	CString mNum3;
	CString mNum4;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
