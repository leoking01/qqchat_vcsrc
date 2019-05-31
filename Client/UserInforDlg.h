#if !defined(AFX_USERINFORDLG_H__82E43F39_9209_4A39_ABB6_4AC58603FD3C__INCLUDED_)
#define AFX_USERINFORDLG_H__82E43F39_9209_4A39_ABB6_4AC58603FD3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserInforDlg.h : header file
// Download by http://www.codesc.net

/////////////////////////////////////////////////////////////////////////////
// CUserInforDlg dialog

class CUserInforDlg : public CDialog
{
// Construction
public:
	CUserInforDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserInforDlg)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_conUserCopy;
	CString	m_userName;
	CString	m_userCopy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserInforDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserInforDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERINFORDLG_H__82E43F39_9209_4A39_ABB6_4AC58603FD3C__INCLUDED_)
