#include <QApplication>
#include "calculator.h"
#include "tertiary.h"
#include <QGridLayout>
#include <QLabel>
#include"newcolorwindow.h"

void Calculator::clear(){
    if(Factor){
        delete Factor;
        Factor=0;
    }
    if(CTFactor){
        delete CTFactor;
        CTFactor=0;
    }
    dettagli->clear();
    Get2Prim->setEnabled(true);
    GetSec->setEnabled(true);
}

void Calculator::clearHistory(){
    for(int i=1;i<pos+1;i++){
        delete ((window->itemAtPosition(0,i))->widget());
    }
    pos=0;
}

void Calculator::clearAll(){
    clear();
    delete SumSoFar;
    SumSoFar=new Primary(0,0,0);
    clearHistory();
}

void Calculator::updateDetails(){
    if(dynamic_cast<Primary*>(CTFactor)){
        dettagli->set_ty("primario");
        dettagli->changeColor_p(*CTFactor);
        dettagli->set_ty1("primario");
        Get2Prim->setEnabled(false);
        GetSec->setEnabled(false);
    }else if(dynamic_cast<Secondary*>(CTFactor)){
        dettagli->set_ty("secondario");
        ColorType* temp=CTFactor->getFirstPrimary();
        dettagli->changeColor_p(*temp);
        dettagli->set_ty1("primario");
        delete temp;
        temp=(static_cast<Secondary*>(CTFactor))->getSecondPrimary();
        dettagli->changeColor_s(*temp);
        dettagli->set_ty2("primario");
        delete temp;
        GetSec->setEnabled(false);
    }else{
        dettagli->set_ty("terziario");
        ColorType* temp=CTFactor->getFirstPrimary();
        dettagli->changeColor_p(*temp);
        dettagli->set_ty1("primario");
        delete temp;
        temp=(static_cast<Tertiary*>(CTFactor))->getSecondary();
        dettagli->changeColor_s(*temp);
        dettagli->set_ty2("secondario");
        Get2Prim->setEnabled(false);
    }
    dettagli->set_perc(QString::number(CTFactor->luminance()));
}

void Calculator::setFactor(ColorButton* cb){
    if(Factor)
        clear();
    Color c=cb->getColor();
    Factor= new ColorButton(c);
    if(c.is_Primary()){
        CTFactor=new Primary(c.getRed(),c.getGreen(),c.getBlue());
    }else if(c.is_Secondary()){
        CTFactor=new Secondary(c.getRed(),c.getGreen(),c.getBlue());
    }else{
        CTFactor=new Tertiary(c.getRed(),c.getGreen(),c.getBlue());
    }
    updateDetails();
    window->addWidget(Factor, 1,7);
}

void Calculator::colorClicked(){
    ColorButton* cb=dynamic_cast<ColorButton*>(sender());
    if(cb){
        setFactor(cb);
    }
}

void Calculator::createNewColor(QWidget* w){
    ColorButton* cb=dynamic_cast<ColorButton*>(w);
    if(cb){
        setFactor(cb);
    }
    delete cb;
}

void Calculator::equalClicked(){
    if(pos){
        if(Factor){
            updateSumSoFar();
        }
        ColorButton* cb=new ColorButton(*SumSoFar);
        clearAll();
        setFactor(cb);
        delete cb;
    }
}

bool Calculator::thereIsFactor(){
    if(CTFactor){
        return true;
    }else{
        msgBox.exec();
        return false;
    }
}

void Calculator::complClicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        Color* cp=c.complementary();
        ColorButton* cb= new ColorButton(*cp);
        delete cp;
        createNewColor(cb);
    }
}

void Calculator::luceClicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        Color* cp=c.LucePura();
        ColorButton* cb= new ColorButton(*cp);
        delete cp;
        createNewColor(cb);
    }
}

void Calculator::minIntClicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        Color* cp=c.MinIntensity();
        ColorButton* cb= new ColorButton(*cp);
        delete cp;
        createNewColor(cb);
    }
}

