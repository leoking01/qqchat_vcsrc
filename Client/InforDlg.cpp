// InforDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "InforDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInforDlg dialog


CInforDlg::CInforDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInforDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInforDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInforDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInforDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInforDlg, CDialog)
	//{{AFX_MSG_MAP(CInforDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInforDlg message handlers
