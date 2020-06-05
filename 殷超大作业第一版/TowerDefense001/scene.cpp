#include "scene.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include"mybutton.h"
#include"tower.h"
#include<QList>
#include"enemy.h"
#include"towerposition.h"
#include<QPixmap>
#include"bullet.h"
#include<QPoint>
Scene::Scene(QWidget *parent) : QMainWindow(parent),wave(0),homeHP(10)
{
  setFixedSize(1200,600);
  startpoint.setX(0);
  startpoint.setY(0);
  home.setX(1000);
  home.setY(500);
  dochoose=false;

  LoadTowerPos();

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

  MyButton*tower=new MyButton(":/image/IMG_0466-2.png");//选择塔按钮
  tower->setParent(this);
  tower->move(800,0);
  connect(tower,&MyButton::clicked,this,[=](){
      tower->zoomdown();
      tower->zoomup();
      QTimer::singleShot(500,this,[=](){
      chooseTower();
  });
 });






  QTimer*timer=new QTimer(this);
  connect(timer, SIGNAL(timeout()),this,SLOT(updateMap()));
  timer->start(100);
  QTimer::singleShot(3000, this, SLOT(gamestart()));

}
void Scene::paintEvent(QPaintEvent*){
   QPainter painter(this);
   //画地图
   QPixmap pixmap(":/image/IMG_0460.PNG");
   painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
   //画塔位、敌人、子弹、塔
   for(auto &towerPosition: this->towerpos_list)
   {
       if(towerPosition.hasShow())
           towerPosition.drawer(&painter);
   }

   for(auto &enemy: this->enemy_list)
   {
       enemy->drawer(&painter);
   }

   for(auto &Tower: this->tower_list)
   {
       Tower->drawer(&painter);
       if(Tower->hasShowRange())
           Tower->drawRange(&painter);
   }
   for(auto &bullet: this->bullet_list)
   {
       bullet->drawer(&painter);
   }



}

void Scene::updateScreen(){
    for(auto &enemy: this->enemy_list)
        enemy->move();
    for(auto &tower: this->tower_list)
        tower->checkInRange();
    update();
}

//设置塔可以放置的位置
void Scene::LoadTowerPos(){
    QPoint pos[] =
    {
        //first row
        QPoint(300, 100),
        QPoint(350, 100),
        QPoint(400, 100),
        QPoint(450, 100),
        QPoint(500, 100),
        QPoint(550, 100),
        //second row
        QPoint(300, 150),
        QPoint(350, 150),
        QPoint(400, 150),
        QPoint(450, 150),
        QPoint(500, 150),
        QPoint(550, 150),
        //third row
        QPoint(400, 200),
        QPoint(450, 200),
        //fourth row
        QPoint(350, 100),
        QPoint(400, 100),
        QPoint(450, 100),
        QPoint(500, 100),
    };
    int num = sizeof(pos) / sizeof(pos[0]);

    for(int i = 0; i < num; ++ i)
        this->towerpos_list.push_back(TowerPosition(pos[i]));
}

//画towerposition

void Scene::mousePressEvent(QMouseEvent *event){
    QPoint pressPos = event->pos();
    for(auto &curPos: towerpos_list)  {
        if(curPos.inRange(pressPos))
        {
            if(curChoose)
            {
                curChoose->setHasShowRange(false);
                curChoose = NULL;
            }
            if(curPos.hasShow() && !curPos.hasTower())
            {
                curPos.setHasTower();
                Tower *tower = new Tower(curPos.getPos());
                this->tower_list.push_back(tower);
                update();
                break;

            }

            else if(curPos.hasTower())
            {
                bool break_flag = false;
                for(auto &curTower: tower_list)
                {
                    if(curTower->getPos() == curPos.getPos())
                    {
                        break_flag = true;
                        if(!curTower->hasShowRange()) {
                            curTower->setHasShowRange();
                            curChoose = curTower;
                            curtowerPos = &curPos;
                        }
                        else {
                           curTower->setHasShowRange(false);
                            if(curChoose)
                                curChoose = NULL;
                        }
                        break;
                    }
                }
                if(break_flag)
                    break;
           }
        }
        else
        {
            if(curChoose) {
                curChoose->setHasShowRange(false);
                curChoose = NULL;
            }
        }
  }
 update();

}
void Scene::updateMap()
{
    for(auto &enemy: this->enemy_list)
        enemy->move();

    for(auto &tower: this->tower_list)
        tower->checkInRange();

    update();
}

void Scene::gamestart(){
  loadWave();
}
bool Scene::loadWave(){
    if (wave >= 3)
        return false;
    int start_interval[]={100,500,1000};
    for(int i=0;i<8;++i){
        Enemy*enemy=new Enemy();
        enemy_list.push_back(enemy);
        QTimer::singleShot(start_interval[i],enemy,SLOT(doActivate()));
        wave++;
    }
    return true;
}
void Scene::chooseTower(){
    if(dochoose){
    for(auto &temp: this->towerpos_list)
    {
        temp.setHasShow();

    }
    }
    update();
}

