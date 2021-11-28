#include "Map.h"
#include "config.h"

Map::Map()
{

	//��ʼ�����ص�ͼ����
	m_map1.load(MAP_PATH);
	m_map2.load(MAP_PATH);

	//���õ�ͼ��ʵy������
	m_map1_posY = -GAME_HEIGHT;
	m_map2_posY = 0;

	//���õ�ͼ�����ٶ�
	m_scroll_speed = MAP_SCROLL_SPEED;
}


Map::~Map()
{
}


void Map::mapPosition()
{
	//�����һ��ͼƬ����
	m_map1_posY += MAP_SCROLL_SPEED;
	if (m_map1_posY >= 0)
	{
		m_map1_posY = -GAME_HEIGHT;
	}

	//����ڶ���ͼƬ����
	m_map2_posY += MAP_SCROLL_SPEED;
	if (m_map2_posY >= GAME_HEIGHT)
	{
		m_map2_posY = 0;
	}
}