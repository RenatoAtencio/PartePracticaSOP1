#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/funciones.h"

using namespace std;

int main(int argc, char* argv[])
{
    char c;
    string nombreUsuario, password, NumerosStr;
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
            NumerosStr = optarg;
            break;
        }
        }
    }


    if ((nombreUsuario == "admin") && (password == "admin")) {
        string permisos = "1,2,3";
        // modo admin
    }
    else {
        // modo user normal
        vector<string> posibleUser = verificarUserInDB(nombreUsuario);
        if (!posibleUser.empty()) {
            // encontro el user
            if (posibleUser[1] == password) {
                // user existe y la contraseña es correcta, se crea user como objeto usuario
                string permisos = "2,3";
                usuario user = crearUsuario(nombreUsuario,password,NumerosStr,permisos);
                cout << "user encontrado y verificado" << endl;
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
