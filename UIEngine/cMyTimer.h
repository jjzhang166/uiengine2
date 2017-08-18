#pragma once
#include <string>
#include <list>
using namespace std;

struct stTimer
{
	unsigned id;//id��
	unsigned timeElapse;	//��ʱ�����еļ��ʱ��
	unsigned timeLastRun;	//��ʱ���ϴ����е�ʱ��
	int iParam;				//Ԥ������
	string strParam;		//Ԥ������
	bool bDel;				//�Ƿ�Ҫ��ɾ��
	stTimer()
	{
		timeElapse = 0;
		timeLastRun = 0;
		id = 0;
		iParam = 0;
		bDel = false;
	}
};

typedef list<stTimer> TimerList;
typedef list<stTimer>::iterator itTimerLisst;

class cMyTimer
{
public:
	cMyTimer();
	virtual ~cMyTimer();
	//��Ӷ�ʱ��
	void AddTimer(unsigned timeId,unsigned timeElapse,int param = 0,char* p = NULL);

	//ɾ����ʱ��
	void DeleteTimer(unsigned id);

	//��ʱ���߼�����
	//���ص�ֵ���Ǹö�ʱ���µļ��ʱ��
	virtual int OnTimer(int id,int iParam,string str) = 0;

	//����Ƿ��ж�ʱ����Ҫɾ��
	void CheckDelTimer();

	//��Ⲣ���ж�ʱ��
	bool TimerRun();

	//����Ƿ����µ�list�ӽ���
	void CheckAddTimer();
private:
	TimerList m_timerList;	//�������ж�ʱ��

	TimerList m_tempList;	//����list
};