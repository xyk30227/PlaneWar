#pragma once
#include "Plane.h"
class EnemyPlane :
	public Plane
{
public:
	EnemyPlane();
	~EnemyPlane();

public:
	//更新坐标
	void updatePosition();

public:
	//状态
	bool m_Free;

	//速度
	int m_Speed;
};

