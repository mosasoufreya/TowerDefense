#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:
    void chooseBack();

public slots:
};

#endif // MYWINDOW_H
