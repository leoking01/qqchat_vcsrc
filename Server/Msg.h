#ifndef CMSG1_H
#define CMSG1_H
class CMsg : public  CObject
{
    public:

		CString m_strText;
	    CString m_msgType;
		struct NomalMsg
		{
			CString who;
			CString toWho;
			CString msgItem;
		} m_nomalMsg;
		struct SystemMsg
		{
			CString type;
			CString name;
			CString msgItem;
		} m_systemMsg;

		struct LOADMSG
		{
			CString name;
			CString password;
		} m_loadMsg;

	public:
		CMsg(CString& preMsg);
		CMsg();
	    void Init();
	    CString WhatType();
	//	void SetMsg();
//	private:
		void BuildNomal();
		void BuildLoad();
		void BuileSystem();

};
#endif