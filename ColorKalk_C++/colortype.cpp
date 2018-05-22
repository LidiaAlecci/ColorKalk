#include "colortype.h"
#include "tertiary.h"
#include "primary.h"
#include "secondary.h"

ColorType::ColorType(unsigned int red,unsigned int green,unsigned int blue) : Color(red,green,blue) {}

ColorType::~ColorType() {}

ColorType* ColorType::getFirstPrimary() const{
    unsigned int red=getRed(), green=getGreen(), blue=getBlue();
    if(red!=0)
        return new Primary(red,0,0);
    if(green!=0)
        return new Primary(0,green,0);
    else //rientra in questo caso anche il nero
        return new Primary(0,0,blue);
}

ColorType* ColorType::buildColorType(Color* c) const{
    unsigned int red=c->getRed(), green=c->getGreen(), blue=c->getBlue();
    if(c->is_Primary()){
        return new Primary(red,green,blue);
    }else if(c->is_Secondary()){
        return new Secondary(red,green,blue);
    }else{
        return new Tertiary(red,green,blue);
    }
}

ColorType* ColorType::operator+(const Color& c2) const{
    Color* c=Color::operator+(c2);
    return buildColorType(c);
}

ColorType* ColorType::operator-(const Color& c2) const{
    Color* c=Color::operator-(c2);
    return buildColorType(c);
}

ColorType* ColorType::complementary() const{
    Color* c=Color::complementary();
    return buildColorType(c);
}

ColorType* ColorType::MaxIntensity() const{
    Color* c=Color::MaxIntensity();
    return buildColorType(c);
}

ColorType* ColorType::MinIntensity() const{
    Color* c=Color::MinIntensity();
    return buildColorType(c);
}

ColorType* ColorType::LucePura() const{
    Color* c=Color::LucePura();
    return buildColorType(c);
}

