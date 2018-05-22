#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "colortype.h"
#include "colorbutton.h"
#include <qpushbutton.h>
#include <qgridlayout.h>
#include "paneldetails.h"
#include <QMessageBox>


class Calculator: public QWidget{
  Q_OBJECT

  public slots:
    void clear();
    void clearAll();
    void equalClicked();
    void colorClicked();
    void complClicked();
    void luceClicked();
    void minIntClicked();
    void maxIntClicked();
    void plusClicked();
    void minClicked();
    void get1Clicked();
    void get2Clicked();
    void secClicked();
    void createNewColor(QWidget *);
    void newColorClicked();
    bool thereIsFactor();
private:
    void setFactor(ColorButton*);
    void updateSumSoFar();
    bool addHistory();
    void compact();
    void clearHistory();
    void updateDetails();

    ColorButton* digitButtons[7];//7 colori già disponibili
    QPushButton* NewColor;
    QPushButton* Compl;
    QPushButton* Luce;
    QPushButton* MinInt;
    QPushButton* MaxInt;
    QPushButton* Plus;
    QPushButton* Clear;
    QPushButton* ClearAll;
    QPushButton* Min;
    QPushButton* Equal;
    QPushButton* Get1Prim;
    QPushButton* Get2Prim;
    QPushButton* GetSec;

    ColorType* SumSoFar;
    ColorType* CTFactor;
    QGridLayout* window;
    ColorButton* Factor;
    PanelDetails* dettagli;
    int pos;
    QMessageBox msgBox;
public:
    Calculator(QWidget* parent = 0);
    ~Calculator();
};

#endif // CALCULATOR_H
