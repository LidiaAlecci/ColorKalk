#include "color.h"
#include "funzioni_ausiliari.cpp"
#include <iostream>
#include <primary.h>

std::ostream& operator<<(std::ostream& os, const Color& c){
    os<<"rgb("<<c.r<<","<<c.g<<","<<c.b<<")";
    return os;
}

Color::Color(unsigned int red, unsigned int green, unsigned int blue): r(red), g(green), b(blue){
    if(red>255) r=255;
    if(green>255) g=255;
    if(blue>255) b=255;
}

Color* Color::complementary() const{
    return new Color(255-r, 255-g, 255-b);
}

double Color::luminance() const{
    return ((0.299*r+0.587*g+0.114*b)/255)*100;
}

unsigned int Color::getRed() const{
    return r;
}

unsigned int Color::getGreen() const{
    return g;
}

unsigned int Color::getBlue() const{
    return b;
}

Color* Color::operator+(const Color& c2) const{
    unsigned int red=r+c2.getRed(), green=g+c2.getGreen(), blue=b+c2.getBlue();
    return new Color(red,green,blue);
}

Color* Color::operator-(const Color& c2) const{
    unsigned int red, green, blue;
    int difRed=r-c2.getRed(), difGreen=g-c2.getGreen(), difBlue=b-c2.getBlue();
    if(difRed<0) red=0;
    else red=difRed;
    if(difGreen<0) green=0;
    else green=difGreen;
    if(difBlue<0) blue=0;
    else blue=difBlue;
    return new Color(red,green,blue);
}

double Color::CpM() const{
    return ((max(r,g,b))/255.0);
}

Color* Color::MaxIntensity() const{
    double cpm=CpM();
    double red=cpm*r, green=cpm*g, blue=cpm*b;
    return new Color(red,green,blue);
}

Color* Color::MinIntensity() const{
    unsigned int minimo=min(r,g,b);
    return new Color(r-minimo,g-minimo,b-minimo);
}

Color* Color::LucePura() const{
    unsigned int minimo=min(r,g,b);
    unsigned int red=r-minimo ,green=g-minimo, blue=b-minimo;
    unsigned int mass=max(r,g,b);
    if(mass==0)// se il colore è il nero allora ritorna il nero
        return new Color(0,0,0);
    //altrimenti
    if(red==mass){
        red=255;
        if(g==0){
            double d=b*(255/mass);//passaggio necessario per evitare troncamenti non voluti
            blue=d;
        }else{
            double d=g*(255/mass);
            green=d;
        }
    }else if(blue==mass){
        blue=255;
        if(g==0){
            double d=r*(255/mass);
            red=d;
        }else{
            double d=g*(255/mass);
            green=d;
        }
    }else{
        green=255;
        if(b==0){
            double d=r*(255/mass);
            red=d;
        }else{
            double d=b*(255/mass);
            blue=d;
        }
    }
    return new Color(red,green,blue);
}

bool Color::is_Primary() const{
    if((r!=0 && b==0 && g==0) ||
            (b!=0 && r==0 && g==0) ||
            (g!=0 && b==0 && r==0) ||
            (b==0 && g==0 &&r==0) )//se e' nero e' considerato lo stesso primario
        return true;
    else
        return false;
}
bool Color::is_Secondary() const{
    if((r!=0 && b!=0 && g==0) ||
            (g!=0 && r!=0 && b==0) ||
            (g!=0 && b!=0 && r==0) )
        return true;
    else
        return false;

}
bool Color::is_Tertiary() const{
    if( r!=0 && b!=0 && g!=0)//contiene tutti e tre i colori primari
        return true;
    else
        return false;
}
