// ClientDlg.cpp : implementation file
// Download by http://www.codesc.net

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "LoadDlg.h"
#include "ChatSocket.h"
#include "Msg.h"
#include "UserInforDlg.h"
//#include "fstream.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_comboWho = _T("");
	m_editMsg = _T("");
	m_userName = _T("");
	m_ipAddress = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_STATIC_USERNUMBER, m_peoNumber);
	DDX_Control(pDX, IDC_STATIC_TIME, m_time);
	DDX_Control(pDX, IDCANCEL, m_exit);
	DDX_Control(pDX, IDC_LIST_USER, m_listUser);
	DDX_Control(pDX, IDC_LIST_OWN, m_listOwn);
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Control(pDX, IDC_COMBO_WHO, m_comboTo);
	DDX_Control(pDX, IDC_BUTTON_USERINFO, m_buttonInfo);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_buttonSend);
	DDX_Control(pDX, IDC_BUTTON_REGISTER, m_buttonRegister);
	DDX_Control(pDX, IDC_BUTTON_LOAD, m_buttonLoad);
	DDX_Control(pDX, IDC_BUTTON_CHANGE, m_buttonChange);
	DDX_CBString(pDX, IDC_COMBO_WHO, m_comboWho);
	DDX_Text(pDX, IDC_EDIT_MSG, m_editMsg);
	DDX_LBString(pDX, IDC_LIST_USER, m_userName);
	DDX_Text(pDX, IDC_EDIT_IPADD, m_ipAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO, OnButtonUserinfo)
	ON_LBN_SELCHANGE(IDC_LIST_USER, OnSelchangeListUser)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//	CMsg a(m_editMsg);
	//	a.WhatType();


	m_comboTo.SetCurSel(0);
	m_userInforDlg=new CUserInforDlg(this);
	this->SetTimer(1,1000,NULL);
	//	userNumber=0;
	// TODO: Add extra initialization here
	GetDlgItem(IDC_LIST_OWN)->EnableWindow(FALSE);
	GetDlgItem(IDC_LIST_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_LIST_USER)->EnableWindow(FALSE);
	GetDlgItem(IDC_LIST_OWN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_USERINFO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_WHO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_IPADD)->EnableWindow(FALSE);
	this->m_IpAddress=this->m_ipAddress;
	if(m_IpAddress.IsEmpty())
	{
		m_IpAddress=_T("localhost");
	}




	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnButtonLoad() 
{
	//while(true)
	//{
	m_loadDlg=new CLoadDlg();
	if(m_loadDlg->DoModal()==IDOK)
	{
		//if(!m_loadDlg->m_user.IsEmpty())
		m_nameCopy=m_userInforDlg->m_userName=m_loadDlg->m_user;
		UpdateData(TRUE);
		if(!m_loadDlg->m_user.IsEmpty())
		{
			if(ConnectSocket(m_IpAddress,8000))
			{

				CString preStr=this->BulidLoadMsg();
				SendMsg(preStr);
				GetDlgItem(IDC_EDIT_IPADD)->EnableWindow(FALSE);
				GetDlgItem(IDOK)->EnableWindow(FALSE);
			}
			else
			{
				AfxMessageBox("连接服务器失败!");
			}
		}
	}
}


BOOL CClientDlg::ConnectSocket(LPCTSTR lpszAddress,UINT nPort)
{
	m_pSocket = new CChatSocket(this);
	if(!m_pSocket->Create())
	{
		delete m_pSocket;
		m_pSocket=NULL;
		AfxMessageBox("套接字错误!");
		return FALSE;
	}
	while(  !m_pSocket->Connect(lpszAddress,nPort) )
	{
		if(AfxMessageBox("无法连接服务器!\n重新连接?",MB_YESNO)==IDNO)
		{
			delete m_pSocket;
			m_pSocket=NULL;
			return FALSE;
		}
	}
	return TRUE;
}

//发送消息
void CClientDlg::OnButtonSend() 
{
	UpdateData(TRUE);

	if(m_editMsg.IsEmpty())
	{
		AfxMessageBox("不能发送空消息");
	}
	else
	{
		CString preStr  =  "我  对  " + this->m_comboWho+" 说 :" + m_editMsg;
		preStr=AddTimeMsg(preStr);
		m_listOwn.AddString(preStr);

		CString pre=BuildNomalMsg(m_editMsg);
		SendMsg(pre);
	}
}



void CClientDlg::SendMsg(CString& strText)
{
	int nLen;
	int nSent;
	//	strText=BuildNomalMsg(strText);
	nLen=strText.GetLength();
	//	    m_editMsg=strText;
	nSent=m_pSocket->Send(LPCTSTR(strText),nLen);
	if(nSent!=SOCKET_ERROR)
	{
		//	m_listMsg.AddString(strText);

		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox("消息发送错误!");
	}
	m_editMsg.Empty();
	UpdateData(FALSE);
}