void Calculator::maxIntClicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        Color* cp=c.MaxIntensity();
        ColorButton* cb= new ColorButton(*cp);
        delete cp;
        createNewColor(cb);
    }
}

void Calculator::updateSumSoFar(){
    ColorType* temp=0;
    if(!pos){//SumSoFar se pos==0 è sempre Primary(0,0,0)
        temp=(*SumSoFar)+(*CTFactor);
        delete SumSoFar;
        SumSoFar=temp;
    }else{
        QLabel* last=dynamic_cast<QLabel*>((window->itemAtPosition(0,pos))->widget());
        if(last){
            QString s=last->text();
            if(s=="-"){
                temp=(*SumSoFar)-(*CTFactor);
                delete SumSoFar;
                SumSoFar=temp;
            }else if(s=="+"){
                temp=(*SumSoFar)+(*CTFactor);
                delete SumSoFar;
                SumSoFar=temp;
            }
        }
    }
}

void Calculator::compact(){
    clearHistory();
    ColorButton* cb= new ColorButton(*SumSoFar);
    window->addWidget(cb,0,++pos);
    QLabel* l= new QLabel("+");
    window->addWidget(l,0,++pos,1,1,Qt::AlignCenter);
}

void Calculator::plusClicked(){
    if(thereIsFactor()){
        if(pos+2>7)
            compact();
        updateSumSoFar();
        ColorButton* cb= new ColorButton(*CTFactor);
        window->addWidget(cb,0,++pos);
        QLabel* l= new QLabel("+");
        window->addWidget(l,0,++pos,1,1,Qt::AlignCenter);
        clear();
    }

}

void Calculator::minClicked(){
    if(thereIsFactor()){
        if(pos+2>7)
            compact();
        updateSumSoFar();
        ColorButton* cb= new ColorButton(*CTFactor);
        window->addWidget(cb,0,++pos);
        QLabel* l= new QLabel("-");
        window->addWidget(l,0,++pos,1,1,Qt::AlignCenter);
        clear();
    }
}

void Calculator::get1Clicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        ColorType* ct=CTFactor->getFirstPrimary();
        ColorButton* cb= new ColorButton(*ct);
        delete ct;
        createNewColor(cb);
    }
}

void Calculator::get2Clicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        if(c.is_Secondary()){
            ColorType* ct=(static_cast<Secondary*>(CTFactor))->getSecondPrimary();
            ColorButton* cb= new ColorButton(*ct);
            delete ct;
            createNewColor(cb);
        }
    }
}

void Calculator::secClicked(){
    if(thereIsFactor()){
        Color c=Factor->getColor();
        if(c.is_Tertiary()){
            ColorType* ct=(static_cast<Tertiary*>(CTFactor))->getSecondary();
            ColorButton* cb= new ColorButton(*ct);
            delete ct;
            createNewColor(cb);
        }
    }
}

void Calculator::newColorClicked(){
    NewColorWindow* ncw=new NewColorWindow(this);
    ncw->show();
}

