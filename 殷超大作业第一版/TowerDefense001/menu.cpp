#include "menu.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include"menu.h"
#include"mybutton.h"
#include "scene.h"
Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
  setFixedSize(1200,600);
  MyButton*back_bin=new MyButton(":/image/IMG_0450-2.png");//返回按钮
  back_bin->setParent(this);
  back_bin->move(0,0);
  connect(back_bin,&MyButton::clicked,this,[=](){
      back_bin->zoomdown();
      back_bin->zoomup();
      QTimer::singleShot(500,this,[=](){
      emit chooseBack();
  });
 });

  MyButton*bin1=new MyButton(":/image/IMG_0461-2.png");//start按钮
  bin1->setParent(this);
  bin1->move(90,190);
  Scene*scene=new Scene;
  connect(bin1,&QPushButton::clicked,this,[=](){
      bin1->zoomdown();
      bin1->zoomup();
      QTimer::singleShot(500,this,[=](){
          this->close();
          scene->show();
      });
  });
  connect(scene,&Scene::chooseBack,this,[=](){
      scene->hide();
      show();
  });



}
void Menu::paintEvent(QPaintEvent*){
   QPainter painter(this);
   QPixmap pixmap(":/image/IMG_0457.PNG");
   painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
