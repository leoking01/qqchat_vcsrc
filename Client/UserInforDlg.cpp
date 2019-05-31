// UserInforDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "UserInforDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserInforDlg dialog


CUserInforDlg::CUserInforDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserInforDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserInforDlg)
	m_userName = _T("");
	m_userCopy = _T("");
	//}}AFX_DATA_INIT
}


void CUserInforDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserInforDlg)
	DDX_Control(pDX, IDC_EDIT_NAME, m_conUserCopy);
	DDX_Text(pDX, IDC_EDIT_NAME, m_userName);
	DDX_Text(pDX, IDC_USERCOPY, m_userCopy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserInforDlg, CDialog)
	//{{AFX_MSG_MAP(CUserInforDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserInforDlg message handlers

void CUserInforDlg::OnOK() 
{
	    if(AfxMessageBox("是否确定更改消息？",MB_YESNO)==IDYES)
		{ 
	    	UpdateData(TRUE);
		}
		else
		{
	    	UpdateData(FALSE);
		}
    CDialog::OnOK();

}
