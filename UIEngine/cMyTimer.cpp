#include "stdafx.h"
#include "cMyTimer.h"
#include "windows.h"
#include "process.h"

cMyTimer::cMyTimer()
{
}

cMyTimer::~cMyTimer()
{

}

void CheckTimerRun(void* p)
{
	cMyTimer* pTimer = (cMyTimer*)p;
	if (pTimer == NULL)
	{
		_endthread();
		return;
	}
	while(true)
	{
		pTimer->CheckAddTimer();
		if (pTimer->QuitThread())
		{
			break;
		}
		//ɾ����Ҫɾ���Ķ�ʱ��
		pTimer->CheckDelTimer();

		//����Ƿ��ж�ʱ��Ҫ����

		if(!pTimer->TimerRun())
		{
			_endthread();
		}

	}
}

//��Ӷ�ʱ��
void cMyTimer::AddTimer(unsigned timeId,unsigned timeElapse,int param,char* p)
{
	if (timeElapse == 0)
	{
		return;
	}
	stTimer stTimerTemp;
	stTimerTemp.bDel = false;
	stTimerTemp.id = timeId;
	stTimerTemp.iParam = param;
	stTimerTemp.timeElapse = timeElapse;
	stTimerTemp.timeLastRun = GetTickCount();//��ȡ�ӿ�����ʱ�䣬���뼶
	if (p != NULL)
	{
		stTimerTemp.strParam = p;
	}
	m_tempList.push_back(stTimerTemp);
	//m_timerList.push_back(stTimerTemp);
	if (m_tempList.size() == 1)
	{
		//˵����ʱ�ǵ�һ����ʱ��
		_beginthread(CheckTimerRun,0,this);
	}
}

//ɾ����ʱ��
void cMyTimer::DeleteTimer(unsigned id)
{
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();++it)
	{
		if (it->id == id)
		{
			it->bDel = true;
			return;
		}
	}
}

void cMyTimer::CheckDelTimer()
{
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();)
	{
		if (it->bDel)
		{
			m_timerList.erase(it);
			it = m_timerList.begin();
			continue;
		}
		++it;
	}
}

bool cMyTimer::TimerRun()
{
	if (m_timerList.size() == 0)
	{
		return false;
	}
	//�Ƚ϶�ʱ���ϴ����е�ʱ������ڵ�ʱ���Ƿ�����timeElapse
	unsigned timeNow = GetTickCount();
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();++it)
	{
		if (timeNow - it->timeLastRun >= it->timeElapse)
		{
			it->timeLastRun = timeNow;
			int newTimeElapse = OnTimer(it->id,it->iParam,it->strParam);
			
			if(newTimeElapse==0)
			{
				it->bDel = true;
			}
		}
	}
	return true;
}

void cMyTimer::CheckAddTimer()
{
	if (m_tempList.size() == 0)
	{
		return;
	}

	for (itTimerLisst it = m_tempList.begin();it != m_tempList.end();++it)
	{
		m_timerList.push_back(*it);
	}
	m_tempList.clear();
}

bool cMyTimer::QuitThread()
{
	bool bRet = m_timerList.size() ? false : true;
	return bRet;
}
