#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
   MyButton(QString pix);
   void zoomdown();
   void zoomup();

signals:

public slots:
};

#endif // MYBUTTON_H
