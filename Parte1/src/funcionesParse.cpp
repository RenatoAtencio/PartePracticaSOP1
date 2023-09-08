#include "../include/funciones.h"

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