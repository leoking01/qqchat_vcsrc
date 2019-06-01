// NewUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "NewUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg dialog


CNewUserDlg::CNewUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewUserDlg)
	m_name = _T("");
	m_password = _T("");
	m_passwordAgain = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
//	this->GetDlgItem(IDOK)->EnableWindow(FALSE);
}


void CNewUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewUserDlg)
	DDX_Control(pDX, IDC_BUTTON_CHECK, m_userCheck);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Text(pDX, IDC_EDIT_PASSWORD1, m_passwordAgain);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewUserDlg, CDialog)
	//{{AFX_MSG_MAP(CNewUserDlg)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, OnButtonCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg message handlers

void CNewUserDlg::OnButtonCheck() 
{
	this->UpdateData(TRUE);
	if( ( !this->m_name.IsEmpty() )
		&&  (!this->m_password.IsEmpty( ) )
		&&  (!this->m_passwordAgain.IsEmpty() )
		&&  (!this->m_user.IsEmpty( ) )
		&&  (this->m_password==this->m_passwordAgain )
		)
	{
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
}

void CNewUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CNewUserDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
