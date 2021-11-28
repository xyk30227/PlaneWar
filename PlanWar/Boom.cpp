#include "Boom.h"


Boom::Boom()
{
	//��ʼ����ըͼƬ����
	for (int i = 1; i <= BOMB_MAX; i++)
	{
		//�ַ���ƴ�ӣ�����  ":/res/bomb-1.png"
		QString str = QString(BOMB_PATH).arg(i);
		m_pixArr.push_back(QPixmap(str));
	}

	//��ʼ������
	m_X = 0;
	m_Y = 0;

	//��ʼ������״̬
	m_Free = true;

	//��ǰ����ͼƬ�±�
	m_index = 0;

	//��ը�����¼
	m_Recoder = 0;
}


Boom::~Boom()
{
}


void Boom::updateInfo()
{
	//����״̬
	if (m_Free)
	{
		return;
	}

	m_Recoder++;
	if (m_Recoder < BOMB_INTERVAL)
	{
		//��¼��ը���δ����ֱ��return������Ҫ��ͼ
		return;
	}
	//���ü�¼
	m_Recoder = 0;

	//�л���ը����ͼƬ
	m_index++;
	//ע�������е��±��0��ʼ�������6
	//���������±����6������Ϊ0
	if (m_index > BOMB_MAX - 1)
	{
		m_index = 0;
		m_Free = true;
	}
}