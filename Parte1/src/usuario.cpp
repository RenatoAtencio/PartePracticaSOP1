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
#include <chrono>
#include <thread>

using namespace std;

class usuario {
private:
    string nombre;
    string password;
    int opcionSeleccionada;
    vector<int> vectorNumeros;
    vector<int> vectorPermisos;

public:
    // Constructor
    usuario(string nombreInput,string passwordInput, int opcionSeleccionadaInput, vector<int> vectorNumerosInput,vector<int> vectorPermisosInput) {
        nombre = nombreInput;
        password = passwordInput;
        opcionSeleccionada = opcionSeleccionadaInput;
        vectorNumeros = vectorNumerosInput;
        vectorPermisos = vectorNumerosInput;
    }

    // Funciones Set
    void setOpcion(int opcion){
        opcionSeleccionada = opcion;
    }

    // Funciones get
    string getNombre(){
        return nombre;
    }
    string getPassword(){
        return password;
    }

    int getOpcion(){
        return opcionSeleccionada;
    }

    // Funciones para permisos
    bool verificarPermiso(int permiso) {
        for (int p : vectorPermisos) {
            if (p == permiso) {
                return true;
            }
        }
        return false;
    }

    void salir() {
        cout << "Saliendo del programa, espere 2 segundos" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    void crearUser(){
        cout << "Crear User" << endl;
    }

    void imprimirMensaje(){
        cout << "Imprimir Msg" << endl;
    }

    void ordenarVector(){
        cout << "Ordenar Vector" << endl;
    }
};