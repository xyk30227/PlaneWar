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
	
	//敌机数组
	EnemyPlane m_enemys[ENEMY_NUM];

	//敌机出场间隔记录
	int m_recorder;

	//爆炸数组
	Boom m_bombs[BOMB_NUM];
public:
	MainScene(QWidget *parent = Q_NULLPTR);

	void initScene();

	void playGame();

	void updatePosition();

	//
	void paintEvent(QPaintEvent *event);

	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent *event);

	//敌机出场
	void enemyToScene();

	void collisionDetection();

	QMediaPlayer *BGplayer;
	QMediaPlayer *Boomplayer;
private:
	Ui::MainSceneClass ui;
};
