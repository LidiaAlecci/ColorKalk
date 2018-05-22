#include "tertiary.h"

Tertiary::Tertiary(unsigned int red,unsigned int green,unsigned int blue) : ColorType(red,green,blue){}

Secondary* Tertiary::getSecondary() const{
    return new Secondary(0,getGreen(),getBlue());
}
