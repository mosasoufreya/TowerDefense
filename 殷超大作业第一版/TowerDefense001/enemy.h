#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QPainter>
#include <QPixmap>
#include <QPropertyAnimation>
#include "tower.h"
#include"waypoint.h"

class Tower;
class WayPoint;
class Enemy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentPos READ getCurrentPos WRITE setCurrentPos)
public:
    Enemy(int speed=10,int hp=5, QString pic="IMG_0455-2.png");
    void drawer(QPainter *painter);
    void move();
    void setCurrentPos(QPoint pos);
    QPoint getCurrentPos();
    void lostSight(Tower *attacker);
    void getAttack(Tower *attacker);
    bool distoCircle(QPoint p1, double r1, QPoint p2, double r2);
    void getDamage(int dam);


private:
    QPoint curpoint;
    QPixmap pix;
    QList<Tower *>	attacker_list;
    bool active;
    WayPoint *waypoint;
    QList<WayPoint *> waypoint_list;
    int HP;
    int curHP;
    int Speed;
    int damage;


signals:

public slots:
    void doActive();
};

#endif // ENEMY_H
