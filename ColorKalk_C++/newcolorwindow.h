#ifndef NEWCOLORWINDOW_H
#define NEWCOLORWINDOW_H

#include<QDialog>
#include<QLineEdit>
#include<QSignalMapper>
#include"colorbutton.h"

class NewColorWindow: public QDialog{
    Q_OBJECT
public:
    NewColorWindow(QWidget*);
private:
    QLineEdit* le1;
    QLineEdit* le2;
    QLineEdit* le3;
    ColorButton* cb;
    QSignalMapper* signalMapper;
    QPushButton* add;
public slots:
    void createButton();
};

#endif // NEWCOLORWINDOW_H
