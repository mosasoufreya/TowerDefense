#include "tower.h"
#include <QPixmap>
#include <QPainter>
#include<QTimer>
#include"enemy.h"
#include<QList>
#include<cmath>

Tower::Tower(QPoint pos,QString pix,int dam, int attackrange, int attackrate)
    : QObject(0),_pos(pos),pixmap(pix),attackRange(attackrange), attackRate(attackrate), _hasShowRange(false), damage(dam),targetEnemy(NULL){
   shootTimer = new QTimer(this);
   connect(shootTimer, SIGNAL(timeout()), this, SLOT(fireBullet()));
}
void Tower::drawer(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);
}
void Tower:: drawRange(QPainter *painter){
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::white);
    painter->drawEllipse(this->_pos, this->attackRange, this->attackRange);

}

void Tower::attack()
{
    shootTimer->start(500);
}

void Tower::attackChoose(Enemy *enemy)
{
    targetEnemy = enemy;
    attack();
    targetEnemy->getAttack(this);
}

void Tower::checkInRange(){
    foreach (Enemy *enemy, enemy_list)
    {
        if (distoCircle(_pos, attackRange, enemy->getCurrentPos(), 1))
        {
            attackChoose(enemy);
            targetEnemy=enemy;
            break;
        }
    }
}

void Tower::lostSight()
{
    targetEnemy->lostSight(this);
    if (targetEnemy)
        targetEnemy = NULL;

    shootTimer->stop();

}



bool Tower::distoCircle(QPoint p1, double r1, QPoint p2, double r2)
{
    const double deltaX = p1.x() - p2.x();
    const double deltaY = p1.y() - p2.y();
    const double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if(distance < r1 + r2)
        return true;

    return false;
}


bool Tower::hasShowRange() const
{
    return this->_hasShowRange;
}


void Tower::setHasShowRange(bool hasShowRange)
{
    this->_hasShowRange = hasShowRange;
}
QPoint Tower::getPos() const{
    return _pos;
}
