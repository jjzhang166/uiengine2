#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	/**
	cCircle
	Բ
	*/
	class cCircle:public cBaseUI
	{
	public:
		cCircle();

		/*
		�вι��캯������ʼԲ����Ӿ�������
		@Param��
			int startx�����Ͻ�x����
			int starty�����Ͻ�y����
			int endx�����½�x����
			int endy�����½�y����
		*/
		explicit cCircle(const int& startx,const int& starty,const int& endx,const int& endy);

		/*
		�вι��캯������ʼԲ����Ӿ�������
		@Param��
			RECT rect����������
		*/
		explicit cCircle(const RECT& rect);

		virtual ~cCircle();

		/*
		SetCircleArea()
		����Բ����Ӿ�������
		@param:
			RECT rect��������
		*/
		void SetCircleArea(const RECT& rect);

		/*
		SetCircleArea()
		����Բ����Ӿ�������
		@Param��
			int startx�����Ͻ�x����
			int starty�����Ͻ�y����
			int endx�����½�x����
			int endy�����½�y����
		*/
		void SetCircleArea(const int& startx, const int& starty, const int& endx, const int& endy);

		/*
		GetHeight()
		��ȡԲ�ĸ߶�
		@return int��
			�߶�
		*/
		const int& GetHeight() const;

		/*
		GetWidth()
		��ȡԲ�Ŀ��
		@return int��
			���
		*/
		const int& GetWidth() const;

		/*
		SetLineColor(const UINT& rgb)
		�����߶���ɫ
		@param��
			UINT rgb���߶�rgbɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		��ȡ�߶���ɫ
		@return UINT��
			�߶�rgbɫ
		*/
		const UINT& GetLineColor() const;

		/*
		SetIsFill(const bool& ok)
		�����Ƿ����Բ������
		@Param��
			bool ok���Ƿ����
		*/
		void SetIsFill(const bool& ok);

		/*
		GetIsFill()
		��ȡ�Ƿ����
		@return bool��
			true�����
			false�������
		*/
		const bool& GetIsFill() const;

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
		@return UINT:
			���ɫ
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT& style)
		�����߶η��
		@param:
			UINT style���߶η��
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		��ȡ�߶η��
		@return UINT��
			�߶η��
		*/
		const UINT& GetLineStyle(const UINT& style);

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		int m_height;

		int m_width;

		int m_lineWidth;

		UINT m_LineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;

		HBRUSH m_hBrush;

		HPEN m_hPen;
	};
}