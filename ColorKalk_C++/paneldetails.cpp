#include "paneldetails.h"
#include <QGridLayout>
#include "colorbutton.h"
#include <QLineEdit>
#include <QLabel>

void PanelDetails::clear(){
    ty->setText("");
    p->changeColor(Color(232,229,229));
    s->changeColor(Color(232,229,229));
    ty1->setText("");
    ty2->setText("");
    perc->setText("");
}

void PanelDetails::set_ty(const QString& s){
    ty->setText(s);
}

void PanelDetails::set_ty1(const QString& s){
    ty1->setText(s);
}

void PanelDetails::set_ty2(const QString& s){
    ty2->setText(s);
}

void PanelDetails::set_perc(const QString& s){
    perc->setText(s);
}

void PanelDetails::changeColor_p(const Color& c){
    p->changeColor(c);
}

void PanelDetails::changeColor_s(const Color& c){
    s->changeColor(c);
}

PanelDetails::PanelDetails(QString name, QWidget* parent): QGroupBox(name,parent){
    setFixedSize(240,200);
    QGridLayout* dett= new QGridLayout(this);
    /* prima riga relativa al tipo */
    QLabel* type= new QLabel("Il colore è un: ");
    ty=new QLineEdit("");
    ty->setReadOnly(true);
    ty->setStyleSheet("background-color: rgb(232, 229, 229);");
    ty->setFixedSize(90,25);
    dett->addWidget(type, 0, 0);
    dett->addWidget(ty, 0, 1,  1, 2);
    /*seconda riga */
    QLabel* f= new QLabel("ed è formato da:");
    dett->addWidget(f, 2,0,1,3);
    /* terza riga */
    p=new ColorButton(Color(232,229,229));
    p->setFixedSize(50,50);
    dett->addWidget(p, 3, 0,1,1, Qt::AlignCenter);
    QLabel* plus= new QLabel("+");
    dett->addWidget(plus, 3, 1, 1,1 ,Qt::AlignCenter);
    s=new ColorButton(Color(232,229,229));
    s->setFixedSize(50,50);
    dett->addWidget(s, 3, 2,1,1, Qt::AlignCenter);
    /* quarta riga */
    ty1=new QLineEdit("");
    ty1->setReadOnly(true);
    ty1->setStyleSheet("background-color: rgb(232, 229, 229);");
    ty1->setFixedSize(90,25);
    dett->addWidget(ty1, 4, 0);
    ty2=new QLineEdit("");
    ty2->setReadOnly(true);
    ty2->setStyleSheet("background-color: rgb(232, 229, 229);");
    ty2->setFixedSize(90,25);
    dett->addWidget(ty2, 4, 2);
    /* quinta riga */
    setLayout(dett);
    QLabel* lum=new QLabel("Luminosità = ");
    dett->addWidget(lum,5,0);
    perc=new QLineEdit("");
    perc->setReadOnly(true);
    perc->setStyleSheet("background-color: rgb(232, 229, 229);");
    dett->addWidget(perc, 5, 2);
    QLabel* per=new QLabel("%");
    dett->addWidget(per,5,3);
}

