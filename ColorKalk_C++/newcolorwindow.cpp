#include "newcolorwindow.h"
#include<QGridLayout>
#include<QLabel>
#include<QValidator>
#include"calculator.h"

void NewColorWindow::createButton(){
    int red=le1->text().toInt(), green=le2->text().toInt(),blue=le3->text().toInt();
    cb= new ColorButton(Color(red,green,blue),this);
    signalMapper->setMapping(add,cb);
}

NewColorWindow::NewColorWindow(QWidget *parent): QDialog(parent){
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);// elimina l'help button dalla QDialog
    cb=0;
    QGridLayout* lay=new QGridLayout(this);
    QLabel* l1=new QLabel("Inserisci un nuovo colore:");
    lay->addWidget(l1,0,0,1,7);
    QLabel* l2=new QLabel("rgb : (");
    le1=new QLineEdit("0");
    QValidator *validator = new QIntValidator(0, 255,lay);
    le1->setValidator(validator);
    le1->setFixedWidth(30);
    le2=new QLineEdit("0");
    le2->setValidator(validator);
    le2->setFixedWidth(30);
    le3=new QLineEdit("0");
    le3->setValidator(validator);
    le3->setFixedWidth(30);
    lay->addWidget(l2,1,0);
    lay->addWidget(le1,1,1);
    lay->addWidget(new QLabel(","),1,2);
    lay->addWidget(le2,1,3);
    lay->addWidget(new QLabel(","),1,4);
    lay->addWidget(le3,1,5);
    lay->addWidget(new QLabel(")"),1,6);
    add=new QPushButton("Inserisci");

    signalMapper= new QSignalMapper(this);
    connect(add,SIGNAL(clicked()), this, SLOT(createButton()));
    connect(add,SIGNAL(clicked()),signalMapper, SLOT(map()));
    Calculator* c=dynamic_cast<Calculator*>(parent);
    connect(signalMapper,SIGNAL(mapped(QWidget*)), c, SLOT(createNewColor(QWidget*)));

    QPushButton* ann=new QPushButton("Chiudi");
    connect(ann,SIGNAL(clicked()),this,SLOT(close()));
    lay->addWidget(add,2,0,1,3);
    lay->addWidget(ann,2,3,1,3);
    setLayout(lay);
    setWindowTitle("Nuovo Colore");
}

