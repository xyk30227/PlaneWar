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
	//�ɻ�����
	int m_X;
	int m_Y;

	//�ɻ��ľ��α߿�
	QRect m_Rect;


};

