#ifndef TERTIARY_H
#define TERTIARY_H

#include "colortype.h"
#include "primary.h"
#include "secondary.h"

class Tertiary: public ColorType{
public:
    ~Tertiary() {}
    Tertiary(unsigned int,unsigned int,unsigned int);
    //getPrimary lo eredita da ColorType
    Secondary* getSecondary() const;
};

#endif // TERTIARY_H
