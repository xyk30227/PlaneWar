#include "Bullet.h"


Bullet::Bullet()
{
	//�����ӵ���Դ
	m_Bullet.load(BULLET_PATH);

	//�ӵ����� ��ʼ������������ã����ڻ�����
	m_X = GAME_WIDTH*0.5 - m_Bullet.width()*0.5;
	m_Y = GAME_HEIGHT;

	//�ӵ�״̬
	m_Free = true;

	//�ӵ��ٶ�
	m_Speed = BULLET_SPEED;

	//�ӵ����ο�
	m_Rect.setWidth(m_Bullet.width());
	m_Rect.setHeight(m_Bullet.height());
	m_Rect.moveTo(m_X, m_Y);
}


Bullet::~Bullet()
{
}


void Bullet::updatePosition()
{
	//����ӵ��ǿ���״̬������Ҫ�������
	//��ҷɻ����Կ����ӵ��Ŀ���״̬Ϊfalse
	if (m_Free)
	{
		return;
	}

	//�ӵ������ƶ�
	m_Y -= m_Speed;
	m_Rect.moveTo(m_X, m_Y);

	if (m_Y <= -m_Rect.height())
	{
		m_Free = true;
	}
}