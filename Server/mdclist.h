#if !defined(AFX_MDCLIST_H__56C18488_55ED_4A3D_88E9_A2AEA2310CF8__INCLUDED_)
#define AFX_MDCLIST_H__56C18488_55ED_4A3D_88E9_A2AEA2310CF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class COleFont;
class CPicture;

/////////////////////////////////////////////////////////////////////////////
// CMdcList wrapper class

// Download by http://www.codesc.net
class CMdcList : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMdcList)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x8bd21d20, 0xec42, 0x11ce, { 0x9e, 0xd, 0x0, 0xaa, 0x0, 0x60, 0x2, 0xf3 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	void SetBackColor(long nNewValue);
	long GetBackColor();
	void SetBorderColor(long nNewValue);
	long GetBorderColor();
	void SetBorderStyle(long nNewValue);
	long GetBorderStyle();
	void SetBoundColumn(VARIANT* newValue);
	VARIANT GetBoundColumn();
	void SetColumnCount(long nNewValue);
	long GetColumnCount();
	void SetColumnHeads(BOOL bNewValue);
	BOOL GetColumnHeads();
	void SetColumnWidths(LPCTSTR lpszNewValue);
	CString GetColumnWidths();
	void SetEnabled(BOOL bNewValue);
	BOOL GetEnabled();
	void SetRefFont(LPDISPATCH newValue);
	COleFont GetFont();
	void SetForeColor(long nNewValue);
	long GetForeColor();
	void SetIntegralHeight(BOOL bNewValue);
	BOOL GetIntegralHeight();
	long GetListCount();
	void SetListIndex(VARIANT* newValue);
	VARIANT GetListIndex();
	void SetListStyle(long nNewValue);
	long GetListStyle();
	void SetLocked(BOOL bNewValue);
	BOOL GetLocked();
	void SetMatchEntry(long nNewValue);
	long GetMatchEntry();
	void SetMouseIcon(LPDISPATCH newValue);
	void SetRefMouseIcon(LPDISPATCH newValue);
	CPicture GetMouseIcon();
	void SetMousePointer(long nNewValue);
	long GetMousePointer();
	void SetMultiSelect(long nNewValue);
	long GetMultiSelect();
	void SetSpecialEffect(long nNewValue);
	long GetSpecialEffect();
	void SetText(LPCTSTR lpszNewValue);
	CString GetText();
	void SetTextColumn(VARIANT* newValue);
	VARIANT GetTextColumn();
	void SetTopIndex(VARIANT* newValue);
	VARIANT GetTopIndex();
	void SetValue(VARIANT* newValue);
	VARIANT GetValue();
	VARIANT GetColumn(VARIANT* pvargColumn, VARIANT* pvargIndex);
	void SetColumn(VARIANT* pvargColumn, VARIANT* pvargIndex, VARIANT* newValue);
	VARIANT GetList(VARIANT* pvargIndex, VARIANT* pvargColumn);
	void SetList(VARIANT* pvargIndex, VARIANT* pvargColumn, VARIANT* newValue);
	BOOL GetSelected(VARIANT* pvargIndex);
	void SetSelected(VARIANT* pvargIndex, BOOL bNewValue);
	void AddItem(VARIANT* pvargItem, VARIANT* pvargIndex);
	void Clear();
	void RemoveItem(VARIANT* pvargIndex);
	void SetIMEMode(long nNewValue);
	long GetIMEMode();
	void SetTextAlign(long nNewValue);
	long GetTextAlign();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDCLIST_H__56C18488_55ED_4A3D_88E9_A2AEA2310CF8__INCLUDED_)