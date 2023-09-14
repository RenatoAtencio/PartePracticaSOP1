#include <sys/wait.h>
#include "../include/funciones.h"

void verSeleccion(int userInput, bool& seguir, usuario* user) {
    switch (userInput) {
    case 0: { // Salir
        seguir = false;
        system("clear");
        user->salir();
        break;
    }
    case 1: { // Crear User
        if (user->verificarPermiso(1)) {
            user->setOpcion(1);
        }else{
            user -> setOpcion(-2);
        }
        break;
    }
    case 2: { // Imprimir MSG
        if (user->verificarPermiso(2)) {
            user->setOpcion(2);
        }
        break;
    }
    case 3: { // Ordenar Vector
        if (user->verificarPermiso(3)) {
            user->setOpcion(3);
        }
        break;
    }
    default: {
        user->setOpcion(-3);
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
    cout << "2) Imprimir mensaje para el usuario" << endl;
    cout << "3) Ordenar vector" << endl;
}

// si opcion = -1, recien comenzo el programa; si =-2 entonces no tiene ese permiso; si =-3 no esta implementada (cuando presiona cualquier num)
void mostrarSeleccion(usuario* user) {
    cout << "Respuesta de la ejecucion" << endl;
    switch (user->getOpcion()) {
    case -2: {
        cout << "No tiene este permiso" << endl;
        break;
    }
    case -1: {
        cout << "------------------" << endl;
        break;
    }
    // case 0 nunca se logra porque el verSeleccion hace que seguir se vuelva false
    case 1: { // crear user (no es proceso externo)
        user->crearUser();
        break;
    }
    case 2: { // escribe msg (es proceso externo)
        pid_t pid = fork();
        if (pid == 0) {
            user->imprimirMensaje();
            exit(0);
        }
        else {
            wait(NULL);
        }
        break;
    }
    case 3: { // ordena vector (es proceso externo)
        pid_t pid = fork();
        if (pid == 0) {
            user->ordenarVector();
            exit(0);
        }
        else {
            wait(NULL);
        }
        break;
    }
    default: {
        cout << "Funcion no implementada" << endl;
    }
    }
}