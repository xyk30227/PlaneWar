#pragma once

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QMouseEvent>
#include "ui_MainScene.h"
#include "Map.h"
#include "HeroPlane.h"
#include "EnemyPlane.h"
#include "Bullet.h"
#include "Boom.h"
#include <QtMultimedia/QMediaPlayer>
class MainScene : public QWidget
{
	Q_OBJECT
public:
	QTimer m_Timer;

	Map m_map;
	
	HeroPlane m_hero;

	Bullet temp_bullet;	
	
	//�л�����
	EnemyPlane m_enemys[ENEMY_NUM];

	//�л����������¼
	int m_recorder;

	//��ը����
	Boom m_bombs[BOMB_NUM];
public:
	MainScene(QWidget *parent = Q_NULLPTR);

	void initScene();

	void playGame();

	void updatePosition();

	//
	void paintEvent(QPaintEvent *event);

	//����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *event);

	//�л�����
	void enemyToScene();

	void collisionDetection();

	QMediaPlayer *BGplayer;
	QMediaPlayer *Boomplayer;
private:
	Ui::MainSceneClass ui;
};
