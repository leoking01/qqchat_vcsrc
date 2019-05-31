; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=6
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Class4=CLoadDlg
Class5=CChatSocket
Resource4=IDD_CLIENT_DIALOG
Class6=CUserInforDlg
Resource5=IDD_DIALOG2

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
LastObject=IDC_BUTTON_CHANGE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=18
Control1=IDC_LIST_MSG,listbox,1353777409
Control2=IDC_LIST_USER,listbox,1352728835
Control3=IDC_STATIC_USERNUMBER,static,1342308352
Control4=IDC_EDIT_MSG,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_STATIC,static,1342308864
Control7=IDC_COMBO_WHO,combobox,1344340226
Control8=IDC_BUTTON_SEND,button,1342242816
Control9=IDC_BUTTON_LOAD,button,1342242816
Control10=IDC_BUTTON_REGISTER,button,1342242816
Control11=IDC_BUTTON_USERINFO,button,1342242816
Control12=IDC_BUTTON_CHANGE,button,1342242816
Control13=IDC_LIST_OWN,listbox,1352728833
Control14=IDCANCEL,button,1342242816
Control15=IDC_EDIT_IPADD,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDOK,button,1342242816
Control18=IDC_STATIC_TIME,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CLoadDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_STATIC,static,1342308864
Control5=IDC_EDIT_USER,edit,1350631552
Control6=IDC_EDIT_PASSWORD,edit,1350631584

[CLS:CLoadDlg]
Type=0
HeaderFile=LoadDlg.h
ImplementationFile=LoadDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CChatSocket]
Type=0
HeaderFile=ChatSocket.h
ImplementationFile=ChatSocket.cpp
BaseClass=CSocket
Filter=N

[DLG:IDD_DIALOG2]
Type=1
Class=CUserInforDlg
ControlCount=5
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDOK,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDCANCEL,button,1342242816
Control5=IDC_USERCOPY,static,1073872896

[CLS:CUserInforDlg]
Type=0
HeaderFile=UserInforDlg.h
ImplementationFile=UserInforDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUserInforDlg
VirtualFilter=dWC

