#pragma once
#include "afxwin.h"


// CMainWnd ���

class CMainWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMainWnd)
public:
	CMainWnd();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMainWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CMenu menu;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnExit();
	afx_msg void OnAddstu();
	afx_msg void OnAddstu1();
	afx_msg void OnAddstu2();

	afx_msg void OnModistu();
	afx_msg void OnQuerystu();
	afx_msg void OnQuerystu1();
	afx_msg void OnQuerystu2();
	afx_msg void OnModistu1();
	afx_msg void OnModistu2();
	afx_msg void Onaddqy();
	afx_msg void OnDeleqy();
	afx_msg void OnQueryqy();
};


