#pragma once
#include <QPixmap>
class Map
{
public:
	Map();
	~Map();

	void mapPosition();

	//��ͼͼƬ����
	QPixmap m_map1;
	QPixmap m_map2;

	//��ͼY������
	int m_map1_posY;
	int m_map2_posY;

	//��ͼ��������
	int m_scroll_speed;
};

