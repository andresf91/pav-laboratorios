#include "dtUsuComent.h"

DTusuComent::DTusuComent(string nickname, string comentario) {
    this->nickname = nickname;
    this->comentario = comentario;
}

string DTusuComent::getNickname() {
    return nickname;
}

string DTusuComent::getComentario() {
    return comentario;
}
