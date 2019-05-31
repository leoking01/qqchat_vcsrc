// ServerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mdclist.h"
//}}AFX_INCLUDES

#if !defined(AFX_SERVERDLG_H__C8836536_A9E3_4221_8381_949BB3CF9ECA__INCLUDED_)
#define AFX_SERVERDLG_H__C8836536_A9E3_4221_8381_949BB3CF9ECA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog
// Download by http://www.codesc.net
#include "ListeningSocket.h"
#include "ClientSocket.h"
//#include "Msg.h"

class CClientSocket;
//class CListeningSocket;
class CLoadDlg;
class CMsg;
class CNewUserDlg;
struct User
{
	CString m_loadName;
	CString m_password;
	CString m_callName;
};
class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

	CListeningSocket* m_pSocket;
	int userNumber;
	CString m_strText;
	CPtrList m_connectionList;
	CLoadDlg* m_dlg;
	CMsg* m_pMsg;
	CNewUserDlg* m_pNewUserDlg;
	CBitmapButton m_button_load;
	CBitmapButton m_button_service;
	CBitmapButton m_button_stop;
	CBitmapButton m_button_send;
//	CBitmapButton m_button_new;

//	CBitmapButton m_button_cancel;
	CBrush m_brBk;
	CStdioFile m_userInforFile;
	User m_pUser;
	CPtrList m_userInforList;

public:
	void OnAccept();
	void UpdateInfo();
	void OnReceive(CClientSocket* pSocket);
	void SendMsg(CString& strText,CClientSocket* pSocket);
	void SendMsgAll(CString& strText);
	void DisplayMsg(LPCTSTR lpszMessage);
	CString AddTimeMsg(CString& text);
	CString BuildSystemMsg();
	bool LoadUserInfor();
    bool BuildUser(CString& inforStream);

	void DeleteSocket(CClientSocket* pSocket);
	CString BuildUserListMsg();
	bool IsExist(User* pUser);

	bool AddUserItem(User* pUser);
	CString FindCallName(CString& loadName);

    CString GetUserItem(CString& name,CString& password);
	void DeleteAllConnect();
//	bool LoadUserInfor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };

	CListBox	m_listMsg;
	CStatic	m_t;
	CStatic	m_peoNumber;
	CListBox	m_listUser;
	CButton	m_buttonStop;
	CButton	m_buttonStart;
	CString	m_editMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonLend();
	afx_msg void OnButtonService1();
	afx_msg void OnButtonSend();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeListUser();
	afx_msg void OnButtonNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__C8836536_A9E3_4221_8381_949BB3CF9ECA__INCLUDED_)
