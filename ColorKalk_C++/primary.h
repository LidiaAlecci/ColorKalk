#ifndef PRIMARY_H
#define PRIMARY_H

#include "colortype.h"

class Primary: public ColorType {
public:
    ~Primary() {}
    Primary(unsigned int=0,unsigned int=0,unsigned int=0);
    //getPrimary lo eredita da ColorType
};

#endif // PRIMARY_H
