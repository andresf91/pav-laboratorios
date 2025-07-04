#include "fabricaControladores.h"
#include "controladorSesion.h"
#include <iostream>
using namespace std;

int main(){
    int opcion;
    bool ok = false;
    bool claveOk;
    bool disp;
    ManejadorUsuarios* manejadorUsuarios = ManejadorUsuarios::getInstancia();
    Sesion* sesion = Sesion::getInstancia();
    Isesion* controladorSesion = FabricaControladores::getFabrica()->getControladorSesion();
    Ialtas* controladorAltas = FabricaControladores::getFabrica()->getControladorAltas();
    string nickname;
    string password;

    do{

        cout << endl << "=== Menu ===" << endl << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Cerrar sesion" << endl;
        cout << "3. Alta Usuario" << endl;
        cout << "4. Alta Pelicula" << endl;
        cout << "5. Alta Cine" << endl;
        cout << "6. Alta Funcion" << endl;
        cout << "7. Crear Reserva" << endl;
        cout << "8. Ver Reservas De Pelicula" << endl;
        cout << "9. Eliminar Pelicula" << endl;
        cout << "10. Ver Informacion Pelicula" << endl;
        cout << "3. Alta usuario" << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        switch (opcion){
        case 1:
            ok = false;
            do{
                cout << "Ingrese su nickname: " << endl;
                cin >> nickname;
                controladorSesion->ingresarUsuario(nickname);
                
                cout << "Ingrese su clave: " << endl;
                cin >> password;
                claveOk = controladorSesion->ingresarClave(password);
                if (claveOk){
                    controladorSesion->confirmarInicioDeSesion();
                    ok = true;
                }else{
                    cout << "Desea reintentar el inicio de sesion? (s/n): " << endl;
                    char respuesta;
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S'){
                        ok = false;
                    }
                    else if (respuesta == 'n' || respuesta == 'N'){
                        controladorSesion->cancelarInicioDeSesion();
                        cout << "Inicio de sesion cancelado." << endl;
                        ok = true; // Salir del bucle
                        break;
                    }
                }
            } while (ok == false);
            break;
        case 2:
            if (Sesion::getInstancia()->getNickname() == ""){
        cout << "No hay una sesion activa." << endl;
        break;
    }else{
        controladorSesion = FabricaControladores::getFabrica()->getControladorSesion();
        if (controladorSesion != nullptr) {
            controladorSesion->cerrarSesion();
            cout << "Sesion cerrada." << endl;
        } else {
            cout << "Error: No hay controlador de sesión disponible." << endl;
        }
    }
    break;
    case 3:
        if (Sesion::getInstancia()->getNickname() != "admin"){
            cout << "No podes dar de alta un usuario sin ser el usuario administrador." << endl;
            break;
        }
        do{
            cout << "Nickname del nuevo usuario: " << endl;
                    cin >> nickname;
            cout << "Clave del nuevo usuario: " << endl ;
                    cin >> password;

            disp = controladorAltas->ingresarUsuario(nickname, password);
            char resp = 'a';
            if(disp == true){
                while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N'){
                    cout << "¿Desea agregar una foto? (s/n): " << endl  ;
                    cin >> resp;
                    if (resp == 's' || resp == 'S'){
                        string urlFoto;
                        cout << "Ingrese la URL de la foto: " << endl;
                        cin >> urlFoto;
                        controladorAltas->ingresarUrl(urlFoto);
                        break;
                    }else if (resp == 'n' || resp == 'N'){
                        controladorAltas->ingresarUrl("");
                    } else{
                        cout << "Opcion invalida. Intente nuevamente el valor: " << endl;
                    }
                };
            }
            if (disp == false){ //else
                cout << "Desea reintentar con otro nickname? (s/n): " << endl;
                char respuesta;
                cin >> respuesta;
                if (respuesta == 's' || respuesta == 'S'){
                    continue;
                }else if (respuesta == 'n' || respuesta == 'N'){
                    cout << "Alta de usuario cancelada." << endl;
                    break;
                }
            }
            
        }while(disp == false);

        if (disp == true){
            controladorAltas->confirmarAltaUsuario();
            cout << "El usuario " << ManejadorUsuarios::getInstancia()->obtenerUsuario(nickname)->getNickname() << " fue creado exitosamente." << endl;
        }else{
            cout << "No se creo el usuario." << endl;
        }
        break;
    case 4:
        if (Sesion::getInstancia()->getNickname() != "admin") {
            cout << "Solo el administrador puede dar de alta una película." << endl;
            break;
        }
        {
            string titulo, sinopsis, urlPoster;
            bool disp = false;
            char reintentar = 'n';
            do {
                cout << "Ingrese el título de la película: " << endl;
                cin >> titulo;
                cout << "Ingrese la sinopsis: " << endl;
                cin >> sinopsis;
                cout << "Ingrese la URL del poster: " << endl;
                cin >> urlPoster;

                disp = controladorAltas->ingresarPelicula(titulo, sinopsis, urlPoster);

                if (disp) {
                    cout << endl << "¿Desea confirmar el alta de la película? (s/n): " << endl;
                    char confirmar;
                    cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S') {
                        controladorAltas->confirmarAltaPeli();
                        cout << endl << "Película dada de alta exitosamente." << endl;
                        break;
                    } else {
                        controladorAltas->cancelarAltaPeli();
                        cout << "Alta de película cancelada." << endl;
                        break;
                    }
                } else {
                    cout << "El título ya existe. ¿Desea reintentar con otro título? (s/n): " << endl;
                    cin >> reintentar;
                    if (reintentar == 's' || reintentar == 'S') {
                        controladorAltas->reintentarConOtroTitulo();
                    } else {
                        controladorAltas->cancelarAltaPeli();
                        cout << "Alta de película cancelada." << endl;
                        break;
                    }
                }
            } while (!disp || (reintentar == 's' || reintentar == 'S'));
        }
        break;
    case 5:
        if (Sesion::getInstancia()->getNickname() != "admin") {
            cout << "Solo el administrador puede dar de alta un cine." << endl;
            break;
        }
        {
            string direccion;
            int capacidad;
            char agregarOtroCine = 's';
            do {
                cout << "Ingrese la dirección del cine: " << endl;
                cin.ignore();
                getline(cin, direccion);
                controladorAltas->agregarUnCine(direccion);

                char agregarMasSalas = 's';
                do {
                    cout << "Ingrese la capacidad de la sala: " << endl;
                    cin >> capacidad;
                    controladorAltas->agregarCapacidad(capacidad);

                    cout << "¿Desea agregar otra sala? (s/n): " << endl;
                    cin >> agregarMasSalas;
                } while (agregarMasSalas == 's' || agregarMasSalas == 'S');

                cout << "¿Desea confirmar el alta del cine? (s/n): " << endl;
                char confirmar;
                cin >> confirmar;
                if (confirmar == 's' || confirmar == 'S') {
                    controladorAltas->confirmarAlta();
                    cout << "Cine dado de alta exitosamente." << endl;
                } else {
                    cout << "¿Desea cancelar y agregar otro cine? (s/n): " << endl;
                    char reintentar;
                    cin >> reintentar;
                    if (reintentar == 's' || reintentar == 'S') {
                        controladorAltas->cancelarYReintentarAltaCine();
                        continue;
                    } else {
                        controladorAltas->cancelarYSalirDeAltaCine();
                        cout << "Alta de cine cancelada." << endl;
                        break;
                    }
                }

                cout << "¿Desea agregar otro cine? (s/n): " << endl;
                cin >> agregarOtroCine;
            } while (agregarOtroCine == 's' || agregarOtroCine == 'S');
        }
        break;
    case 6:
        // Implementar la funcionalidad para dar de alta una función
        break;
    case 7:
        // Implementar la funcionalidad para crear una reserva
        break;
    case 8:
        // Implementar la funcionalidad para ver las reservas de una película
        break;
    case 9:
        // Implementar la funcionalidad para eliminar una película
        break;
    case 10:
        // Implementar la funcionalidad para ver la información de una película
        break;
    default:
        break;
    }
} while (opcion != 0);

    return 0;
}