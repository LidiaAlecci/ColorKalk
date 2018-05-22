#include "colorbutton.h"
#include <iostream>

ColorButton::ColorButton(const Color& c, QWidget* parent): QPushButton(parent), col(c){
    int red=c.getRed(), green=c.getGreen(), blue=c.getBlue();
    QString string="background-color: rgb(";
    string.append(QString::number(red)); string.append(", ");
    string.append(QString::number(green)); string.append(", ");
    string.append(QString::number(blue)); string.append(");");
    setStyleSheet(string);
    setFixedSize(60,60);
    setEnabled(false);

}

Color ColorButton::getColor() const{
    return Color(col.getRed(),col.getGreen(),col.getBlue());
}

void ColorButton::changeColor(const Color& c){
    int red=c.getRed(), green=c.getGreen(), blue=c.getBlue();
    QString string="background-color: rgb(";
    string.append(QString::number(red)); string.append(", ");
    string.append(QString::number(green)); string.append(", ");
    string.append(QString::number(blue)); string.append(");");
    setStyleSheet(string);
    setFixedSize(50,50);
    setEnabled(false);
    col=Color(red,green,blue);
}
