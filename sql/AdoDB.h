#pragma once
#include "StdAfx.h"
#include <ATLComTime.h>	//COleDateTime����Ҫ
#include <afxdisp.h>	//COleCurrency����Ҫ

class CAdoDB
{
public:
	//������������ָ��
	_ConnectionPtr pConn;
	_RecordsetPtr pRs;
public:
	CAdoDB(void);	//���캯��
	~CAdoDB(void);	//��������
	BOOL OpenDB(void);	//�����ݿ�����
	BOOL ExecuteSQL(_bstr_t sql, _variant_t *t);	//ִ��һ��SQL����
	_RecordsetPtr& GetRecordset(_bstr_t sql);//ִ��һ��SQL��ѯ
	static CString toString(_variant_t vt);
	_RecordsetPtr& GetRecordset_Edit(_bstr_t sql);//ִ��һ��SQL��ѯ
};
