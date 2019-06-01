// Server.h : main header file for the SERVER application
//

#if !defined(AFX_SERVER_H__15DE79D8_5E40_4A09_954A_B7B7BD9A20A8__INCLUDED_)
#define AFX_SERVER_H__15DE79D8_5E40_4A09_954A_B7B7BD9A20A8__INCLUDED_
// Download by http://www.codesc.net
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerApp:
// See Server.cpp for the implementation of this class
//

class CServerApp : public CWinApp
{
public:
	CServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	//afx_msg void On32775_aboutApp();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER_H__15DE79D8_5E40_4A09_954A_B7B7BD9A20A8__INCLUDED_)
