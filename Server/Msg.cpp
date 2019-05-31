#include "stdafx.h"
#include "Msg.h"

CMsg::CMsg(CString& preMsg)
{
	m_strText=preMsg;
	Init();

}
CMsg::CMsg()
{
	m_strText=_T("");
	Init();
}

void CMsg::Init()
{
	m_strText=_T("");
    m_nomalMsg.who=m_nomalMsg.toWho=m_nomalMsg.msgItem=_T("");
	m_systemMsg.msgItem=m_systemMsg.type=_T("");
//	m_loadMsg.name=m_loadMsg.password=_T("");

}


CString CMsg::WhatType()
{
	CString preType("NULLMSG");
	int begin=0;
	int end=0;
	end=m_strText.Find("_");
    preType=m_strText.Mid(begin,end-begin);
	if(preType!="NOMALMSG"&&
		preType!="SYSTEMMSG"&&
		preType!="LOADMSG")
	{
		preType="ERRORMSG";
	}
		return preType;
}

void CMsg::BuildNomal()
{
	int begin=0;
	int end=0;
	end=m_strText.Find("_");
	begin=end+1;
	end=m_strText.Find("_",begin);
	
	m_nomalMsg.who=m_strText.Mid(begin,end-begin);//提取是谁发的消息
	

	begin=end+1;
	end=m_strText.Find("_",begin);
	m_nomalMsg.toWho=m_strText.Mid(begin,end-begin);//提取发给谁

    m_nomalMsg.msgItem=m_strText.Mid(end+1);//消息体




}
void CMsg::BuildLoad()
{
	int begin=0;
	int end=0;
	end=m_strText.Find("_");

	begin=end+1;
	end=m_strText.Find("_",begin);
    m_loadMsg.name=m_strText.Mid(begin,end-begin);//提取是谁发的消息

	begin=end+1;
    m_loadMsg.password=m_strText.Mid(begin);//消息体

}


void CMsg::BuileSystem()
{
	int begin=0;
	int end=0;
	end=m_strText.Find("_");//SYSTEMMSG

	begin=end+1;
	end=m_strText.Find("_",begin);
	m_systemMsg.type=m_strText.Mid(begin,end-begin);//CLOSE

	begin=end+1;
	end=m_strText.Find("_",begin);
	m_systemMsg.name=m_strText.Mid(begin,end-begin);//NAME

	begin=end+1;
	end=m_strText.Find("_",begin);
	m_systemMsg.msgItem=m_strText.Mid(begin);

}

	
