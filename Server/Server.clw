; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewUserDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=7
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CLoadDlg
Class5=CListeningSocket
Class6=CClientSocket
Resource4=IDD_SERVER_DIALOG
Class7=CNewUserDlg
Resource5=IDD_DIALOG2

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
LastObject=IDC_BUTTON_LEND
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=13
Control1=IDC_LIST_USER,listbox,1352728835
Control2=IDC_EDIT_MSG,edit,1350631552
Control3=IDC_STATIC,static,1342308864
Control4=IDCANCEL,button,1342242827
Control5=IDC_STATIC_USER,static,1342308352
Control6=IDC_STATIC_TIME,static,1342308864
Control7=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control8=IDC_LIST_MSG,listbox,1352728835
Control9=IDC_BUTTON_LEND,button,1342242827
Control10=IDC_BUTTON_SERVICE1,button,1342242827
Control11=IDC_BUTTON_SEND,button,1342242827
Control12=IDC_STATIC,static,1342177294
Control13=IDC_BUTTON_NEW,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CLoadDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=IDC_STATIC,static,1342308864
Control8=IDC_EDIT_PORTNUMBER,edit,1350631552
Control9=IDC_STATIC,static,1342308864

[CLS:CLoadDlg]
Type=0
HeaderFile=LoadDlg.h
ImplementationFile=LoadDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_PORTNUMBER
VirtualFilter=dWC

[CLS:CListeningSocket]
Type=0
HeaderFile=ListeningSocket.h
ImplementationFile=ListeningSocket.cpp
BaseClass=CSocket
Filter=N

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N

[DLG:IDD_DIALOG2]
Type=1
Class=CNewUserDlg
ControlCount=11
Control1=IDOK,button,1476460545
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT_USER,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=IDC_STATIC,static,1342308864
Control8=IDC_EDIT_PASSWORD1,edit,1350631584
Control9=IDC_STATIC,static,1342308864
Control10=IDC_EDIT_NAME,edit,1350631552
Control11=IDC_BUTTON_CHECK,button,1342242816

[CLS:CNewUserDlg]
Type=0
HeaderFile=NewUserDlg.h
ImplementationFile=NewUserDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_CHECK
VirtualFilter=dWC

