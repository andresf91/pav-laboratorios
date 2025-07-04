#include "controladorPuntajesYComentarios.h"

// Inicialización del puntero estático
ControladorPuntajesYComentarios* ControladorPuntajesYComentarios::instancia = nullptr;

ControladorPuntajesYComentarios* ControladorPuntajesYComentarios::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorPuntajesYComentarios();
    }
    return instancia;
}

// ----------- DSS Ver comentarios y puntajes de películas -----------

void ControladorPuntajesYComentarios::listarPeliculas2() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    cout << "=== Listado de Peliculas ===" << endl;
    for (auto par : manejador->getPeliculas()) {
        Pelicula* p = par.second;
        DTpelicula2 dt = p->getDT2();
        cout << "Titulo: " << dt.getTitulo() << endl;
        cout << "Poster: " << dt.getUrlPoster() << endl;
    }
}

void ControladorPuntajesYComentarios::seleccionarPelicula(string titulo) {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    string _titulo = titulo;
    do{
        if (manejador->existePelicula(_titulo)){
            setTitulo(_titulo);
        }else{
            cout << "El titulo ingresado no corresponde a ninguna pelicula existente." << endl;
            cout << "Vuelva a ingresar nuevamente el titulo: ";
            cin >> _titulo;
            cout << endl;
        }
    }while(manejador->existePelicula(_titulo) == false);
}

void ControladorPuntajesYComentarios::infoPuntajesYComentarios() {
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (p == nullptr) {
        cout << "Película no encontrada." << endl;
        return;
    }
    // Imprime promedio de puntajes
    cout << "Promedio de puntajes: " << p->getPromedioPuntaje() << endl;

    // Imprime comentarios
    vector<Comentario*> comentarios = p->getComentarios(); // Debes tener este método
    if (comentarios.empty()) {
        cout << "No hay comentarios para esta película." << endl;
    } else {
        cout << "Comentarios:" << endl;
        for (Comentario* c : comentarios) {
            imprimirComentario(c, 0);
        }
    }
}

void ControladorPuntajesYComentarios::imprimirComentario(Comentario* c, int nivel) {
    // Armar el string "nickname: comentario"
    string contenido = comentario->getUsuario()->getNickname() + ": " + comentario->getTexto();
    DTcomentario dtc = comentario->getDTcomentario();

    // Imprime con sangría según el nivel
    for (int i = 0; i < nivel; ++i){
        cout << "    ";
    }
    cout << dtc.getContenido() << endl;

    // Imprime respuestas (si las hay)
    for (Comentario* respuesta : comentario->getRespuestas()) {
        imprimirComentario(respuesta, nivel + 1);
    }
}

// ----------- DSS Comentar película -----------

void ControladorPuntajesYComentarios::listarPeliculas() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    cout << "=== Listado de Peliculas ===" << endl;
    for (auto par : manejador->getPeliculas()) {
        Pelicula* pelicula = par.second;
        cout << "Titulo: " << pelicula->getTitulo() << endl;
    }
}

void ControladorPuntajesYComentarios::listarComentarios() {
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (p == nullptr){
        cout << "Película no encontrada." << endl;
        return;
    }
    vector<Comentario*> comentarios = p->getComentarios();
    for (Comentario* c : comentarios){
        imprimirComentario(c, 0);
    }
}

void ControladorPuntajesYComentarios::comentarioNuevo(string texto) {
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (p == nullptr){
        cout << "Película no encontrada." << endl;
        return;
    }
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    Comentario* c = new Comentario(texto, u);
    p->agregarComentario(c);
}
//
//
//
// falta chequear de acá en adelante
//
//
//

void ControladorPuntajesYComentarios::elegirComentario(int nroComentario) {
    this->nroComentario = nroComentario;
}

void ControladorPuntajesYComentarios::responderComentario(string texto) {
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (!p) throw std::runtime_error("Película no encontrada");
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    p->responderComentario(nroComentario, texto, u); // Debes tener este método en Pelicula
}

bool ControladorPuntajesYComentarios::continuarRespondiendo() {
    return this->respuesta;
}

// ----------- DSS Puntuar película -----------

bool ControladorPuntajesYComentarios::elegirPeliAPuntuar(string titulo) {
    this->titulo = titulo;
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (!p || !u) throw std::runtime_error("Película o usuario no encontrado");
    this->puntuada = p->usuarioYaPuntuo(u); // Debes tener este método en Pelicula
    return !this->puntuada;
}

int ControladorPuntajesYComentarios::obtenerPuntaje() {
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (!p || !u) throw std::runtime_error("Película o usuario no encontrado");
    return p->getPuntajeUsuario(u); // Debes tener este método en Pelicula
}

void ControladorPuntajesYComentarios::actualizarPuntaje(int puntaje) {
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (!p || !u) throw std::runtime_error("Película o usuario no encontrado");
    p->actualizarPuntaje(u, puntaje); // Debes tener este método en Pelicula
}

void ControladorPuntajesYComentarios::puntuarPelicula(int puntaje) {
    string nick = Sesion::getInstancia()->getNickname();
    Usuario* u = ManejadorUsuarios::getInstancia()->obtenerUsuario(nick);
    Pelicula* p = ManejadorPeliculas::getInstancia()->obtenerPelicula(titulo);
    if (!p || !u) throw std::runtime_error("Película o usuario no encontrado");
    p->puntuar(u, puntaje); // Debes tener este método en Pelicula
}

// ----------- Getters y Setters auxiliares -----------

string ControladorPuntajesYComentarios::getTitulo() { return titulo; }
int ControladorPuntajesYComentarios::getNroComentario() { return nroComentario; }
bool ControladorPuntajesYComentarios::getRespuesta() { return respuesta; }
bool ControladorPuntajesYComentarios::getPuntuada() { return puntuada; }
void ControladorPuntajesYComentarios::setTitulo(string titulo) { this->titulo = titulo; }
void ControladorPuntajesYComentarios::setNroComentario(int nroComentario) { this->nroComentario = nroComentario; }
void ControladorPuntajesYComentarios::setSetDTPelicula2() { this->setDTpeliculas2.clear(); }
void ControladorPuntajesYComentarios::setPuntajesYComentarios() { /* ... */ }
void ControladorPuntajesYComentarios::setSetTitulos(set<string> titulos) { this->Titulos = titulos; }
void ControladorPuntajesYComentarios::setSetComentarios() { this->comentarios.clear(); }
void ControladorPuntajesYComentarios::setRespuesta(bool valor) { this->respuesta = valor; }
void ControladorPuntajesYComentarios::setPuntuada(bool valor) { this->puntuada = valor; }

ControladorPuntajesYComentarios::ControladorPuntajesYComentarios() {}
ControladorPuntajesYComentarios::~ControladorPuntajesYComentarios() {}