Calculator::Calculator(QWidget *parent): QWidget(parent){
    setWindowIcon(QIcon(":/images/interface.png"));
    SumSoFar= new Primary(0,0,0);
    CTFactor=0;
    Factor=0;
    pos=0;
    msgBox.setText("Devi selezionare un colore prima!");
    msgBox.setWindowTitle("Attenzione!");

    digitButtons[0]= new ColorButton(Color(112,219,147));
    digitButtons[1]= new ColorButton(Color(99,86,136));
    digitButtons[2]= new ColorButton(Color(255,211,155));
    digitButtons[3]= new ColorButton(Color(255,0,0));
    digitButtons[4]= new ColorButton(Color(30,97,178));
    digitButtons[5]= new ColorButton(Color(255,127,0));
    digitButtons[6]= new ColorButton(Color(255,185,15));

    for(int i=0; i<7; i++){
        digitButtons[i]->setEnabled(true);
        connect(digitButtons[i],SIGNAL(clicked()),this,SLOT(colorClicked()));
    }
    NewColor=new QPushButton("Nuovo\nColore");
    NewColor->setFixedSize(60,60);
    QApplication::connect(NewColor, SIGNAL(clicked()),this,SLOT(newColorClicked()));
    Compl=new QPushButton("Compl");
    Compl->setFixedSize(60,60);
    connect(Compl,SIGNAL(clicked()),this,SLOT(complClicked()));
    Luce=new QPushButton("Luce\nPura");
    Luce->setFixedSize(60,60);
    connect(Luce,SIGNAL(clicked()),this,SLOT(luceClicked()));
    MinInt=new QPushButton("Min\nInt");
    MinInt->setFixedSize(60,60);
    connect(MinInt,SIGNAL(clicked()),this,SLOT(minIntClicked()));
    MaxInt=new QPushButton("Max\nInt");
    MaxInt->setFixedSize(60,60);
    connect(MaxInt,SIGNAL(clicked()),this,SLOT(maxIntClicked()));
    Plus=new QPushButton("+");
    Plus->setFixedSize(60,60);
    connect(Plus,SIGNAL(clicked()),this,SLOT(plusClicked()));
    Clear=new QPushButton("Clear");
    Clear->setFixedSize(60,60);
    connect(Clear,SIGNAL(clicked()),this,SLOT(clear()));
    ClearAll=new QPushButton("Clear\nAll");
    ClearAll->setFixedSize(60,60);
    connect(ClearAll,SIGNAL(clicked()),this,SLOT(clearAll()));
    Min=new QPushButton("-");
    Min->setFixedSize(60,60);
    connect(Min,SIGNAL(clicked()),this,SLOT(minClicked()));
    Equal=new QPushButton("=");
    Equal->setFixedSize(60,60);
    connect(Equal,SIGNAL(clicked()),this,SLOT(equalClicked()));
    Get1Prim=new QPushButton("1°\nPrim");
    Get1Prim->setFixedSize(60,60);
    connect(Get1Prim,SIGNAL(clicked()),this,SLOT(get1Clicked()));
    Get2Prim=new QPushButton("2°\nPrim");
    Get2Prim->setFixedSize(60,60);
    connect(Get2Prim,SIGNAL(clicked()),this,SLOT(get2Clicked()));
    GetSec=new QPushButton("Second");
    GetSec->setFixedSize(60,60);
    connect(GetSec,SIGNAL(clicked()),this,SLOT(secClicked()));

    window=new QGridLayout();
    /*          DISPLAY             */

    QLabel* t1=new QLabel("Operazioni");
    QLabel* t2=new QLabel("Fattore");
    t1->setFixedSize(80,60);
    t2->setFixedSize(80,60);
    window->addWidget(t1,0,0,1,1, Qt::AlignCenter);
    window->addWidget(t2,1,0,1,1, Qt::AlignCenter);


    /*          PANNELLO DETTAGLI   */
    dettagli=new PanelDetails("Dettagli Colore",this);
    window->addWidget(dettagli, 4, 0,3,4);

    /*          TASTIERINO          */
    window->addWidget(Compl, 4, 4);
    window->addWidget(Luce, 3, 3);
    window->addWidget(MinInt, 3, 4);
    window->addWidget(MaxInt, 3, 5);
    window->addWidget(Plus, 4, 7);
    window->addWidget(Get1Prim, 3, 0);
    window->addWidget(Get2Prim, 3, 1);
    window->addWidget(GetSec, 3, 2);
    window->addWidget(Clear, 3, 6);
    window->addWidget(ClearAll, 3, 7);
    window->addWidget(Min, 5, 7);
    window->addWidget(NewColor, 6, 6);
    window->addWidget(Equal, 6, 7);
    window->addWidget(digitButtons[0],4, 5);
    window->addWidget(digitButtons[1],4, 6);
    window->addWidget(digitButtons[2],5, 4);
    window->addWidget(digitButtons[3],5, 6);
    window->addWidget(digitButtons[4],6, 4);
    window->addWidget(digitButtons[5],6, 5);
    window->addWidget(digitButtons[6],5, 5);
    setLayout(window);

    setWindowTitle("ColorKalk");
}

Calculator::~Calculator(){
    delete SumSoFar;
    delete CTFactor;
}
