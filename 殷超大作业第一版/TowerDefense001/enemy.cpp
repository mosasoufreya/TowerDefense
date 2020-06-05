#include "enemy.h"
#include "tower.h"
#include"cmath"
#include "waypoint.h"
Enemy::Enemy( int speed,int hp, QString pic)
    :QObject(0),HP(hp),pix(pic),Speed(speed)
{
  active=false;
  curHP=HP;
  damage=0;
}
void Enemy:: drawer(QPainter *painter){
    painter->drawPixmap(curpoint,pix);
}
void Enemy::move(){
    if (!active)
        return;

    if ((curpoint, 1, waypoint->pos(), 1))
    {

        if (waypoint->nextWayPoint())
        {
            curpoint = waypoint->pos();
            waypoint = waypoint->nextWayPoint();
        }

    }


    QPoint targetPoint = waypoint->pos();
    qreal movementSpeed = Speed;
    QVector2D normalized(targetPoint - curpoint);
    normalized.normalize();
       curpoint += normalized.toPoint() * movementSpeed * 0.5;

}
void Enemy::setCurrentPos(QPoint pos){
    curpoint=pos;
}
QPoint Enemy::getCurrentPos(){
    return curpoint;
}
void Enemy::lostSight(Tower *attacker)
{
    attacker_list.removeOne(attacker);
}

void Enemy::getAttack(Tower *attacker)
{
    attacker_list.push_back(attacker);
}
void Enemy::doActive(){
    active=true;
}
bool Enemy::distoCircle(QPoint p1, double r1, QPoint p2, double r2)
{
    const double deltaX = p1.x() - p2.x();
    const double deltaY = p1.y() - p2.y();
    const double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if(distance < r1 + r2)
        return true;

    return false;
}

void Enemy::getDamage(int dam)
{    damage=dam;
     curHP=curHP-damage;

}
