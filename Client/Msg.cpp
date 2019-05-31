#include "stdafx.h"
#include "Msg.h"

CMsg::CMsg(CString& preMsg)
{
	m_strText=preMsg;

}

void CMsg::Init()
{
	m_strText=_T("");
}


CString CMsg::WhatType()
{
	CString preType("NULLMSG");
	CString who;
	CString toWho;
	CString msgItem;
	int begin=0;
	int end=0;
	m_strText="NOMALMSG_hupeng_jianghe_消息分裂的第一条消息,一定要成功";
	
	if(m_strText.SpanIncluding("NOMALMSG")=="NOMALMSG")
	{
		end=m_strText.Find("_");
        preType=m_strText.Mid(begin,end-begin);
		begin=end+1;
		end=m_strText.Find("_",begin);
		m_nomalMsg.who=m_strText.Mid(begin,end-begin);

		begin=end+1;
		end=m_strText.Find("_",begin);
		m_nomalMsg.toWho=m_strText.Mid(begin,end-begin);

		begin=end+1;
	//	end=m_strText.Find("_",begin);
		m_nomalMsg.msgItem=m_strText.Mid(begin);

		CString m="preType:"+preType;
		AfxMessageBox(m);
		m="who:"+m_nomalMsg.who;//+"\ntoWho:"+toWho+"\nMessage:"+msgItem;
		AfxMessageBox(m);
		m="toWho:"+m_nomalMsg.toWho;
		AfxMessageBox(m);
		m="Message:"+m_nomalMsg.msgItem;
			AfxMessageBox(m);
		

	}
	return m_strText;

	
}