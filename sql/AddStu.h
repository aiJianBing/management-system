#pragma once


// CAddStu 对话框

class CAddStu : public CDialog
{
	DECLARE_DYNAMIC(CAddStu)

public:
	CAddStu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddStu();

// 对话框数据
	enum { IDD = IDD_ADDSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString mSno;
	CString mSname;
	CString mSTYBE;
	float mSPRICE;
	CString mSVALIDITY;
	CString mSEXPLAIN;
	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
