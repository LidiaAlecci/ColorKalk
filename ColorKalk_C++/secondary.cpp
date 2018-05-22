#include "secondary.h"

Secondary::Secondary(unsigned int red,unsigned int green,unsigned int blue) : ColorType(red,green,blue){}

Primary* Secondary::getSecondPrimary() const{
    unsigned int red=getRed(), green=getGreen(), blue=getBlue();
    if(red!=0 && green!=0)
        return new Primary(0,green,0);
    else
        return new Primary(0,0,blue);

}