void CClientDlg::OnReceive(CChatSocket* pSocket)
{
	char *pBuf=new char[1025];
	int nBufSize=1024;
	int nReceived;
	CString name;
	CString strReceived;
	//	this->m_listUser.AddString("keyi"); 
	nReceived=pSocket->Receive(pBuf,nBufSize);

	if(nReceived!=SOCKET_ERROR)
	{
		pBuf[nReceived]=NULL;
		strReceived=pBuf;
		if(strReceived=="SERVERDOWN")
		{
			m_listMsg.AddString("断开连接");
			AfxMessageBox("与服务器断开连接");
			GetDlgItem(IDC_LIST_OWN)->EnableWindow(FALSE);
			GetDlgItem(IDC_LIST_MSG)->EnableWindow(FALSE);
			GetDlgItem(IDC_LIST_USER)->EnableWindow(FALSE);
			GetDlgItem(IDC_LIST_OWN)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_USERINFO)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
			GetDlgItem(IDC_COMBO_WHO)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_IPADD)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_LOAD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_REGISTER)->EnableWindow(TRUE);
			this->m_exit.SetWindowText("退出");
		}
		else if(IsUserLoad(strReceived))
		{
			UpdateUserInfo();
			UpdateData();
		}
		else if(IsToMe(strReceived))
		{
		}
		else if(IsMakeSure(strReceived))
		{
		}
		else
		{
			m_listMsg.AddString(strReceived);
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox("信息接受错误!");
	}
	delete pBuf;
}


void CClientDlg::OnButtonChange() 
{
	AfxMessageBox("功能尚未实现");
}


void CClientDlg::OnButtonUserinfo() 
{
	m_userInforDlg->DoModal();
	if(this->m_nameCopy!=m_userInforDlg->m_userName)
	{
		CString preStr=this->BulidChangeMsg();
		SendMsg(preStr);
		this->m_nameCopy=m_userInforDlg->m_userName;
		UpdateData(TRUE);
	}
}


CString CClientDlg::BuildNomalMsg(CString& preString)
{
	CString a;
	a="NOMALMSG_"+m_userInforDlg->m_userName+"_"+this->m_comboWho+"_"+preString;
	return a;
}

CString CClientDlg::BulidLoadMsg()
{
	CString a;
	a="SYSTEMMSG_LOAD_"+m_userInforDlg->m_userName+"_"+m_loadDlg->m_password;
	return a;
}

CString CClientDlg::BulidChangeMsg()
{
	CString a;
	a="SYSTEMMSG_CHANGE_"+m_nameCopy+"_"+this->m_userInforDlg->m_userName;
	return a;
}

CString CClientDlg::BulidCancelMsg()
{
	CString a="SYSTEMMSG_CLOSE_"+this->m_userInforDlg->m_userName+"_";
	return a;
}

void CClientDlg::OnCancel() 
{
	CString WindowValue;
	m_exit.GetWindowText(WindowValue);

	if(WindowValue=="下线")
	{
		CString a=BulidCancelMsg();
		SendMsg(a);
	}
	CDialog::OnCancel();
}


