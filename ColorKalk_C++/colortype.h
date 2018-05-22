#ifndef COLORTYPE_H
#define COLORTYPE_H

#include "color.h"

class ColorType: public Color{
public:
    ColorType(unsigned int=0,unsigned int=0,unsigned int=0);
    ~ColorType() =0; // per rendere la classe astratta
    virtual ColorType* getFirstPrimary() const;
    ColorType* operator+(const Color&) const;
    ColorType* operator-(const Color&) const;
    ColorType* complementary() const;//ritorna il colore complementare
    ColorType* MaxIntensity() const;//ritorna il colore che e' la massima intensita'  dell'oggetto di invocazione
    ColorType* MinIntensity() const;//ritorna il colore con la minima intensita'  dell'oggetto di invocazione
    ColorType* LucePura() const;
private:
    ColorType* buildColorType(Color*) const;
};

#endif // COLORTYPE_H
