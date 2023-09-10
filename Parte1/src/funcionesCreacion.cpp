#include "../include/funciones.h"

usuario crearUsuario(string nombreUser, string passwordUser, string numerosString,string permisos){
    vector<int> vectorNumeros = separarStringPorComaVectorInt(numerosString);
    vector<int> vectorPermisos = separarStringPorComaVectorInt(permisos);
    usuario user(nombreUser,passwordUser,vectorNumeros,vectorPermisos);
    return user;
}