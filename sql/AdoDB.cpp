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
	//�� ��MySQL���ݿ⽨������
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
	//�� ����COM���
	::CoInitialize(NULL);
	//�������ʵ��
	pConn.CreateInstance(L"ADODB.Connection");
	pRs.CreateInstance(L"ADODB.Recordset");
}

CAdoDB::~CAdoDB(void)
{
	try{
		if(pRs!=NULL && pRs->State==adStateOpen)
		{	//adStateOpen-ָ�������Ѵ�
			pRs->Close();		//�رռ�¼��
			pRs.Release();		//�ͷż�¼��ָ��ʵ��
		}
		if(pConn!=NULL && pConn->State==adStateOpen)
		{	//adStateOpen-ָ�������Ѵ�
			pConn->Close();		//�ر����ݿ�����
			pConn.Release();	//�ͷ�����ָ��ʵ��
		}
		::CoUninitialize();		//�ͷ�com���
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
		case VT_BSTR:	//var���ַ�������
		{
			str=var.bstrVal;
			break;
		}
		case VT_I2:		//var�Ƕ�����(2�ֽ�) 
		{
			str.Format(L"%d",(int)var.iVal);
			break;
		}
		case VT_I4:		//var�ǳ�����(4�ֽ�)
		{
			str.Format(L"%d", var.lVal);
			break;
		}
		case VT_R4:		//var�ǵ����ȸ�����(4�ֽ�)
		{
			str.Format(L"%10.6f", (float)var.fltVal);
			break;
		}
		case VT_R8:		//va˫���ȸ�����(8�ֽ�)
		{
			str.Format(L"%10.6lf", var.dblVal);
			break;
		}
		case VT_BOOL:	//var�ǲ�����-VARIANT_BOOL
		{
			str = (var.boolVal==0) ?L"FALSE": L"TRUE";
			break;
		}
		case VT_CY:		//var��������
		{
			str=COleCurrency(var).Format();
			break;
		}
		case VT_DATE:	//var������ʱ������
		{
			COleDateTime d = COleDateTime(var);
			str.Format(L"%4d-%02d-%02d",d.GetYear(),d.GetMonth(),d.GetDay()); 
			break;
		}
		default:		//var����������
		{
			str.Format(L"Unk type %d\n",var.vt);
			TRACE(L"Unknown type %d\n",var.vt);
			break;
		}
	}
	return str;
}