#pragma once
#include <QPixmap>
#include "Plane.h"
#include "Bullet.h"
class HeroPlane:public Plane
{
public:
	HeroPlane();
	~HeroPlane();

public:
	void shot();

	void setPosition(int x, int y);

public:	
	//��ϻ
	Bullet m_bullets[BULLET_NUM];

	//��������¼
	int m_recorder;
};

