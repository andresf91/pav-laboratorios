#include <iostream>
#include "socio.h"
#include "defMascotas.h"
#include "mascota.h"
#include "perro.h"
#include "gato.h"
#include "dtMascota.h"
#include "dtPerro.h"
#include "dtGato.h"
#include "consulta.h"
#include "dtFecha.h"
#include <string>
#include <stdexcept>

using namespace std;

//Firmas de las funciones del menu del main

// Muestra el menú
void menu();

// Registra un socio con su mascota.
void registrarSocio(string ci, string nombre, dtFecha* fechaIngreso, dtMascota* dtMascota);

// Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cédula,
// se levanta una excepción std::invalid_argument
void agregarMascota(string ci, dtMascota* dtMascota);

// Crea una consulta con un motivo para un socio. Si no existe un socio registrado con
// esa cédula, se levanta una excepción std::invalid_argument.
void ingresarConsulta(string _motivo, string _ci,Fecha _fecha);

// Devuelve las consultas antes de cierta fecha
Consulta** verConsultasAntesDeFecha(Fecha& _fecha, string _socio, int& cantConsultas);

// Elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con
// esa cédula, se levanta una excepción std::invalid_argument.
void eliminarSocio(string _ci);

// Devuelve un arreglo con las mascotas del socio. El largo del arreglo está dado por el parámetro
// cantMascotas. Si no existe un socio registrado con esa cédula, se levanta una
// excepción std::invalid_argument.
//Mascota obtenerMascotas(string _ci, int& cantMascotas);
// Recopilar datos de la mascota (devuelve un dtMascota)
dtMascota* recopilarDatosMascota();

// Recopilar datos de la fecha (devuelve un dtFecha)
dtFecha* recopilarDatosFecha();

// Recopilar los datos del socio
Socio* recopilarDatosSocio();

// Recorre el vector de socios y se fija si existe un socio con esa Ci
bool existeSocioConCi(string _ci);

int buscarSocioPorCi(string ci);

// Verifica si hay espacio en el arreglo de socios.
bool hayEspacio();


bool esPrevia (Fecha* fecha1, Fecha* fecha2);
// Comprar 2 fechas y devuelve True fecha1 < fecha2

#define MAX_SOCIOS 3
Socio* socios[MAX_SOCIOS]; // Arreglo de socios.
int numSocios = 0;



int main(){
	cout << "La cantidad actual de socios registrados es: " << numSocios << endl;
	menu();
	//Mascota** mascotas;
	//mascotas = socios[0].getMascotas();
	//mascotas[0]->infoMascota(); 
    return 0;
}



