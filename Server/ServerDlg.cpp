// ServerDlg.cpp : implementation file
// Download by http://www.codesc.net

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "LoadDlg.h"
#include "Msg.h"
#include "NewUserDlg.h"

//#include <fstream.h>
/*
#include "ClientSocket.h"
#include "ListeningSocket.h"*/

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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_editMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
//	DDX_Control(pDX, IDC_BUTTON_SERVICE, m_service);
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Control(pDX, IDC_STATIC_TIME, m_t);
	DDX_Control(pDX, IDC_STATIC_USER, m_peoNumber);
	DDX_Control(pDX, IDC_LIST_USER, m_listUser);

	DDX_Text(pDX, IDC_EDIT_MSG, m_editMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_LEND, OnButtonLend)
	ON_BN_CLICKED(IDC_BUTTON_SERVICE1, OnButtonService1)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LIST_USER, OnSelchangeListUser)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CServerDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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
	if(!LoadUserInfor())
	{ 
		AfxMessageBox("用户信息载入失败，请检测文件user.dat是否存在？");
	    exit(1);
	}
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	m_button_load.LoadBitmaps(IDB_BITMAP_UP, IDB_BITMAP_DOWN);//IDB_BITMAP1:平时；IDB_BITMAP2：按下
    m_button_load.SubclassDlgItem(IDC_BUTTON_LEND, this);
    m_button_load.SizeToContent();


	m_button_service.LoadBitmaps(IDB_BITMAP_SERUP, IDB_BITMAP_SERDOWN);//IDB_BITMAP1:平时；IDB_BITMAP2：按下
    m_button_service.SubclassDlgItem(IDC_BUTTON_SERVICE1, this);
    m_button_service.SizeToContent();

/*	m_button_new.LoadBitmaps(IDB_BITMAP_NEWUP, IDB_BITMAP_NEWDOWN);//IDB_BITMAP1:平时；IDB_BITMAP2：按下
    m_button_new.SubclassDlgItem(IDC_BUTTON_NEW, this);
    m_button_new.SizeToContent();*/

	m_button_send.LoadBitmaps(IDB_BITMAP_SENDUP,IDB_BITMAP_SENDDOWN);
	m_button_send.SubclassDlgItem(IDC_BUTTON_SEND,this);
	m_button_send.SizeToContent();


	m_button_stop.LoadBitmaps(IDB_BITMAP_STOPUP,IDB_BITMAP_STOPDOWN);
	m_button_stop.SubclassDlgItem(IDCANCEL,this);
	m_button_stop.SizeToContent();
  //m_listMsg.Set

//	m_peoNumber.SetIcon(IDI_ICON1);

	
/*	m_button_cancel.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP4);//IDB_BITMAP1:平时；IDB_BITMAP2：按下
    m_button_cancel.SubclassDlgItem(IDC_BUTTON2, this);
    m_button_cancel.SizeToContent();*/


 
	CBitmap bmp; 
    bmp.LoadBitmap(IDB_BITMAP_BG); 
    m_brBk.CreatePatternBrush(&bmp); 
    bmp.DeleteObject(); 


//	dlg = new CLoadDlg();
	 m_pSocket=new CListeningSocket(this);
	 m_pNewUserDlg=new CNewUserDlg(this);
	 userNumber=0;
//	 CString pre="NULLMSG";
	 m_pMsg=new CMsg();
	 this->SetTimer(1,1000,NULL);
//	 m_connectionList =new CPtrList();
	 GetDlgItem(IDC_BUTTON_LEND)->EnableWindow(TRUE);
     //GetDlgItem(IDCANCEL)->EnableWindow(FALSE);
	      GetDlgItem(IDCANCEL)->EnableWindow(TRUE);

	 GetDlgItem(IDC_BUTTON_SERVICE1)->EnableWindow(FALSE);
	 GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	 //GetDlgItem(IDC_BUTTON_SERVICE1)->EnableWindow(TRUE);
	 //GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE );

     GetDlgItem(IDC_LIST_MSG)->EnableWindow(FALSE);
     GetDlgItem(IDC_LIST_USER)->EnableWindow(FALSE);
     GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
//	 m_pNewUserDlg->GetDlgItem(IDOK)->EnableWindow(FALSE);
	 UpdateInfo();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CServerDlg::OnCancel() 
{
	
	CString systemMsg;
	systemMsg="SERVERDOWN";
	SendMsgAll(systemMsg);
	DeleteAllConnect();
	CDialog::OnCancel();
}



