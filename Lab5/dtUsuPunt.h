#ifndef DTUSUPUNT_H
#define DTUSUPUNT_H

#include <string>
using namespace std;

class DTusuPunt{
private:
    string nickname;
    int puntaje;
public:
    DTusuPunt(string, int);
    string getNickname();
    int getPuntaje();
};

#endif