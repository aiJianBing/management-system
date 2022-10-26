#pragma once


// CDelStu 对话框

class CDelStu : public CDialog
{
	DECLARE_DYNAMIC(CDelStu)

public:
	CDelStu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDelStu();

// 对话框数据
	enum { IDD = IDD_xiu };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString mSno;
	CString mSname;
	CString mSTYBE;
	CString mSPRICE;
	CString mSVALIDITY;
	CString mSEXOLAIN;
	_RecordsetPtr pRecordset;
	virtual BOOL OnInitDialog();
	void ShowData(void);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedxiu();
	afx_msg void OnBnClickedCancel();
};
