#pragma once
#include "StdAfx.h"
#include <ATLComTime.h>	//COleDateTime类需要
#include <afxdisp.h>	//COleCurrency类需要

class CAdoDB
{
public:
	//定义两个智能指针
	_ConnectionPtr pConn;
	_RecordsetPtr pRs;
public:
	CAdoDB(void);	//构造函数
	~CAdoDB(void);	//析构函数
	BOOL OpenDB(void);	//打开数据库连接
	BOOL ExecuteSQL(_bstr_t sql, _variant_t *t);	//执行一个SQL命令
	_RecordsetPtr& GetRecordset(_bstr_t sql);//执行一个SQL查询
	static CString toString(_variant_t vt);
	_RecordsetPtr& GetRecordset_Edit(_bstr_t sql);//执行一个SQL查询
};
