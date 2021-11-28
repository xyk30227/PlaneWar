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
	//µ¯Ï»
	Bullet m_bullets[BULLET_NUM];

	//·¢Éä¼ä¸ô¼ÇÂ¼
	int m_recorder;
};

