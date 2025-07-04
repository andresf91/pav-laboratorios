#include "controladorReservas.h"

ControladorReservas* ControladorReservas::instancia = nullptr;

ControladorReservas::ControladorReservas() {}

ControladorReservas* ControladorReservas::getControladorReservas() {
    if (instancia == nullptr) {
        instancia = new ControladorReservas();
    }
    return instancia;
}

void ControladorReservas::listarPeliculas() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    cout << "=== Listado de Peliculas ===" << endl;
    for (auto par : manejador->getPeliculas()) {
        Pelicula* pelicula = par.second;
        cout << "Titulo: " << pelicula->getTitulo() << endl;
    }
}

void ControladorReservas::seleccionarPelicula(string titulo) {
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

void ControladorReservas::mostrarSinopsisYPoster() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    Pelicula* peli = manejador->obtenerPelicula(getTitulo());
    DTpelicula peliculon = peli->getDTpelicula();
    cout << "-> Sinopsis:" << endl;
    cout << peliculon.getSinopsis() << endl;
    cout << "-> URL: " << peliculon.getUrlPoster() << endl;
}

void ControladorReservas::listarCines(){
    ManejadorCines* manejador = ManejadorCines::getInstancia();
    cout << "=== Listado de Cines ===" << endl << endl;
    for (auto par : manejador->getCines()) {
        Cine* cine = par.second;
        DTcine _cine= cine->getDTcine();
        cout << "Nro Cine: " << _cine.getNroCine() << endl;
        cout << "Direccion: " << _cine.getDireccion() << endl << endl;
    }
}

void ControladorReservas::elegirCine(int nroCine) {
    ManejadorCines* manejador = ManejadorCines::getInstancia();
        int nuevoNroCine = nroCine;
        cout << "=== Funciones ===" << endl << endl;
        for (auto par : manejador->getCines()) {
            Cine* cine = par.second;
            do{   
                if(cine->getNroCine() == nuevoNroCine){
                    setNroCine(nuevoNroCine);
                    vector<DTfuncion2> DTf2 = cine->getDTf2(getTitulo());
                    for(auto it : DTf2){
                        agregarAlSetNroFunciones(it.getNroFuncion());
                        cout << "Funcion Nro: " << it.getNroFuncion() << endl;
                        cout << "Fecha: " << it.getFecha().getDia() << "/" << it.getFecha().getMes() << "/" << it.getFecha().getAnio() << endl;
                        cout << "Horario:" << it.getHorario().getHora() << ":" << it.getHorario().getMinuto() << endl;                        
                    }
                }else{
                    cout << "Cine no encontrado. " << endl << "Ingrese nroCine nuevamente: ";
                    cin >> nuevoNroCine;
                    cout << endl;
                }
            } while (cine->getNroCine() != nuevoNroCine);
        }
}

void ControladorReservas::elegirFuncion(int nroFuncion) {
    bool bandera = false;
    int valor = nroFuncion;
    do{
        for (int it : getNrosFunciones()){
            if (it == valor){
                bandera = true;
                setNroFuncion(valor);
            }
        }
        if (bandera == false){
            cout << "Numero de funcion incorrecto, ingrese otro por favor: ";
            cin >> valor;
            cout << endl;
        }
    }while(bandera == false);
}

void ControladorReservas::ingresarAsientos(int cantAsientos) {
    this->cantAsientos = cantAsientos;
}

void ControladorReservas::ingresarBanco(string nombreBanco) {
    ManejadorFinancieras* manejador = ManejadorFinancieras::getInstancia();
    bool bandera = false;
    string nombre = nombreBanco;
    do{
        if (manejador->existeFinanciera(nombre)){
            bandera = true;
            setNombreBanco(nombre);
        }else{
            cout << "El nombre del banco es incorrecto, ingrese otro por favor: ";
            cin >> nombre;
            cout << endl;
        }
    }while(bandera == false);
}

void ControladorReservas::obtDescuentoFinanciera(string financiera) {
    ManejadorFinancieras* manejador = ManejadorFinancieras::getInstancia();
    Financiera* fin = manejador->obtenerFinanciera(financiera);
    DTfinanciera dtf = fin->getDTF();
    if (dtf.getTieneDescuento() == true){
        cout << "Tiene un " << dtf.getPorcentajeDescuento() << "% de descuento." << endl;
    }else{
        cout << "No tiene ningun descuento." << endl;
    }
}

