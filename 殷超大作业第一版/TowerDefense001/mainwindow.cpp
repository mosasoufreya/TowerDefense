#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include"menu.h"
#include"mybutton.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setFixedSize(1200,600);
    ui->setupUi(this);

   MyButton*bin1=new MyButton(":/image/IMG_0450-2.png");//quit按钮
   bin1->setParent(this);
   bin1->move(800,300);
   connect(bin1,&MyButton::clicked,this,[=](){
       bin1->zoomdown();
       bin1->zoomup();
       QTimer::singleShot(500,this,[=](){
           this->close();
   });
  });

   MyButton*bin2=new MyButton(":/image/IMG_0449-2.png");//start按钮
   bin2->setParent(this);
   bin2->move(220,320);
   Menu*scene=new Menu;
   connect(bin2,&QPushButton::clicked,this,[=](){
       bin2->zoomdown();
       bin2->zoomup();
       QTimer::singleShot(500,this,[=](){
           this->close();
           scene->show();
       });
   });
   connect(scene,&Menu::chooseBack,this,[=](){
       scene->hide();
       show();
   });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
   QPainter painter(this);
   QPixmap pixmap(":/image/IMG_7864.PNG");
   painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


}
