#ifndef DTPELICULA2_H
#define DTPELICULA2_H

#include <string>
using namespace std;

class DTpelicula2{
private:
    string titulo;
    string urlPoster;
public:
    DTpelicula2(string, string);
    string getTitulo();
    string getUrlPoster();
};

#endif