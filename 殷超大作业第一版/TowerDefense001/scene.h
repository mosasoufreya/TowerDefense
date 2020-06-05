#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include"tower.h"
#include<QList>
#include"enemy.h"
#include<QTimer>
#include<towerposition.h>
#include"bullet.h"
#include<QPoint>

class Scene : public QMainWindow
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void LoadTowerPos();
    void updateScreen();
    void mousePressEvent(QMouseEvent *event);
    bool loadWave();
signals:
    void chooseBack();


public slots:
    void updateMap();
    void chooseTower();
    void gamestart();
private:
    QList<Tower*> tower_list;
    QList<Enemy*>enemy_list;
    QList<TowerPosition>towerpos_list;
    QList<Bullet *>    bullet_list;
    Tower * curChoose = NULL;
    TowerPosition *curtowerPos = NULL;
    int wave;
    QPoint startpoint;
    QPoint home;
    int homeHP;
    bool dochoose;
};
#endif // SCENE_H
