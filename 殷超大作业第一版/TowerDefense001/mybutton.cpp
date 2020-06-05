#include "mybutton.h"
#include <QPixmap>
#include <QPropertyAnimation>
MyButton::MyButton(QString pix):QPushButton(0){
    QPixmap pixmap(pix);
    setFixedSize(pixmap.width(),pixmap.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(pixmap);
    setIconSize(QSize(pixmap.width(),pixmap.height()));
}
void MyButton::zoomdown(){
    QPropertyAnimation*anima=new QPropertyAnimation(this,"geometry");
    anima->setDuration(200);
    anima->setStartValue(QRect(x(),y(),width(),height()));
    anima->setEndValue(QRect(x(),y()+5,width(),height()));
    anima->setEasingCurve(QEasingCurve::OutBounce);
    anima->start();
}
void MyButton::zoomup(){
    QPropertyAnimation*anima=new QPropertyAnimation(this,"geometry");
    anima->setDuration(200);
    anima->setStartValue(QRect(x(),y()+5,width(),height()));
    anima->setEndValue(QRect(x(),y(),width(),height()));
    anima->setEasingCurve(QEasingCurve::OutBounce);
    anima->start();
}
