#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <string>
using namespace std;

class DTpelicula{
private:
    string urlPoster;
    string sinopsis;
public:
    DTpelicula(string, string);
    string getUrlPoster();
    string getSinopsis();
};

#endif