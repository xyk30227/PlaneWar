#include "EnemyPlane.h"


EnemyPlane::EnemyPlane()
{
	//�л���Դ����
	m_Plane.load(ENEMY_PATH);

	//�л�λ��
	m_X = 0;
	m_Y = 0;

	//�л�״̬
	m_Free = true;

	//�л��ٶ�
	m_Speed = ENEMY_SPEED;

	//�л�����
	m_Rect.setWidth(m_Plane.width());
	m_Rect.setHeight(m_Plane.height());
	m_Rect.moveTo(m_X, m_Y);
}


EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::updatePosition()
{
	//����״̬������������
	if (m_Free)
	{
		return;
	}

	m_Y += m_Speed;
	m_Rect.moveTo(m_X, m_Y);

	if (m_Y >= GAME_HEIGHT + m_Rect.height())
	{
		m_Free = true;
	}
}
