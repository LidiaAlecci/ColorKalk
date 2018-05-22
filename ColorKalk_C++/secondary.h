#ifndef SECONDARY_H
#define SECONDARY_H

#include "colortype.h"
#include "primary.h"

class Secondary: public ColorType{
public:
    ~Secondary() {}
    Secondary(unsigned int=0,unsigned int=0,unsigned int=0);
    //getPrimary lo eredita da ColorType
    Primary* getSecondPrimary() const;
};

#endif // SECONDARY_H