bool CClientDlg::IsUserLoad(CString& textStr)
{
	int begin = 0;
	int end = textStr.Find("_");
	CString aName;
	CString preHead = textStr.Mid(begin,end);
	if( preHead=="USERLIST"  )
	{
		m_listUser.ResetContent();
		begin=end+1;
		end=textStr.Find("_",begin);
		while(true)
		{
			if(end!=-1)
			{
				aName = textStr.Mid(begin,end-begin);
				begin = end+1;
				m_listUser.AddString(aName);
				end = textStr.Find("_",begin);
			}
			else
			{
				aName = textStr.Mid(begin);
				m_listUser.AddString(aName);
				break;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}


bool CClientDlg::IsToMe(CString& text)
{
	int begin=0;
	int end=text.Find("_");
	CString a=text.Mid(begin,end-begin);
	if(a=="CHAT")
	{
		CString who;
		CString toWho;
		CString item;
		CString msg;

		begin = end+1;
		end =text.Find("_",begin);
		who =text.Mid(begin,end-begin);
		begin =end+1;
		end =text.Find("_",begin);
		toWho =text.Mid(begin,end-begin);

		begin = end+1;
		item = text.Mid(begin);
		msg = who+" 对  "+toWho+"  说 ："+item;
		msg = AddTimeMsg(msg);
		m_listMsg.AddString(msg);
		if(toWho==m_userInforDlg->m_userName)
		{
			msg=who+" 对  你  说 ："+item;
			msg=AddTimeMsg(msg);
			m_listOwn.AddString(msg);
		}
		return true;
	}
	else 
		return false;
}

void CClientDlg::OnSelchangeListUser() 
{
	int a=this->m_listUser.GetCurSel( ); 
	m_listUser.GetText(a,m_userName);

	//	AfxMessageBox(m_userName);
	//	 this->m_comboTo.AddString();*/
	if(m_userName!=m_userInforDlg->m_userName)
	{
		if(m_comboTo.FindString(0,m_userName)==CB_ERR)
		{
			m_comboTo.AddString(m_userName);
			a=m_comboTo.FindString(0,m_userName);
			m_comboTo.SetCurSel(a);
		}
	}
	//	AfxMessageBox(this->m_userName);
}

void CClientDlg::OnTimer(UINT nIDEvent) 
{
	CTime a=CTime::GetCurrentTime();
	CString b=a.Format("%H:%M:%S");
	m_time.SetWindowText(b);	
	CDialog::OnTimer(nIDEvent);
}


CString CClientDlg::AddTimeMsg(CString& text)
{
	CTime a=CTime::GetCurrentTime();
	CString b=a.Format("(%H:%M:%S)");
	b=b+text;
	return b;
}


void CClientDlg::UpdateUserInfo()
{
	m_userNumber=m_listUser.GetCount();
	CString preText;
	preText.Format("当前在线人数:%d",m_userNumber);
	preText=preText+"\n"+m_userInforDlg->m_userName+"  欢迎进入聊天室！";
	m_peoNumber.SetWindowText(preText);
}



bool CClientDlg::IsMakeSure(CString& textMsg)
{
	int begin=0;
	int end=textMsg.Find("_");
	CString head=textMsg.Mid(begin,end-begin);
	if(head=="SUCCESS")
	{
		begin = end+1;
		CString preName=textMsg.Mid(begin);
		this->m_userInforDlg->m_userName=preName;
		this->m_userInforDlg->m_userCopy=preName;
		GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_USERINFO)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_WHO)->EnableWindow(TRUE);
		GetDlgItem(IDC_LIST_USER)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_LOAD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_REGISTER)->EnableWindow(FALSE);
		m_exit.SetWindowText("下线");
		UpdateUserInfo();
		return true;
	}
	else if( head=="FAIL"  )
	{
		AfxMessageBox("登陆失败");  
		return true;
	}
	return false;
}

void CClientDlg::OnOK() 
{
	CString buttonText;
	m_ok.GetWindowText(buttonText);
	if(buttonText=="更改IP")
	{
		GetDlgItem(IDC_EDIT_IPADD)->EnableWindow(TRUE);
		m_ok.SetWindowText("确定");
	}
	else if(buttonText=="确定")
	{
		UpdateData(TRUE);
		if(CheckId(this->m_ipAddress)||m_ipAddress=="localhost")
		{
			m_IpAddress=m_ipAddress;
			GetDlgItem(IDC_EDIT_IPADD)->EnableWindow(FALSE);
			m_ok.SetWindowText("更改IP");
		}
		else
		{
			AfxMessageBox("请输入正确的IP格式");
		}
	}
	//	CDialog::OnOK();
}


bool CClientDlg::CheckId(CString& preIp)
{
	int begin=0;
	int end=0;
	CString seg1;
	CString seg2;
	CString seg3;
	CString seg4;

	end=preIp.Find(".",begin);
	seg1=preIp.Mid(begin,end-begin);
	begin=end+1;

	end=preIp.Find(".",begin);
	seg2=preIp.Mid(begin,end-begin);
	begin=end+1;

	end=preIp.Find(".",begin);
	seg3=preIp.Mid(begin,end-begin);
	begin=end+1;

	seg4=preIp.Mid(begin);

	if((!seg1.IsEmpty())&&
		(!seg2.IsEmpty())&&
		(!seg3.IsEmpty())&&
		(!seg4.IsEmpty()))
	{
		if(IsNumberOfIp(seg1)&&
			IsNumberOfIp(seg2)&&
			IsNumberOfIp(seg3)&&
			IsNumberOfIp(seg4)
			)
		{
			return true;
		}
	}
	return false;
}



bool CClientDlg::IsNumberOfIp(CString ipSeg)
{
	int size=ipSeg.GetLength();
	char *segChar;
	if(size>0&&size<=3)
	{
		segChar=new char[size];
		for(int i=0;i<size;i++)
		{
			segChar[i]=ipSeg[i];
		}
		int number=atoi(segChar);
		if(!(number>=0&&number<=255))
		{
			return false;
		}
	}
	delete segChar;
	return true;
}
