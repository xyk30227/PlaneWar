#include "HeroPlane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
	//��ʼ�����طɻ�ͼƬ��Դ
	m_Plane.load(HERO_PATH);

	//��ʼ������
	m_X = GAME_WIDTH * 0.5 - m_Plane.width()*0.5;
	m_Y = GAME_HEIGHT - m_Plane.height();

	//��ʼ�����ο�
	m_Rect.setWidth(m_Plane.width());
	m_Rect.setHeight(m_Plane.height());
	m_Rect.moveTo(m_X, m_Y);


	//��ʼ����������¼
	m_recorder = 0;
}


HeroPlane::~HeroPlane()
{

}


void HeroPlane::setPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
	m_Rect.moveTo(m_X, m_Y);
}

void HeroPlane::shot()
{
	//�ۼ�ʱ������¼����
	m_recorder++;
	//�ж������¼���� δ�ﵽ��������ֱ��return
	if (m_recorder < BULLET_INTERVAL)
	{
		return;
	}
	//���﷢��ʱ�䴦��
	//���÷���ʱ������¼
	m_recorder = 0;

	//�����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//����ǿ��е��ӵ����з���
		if (m_bullets[i].m_Free)
		{
			//�����ӵ�����״̬��Ϊ��
			m_bullets[i].m_Free = false;
			//���÷�����ӵ�����
			m_bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
			m_bullets[i].m_Y = m_Y - 25;
			break;
		}
	}
}