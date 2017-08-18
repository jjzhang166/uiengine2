#pragma once
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	cRectangle
	����
	*/
	class cRectangle:public cBaseUI
	{
	public:
		cRectangle();

		/*
		�вι��캯������ʼ����������
		@Param��
			RECT rect����������
		*/
		explicit cRectangle(const RECT& rect);

		/*
		�вι��캯������ʼ����������
		@Param:
			int left���������������
			int right�������������ұ�
			int top�������������ϱ�
			int bottom�������������±�
		*/
		cRectangle(const int& left, const int& right, const int& top, const int& bottom);

		virtual ~cRectangle();

		/*
		SetRect(const RECT& rect)
		���þ�������
		@Param��
			RECT rect����������
		*/
		void SetRect(const RECT& rect);

	
		/*
		SetRect(const int& left, const int& right, const int& top, const int& bottom);
		���þ�������
		@Param:
			int left���������������
			int right�������������ұ�
			int top�������������ϱ�
			int bottom�������������±�
		*/
		void SetRect(const int& left, const int& right, const int& top, const int& bottom);

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
			ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;

		/*
		GetWidth()
		��ȡ���ο��
		@return int��
			���ο��
		*/
		int GetWidth() const;

		/*
		GetHeight()
		��ȡ���θ߶�
		@return int��
			�߶�
		*/
		int GetHeight() const;

		/*
		SetLineColor(const UINT& rgb)
		�����߶���ɫ
		@Param:
			UINT rgb���߶���ɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		��ȡ�߶���ɫ
		@return UINT:
			�߶���ɫ
		*/
		const UINT& GetLineColor() const;

		/*
		SetIsFill(const bool& ok)
		�����Ƿ�����������
		@Param:
			bool ok:�Ƿ����
		*/
		void SetIsFill(const bool& ok);

		/*
		IsFill()
		�Ƿ����
		@return bool��
			true�����
			false�������
		*/
		const bool& isFIll() const;

		/*
		SetFillColor(const UINT& rgb)
		�������ɫ
		@Param��
			UINT rgb�����ɫ
		*/
		void SetFillColor(const UINT& rgb);

		/*
		GetFillColor()
		��ȡ���ɫ
		@return UINT��
			���ɫ
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT&v style)
		�����߶η��
		@Param��
			UINT style:�߶η��
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		��ȡ�߶η��
		@return UINT��
			�߶η��
		*/
		const UINT& GetLineStyle() const;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		RECT m_rect;

		int m_Linewidth;

		UINT m_lineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;

		HPEN m_hPen;

		HBRUSH m_hBrush;
	};
}