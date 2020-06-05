#ifndef TOWER_H
#define TOWER_H
#include<QTimer>
#include <QObject>
#include <QPixmap>
#include <QPainter>
#include "enemy.h"
#include<QList>
class Enemy;

class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos,QString pix=":/image/IMG_0464-2.png",int dam=2, int attackrange=100, int attackrate=1000);
    void drawer(QPainter *painter);
    void drawRange(QPainter *painter);
    void attack();
    void attackChoose(Enemy *enemy);
    void checkInRange();
    void lostSight();
    bool hasShowRange() const;
    void setHasShowRange(bool hasShowRange = true);
    bool distoCircle(QPoint p1, double r1, QPoint p2, double r2);
    QPoint getPos() const;
signals:

public slots:

private:
    QPoint _pos;
    QString pixmap;
    int attackRange;
    int damage;
    int attackRate;
    bool _hasShowRange;
    QTimer* shootTimer;
    QList<Enemy*>enemy_list;
    Enemy* targetEnemy;
};

#endif // TOWER_H
