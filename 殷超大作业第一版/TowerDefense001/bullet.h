#ifndef BULLET_H
#define BULLET_H

#include <QPoint>

#include <QPixmap>
#include <QObject>
#include <QPainter>
#include"enemy.h"
class Enemy;
class Bullet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _currentPos READ getCurrentPos WRITE setCurrentPos)
public:
    Bullet(QPoint startPos, QPoint targetPoint, int dam, Enemy *target,QString pic="IMG_0462-2.png");
    void drawer(QPainter *painter);
    void move();
    void setCurrentPos(QPoint pos);
    QPoint getCurrentPos();

signals:


public slots:
    void hitTarget();
private:
    QPoint _startpoint;
    QPoint _targetpoint;
    QPoint curpoint;
    QPixmap pix;
    Enemy *targetEnemy;
    int	   damage;
    bool hit_target;
};

#endif // BULLET_H