float ControladorReservas::obtenerPrecioTotal() {
    ManejadorCines* manejadorC = ManejadorCines::getInstancia();
    Cine* cine = manejadorC->obtenerCine(getTitulo());
    Funcion* funcion;
    Financiera* financiera;
    float precioTotal = 0.0;
    for (auto it : cine->getSalas()){
        for(auto it2 : it->getFunciones()){
            if (it2->getNroFuncion() == getNroFuncion()){
                funcion = it2;
                setFuncion(funcion);
            }
        }
    }
    if (getNombreFinanciera() == ""){
        precioTotal = funcion->getCostoPorAsiento() * getCantAsientos();
        setTipoReserva(DEBITO);
    }else if (getNombreBanco() == ""){
        ManejadorFinancieras* manejadorF = ManejadorFinancieras::getInstancia();
        financiera = manejadorF->obtenerFinanciera(getNombreFinanciera());
        precioTotal = ((funcion->getCostoPorAsiento() * (financiera->getDescuento()/100))* getCantAsientos());
        setTipoReserva(CREDITO);
    }
    setPrecioTotal(precioTotal);
    return precioTotal;
}

void ControladorReservas::confirmarReserva() {
    ManejadorUsuarios* manejadorU = ManejadorUsuarios::getInstancia();
    Sesion* sesion = Sesion::getInstancia();
    string nick = sesion->getNickname();
    Usuario* usr = manejadorU->obtenerUsuario(nick);
    ManejadorFinancieras* manejadorF = ManejadorFinancieras::getInstancia();
    Financiera* financiera = manejadorF->obtenerFinanciera(getNombreFinanciera());
    float descuento = financiera->getDescuento();
    if(getTipo() == CREDITO){
        Credito* credito = new Credito(getCantAsientos(), getPrecioTotal(), usr, getFuncion(), descuento, getNombreFinanciera());
        usr->agregarReserva(credito);
        destroyControladorReservas();
    }else if (getTipo() == DEBITO){
        Debito* debito = new Debito(getCantAsientos(),getPrecioTotal(),usr,getFuncion(),getNombreBanco());
        usr->agregarReserva(debito);
        destroyControladorReservas();
    }

}


void ControladorReservas::cancelarReserva2(){
    destroyControladorReservas();/*Termina el caso de uso, resolver en el main*/

}

void ControladorReservas::reintentarConOtraPelicula(){
    destroyControladorReservas();/*Vuelve a comenzar el caso de uso, resolver en el main*/

}

void ControladorReservas::cancelarYLiberarTitulo(){/*Termina el caso de uso y libera la memoria asociada a titulo, resolver en el main*/
    destroyControladorReservas();
}

void ControladorReservas::cancelarReserva(){/*Termina el caso de uso, resolver en el main*/
    destroyControladorReservas();

}

void ControladorReservas::detallesPelicula(){
    ManejadorPeliculas * manp = ManejadorPeliculas::getInstancia();
    Pelicula * peli = manp->obtenerPelicula(getTitulo());
    DTpelicula dtp = peli->getDTpelicula();
    cout << "Poster:" << dtp.getUrlPoster() <<endl;
    cout << "Sinopsis:" << dtp.getSinopsis() <<endl;
}

void ControladorReservas::cancelarYSalirVerInformacionPelicula(){
    destroyControladorReservas();
}

void ControladorReservas::seleccionarCine2(int nroCine) {
    ManejadorCines * manejador = ManejadorCines::getInstancia();
    int nrocine = nroCine;
    bool salir=false;
    do{
        for(auto it : manejador->getCines()){
            Cine * cine = it.second;
            if(cine->getNroCine()==nrocine){
                setNroCine(nrocine);
                salir=true;
            }else{
            cout << "El numero ingresado no corresponde a ningun cine existente." << endl;
            cout << "Vuelva a ingresar nuevamente el nroCine: ";
            cin >> nrocine;
            cout << endl;
            }
        }
    }while(salir == false);
}

void ControladorReservas::listarFunciones(){
    ManejadorCines* manejador = ManejadorCines::getInstancia();
    Cine* cine;
    ManejadorPeliculas* manejadorP = ManejadorPeliculas::getInstancia();
    Pelicula* peli = manejadorP->obtenerPelicula(getTitulo());
   	auto ahora = chrono::system_clock::now();
    time_t ahora_t = chrono::system_clock::to_time_t(ahora);
    tm tiempo_local = *localtime(&ahora_t);
    int dia = tiempo_local.tm_mday;
    int mes = tiempo_local.tm_mon + 1;
    int anio = tiempo_local.tm_year + 1900;
    int hora = tiempo_local.tm_hour;
    int minuto = tiempo_local.tm_min;
    DTfecha fechaActual(dia, mes, anio);
	DTtiempo horaActual(hora, minuto);
    for(auto it : manejador->getCines()) {
        if (it.second->getNroCine() == getNroCine()){
            cine = it.second;
        }
    }
    cout << "=== Funciones ===" << endl << endl;
    for (auto it2 : cine->getSalas()) {
        for (auto it3 : it2->getFunciones()){
            if (it3->getPelicula() == peli){
                DTfecha fecha = it3->getFecha();
                DTtiempo horario = it3->getHorario();
                if(esPrevia(fechaActual, fecha) && esHorarioPrevio(horaActual, horario)){
                    DTfuncion dtf = it3->getdtFuncion();
					cout << "Nro funcion: " << dtf.getNroFuncion() << endl;
					cout << "Fecha: " << dtf.getFecha().getAnio() << "/" << dtf.getFecha().getMes() << "/" << dtf.getFecha().getDia() << endl;
                    cout << "Hora: " << dtf.getHorario().getHora() << ":" << dtf.getHorario().getMinuto() << endl << endl;
                }
            }
        }
    }
}

