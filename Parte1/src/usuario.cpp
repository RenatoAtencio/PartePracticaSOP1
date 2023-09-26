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
        vectorPermisos = vectorPermisosInput;
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

    vector<int> getPermisos(){
        return vectorPermisos;
    }

    int getOpcion(){
        return opcionSeleccionada;
    }

    // Funcion para verificar permisos
    bool verificarPermiso(int permiso) {
        for (int p : vectorPermisos) {
            if (p == permiso) {
                return true;
            }
        }
        return false;
    }

    // metodos 
    void salir() {
        cout << "Saliendo del programa, espere 2 segundos" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    void crearUser(){
        string newUsername, newPassword, respuesta = "-1";
        bool incorrecto = true;
        while (incorrecto){
            cout << "Ingrese el nombre del nuevo usuario: ";
            cin >> newUsername;
            cout << "Ingrese la password del nuevo usuario: ";
            cin >> newPassword;
            while ((respuesta != "s") && (respuesta !="n")){
                cout << "El nombre: " << newUsername << " y contraseña: " << newPassword << " son correctos? (s/n) : ";
                cin >> respuesta;
            }
            if (respuesta == "s"){
                incorrecto = false;
            }
            respuesta = "-1";
        }

        ofstream file(getenv("DB_USERS"), std::ios::app);
        if (file.is_open()) {
            file << newUsername << ";" << newPassword << endl;
            file.close();
            cout << "User agregado" << endl;
        }
        else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }

    void imprimirMensaje(){
        pid_t pid = getpid();
        cout << "Hola como estas " << nombre << " PID = " << pid << endl;
    }

    void ordenarVector(){
        sort(vectorNumeros.begin(),vectorNumeros.end());
        cout << "Vector ordenado (PID = " << getpid() << ")" << endl;
        for (int num : vectorNumeros){
            cout << num << " ";
        }
        cout << endl;
    }
};