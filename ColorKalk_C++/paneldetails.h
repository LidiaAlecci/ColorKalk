#ifndef PANELDETAILS_H
#define PANELDETAILS_H

#include<QGroupBox>
#include <QLineEdit>
#include "colorbutton.h"

class PanelDetails: public QGroupBox{
public:
    PanelDetails(QString="", QWidget *parent=0);
    void clear();
    void set_ty(const QString&);
    void set_ty1(const QString&);
    void set_ty2(const QString&);
    void set_perc(const QString&);
    void changeColor_p(const Color&);
    void changeColor_s(const Color&);
private:
    QLineEdit* ty;
    ColorButton* p;
    ColorButton* s;
    QLineEdit* ty1;
    QLineEdit* ty2;
    QLineEdit* perc;
};

#endif // PANELDETAILS_H
