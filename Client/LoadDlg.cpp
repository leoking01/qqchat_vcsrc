// LoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "LoadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg dialog


CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoadDlg)
	m_password = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
}


void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoadDlg)
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CLoadDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg message handlers

void CLoadDlg::OnOK() 
{
	
//	CClientDlg::SendMsg(BuildLoadMsg());
	if(!m_user.IsEmpty())
	{ 
		if(AfxMessageBox("用户名不能为空,从新输入？",MB_YESNO)==IDNO)
		{
			CDialog::OnOK();
			return;
		}
		else
		{
			return;

		}
	}
	CDialog::OnOK();
	   
}

void CLoadDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
