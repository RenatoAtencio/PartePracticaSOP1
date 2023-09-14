#include "../include/funciones.h"

// separa un string por ; , devuelve un vector con las partes separadas como int
vector<int> separarStringPorComaVectorInt(string numeros){
    vector<int> vectorInt;
    stringstream stream(numeros);
    string numero;
    while (getline(stream, numero, ',')) {
        int num = stoi(numero);
        vectorInt.push_back(num);
    }
    return vectorInt;
}

// separa un string por ; , devuelve un vector con las partes separadas como string
vector<string> separarStringPorPuntoComaVectorStr(string secuencia){
    vector<string> palabras;
    stringstream stream(secuencia);
    string palabra;
    while (getline(stream, palabra, ';')) {
        palabras.push_back(palabra);
    }
    return palabras;
}