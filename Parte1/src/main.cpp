#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/funciones.h"

using namespace std;

void comenzarEjecucion(string permisos, string nombreUsuario, string password, string numerosStr);

int main(int argc, char* argv[])
{
    char c;
    string nombreUsuario, password, numerosStr;
    while ((c = getopt(argc, argv, "u:p:v:")) != -1) {
        switch (c) {
        case 'u': { // user
            nombreUsuario = optarg;
            break;
        }
        case 'p': {
            password = optarg;
            break;
        }
        case 'v': { // string de los numeros
            numerosStr = optarg;
            break;
        }
        }
    }

    system("clear");

    if ((nombreUsuario == "admin") && (password == "admin")) {
        // modo admin
        string permisos = "1,2,3";
        comenzarEjecucion(permisos,nombreUsuario,password,numerosStr);
    }
    else {
        // modo user normal
        vector<string> posibleUser = verificarUserInDB(nombreUsuario);
        if (!posibleUser.empty()) {
            // encontro el user
            if (posibleUser[1] == password) {
                // user existe y la contraseña es correcta, se crea user como objeto usuario
                string permisos = "2,3";
                comenzarEjecucion(permisos,nombreUsuario,password,numerosStr);
            }
            else {
                // contraseña incorrecta
                cout << "User encontrado pero la contraseña es incorrecta" << endl;
            }
        }
        else {
            // user no esta en la DB
            cout << "User not found" << endl;
        }
    }
    return 0;
}

void comenzarEjecucion(string permisos, string nombreUsuario, string password, string numerosStr) {
    int opcion;
    usuario user = crearUsuario(nombreUsuario, password, numerosStr, permisos);
    bool seguir = true;
    while (seguir) {
        mostrarMenu(&user);
        cout << "Ingrese Opcion: ";
        cin >> opcion;
        verSeleccion(opcion, seguir, &user);
        system("clear");
    }
}