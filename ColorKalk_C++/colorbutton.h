#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>
#include "color.h"

class ColorButton: public QPushButton{
public:
    ColorButton(const Color& =Color(0,0,0), QWidget* parent = 0);
    Color getColor() const;
    void changeColor(const Color&);
private:
    Color col;
};

#endif // COLORBUTTON_H
