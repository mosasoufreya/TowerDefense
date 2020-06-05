#include "bullet.h"

Bullet::Bullet(QPoint startpoint, QPoint targetpoint, int dam, Enemy *target,QString pic)
    : QObject(0),pix(pic),targetEnemy(target),damage(dam)
{curpoint=startpoint;
    _targetpoint=targetpoint;
    hit_target=false;

}
void Bullet:: drawer(QPainter *painter){
    painter->drawPixmap(curpoint,pix);
}
void Bullet::move(){
    QPropertyAnimation*anima=new QPropertyAnimation(this,"curpoint");
    anima->setDuration(2000);
    anima->setStartValue(_startpoint);
    anima->setEndValue(_targetpoint);
    anima->start();

}
void Bullet::setCurrentPos(QPoint pos){
    curpoint=pos;
}
QPoint Bullet::getCurrentPos(){
    return curpoint;
}
void Bullet::hitTarget(){
    hit_target=true;
}
