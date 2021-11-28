#pragma once
#include "config.h"
#include <QPixmap>
class Plane
{
public:
	Plane();
	~Plane();

public:
	virtual void shot(){};


public:
	QPixmap m_Plane;
	//飞机坐标
	int m_X;
	int m_Y;

	//飞机的矩形边框
	QRect m_Rect;


};

