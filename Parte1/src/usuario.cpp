#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class usuario {
private:
    string nombre;
    string password;
    vector<int> vectorNumeros;
    vector<int> vectorPermisos;

public:
    // Constructor
    usuario(string nombreInput,string passwordInput, vector<int> vectorNumerosInput,vector<int> vectorPermisosInput) {
        nombre = nombreInput;
        password = passwordInput;
        vectorNumeros = vectorNumerosInput;
        vectorPermisos = vectorNumerosInput;
    }

    // Funciones get
    string getNombre(){
        return nombre;
    }
    string getPassword(){
        return password;
    }


    // Funciones para permisos
    // bool verificarPermiso(int permiso) {
    //     for (int p : permisos) {
    //         if (p == permiso) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    void salir() {
        cout << "A salido del programa" << endl;
    }

    void crearUser(){
 
    }

    void imprimirMensaje(){

    }

    void ordenarVector(){

    }
};