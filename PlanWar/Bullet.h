#pragma once
#include "config.h"
#include <QPixmap>
class Bullet
{
public:
	Bullet();
	~Bullet();

	//�����ӵ�����
	void updatePosition();

public:
	//�ӵ���Դ����
	QPixmap m_Bullet;
	//�ӵ�����
	int m_X;
	int m_Y;
	//�ӵ��ƶ��ٶ�
	int m_Speed;
	//�ӵ��Ƿ�����
	bool m_Free;
	//�ӵ��ľ��α߿�������ײ��⣩
	QRect m_Rect;
};