void CServerDlg::OnButtonService1() 
{
	AfxMessageBox( _T("点击了开始服务的按钮。侦听开始!" ) ) ;
	//AfxMessageBox("侦听开始!");
	//return ;

	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
    GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
    GetDlgItem(IDC_LIST_MSG)->EnableWindow(TRUE);
    GetDlgItem(IDC_LIST_USER)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SERVICE1)->EnableWindow(FALSE);

   	 if(m_pSocket->Create(m_dlg->m_portNumber))
	 {
	      if(!m_pSocket->Listen())
		  {
		       AfxMessageBox("侦听失败!");
		  }
	 }
}

/*void CServerDlg::OnClose() 
{
	CDialog::OnCancel();
	
	CDialog::OnClose();
}*/



void CServerDlg::OnAccept()
{

	CClientSocket* pSocket=new CClientSocket(this);
	if(m_pSocket->Accept(*pSocket))
	{
		pSocket->Initialize();
		m_connectionList.AddTail(pSocket);
		userNumber++;
		
		UpdateInfo();

	}
	else
	{
		delete pSocket;
	}
}


	void CServerDlg::UpdateInfo()
	{
		CString preText;
		preText.Format("当前在线人数:%d",userNumber);
		m_peoNumber.SetWindowText(preText);

	}


void CServerDlg::OnReceive(CClientSocket* pSocket)
{

	char *pBuf=new char[1025];
	int nBufSize=1024;
	int nReceived;
	CString strReceived;
	nReceived=pSocket->Receive(pBuf,nBufSize);
	if(nReceived!=SOCKET_ERROR)
	{
		pBuf[nReceived]=NULL;
		strReceived=pBuf;
		m_pMsg->m_strText=strReceived;
	    CString preType=m_pMsg->WhatType();
		
        
		if(preType=="NOMALMSG")
		{
            m_pMsg->BuildNomal();
			CString a="CHAT_"+m_pMsg->m_nomalMsg.who+"_"+m_pMsg->m_nomalMsg.toWho+"_"+m_pMsg->m_nomalMsg.msgItem;
			//a=AddTimeMsg(a);
        	SendMsgAll(a);
			a=m_pMsg->m_nomalMsg.who+"  对  "+m_pMsg->m_nomalMsg.toWho+"  说 :"+m_pMsg->m_nomalMsg.msgItem;
			a=AddTimeMsg(a);
			m_listMsg.AddString(a);
		}

		else if(preType=="SYSTEMMSG")
		{
            m_pMsg->BuileSystem();

			
			if(m_pMsg->m_systemMsg.type=="LOAD")
			{
				CString sf=this->GetUserItem(m_pMsg->m_systemMsg.name,m_pMsg->m_systemMsg.msgItem);
					if(!sf.IsEmpty())
					{
                        SendMsg(sf,pSocket);
						Sleep(1000);
						CString callNameStr=FindCallName(m_pMsg->m_systemMsg.name);
			            CString a="系统消息(L):"+callNameStr+"  进入了聊天室!";
				        m_listUser.AddString(callNameStr);
                        a=AddTimeMsg(a);
			        	m_listMsg.AddString(a);
				        SendMsgAll(a);
                        Sleep(1000);
				        CString userList=BuildUserListMsg();
				        SendMsgAll(userList);
					}
					else
					{
						CString error="FAIL_";
						SendMsg(error,pSocket);
						DeleteSocket(pSocket);

					}

				
			}
			else if(m_pMsg->m_systemMsg.type=="CLOSE")
			{
				CString a="系统消息(CL)"+m_pMsg->m_systemMsg.name+"  退出了聊天室!";
				int pos=m_listUser.FindString(0,m_pMsg->m_systemMsg.name);
				m_listUser.DeleteString(pos);
                
			//	this->SendMsgAll(a);
		//		pSocket->Close();
				DeleteSocket(pSocket);
			//	userNumber=m_listUser.GetCount();
                UpdateInfo();
				a=AddTimeMsg(a);
				m_listMsg.AddString(a);
				SendMsgAll(a);	
			

			}
			else if(m_pMsg->m_systemMsg.type=="CHANGE")
			{
 
				CString a="系统消息(CH)"+m_pMsg->m_systemMsg.name+"  改名为  "+m_pMsg->m_systemMsg.msgItem;
				a=AddTimeMsg(a);
				m_listMsg.AddString(a);
				SendMsgAll(a);

				int pos=m_listUser.FindString(0,m_pMsg->m_systemMsg.name);
				m_listUser.DeleteString(pos);
				m_listUser.AddString(m_pMsg->m_systemMsg.msgItem);

				Sleep(1000);

				CString userList=BuildUserListMsg();
				SendMsgAll(userList);

			}
			else
			{
				AfxMessageBox("消息错误!");
			}


		}


	}
	else
	{
		AfxMessageBox("信息接受错误!");
	}
		delete pBuf;

}



	void CServerDlg::SendMsg(CString& strText,CClientSocket* pSocket)
	{
		int nLen;
	    int nSent;
		nLen=strText.GetLength();
		nSent=pSocket->Send(LPCTSTR(strText),nLen);
		if(nSent==SOCKET_ERROR)
		{
			AfxMessageBox("消息发送错误!");
		}
	//	m_msgEdit.Empty();
		UpdateData(FALSE);

	}


	void CServerDlg::SendMsgAll(CString& strText)
	{
		POSITION pos;
		for(int i=0;i<userNumber;i++)
		{
			
			pos=m_connectionList.FindIndex(i);
			CClientSocket* pSocket=(CClientSocket*)m_connectionList.GetPrev(pos);
			SendMsg(strText,pSocket);
			
		}
		m_editMsg.Empty();

	}


	    void CServerDlg::DisplayMsg(LPCTSTR lpszMessage)
	{
		m_listMsg.AddString(lpszMessage);
	}



