#if !defined(AFX_NEWUSERDLG_H__F44D5A54_5C65_4DB7_9875_246579456905__INCLUDED_)
#define AFX_NEWUSERDLG_H__F44D5A54_5C65_4DB7_9875_246579456905__INCLUDED_
// Download by http://www.codesc.net
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg dialog

class CNewUserDlg : public CDialog
{
// Construction
public:
	CNewUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewUserDlg)
	enum { IDD = IDD_DIALOG2 };
	CButton	m_userCheck;
	CString	m_name;
	CString	m_password;
	CString	m_passwordAgain;
	CString	m_user;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewUserDlg)
	afx_msg void OnButtonCheck();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWUSERDLG_H__F44D5A54_5C65_4DB7_9875_246579456905__INCLUDED_)
