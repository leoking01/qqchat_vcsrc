// LoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
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
	m_editName = _T("");
	m_editPassword = _T("");
	m_portNumber = 0;
	//}}AFX_DATA_INIT
}


void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoadDlg)
	DDX_Control(pDX, IDC_EDIT_PORTNUMBER, m_controlPort);
	DDX_Text(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_editPassword);
	DDX_Text(pDX, IDC_EDIT_PORTNUMBER, m_portNumber);
	DDV_MinMaxUInt(pDX, m_portNumber, 8000, 9000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CLoadDlg)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg message handlers

void CLoadDlg::OnOK() 
{
	UpdateData(TRUE);
	
	CDialog::OnOK();
}

void CLoadDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CLoadDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
