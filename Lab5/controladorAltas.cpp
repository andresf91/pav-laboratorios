#include "controladorAltas.h"

ControladorAltas* ControladorAltas::instancia = nullptr;
ControladorAltas::ControladorAltas() {}

ControladorAltas* ControladorAltas::getControladorAltas() {
    if (instancia == nullptr) {
        instancia = new ControladorAltas();
    }
    return instancia;
}

void ControladorAltas::agregarUnCine(string direccion){
    bool ok;
    char opcion;
    string dir = direccion;
    do{
        if(ManejadorCines::getInstancia()->obtenerCine(dir) == nullptr){
            setDireccion(direccion);
            ok = true;
        }else{
            
            cout << "Ya existe un cine registrado con esa direccion." << endl;
            cout << "¿Desea intentar ingresar una direccion distinta?" << endl;
            cout << "SI (S) - NO (N) --> ";
            cin >> opcion;
            cout << endl;
            if (opcion == 's' || opcion == 'S'){
                cout << "Ingresa la direccion: " << endl;
                cin >> dir;
                cout << endl;
                ok = false;
            }else if (opcion == 'n' || opcion == 'N'){
                ok = true;
                setDireccion(""); // chequear en el main para terminar el caso de uso
            }
        }
    }while(ok == false);
}

void ControladorAltas::agregarCapacidad(int capacidad){
    this->capacidadesDeSalas.push_back(capacidad);
}

void ControladorAltas::confirmarAlta(){
    this->cine = new Cine(ManejadorCines::getInstancia()->getCantCinesCreados(), getDireccion());
    for (size_t i = 0; i < capacidadesDeSalas.size(); i++) {
    int capacidad = capacidadesDeSalas[i];
    getCine()->crearUnaSala(capacidad);
    getCine()->agregarSala(getCine()->getSala());
    }
    ManejadorCines::getInstancia()->agregarCine(getCine());
    ManejadorCines::getInstancia()->setCantCinesCreados(ManejadorCines::getInstancia()->getCantCinesCreados()+1);
    destroyControladorAltas();
}

void ControladorAltas::cancelarYReintentarAltaCine() {
    destroyControladorAltas(); // volver a iniciar el caso de uso
}

void ControladorAltas::cancelarYSalirDeAltaCine() {
    destroyControladorAltas(); // terminar el caso de uso
}

void ControladorAltas::listarPeliculas() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    cout << "=== Listado de Peliculas ===" << endl;
    for (auto par : manejador->getPeliculas()) {
        Pelicula* pelicula = par.second;
        cout << "Titulo: " << pelicula->getTitulo() << endl;
    }
}