void ControladorReservas::infoOtraPelicula() {
    destroyControladorReservas(); /*Termina el caso de uso, resolver en el main*/
}

void ControladorReservas::cancelarYSalirVerInformacionPelicula1(){
    destroyControladorReservas();
}

void ControladorReservas::cancelarYSalirVerInformacionPelicula2(){
    destroyControladorReservas();
}

void ControladorReservas::eliminarPelicula() {
    ManejadorPeliculas* manejador = ManejadorPeliculas::getInstancia();
    manejador->eliminarPelicula(getTitulo());
    cout << "Pelicula eliminada correctamente." << endl;
    destroyControladorReservas(); /*Termina el caso de uso, resolver en el main*/
}

void ControladorReservas::cancelarYSalirEliminarPelicula() {
    destroyControladorReservas(); /*Termina el caso de uso, resolver en el main*/
}

bool ControladorReservas::esPrevia(DTfecha fecha1, DTfecha fecha2) {
	// si fecha 1 es menor que fecha 2 retorna TRUE
	if (fecha1.getAnio() < fecha2.getAnio())
	{
		return true;
	}
	else if (fecha1.getAnio() == fecha2.getAnio())
	{
		if (fecha1.getMes() < fecha2.getMes())
		{
			return true;
		}
		else if (fecha1.getMes() == fecha2.getMes())
		{
			if (fecha1.getDia() < fecha2.getDia())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool ControladorReservas::esHorarioPrevio(DTtiempo horario1, DTtiempo horario2) {
	// si horario1 es menor que horario2 retorna TRUE
	if (horario1.getHora() < horario2.getHora()){
		return true;
	}else if (horario1.getHora() == horario2.getHora()){
		if (horario1.getMinuto() < horario2.getMinuto()){
			return true;
		}else{
			return false;
        }
	}else{
		return false;
	}
}

void ControladorReservas::setTitulo(string titulo){
    this->titulo = titulo;
}

void ControladorReservas::setFuncion(Funcion* func) {
    this->funcion = func;
}

void ControladorReservas::setNombreBanco(string nombre) {
    this->nombreBanco = nombre;
}

void ControladorReservas::setNroCine(int nrocine){
    this->nroCine = nrocine;
}

void ControladorReservas::setNroFuncion(int valor) {
    this->nroFuncion = valor;
}

void ControladorReservas::setTipoReserva(TipoPago tipo) {
    this->tipo = tipo;
}

void ControladorReservas::setPrecioTotal(float precio) {
    this->precioTotal = precio;
}

void ControladorReservas::agregarAlSetNroFunciones(int valor) {
    this->nrosFunciones.insert(valor);
}

int ControladorReservas::getNroFuncion() {
    return this->nroFuncion;
}

int ControladorReservas::getNroCine() {
    return this->nroCine;
}

float ControladorReservas::getPrecioTotal() {
    return this->precioTotal;
}

TipoPago ControladorReservas::getTipo(){
    return this->tipo;
}

Funcion* ControladorReservas::getFuncion() {
    return this->funcion;
}

set<int> ControladorReservas::getNrosFunciones() {
    return this->nrosFunciones;
}

string ControladorReservas::getNombreFinanciera(){
    return this->nombreFinanciera;
}

int ControladorReservas::getCantAsientos() {
    return this->cantAsientos;
}

string ControladorReservas::getNombreBanco(){
    return this->nombreBanco;
}

string ControladorReservas::getTitulo(){
    return this->titulo;
}

string ControladorReservas::getUrlPoster() {
    return this->urlPoster;
}

string ControladorReservas::getSinopsis() {
    return this->sinopsis;
}

void ControladorReservas::destroyControladorReservas() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

ControladorReservas::~ControladorReservas() {
    this->funcion = nullptr;
    this->nrosFunciones.clear();
}