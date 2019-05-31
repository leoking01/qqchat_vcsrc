#if !defined(AFX_INFORDLG_H__DD647E89_2164_42AF_AF35_3AA8A5E64DA0__INCLUDED_)
#define AFX_INFORDLG_H__DD647E89_2164_42AF_AF35_3AA8A5E64DA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InforDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInforDlg dialog

class CInforDlg : public CDialog
{
// Construction
public:
	CInforDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInforDlg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Download by http://www.codesc.net
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInforDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInforDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORDLG_H__DD647E89_2164_42AF_AF35_3AA8A5E64DA0__INCLUDED_)