void CServerDlg::OnTimer(UINT nIDEvent) 
{

   	CTime a=CTime::GetCurrentTime();
    CString b=a.Format("%H:%M:%S");
	m_t.SetWindowText(b);
	CDialog::OnTimer(nIDEvent);
}


CString CServerDlg::AddTimeMsg(CString& text)
{
	CTime a=CTime::GetCurrentTime();
    CString b=a.Format("(%H:%M:%S)");
    b=b+text;
	return b;
}



CString CServerDlg::BuildSystemMsg(/*CClientSocket* pSocket,CMsg* preMsg*/)
{

	CString a("a");
	return a;
	
}



bool CServerDlg::LoadUserInfor()
{
	CString pFileName("user.dat");
	CString inforStream;
	CString name;


	if( m_userInforFile.Open( pFileName, CFile::modeRead | CFile::typeText ) )
	{
		m_userInforFile.SeekToBegin();

		
		while(m_userInforFile.ReadString(inforStream))
		{

			if(BuildUser(inforStream))
			{
				User *pUser=new User();
				pUser->m_callName=m_pUser.m_callName;
				pUser->m_password=m_pUser.m_password;
				pUser->m_loadName=m_pUser.m_loadName;
				this->m_userInforList.AddTail(pUser);
			}
			else
			{
				AfxMessageBox("错误信息:"+inforStream);
			}
		
		}
		m_userInforFile.Close();
		
		return true;
	}
	else
	{
		return false;
	}

}



void CServerDlg::DeleteSocket(CClientSocket* pSocket)
	{
		pSocket->Close();
		POSITION pos,temp;
		for(pos=m_connectionList.GetHeadPosition();pos!=NULL;)
		{
			temp=pos;
			CClientSocket* pSock=(CClientSocket*)m_connectionList.GetNext(pos);
			if(pSock==pSocket)
			{
				m_connectionList.RemoveAt(temp);
				userNumber--;
				break;
			}

		}
		delete pSocket;

	}

HBRUSH CServerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd == this) 
	{ 
      return m_brBk; 
	} 
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CServerDlg::OnButtonLend() 
{
		while(true)
	{
		m_dlg=new CLoadDlg();
		m_dlg->m_portNumber=8000;
		m_dlg->m_editName="Administrator";
		m_dlg->m_editPassword="1988822";
		UpdateData(TRUE);
		if(m_dlg->DoModal()==IDOK)
		{
			CString errorStr=_T("");
			if(m_dlg->m_portNumber<8000)
			{
				errorStr="输入端口号不小于8000\n";
			}
			else if(m_dlg->m_portNumber>9000)
			{
				errorStr="输入端口号不大于9000\n";
			}
			if(m_dlg->m_editName!="Administrator")
			{
				errorStr=errorStr+"用户名错误！\n";
			}
			if(m_dlg->m_editPassword!="1988822")
			{
				errorStr=errorStr+"密码错误\n";
			}

			if(errorStr!="")
			{
				if(AfxMessageBox(errorStr,MB_YESNO)==IDNO)
				{
					break;
				}
			}
			else
			{
                // port=dlg.m_portNumber;
				 GetDlgItem(IDC_BUTTON_SERVICE1)->EnableWindow(TRUE);
                 GetDlgItem(IDC_BUTTON_LEND)->EnableWindow(FALSE);
				 break;
			}
		}
	}
	
}

/*void CServerDlg::OnButtonService1() 
{
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
    GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
    GetDlgItem(IDC_LIST_MSG)->EnableWindow(TRUE);
    GetDlgItem(IDC_LIST_USER)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SERVICE)->EnableWindow(FALSE);

   	 if(m_pSocket->Create(m_dlg->m_portNumber))
	 {
	      if(!m_pSocket->Listen())
		  {
		       AfxMessageBox("侦听失败!");
		 
		  }
	 }
	
}*/