void menu(){
	
	int opcion;
	do{
	cout << endl <<"Bienvenido!" << endl << "Elija una opcion: " << endl;
	cout << "1) Registrar socio" << endl;
	cout << "2) Agregar mascota" << endl;
	cout << "3) Insertar consulta" << endl;
	cout << "4) Ver consultas antes de fecha dada" << endl;
	cout << "5) Eliminar socio" << endl;
	cout << "6) Obtener mascotas" << endl;
	cout << "0) Salir" << endl;
	
	cout << "-> "; cin >> opcion;

	switch(opcion){
		case(1):
			{
				if(!hayEspacio()){
        			cout << "No se pueden registrar más socios." << endl;
        			break;
    			}
    			Socio* nSocio = recopilarDatosSocio();
				dtMascota* _Mascota = recopilarDatosMascota();
				dtFecha __fecha = nSocio->getFecha();
				dtFecha* _fecha = &__fecha;
				registrarSocio(nSocio->getCi(), nSocio->getNombre(), _fecha, _Mascota);

				//delete _fecha;

			    break;
			}
		case(2):

			{
				string ci;
                if (numSocios == 0) {
                    cout << "No hay socios registrados." << endl;
                    break;
                }
                cout << "----- DATOS DEL SOCIO -----" << endl;                cout << "Documento del socio: ";
                cin >> ci;
                    if(existeSocioConCi(ci)){
                        dtMascota* _Mascota = recopilarDatosMascota();
                        agregarMascota(ci, _Mascota);                   
                }
			}
			/*
			{
				if (numSocios == 0) {
			        cout << "No hay socios registrados." << endl;
			        break;
			    }

			    cout << "***----- DATOS DEL SOCIO -----***" << endl;
			    cout << "Documento del socio: ";
			    cin >> _ci;

			    int indiceSocio = buscarSocioPorCi(_ci);
			    while (indiceSocio == -1 && _ci != "0") {
			        cout << "Socio no encontrado. Ingrese otro documento (0 para salir): ";
			        cin >> _ci;
			        indiceSocio = buscarSocioPorCi(_ci);
			    }
			    
			    if (_ci == "0") break;

			    cout << "***----- DATOS DE LA MASCOTA -----***" << endl;

			    cout << "Nombre de su mascota: " << endl;
			    cout << "-> "; cin >> _nombreMascota;

			    cout << "Genero de su mascota: (M)acho o (H)embra " << endl;
			    do{
			        cout << "-> "; cin >> _opcionGenero;
			        if (_opcionGenero != 'M' && _opcionGenero != 'm' && 
			            _opcionGenero != 'H' && _opcionGenero != 'h') {
			            cout << "Opcion incorrecta, intente nuevamente." << endl;
			        }
			        _genero = (_opcionGenero == 'M' || _opcionGenero == 'm') ? Macho : Hembra;
			    }while (_opcionGenero != 'M' && _opcionGenero != 'm' &&
			             _opcionGenero != 'H' && _opcionGenero != 'h');

			    cout << "Peso de su mascota: " << endl;
			    cout << "-> "; cin >> _peso;

			    cout << "¿Es (P)erro o (G)ato?" << endl;
			    do{
			        cout << "-> "; cin >> _tipoMascota;
			    }while (_tipoMascota != 'P' && _tipoMascota != 'p' &&
			             _tipoMascota != 'G' && _tipoMascota != 'g');

			    // CREAR LA MASCOTA SEGÚN EL TIPO
			    Mascota* mascota = nullptr;
			    if(_tipoMascota == 'P' || _tipoMascota == 'p'){
			        do{
			            cout << "¿De que raza es?" << endl;
			            cout << "0 - Labrador." << endl;
			            cout << "1 - Ovejero." << endl;
			            cout << "2 - Bulldog." << endl;
			            cout << "3 - Pitbull." << endl;
			            cout << "4 - Collie." << endl;
			            cout << "5 - Pekines." << endl;
			            cout << "6 - Otro." << endl;
			            cout << "-> "; cin >> _opcionRaza;
			            if(_opcionRaza < 0 || _opcionRaza > 6){
			            	cout << "Opcion incorrecta, intente nuevamente." << endl;
			            }
			        }while (_opcionRaza < 0 || _opcionRaza > 6);
			        
			        switch(_opcionRaza){
			        	case 0: _raza = Labrador; break;
			        	case 1: _raza = Ovejero; break;
			        	case 2: _raza = Bulldog; break;
			        	case 3: _raza = Pitbull; break;
			        	case 4: _raza = Collie; break;
			        	case 5: _raza = Pekines; break;
			        	case 6: _raza = Otro; break;
			        	default: cout << "Opcion incorrecta, intente nuevamente." << endl; break;
			        }

			        do{
			            cout << "¿Está vacunado?" << endl;
			            cout << "0 - Si." << endl << "1 - No" << endl;
			            cout << "-> "; cin >> _opcionVacuna; 
			            if(_opcionVacuna != 0 && _opcionVacuna != 1){
			            	cout << "Opcion incorrecta, intente nuevamente." << endl;
			            }
			        }while (_opcionVacuna != 0 && _opcionVacuna != 1);
			        vacuna = (_opcionVacuna == 0);

			        mascota = new Perro(_nombreMascota, _genero, _peso, _raza, vacuna);
			    } else if (_tipoMascota == 'G' || _tipoMascota == 'g') {
			        do{
			            cout << "¿Qué tipo de pelo tiene? -> (L)argo, (Mediano) o (C)orto." << endl;
			            cout << "-> "; cin >> _opcionTipoDePelo;
			            if (_opcionTipoDePelo != 'l' && _opcionTipoDePelo != 'L' &&
			                 _opcionTipoDePelo != 'm' && _opcionTipoDePelo != 'M' &&
			                 _opcionTipoDePelo != 'c' && _opcionTipoDePelo != 'c'){
			            	cout << "Opcion incorrecta, intente nuevamente por favor." << endl;
			            }
			        }while(_opcionTipoDePelo != 'l' && _opcionTipoDePelo != 'L' &&
			            	 _opcionTipoDePelo != 'm' && _opcionTipoDePelo != 'M' &&
			                 _opcionTipoDePelo != 'c' && _opcionTipoDePelo != 'c');
			        mascota = new Gato(_nombreMascota, _genero, _peso, _tipoPelo);
			    }

			    // Agregar mascota al socio
			    agregarMascota(_ci, mascota);
			    break;
			}
			*/
		case(3):
			/*
			{
				if(numSocios == 0){
					throw std::invalid_argument("No hay socios registrados en el sistema");
					break;
				}
				cout << "***----- DATOS DEL SOCIO -----***" << endl;
				cout << "Documento del socio: ";
				cout << "-> "; cin >> _ci;
				int ciCheck = buscarSocioPorCi(_ci);
				if(ciCheck != -1){
					string consulta;
					cout << "Ingrese su consulta: ";
					cin >> consulta;
					int _dia, _mes, _anio;
					cout << "Fecha de de la consulta: " << endl;
					cout << "* DIA de consulta -> "; cin >> _dia;
					cout << "* MES de consulta -> "; cin >> _mes;
					cout << "* AÑO de consulta -> "; cin >> _anio;
					Fecha fechaConsulta(_dia,_mes,_anio);
					ingresarConsulta(consulta,_ci,fechaConsulta);
	
				}else{
					throw std::invalid_argument("Socio no encontrado");
				}

			break;
			}
			*/
		case(4): 
		/*
		{
			if(numSocios == 0){
				throw std::invalid_argument("No hay socios registrados en el sistema");
				break;
			}
			cout << "VER CONSULTAS ANTES DE UNA FECHA" << endl;
			cout << "***----- DATOS DEL SOCIO -----***" << endl;
			cout << "Documento del socio: "; cin >> _ci;
				
			int ciCheck = buscarSocioPorCi(_ci);
				
			if(ciCheck != -1){
				int _dia, _mes,_anio;
				cout << "Fecha de de la consulta: " << endl;
				cout << "* DIA de consulta -> "; cin >> _dia;
				cout << "* MES de consulta -> "; cin >> _mes;
				cout << "* AÑO de consulta -> "; cin >> _anio;
				
				Fecha* _fecha2 = new Fecha(_dia,_mes,_anio);
				Socio* _socio = &socios[ciCheck];
				Consulta** _consultas = _socio->getConsultas();
				int _cantConsultas = _socio->getNumConsultas() -1;
			
				for (int i=0; i < _cantConsultas; i++) {

					Fecha* _fecha1 = &_consultas[i]->getFecha();//no tiene permiso pa
					if (esPrevia(_fecha1, _fecha2)) {
					Consulta consulta = *_consultas[i];
					consulta.imprimirConsulta();
					//	Consulta& _laConsulta = *_consultas[i]; 
					//	_laConsulta.imprimirConsulta();
					}
				}
			


			}else{
				throw std::invalid_argument("Socio no encontrado");
				break;
			}			
			break;
			}
		break;
		*/
		case(5): 
			/*
			if(numSocios == 0){
			throw std::invalid_argument("No hay socios registrados en el sistema");
			break;
			}
			cout <<"***----ELIMINAR SOCIO----***" << endl;
			cout << "***----- DATOS DEL SOCIO -----***" << endl;
			cout << "Documento del socio: ";
			cin >> _ci;

			if(existeSocioConCi(_ci)){
				int socioBorrar = buscarSocioPorCi(_ci);
				//socios[socioBorrar].~Socio();
				numSocios = numSocios-1;
			}else{
				throw std::invalid_argument("No existe socio con esa cedula");
			}



		
		break;
		*/
		case(6): break;
		case(0): break;
		default: cout << "Intente nuevamente." << endl; break;
	}
}while(opcion != 0);
}
 

