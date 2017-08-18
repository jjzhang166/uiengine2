#pragma once
#include<list>
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	*class cSight
	*��Ұ������һ����Ұ������ǰ���ܿ������������������
	*/
	class cSight:public cBaseUI
	{
	public:
		cSight();
		virtual ~cSight();
		virtual const RECT GetRect() const override;

		/*
		*Draw(HDC hDc)
		*����ui�ؼ�
		*@Param:
		*HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		*addChild(cBaseUI* ui);
		*����ӽڵ�
		*@Param ui*���ӽڵ����ָ��
		*/
		void addChild(cBaseUI* ui);
	private:
		std::list<cBaseUI*> m_uiList;
	};
}