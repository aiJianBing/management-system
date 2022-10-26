#include "AdoDB.h"
BOOL CAdoDB::ExecuteSQL(_bstr_t sql, _variant_t *t)
{
	try{
		pConn->Execute(sql, t, 0);
		return true;
	}catch(_com_error e){
		AfxMessageBox(e.Description());
		return false;
	}
}

_RecordsetPtr& CAdoDB::GetRecordset(_bstr_t sql)
{
	try{
		pRs = pConn->Execute(sql, 0, 0);
	}catch(_com_error e){
		AfxMessageBox(e.Description());
	}
	return pRs;
}
_RecordsetPtr& CAdoDB::GetRecordset_Edit(_bstr_t sql)
{
	try{
		pRs->Open(sql,pConn.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}catch(_com_error e){
		AfxMessageBox(e.Description());
	}
	return pRs;
}
BOOL CAdoDB::OpenDB()
{
	//④ 和MySQL数据库建立连接
	try{
		pConn->Open(L"Driver={MySQL ODBC 5.3 Unicode Driver};Server=localhost;Database=medication",
		L"root",L"123456",adModeUnknown);
		return true;
	}catch(_com_error e){
		AfxMessageBox(e.Description());
		return false;
	}
}

CAdoDB::CAdoDB(void)
{
	//① 启用COM组件
	::CoInitialize(NULL);
	//创建组件实例
	pConn.CreateInstance(L"ADODB.Connection");
	pRs.CreateInstance(L"ADODB.Recordset");
}

CAdoDB::~CAdoDB(void)
{
	try{
		if(pRs!=NULL && pRs->State==adStateOpen)
		{	//adStateOpen-指出对象已打开
			pRs->Close();		//关闭记录集
			pRs.Release();		//释放记录集指针实例
		}
		if(pConn!=NULL && pConn->State==adStateOpen)
		{	//adStateOpen-指出对象已打开
			pConn->Close();		//关闭数据库连接
			pConn.Release();	//释放连接指针实例
		}
		::CoUninitialize();		//释放com组件
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

CString CAdoDB::toString(_variant_t var)
{
	CString str;
	switch(var.vt)
	{
		case VT_BSTR:	//var是字符串数据
		{
			str=var.bstrVal;
			break;
		}
		case VT_I2:		//var是短整形(2字节) 
		{
			str.Format(L"%d",(int)var.iVal);
			break;
		}
		case VT_I4:		//var是长整形(4字节)
		{
			str.Format(L"%d", var.lVal);
			break;
		}
		case VT_R4:		//var是单精度浮点型(4字节)
		{
			str.Format(L"%10.6f", (float)var.fltVal);
			break;
		}
		case VT_R8:		//va双精度浮点型(8字节)
		{
			str.Format(L"%10.6lf", var.dblVal);
			break;
		}
		case VT_BOOL:	//var是布尔型-VARIANT_BOOL
		{
			str = (var.boolVal==0) ?L"FALSE": L"TRUE";
			break;
		}
		case VT_CY:		//var货币类型
		{
			str=COleCurrency(var).Format();
			break;
		}
		case VT_DATE:	//var是日期时间类型
		{
			COleDateTime d = COleDateTime(var);
			str.Format(L"%4d-%02d-%02d",d.GetYear(),d.GetMonth(),d.GetDay()); 
			break;
		}
		default:		//var是其它类型
		{
			str.Format(L"Unk type %d\n",var.vt);
			TRACE(L"Unknown type %d\n",var.vt);
			break;
		}
	}
	return str;
}