void registrarSocio(string ci, string nombre, dtFecha* fechaIngreso, dtMascota* _mascota){
			
			if (!hayEspacio()) {
        		cout << "No hay espacio para registrar más socios." << endl;
        		return;
    		}

    		int indice = buscarSocioPorCi(ci);

    		// Verificar que no exista ya el CI
		    if (indice != -1) { //PRIMER -1
		        cout << "Ya existe un socio con este CI." << endl;
		        return;
		    } 
			
			dtFecha fecha = dtFecha(fechaIngreso);
			dtMascota mascota = dtMascota(_mascota);

		    // Crear el socio y agregarlo al arreglo
    		socios[numSocios] = new Socio(ci, nombre, fecha);
    		/// Agregar la mascota al socio 
    		agregarMascota(ci, _mascota);
    		numSocios++;
			//agregrar socio 
		    cout << "La cantidad de socios actual es: " << numSocios << endl;
}

dtFecha* recopilarDatosFecha(){
	int _dia, _mes, _anio;
	cout << "Fecha de ingreso: " << endl;
	cout << "* DIA de ingreso -> "; cin >> _dia;
	cout << "* MES de ingreso -> "; cin >> _mes;
	cout << "* AÑO de ingreso -> "; cin >> _anio;

	dtFecha* fecha= new dtFecha(_dia, _mes, _anio);
	return fecha;
}

