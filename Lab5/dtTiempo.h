#ifndef DTTIEMPO_H
#define DTTIEMPO_H

class DTtiempo{
private:
    int hora;
    int minuto;
public:
    DTtiempo(int, int);
    int getHora();
    int getMinuto();
};

#endif