#include "EnemyPlane.h"


EnemyPlane::EnemyPlane()
{
	//敌机资源加载
	m_Plane.load(ENEMY_PATH);

	//敌机位置
	m_X = 0;
	m_Y = 0;

	//敌机状态
	m_Free = true;

	//敌机速度
	m_Speed = ENEMY_SPEED;

	//敌机矩形
	m_Rect.setWidth(m_Plane.width());
	m_Rect.setHeight(m_Plane.height());
	m_Rect.moveTo(m_X, m_Y);
}


EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::updatePosition()
{
	//空闲状态，不计算坐标
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