Socio* recopilarDatosSocio(){

	string _ci, _nombreSocio; 

	cout << "***----- DATOS DEL SOCIO -----***" << endl;
    cout << "Documento del socio: " << endl;
    cout << "-> "; cin >> _ci;

    // Verificar que no exista el CI
    
        do{
        	if(existeSocioConCi(_ci)){
	        cout << "Ya existe un socio registrado con ese documento." << endl;
	        cout << "Documento del socio: " << endl;
	        cout << "-> "; cin >> _ci;
	    }

        }while(existeSocioConCi(_ci));
		
        cout << "Nombre del socio: " << endl;
    	cout << "-> "; cin >> _nombreSocio;
		
    	// registrar socio
		//devolver registrar los datos de socio al main
		int _dia, _mes, _anio;
		cout << "Fecha de ingreso: " << endl;
		cout << "* DIA de ingreso -> "; cin >> _dia;
		cout << "* MES de ingreso -> "; cin >> _mes;
		cout << "* AÑO de ingreso -> "; cin >> _anio;
		dtFecha fecha(_dia,_mes,_anio);
    	Socio *nuevosocio = new Socio(_ci, _nombreSocio, fecha);
		return nuevosocio;
		

}

// Función para verificar si una cédula ya existe
bool existeSocioConCi(string _ci) {
    for (int i = 0; i < numSocios; ++i) {
        if (socios[i]->getCi() == _ci) {
            return true;
        }
    }
    return false;
}

bool hayEspacio(){
	return numSocios < MAX_SOCIOS;
}

int buscarSocioPorCi(string ci){
    for (int i = 0; i < numSocios; i++) {
        if (socios[i]->getCi() == ci) {
            return i; // Retorna el índice si lo encuentra
        }
    }
    return -1; // No encontrado
}

