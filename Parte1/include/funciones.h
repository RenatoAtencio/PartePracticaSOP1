#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "../src/usuario.cpp"
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
#include <cctype>

using namespace std;

// funciones de parse (funcionesParse.cpp)
vector<int> separarStringPorComaVectorInt(string secuencia);
vector<string> separarStringPorPuntoComaVectorStr(string secuencia);

// funciones de verficacion (funcionesVerificacion.cpp)
vector<string> verificarUserInDB(string nombre);

// funciones de creacion (funcionesCreacion.cpp)
usuario crearUsuario(string nombreUser, string passwordUser, string numerosString,string permisos);

#endif