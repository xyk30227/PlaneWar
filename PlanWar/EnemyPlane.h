#pragma once
#include "Plane.h"
class EnemyPlane :
	public Plane
{
public:
	EnemyPlane();
	~EnemyPlane();

public:
	//��������
	void updatePosition();

public:
	//״̬
	bool m_Free;

	//�ٶ�
	int m_Speed;
};