void agregarMascota(string _ci, dtMascota* _mascota) {
    
	int _opcionRaza, _opcionVacuna;
	RazaPerro _raza;
	TipoPelo _tipoPelo;
	bool vacuna;
	char _opcionTipoDePelo;

	//try{
    if(numSocios > 0){}
   // if (indice == -1) {
   //     throw invalid_argument("Socio no encontrado");
    //}
	Socio* ptrSocio;
	if(numSocios == 0){
		ptrSocio = socios[numSocios];//Estaba indice cambiamos por numSocios
	}else{
		int indice = buscarSocioPorCi(_ci);
		ptrSocio = socios[indice];		
	}


    TipoMascota tipo = _mascota->getTipoMascota();

    if(tipo == PERRO){
		
        do{
            cout << "¿De que raza es?" << endl;
            cout << "0 - Labrador." << endl;
            cout << "1 - Ovejero." << endl;
            cout << "2 - Bulldog." << endl;
            cout << "3 - Pitbull." << endl;
            cout << "4 - Collie." << endl;
            cout << "5 - Pekines." << endl;
            cout << "6 - Otro." << endl;
            cout << "-> "; cin >> _opcionRaza;
            if(_opcionRaza < 0 || _opcionRaza > 6){
            	cout << "Opcion incorrecta, intente nuevamente." << endl;
            }
        }while (_opcionRaza < 0 || _opcionRaza > 6);
        
        switch(_opcionRaza){
        	case 0: _raza = Labrador; break;
        	case 1: _raza = Ovejero; break;
        	case 2: _raza = Bulldog; break;
        	case 3: _raza = Pitbull; break;
        	case 4: _raza = Collie; break;
        	case 5: _raza = Pekines; break;
        	case 6: _raza = Otro; break;
        	default: cout << "Opcion incorrecta, intente nuevamente." << endl; break;
        }

        do{
            cout << "¿Está vacunado?" << endl;
            cout << "0 - Si." << endl << "1 - No" << endl;
            cout << "-> "; cin >> _opcionVacuna; 
            if(_opcionVacuna != 0 && _opcionVacuna != 1){
            	cout << "Opcion incorrecta, intente nuevamente." << endl;
            }

            if(_opcionVacuna == 0){
            	vacuna = true;
            }else{
            	vacuna=false;
            }

        }while (_opcionVacuna != 0 && _opcionVacuna != 1);
        vacuna = (_opcionVacuna == 0);
        Perro dogg = new Perro(_mascota, _raza, vacuna);
        Perro* perro = &dogg;
        ptrSocio->push_back_perro(perro);


        /*Socio**/// ptrSocio = socios[numSocios];//Cambiar indice -> numSocios
        //ptrSocio->push_back_gato(gato);
        

    } else if (tipo == GATO) {
        do{
            cout << "¿Qué tipo de pelo tiene? -> (L)argo, (M)ediano o (C)orto." << endl;
            cout << "-> "; cin >> _opcionTipoDePelo;
            if (_opcionTipoDePelo != 'l' && _opcionTipoDePelo != 'L' &&
                 _opcionTipoDePelo != 'm' && _opcionTipoDePelo != 'M' &&
                 _opcionTipoDePelo != 'c' && _opcionTipoDePelo != 'C'){
            	cout << "Opcion incorrecta, intente nuevamente por favor." << endl;
            }
        }while(_opcionTipoDePelo != 'l' && _opcionTipoDePelo != 'L' &&
                 _opcionTipoDePelo != 'm' && _opcionTipoDePelo != 'M' &&
                 _opcionTipoDePelo != 'c' && _opcionTipoDePelo != 'C');
		switch(_opcionTipoDePelo){//arreglado los tipos de pelo no se guardaban de forma correcta
			case 'c' : _tipoPelo = Corto; break;
			case 'C' : _tipoPelo = Corto; break;
			case 'm' : _tipoPelo = Mediano; break;
			case 'M' : _tipoPelo = Mediano; break;
			case 'l' : _tipoPelo = Largo; break;
			case 'L' : _tipoPelo = Largo; break;
			default: cout << "opcion incorrecta" <<endl;

		}
		Gato cat = new Gato(_mascota, _tipoPelo);
		Gato* gato = &cat;
        /*Socio**/ //ptrSocio = socios[numSocios];//Cambiar indice -> numSocios
        ptrSocio->push_back_gato(gato);
       
    }
	//Mascota* ptrPet = ptrSocio->getMascotas()[0];
    cout << "Mascota agregada exitosamente." << endl;
    //cout << ptrSocio->getNombre() << endl;
    //cout << ptrPet->getNombre() << endl;
    
    	//}catch(invalid_argument& e){
        // Capturar la excepción y manejarla
      //  cerr << "Error: " << e.what() << endl;

	//}
}
/*
void ingresarConsulta(string motivo, string ci, Fecha fechaConsulta) {
    Socio* socioEncontrado = nullptr;

    /////Buscar el socio en el arreglo fijo de socios
    for (int i = 0; i < numSocios; i++) {
        if (socios[i].getCi() == ci) {
            socioEncontrado = &socios[i];
            break;
        }
    }
	
    ////Verificar si hay espacio para mas consultas
    if (socioEncontrado->getNumConsultas() >= MAX_CONSULTAS) {
        cout << "Error: No hay espacio para mas consultas en este socio." << endl;
        return;
    }

    ////Crear la consulta y agregarla al socio
    Consulta* nuevaConsulta = new Consulta(fechaConsulta, motivo, socioEncontrado);
    socioEncontrado->agregarConsulta(nuevaConsulta);
	delete nuevaConsulta;
    cout << "Consulta ingresada correctamente." << endl;
}
bool esPrevia(Fecha* fecha1, Fecha* fecha2){
    // si fecha 1 es menor que fecha 2 retorna TRUE
    if (fecha1->getAnio() < fecha2->getAnio()){//Fecha 1 es menor (año menor)
		return true;
		}else if(fecha1->getAnio() == fecha2->getAnio()){
				if(fecha1->getMes() < fecha2->getMes()){
					return true;
				}else if(fecha1->getMes() == fecha2->getMes()){
						if(fecha1->getDia() < fecha2->getDia()){
							return true;
							}else{
								return false;
							}
						}else{
							return false;
							}
		}else{
			return false;
			}
		}
*/


