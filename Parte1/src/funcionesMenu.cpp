#include "../include/funciones.h"

void verSeleccion(int userInput, bool& seguir, usuario* user) {
    switch (userInput) {
    case 0: { // Salir
        seguir = false;
        system("clear");
        user -> salir();
        break;
    }
    case 1: { // Crear User
        if (user -> verificarPermiso(1)) {
            user -> setOpcion(1);
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 2: { // Imprimir MSG
        if (user -> verificarPermiso(2)) {
            user -> setOpcion(2);
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    case 3: { // Ordenar Vector
        if (user -> verificarPermiso(3)) {
            user -> setOpcion(3);
        }
        else {
            cout << "No tiene este permiso" << endl;
        }
        break;
    }
    default : {
        user -> setOpcion(-2);
    }
    }
}

void mostrarMenu(usuario* user) {
    pid_t padrePID = getpid();
    printf("Sistema 1 (PID = %i)\n", padrePID);
    cout << "##################" << endl;
    // en esta parte deberia usar una funcion que genere la respuesta, usando el user
    mostrarSeleccion(user);
    cout << "##################" << endl;
    cout << "0) Salir" << endl;
    cout << "1) Crear Usuario" << endl;
    cout << "0) Imprimir mensaje para el usuario" << endl;
    cout << "0) Ordenar vector" << endl;

    // en esta parte deberia usar otra funcion para recibir la respuesta
}

void mostrarSeleccion(usuario* user) {
    cout << "Respuesta de la ejecucion" << endl;
    switch (user -> getOpcion()) {
    case -1: {
        cout << "------------------" << endl;
        break;
    }
    // case 0 nunca se logra porque el verSeleccion hace que seguir se vuelva false
    case 1: {
        user -> crearUser();
        break;
    }
    case 2: {
        user -> imprimirMensaje();
        break;
    }
    case 3: {
        user -> ordenarVector();
        break;
    }
    default : {
        cout << "No tiene este permiso" << endl;
    }
    }
}