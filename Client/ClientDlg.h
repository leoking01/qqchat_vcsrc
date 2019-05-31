// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__B3DAA1B4_E387_4A96_ABFD_31040E749CAB__INCLUDED_)
#define AFX_CLIENTDLG_H__B3DAA1B4_E387_4A96_ABFD_31040E749CAB__INCLUDED_
// Download by http://www.codesc.net
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
class CLoadDlg;
class CChatSocket;
class CUserInforDlg;

class CClientDlg : public CDialog
{
// Construction
public:
	 CClientDlg(CWnd* pParent = NULL);	// standard constructor
BOOL ConnectSocket(LPCTSTR lpszAddress,UINT nport);
public://Attribute
    CLoadDlg* m_loadDlg;
	CChatSocket* m_pSocket;
	CUserInforDlg *m_userInforDlg;
	CString m_nameCopy;
	int m_userNumber;
	CString m_IpAddress;
 //   CStdioFile 


	void SendMsg(CString& strText);
	void OnReceive(CChatSocket* pSocket);
	CString BuildNomalMsg(CString& preString);
	CString BulidLoadMsg();
	CString BulidChangeMsg();
	CString BulidCancelMsg();
	bool IsUserLoad(CString& textStr);
	CString AddTimeMsg(CString& text);
	void UpdateUserInfo();
	bool IsToMe(CString& text);

	bool IsMakeSure(CString& textMsg);
	bool CheckId(CString& preIp);
private:
	bool IsNumberOfIp(CString ipSeg);

	

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CButton	m_ok;
	CStatic	m_peoNumber;
	CStatic	m_time;
	CButton	m_exit;
	CListBox	m_listUser;
	CListBox	m_listOwn;
	CListBox	m_listMsg;
	CComboBox	m_comboTo;
	CButton	m_buttonInfo;
	CButton	m_buttonSend;
	CButton	m_buttonRegister;
	CButton	m_buttonLoad;
	CButton	m_buttonChange;
	CString	m_comboWho;
	CString	m_editMsg;
	CString	m_userName;
	CString	m_ipAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonLoad();
	afx_msg void OnButtonSend();
	afx_msg void OnButtonChange();
	afx_msg void OnButtonUserinfo();
	virtual void OnCancel();
	afx_msg void OnSelchangeListUser();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__B3DAA1B4_E387_4A96_ABFD_31040E749CAB__INCLUDED_)
