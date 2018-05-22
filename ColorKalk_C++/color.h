#ifndef COLOR_H
#define COLOR_H

#include<iostream>

class Color{
    friend std::ostream& operator<<(std::ostream&, const Color&);
private:
    unsigned int r;
    unsigned int g;
    unsigned int b;
public:
    Color(unsigned int=0,unsigned int=0,unsigned int=0);//controllo che r,g,b siano <= 255
    //Costruttore di copia e assegnazione vanno bene quelli standard
    virtual ~Color() {}
    double luminance() const;//luminanza in percentuale
    double CpM() const;//ritorna il coefficiente proporzionale minimo (e' necessario per la funzione MaxIntensity())
    virtual Color* operator+(const Color&) const;
    virtual Color* operator-(const Color&) const;
    virtual Color* complementary() const;//ritorna il colore complementare
    virtual Color* MaxIntensity() const;//ritorna il colore che e' la massima intensita'  dell'oggetto di invocazione
    virtual Color* MinIntensity() const;//ritorna il colore con la minima intensita'  dell'oggetto di invocazione
    virtual Color* LucePura() const;//ritorna il corrispettivo colore che rappresenta la Luce Pura a partire dall'oggetto di invocazione

    unsigned int getRed() const;
    unsigned int getGreen() const;
    unsigned int getBlue() const;

    bool is_Primary() const;
    bool is_Secondary() const;
    bool is_Tertiary() const;
};

std::ostream& operator<<(std::ostream&, const Color&);

#endif // COLOR_H
