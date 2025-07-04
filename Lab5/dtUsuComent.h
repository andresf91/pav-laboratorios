#ifndef DTUSUCOMENT_H
#define DTUSUCOMENT_H

#include <string>
using namespace std;

class DTusuComent{
private:
    string nickname;
    string comentario;
public:
    DTusuComent(string, string);
    string getNickname();
    string getComentario();
};

#endif