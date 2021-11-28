#pragma once
#include "Effect.h"
#include "config.h"
#include <QPixmap>
#include <QVector>
class Boom :
	public Effect
{
public:
	Boom();
	~Boom();

	//������Ϣ������ͼƬ�±ꡢ���ż����
	void updateInfo();

public:

	//�ű�ը��Դ����
	QVector<QPixmap> m_pixArr;

	//��ըλ��
	int m_X;
	int m_Y;

	//��ը״̬
	bool m_Free;

	//��ը��ͼ��ʱ����
	int m_Recoder;

	//��ըʱ���ص�ͼƬ�±�
	int m_index;

};