void CServerDlg::OnButtonSend() 
{
	UpdateData(TRUE);


   CString b=AddTimeMsg(m_editMsg);

	m_listMsg.AddString(b);
	SendMsgAll(b);
	m_editMsg=_T("");
	UpdateData(FALSE);	
}

void CServerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

CString CServerDlg::BuildUserListMsg()
{
	CString a;
	a="USERLIST";
	for(int i=0;i<m_listUser.GetCount();i++)
	{
		CString b;
		m_listUser.GetText(i,b);
		a=a+"_"+b;

	}
	return a;

}

void CServerDlg::OnSelchangeListUser() 
{

}


bool CServerDlg::BuildUser(CString& inforStream)
{
	int begin=0;
	int end=inforStream.Find("_",begin);
	m_pUser.m_loadName=inforStream.Mid(begin,end-begin);

	begin=end+1;
	end=inforStream.Find("_",begin);

	m_pUser.m_password=inforStream.Mid(begin,end-begin);

	begin=end+1;
	m_pUser.m_callName=inforStream.Mid(begin);
	if((!m_pUser.m_callName.IsEmpty())&&
		(!m_pUser.m_loadName.IsEmpty())&&
		(!m_pUser.m_password.IsEmpty()))
	{
		return true;
	}
	else
	{
	    return false;
	}

}


void CServerDlg::OnButtonNew() 
{

	if(m_pNewUserDlg->DoModal()==IDOK)
	{
		
			User *p=new User();
			p->m_loadName=m_pNewUserDlg->m_user;
			p->m_callName=m_pNewUserDlg->m_name;
			p->m_password=m_pNewUserDlg->m_password;
		

			if(!IsExist(p))
			{
			
			    m_pNewUserDlg->m_user.Empty();
		     	m_pNewUserDlg->m_name.Empty();
			    m_pNewUserDlg->m_password.Empty();
				m_pNewUserDlg->m_passwordAgain.Empty();
			//	m_pNewUserDlg->UpdateData(TRUE);
			//	UpdateData(TRUE);
				this->m_userInforList.AddTail(p);
				AddUserItem(p);
			}
			else
			{
				AfxMessageBox("此用户已经存在!");
			}
	}
}


bool CServerDlg::IsExist(User* pUser)
{
	POSITION pos;
	for(int i=0;i<m_userInforList.GetCount();i++)
	{
		pos=m_userInforList.FindIndex(i);
		User* ppUser=(User*)m_userInforList.GetPrev(pos);
		if( ppUser->m_callName==pUser->m_callName)
		{
			return true;
		}
		else if(ppUser->m_loadName==pUser->m_loadName)
		{
			return true;
		}
			
	}
	return false;

}


bool CServerDlg::AddUserItem(User* pUser)

{
	CString pFileName("user.dat");
	  if( m_userInforFile.Open( pFileName, CFile::modeWrite | CFile::typeText ) )
	{
		m_userInforFile.SeekToEnd();
		CString item=pUser->m_loadName+"_"+pUser->m_password+"_"+pUser->m_callName+"\n";
		m_userInforFile.WriteString(item);
		AfxMessageBox("成功");
		m_userInforFile.Close();
		return true;
	}
	  else
	  {
		  return false;
	  }


}


CString CServerDlg::GetUserItem(CString& name,CString& password)
{
	POSITION pos;
	CString a=_T("");
	for(int i=0;i<m_userInforList.GetCount();i++)
	{
		pos=m_userInforList.FindIndex(i);
		User* ppUser=(User*)m_userInforList.GetPrev(pos);
		if(ppUser->m_loadName==name&&ppUser->m_password==password)
		{
             a="SUCCESS_"+ppUser->m_callName;
		//	 AfxMessageBox("GetUserItem"+a);
			 break;
		}
			
	}
    return a;
}


	CString CServerDlg::FindCallName(CString& loadName)
	{
		POSITION pos;
	    for(int i=0;i<m_userInforList.GetCount();i++)
		{
		    pos=m_userInforList.FindIndex(i);
		    User* ppUser=(User*)m_userInforList.GetPrev(pos);
		    if( ppUser->m_loadName==loadName)
			{
			
			    return ppUser->m_callName;
			}
			
		}
	    return "";
	}






void CServerDlg::DeleteAllConnect()
{
		POSITION pos;
		for(int i=0;i<userNumber;i++)
	{
			
		pos=m_connectionList.FindIndex(i);
		CClientSocket* pSocket=(CClientSocket*)m_connectionList.GetPrev(pos);
		pSocket->Close();
			
	}

	m_connectionList.RemoveAll();
}

void CServerDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
