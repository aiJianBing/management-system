#pragma once


// CAddStu �Ի���

class CAddStu : public CDialog
{
	DECLARE_DYNAMIC(CAddStu)

public:
	CAddStu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddStu();

// �Ի�������
	enum { IDD = IDD_ADDSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
