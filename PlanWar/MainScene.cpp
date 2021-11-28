#include "MainScene.h"
#include "config.h"
#include <ctime>
#include <QIcon>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
MainScene::MainScene(QWidget *parent)
	: QWidget(parent)
{
	initScene();
	//ui.setupUi(this);
}

void MainScene::initScene()
{
	setFixedSize(GAME_WIDTH, GAME_HEIGHT);

	setWindowTitle(GAME_TITLE);

	setWindowIcon(QIcon(GAME_ICON));

	m_recorder = 0;
	m_Timer.setInterval(GAME_RATE);

	//���������
	srand((unsigned int)time(NULL));  //ͷ�ļ�  #include <ctime>
	BGplayer = new QMediaPlayer();
	BGplayer->setMedia(QUrl(SOUND_BACKGROUND));
	BGplayer->play();
	
	Boomplayer = new QMediaPlayer();
	Boomplayer->setMedia(QUrl(SOUND_BOMB));
}


void MainScene::playGame()
{

// 	//������ʱ��
	m_Timer.start();

	//������ʱ��
	connect(&m_Timer, &QTimer::timeout, [=]()
	{
		enemyToScene();
		//������Ϸ��Ԫ�ص�����
		updatePosition();
		//���»���ͼƬ
		update();
		//
		collisionDetection();
	});	
}

void MainScene::updatePosition()
{
	m_map.mapPosition();

	m_hero.shot();
	//�����ӵ�����
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//����ӵ�״̬Ϊ�ǿ��У����㷢��λ��
		if (!m_hero.m_bullets[i].m_Free)
		{
			m_hero.m_bullets[i].updatePosition();
		}
	}

	//�л��������
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//�ǿ��ел� ��������
		if (m_enemys[i].m_Free == false)
		{
			m_enemys[i].updatePosition();
		}
	}

	//���㱬ը���ŵ�ͼƬ
	for (int i = 0; i < BOMB_NUM; i++)
	{
		if (m_bombs[i].m_Free == false)
		{
			m_bombs[i].updateInfo();
		}
	}
}

//
void MainScene::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	//���Ƶ�ͼ
	painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
	painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

	painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);
	

	//�����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//����ӵ�״̬Ϊ�ǿ��У����㷢��λ��
		if (!m_hero.m_bullets[i].m_Free)
		{
			painter.drawPixmap(m_hero.m_bullets[i].m_X, m_hero.m_bullets[i].m_Y, m_hero.m_bullets[i].m_Bullet);
		}
	}

	//���Ƶл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free == false)
		{
			painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_Plane);
		}
	}

	//���Ʊ�ըͼƬ
	for (int i = 0; i < BOMB_NUM; i++)
	{
		if (m_bombs[i].m_Free == false)
		{
			painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
		}
	}
}


void MainScene::mouseMoveEvent(QMouseEvent *event)
{
	int x = event->x() - m_hero.m_Rect.width()*0.5; //���λ�� - �ɻ����ε�һ��
	int y = event->y() - m_hero.m_Rect.height()*0.5;

	//�߽���
	if (x <= 0)
	{
		x = 0;
	}
	if (x >= GAME_WIDTH - m_hero.m_Rect.width())
	{
		x = GAME_WIDTH - m_hero.m_Rect.width();
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y >= GAME_HEIGHT - m_hero.m_Rect.height())
	{
		y = GAME_HEIGHT - m_hero.m_Rect.height();
	}
	m_hero.setPosition(x, y);
}

void MainScene::enemyToScene()
{
	m_recorder++;
	if (m_recorder < ENEMY_INTERVAL)
	{
		return;
	}

	m_recorder = 0;

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free)
		{
			//�л�����״̬��Ϊfalse
			m_enemys[i].m_Free = false;
			//��������
			m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
			m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
			break;
		}
	}
}

void MainScene::collisionDetection()
{
	//�������зǿ��еĵл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free)
		{
			//���зɻ� ��ת��һ��ѭ��
			continue;
		}

		//�������� �ǿ��е��ӵ�
		for (int j = 0; j < BULLET_NUM; j++)
		{
			if (m_hero.m_bullets[j].m_Free)
			{
				//�����ӵ� ��ת��һ��ѭ��
				continue;
			}

			//����ӵ����ο�͵л����ο��ཻ��������ײ��ͬʱ��Ϊ����״̬����
			if (m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
			{
				m_enemys[i].m_Free = true;
				m_hero.m_bullets[j].m_Free = true;
				
				for (int k = 0; k < BOMB_NUM; k++)
				{
					if (m_bombs[k].m_Free)
					{
						//������Ч
						Boomplayer->play();
						//��ը״̬����Ϊ�ǿ���
						m_bombs[k].m_Free = false;
						//��������

						m_bombs[k].m_X = m_enemys[i].m_X;
						m_bombs[k].m_Y = m_enemys[i].m_Y;
						break;
					}
				}
			}
		}
	}


}