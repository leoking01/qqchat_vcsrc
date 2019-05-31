#if !defined(AFX_LOADDLG_H__CE6270ED_4C25_453F_9BAF_5ACDD85DA1F7__INCLUDED_)
#define AFX_LOADDLG_H__CE6270ED_4C25_453F_9BAF_5ACDD85DA1F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoadDlg.h : header file
// Download by http://www.codesc.net

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg dialog

class CLoadDlg : public CDialog
{
// Construction
public:
	CLoadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoadDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_controlPort;
	CString	m_editName;
	CString	m_editPassword;
	UINT	m_portNumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADDLG_H__CE6270ED_4C25_453F_9BAF_5ACDD85DA1F7__INCLUDED_)
