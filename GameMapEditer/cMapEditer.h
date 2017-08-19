#pragma once
#include"../UIEngine/cGameEngine.h"

class cMapEditer
{

public:
	cMapEditer();

	/*
	�вι��캯������ʼ����ͼ�༭����
	@Param��
		HWND hWnd����ͼ�༭���ھ��
	*/
	cMapEditer(HWND hWnd);

	~cMapEditer();

	/*
	SetRowAndRank(const int& row,const int& rank)
	��������༭��ͼ��������
	@Param:
		int row����ͼ����
		int rank����ͼ����
	*/
	BOOL SetRowAndRabk(const int& row, const int& rank, const int& terrianSpecies);

	/*
	LoadMapResource(const LPWSTR& mapPath)
	���ص�ͼλͼ��Դ
	@param��
		LPWSTR mapPath��λͼ��Դ·��
	*/
	BOOL LoadMapResource(const LPWSTR& mapPath);

	/*
	FromFileLoadMapConfig(const LPWSTR& fileName)
	�ӵ�ͼ�ļ��м��ص�ͼ����
	@Param��
		LPWSTR fileName:�ļ�·����
	*/
	BOOL FromFileLoadMapConfig(const LPWSTR& fileName);

	/*
	CreateSplitLine()
	���ɷָ���
	*/
	void CreateSplitLine();

	/*
	 SaveMapFile(const LPWSTR& fileName);
	 �����ͼ�ļ�
	 @Param��
		LPWSTR fileName���ļ���
	@return BOOL��
		TRUE������ɹ�
		FALSE������ʧ��
	*/
	BOOL SaveMapFile(const LPWSTR& fileName);

	/*
	MouseDown()
	��갴��
	*/
	void MouseDown();

	/*
	StartEdit(HWND hWnd)
	���вι��캯������ͬ���ĳ�ʼ������
	@Param:
		HWND hWnd���༭���ھ��
	*/
	void StartEdit(HWND hWnd);
private:
	/*
	deleteMapInfo()
	�ͷŵ�ͼ��Ϣ�����ڴ�
	*/
	bool deleteMapInfo(); 

	/*
	AutoChangeWndSize()
	���ݵ�ͼ��Դ�Զ��������ڴ�С
	@Param:
		int mapWidth����ͼ���
		int mapHeight����ͼ�߶�
	*/
	BOOL AutoChangeWndSize(const int& mapWidth, const int& mapHeight);

	/*
	initMapInfo()
	��ʼ����ͼ��Ϣ
	*/
	void initMapInfo();

	/*
	CreateTerrianRect(const POINT& pt)
	����һ�����α�־����
	@Param��
		POINT pt��������
		int w:���ο��
		int h:���и߶�
		UINT fillColor�����ɫ
	*/
	void CreateTerrianRect(const POINT& pt,const int& w,const int& h,const UINT& fillColor);

	int m_row;

	int m_rank;

	LPWSTR m_MapPath;

	int m_terrianSpecies;

	int **m_mapInfo;

	int m_wndWidth;

	int m_wndHeight;

	int m_baseXSize;

	int m_baseYSize;

	MyEngine::cGameEngine* m_Ui;

	std::list<MyEngine::cBaseUI*> m_terrianRect;

	std::list<MyEngine::cBaseUI*> m_splitLine;

	MyEngine::cPicture *m_MapImage;
};