void ControladorAltas::seleccionarPelicula(string titulo) {
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

void ControladorAltas::listarCines(){
    ManejadorCines* manejador = ManejadorCines::getInstancia();
    cout << "=== Listado de Cines ===" << endl << endl;
    for (auto par : manejador->getCines()) {
        Cine* cine = par.second;
        DTcine _cine= cine->getDTcine();
        cout << "Nro Cine: " << _cine.getNroCine() << endl;
        cout << "Direccion: " << _cine.getDireccion() << endl << endl;
    }
}

void ControladorAltas::seleccionarCine(int nroCine){
    ManejadorCines* manejador = ManejadorCines::getInstancia();
    int nuevoNroCine = nroCine;
    cout << "=== Salas y Funciones ===" << endl << endl;
    for (auto par : manejador->getCines()) {
        Cine* cine = par.second;
        do{   
            if(cine->getNroCine() == nuevoNroCine){
                setNroCine(nuevoNroCine);
                setCine(cine);
                vector<DTsalaConFunciones> DTscfs = getCine()->getDTscfs();
                for(auto it : DTscfs){
                    cout << "Sala Nro: " << it.getNroSala() << endl;
                    cout << "Capacidad: " << it.getCapacidad() << endl;
                    cout << "Funciones disponibles:" << endl;
                    for(auto funcion : it.getHorariosO()){
                        DTfecha fechaFuncion(funcion.getFecha());
                        DTtiempo horarioFuncion(funcion.getHorario());
                        cout << "- Fecha: " << fechaFuncion.getAnio() << "/" << fechaFuncion.getMes() << "/" << fechaFuncion.getDia() << endl;
                        cout << ", Hora: " << horarioFuncion.getHora() << ":" << horarioFuncion.getMinuto() << endl << endl;
                    }
                }
            }else{
                cout << "Cine no encontrado. " << endl << "Ingrese nroCine nuevamente: ";
                cin >> nuevoNroCine;
                cout << endl;
            }
        } while (cine->getNroCine() != nuevoNroCine);
    }
}

void ControladorAltas::seleccionarSala(int nroSala){
    int _nroSala = nroSala;
    bool bandera=false;
    do{    
        for(auto it : getCine()->getSalas()){
            if (it->getNroSala() == _nroSala){
                setNroSala(_nroSala);
                bandera=true;
            }
        }
        if (bandera == false){
            cout << "Nro de sala incorrecto, intente nuevamente." << endl;
            cout << "Ingrese el nro de la sala: ";
            cin >> _nroSala;
            cout << endl;
        }
    }while(bandera == false);
}

void ControladorAltas::ingresarDetallesFuncion(DTfecha fecha,DTtiempo hora){
    ManejadorPeliculas * manejador = ManejadorPeliculas::getInstancia();
    Pelicula * peli = manejador->obtenerPelicula(getTitulo());
    Sala * sala = nullptr;

    for (auto it : getCine()->getSalas()){
        if (it->getNroSala() == getNroSala()){
                sala=it;
            }
    }
    Funcion * func=new Funcion(getCine()->getCantFuncionesCreadas(),fecha,hora,peli,sala);
    getCine()->setCantFuncionesCreadas(getCine()->getCantFuncionesCreadas()+1);
    sala->agregarFuncion(func);
}

void ControladorAltas::terminarDeAgregarFunciones(){
    destroyControladorAltas();
}

bool ControladorAltas::ingresarUsuario(string nickname, string clave){
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();
    if(manejador->existeUsuario(nickname) == false){
        setNickname(nickname);
        setClave(clave);
        return true;
    }else{
        cout << "Ya existe un usuario creado con ese nickname." << endl;
        return false;
    }
}

void ControladorAltas::ingresarUrl(string urlFoto){
    setUrlFoto(urlFoto);
}

void ControladorAltas::confirmarAltaUsuario(){
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();
    if(getUrlFoto() == ""){
        Usuario* usr = new Usuario(getNickname(), getClave());
        manejador->agregarUsuario(usr);
    }else{
        Usuario* user = new Usuario(getNickname(), getClave(), getUrlFoto());
        manejador->agregarUsuario(user);
    }
}

void ControladorAltas::cancelarYReintentarAltaUsuario(){
    destroyControladorAltas(); // se comienza nuevamente el caso de uso
}

void ControladorAltas::cancelarAlta(){
    destroyControladorAltas(); // se termina el caso de uso
}

bool ControladorAltas::ingresarPelicula(string titulo, string sinopsis, string urlPoster){
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    if(manejador->existePelicula(titulo) == false){
        setTitulo(titulo);
        setSinopsis(sinopsis);
        setUrlFoto(urlPoster);
        return true;
    }else{
        cout << "Ya existe una pelicula creada con ese titulo." << endl;
        return false;
    }
}

void ControladorAltas::confirmarAltaPeli(){
        ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
        Pelicula* peli = new Pelicula(getTitulo(), getSinopsis(), getUrlPoster());
        manejador->agregarPelicula(peli);
}

void ControladorAltas::reintentarConOtroTitulo(){
    destroyControladorAltas(); // se comienza nuevamente el caso de uso
}

void ControladorAltas::cancelarAltaPeli(){
    destroyControladorAltas(); // se termina el caso de uso
}

Cine* ControladorAltas::getCine() {
    return this->cine;
}

string ControladorAltas::getDireccion(){
    return this->direccion;
}

string ControladorAltas::getTitulo(){
    return this->titulo;
}

string ControladorAltas::getSinopsis(){
    return this->sinopsis;
}

string ControladorAltas::getNickname(){
    return this->nickname;
}

string ControladorAltas::getClave(){
    return this->clave;
}

string ControladorAltas::getUrlFoto(){
    return this->urlFoto;
}

string ControladorAltas::getUrlPoster(){
    return this->urlPoster;
}

int ControladorAltas::getNroCine(){
    return this->nroCine;
}

int ControladorAltas::getNroSala(){
    return this->nroSala;
}

void ControladorAltas::setCine(Cine * cine){
    this->cine = cine;
}

void ControladorAltas::setDireccion(string dir){
    this->direccion = dir;
}

void ControladorAltas::setTitulo(string titulo){
    this->titulo = titulo;
}

void ControladorAltas::setSinopsis(string sinopsis){
    this->sinopsis = sinopsis;
}

void ControladorAltas::setNickname(string nick){
    this->nickname = nick;
}

void ControladorAltas::setClave(string clave){
    this->clave = clave;
}

void ControladorAltas::setUrlFoto(string url){
    this->urlFoto = url;
}

void ControladorAltas::setUrlPoster(string url){
    this->urlPoster = url;
}

void ControladorAltas::setNroCine(int nrocine){
    this->nroCine = nrocine;
}

void ControladorAltas::setNroSala(int nroSala){
    this->nroSala = nroSala;
}

void ControladorAltas::destroyControladorAltas() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

ControladorAltas::~ControladorAltas() {
    this->capacidadesDeSalas.clear();
}