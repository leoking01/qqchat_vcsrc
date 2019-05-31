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
	public:
		CMsg(CString& preMsg);
	void Init();
	CString WhatType();

};
#endif