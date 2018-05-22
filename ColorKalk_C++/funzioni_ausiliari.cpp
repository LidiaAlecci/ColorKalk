
unsigned int max(unsigned int a, unsigned int b, unsigned int c){//ritorna il massimo tra tre unsigned int
    if(a>=b && a>=c)
        return a;
    else if(b>=a && b>=c)
        return b;
    else
        return c;
}

unsigned int min(unsigned int a, unsigned int b, unsigned int c){//ritorna il minimo tra tre unsigned int
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}