dtMascota* recopilarDatosMascota(){

	Genero _genero;
	float _peso;
	char _opcionGenero;
	string _nombreMascota;
	dtMascota* mascota = nullptr;
	char _tipoMascota;

	cout << "***----- DATOS DE LA MASCOTA -----***" << endl;

    cout << "Nombre de su mascota: " << endl;
    cout << "-> "; cin >> _nombreMascota;

    cout << "Genero de su mascota: (M)acho o (H)embra " << endl;
    do{
        cout << "-> "; cin >> _opcionGenero;
        if (_opcionGenero != 'M' && _opcionGenero != 'm' && 
            _opcionGenero != 'H' && _opcionGenero != 'h') {
            cout << "Opcion incorrecta, intente nuevamente." << endl;
        }
    }while (_opcionGenero != 'M' && _opcionGenero != 'm' &&
             _opcionGenero != 'H' && _opcionGenero != 'h');
    if (_opcionGenero == 'M' || _opcionGenero == 'm'){// antes !=m || != M // arreglado && -> ||
    	_genero = Macho;
    }else{
    	_genero = Hembra;
    }

	do {
		cout << "Peso de su mascota: " << endl;
		cout << "-> "; cin >> _peso;
		if (cin.fail() || _peso < 0) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Entrada inválida. Por favor, ingrese un número positivo." << endl;
		}
	} while (cin.fail() || _peso < 0);

     
    do{
    	cout << "¿Es (P)erro o (G)ato?" << endl;
        cout << "-> "; cin >> _tipoMascota;
    }while (_tipoMascota != 'P' && _tipoMascota != 'p' &&
             _tipoMascota != 'G' && _tipoMascota != 'g');

    if (_tipoMascota == 'p' || _tipoMascota == 'P'){	
    	mascota = new dtMascota(_nombreMascota, _genero, _peso, PERRO);
		//dtPerro::dtPerro(string _nombre, Genero _genero, float _peso, TipoMascota _tipo):dtMascota(_nombre, _genero,_peso) 

    }else{
    	mascota = new dtMascota(_nombreMascota, _genero, _peso, GATO);
		//dtGato::dtGato(string _nombre, Genero _genero, float _peso,TipoMascota _tipoMascota):dtMascota(_nombre, _genero, _peso) NUEVO CONSTRUCTOR
    }

    // CREAR LA MASCOTA SEGÚN EL TIPO
    
    return mascota;
}