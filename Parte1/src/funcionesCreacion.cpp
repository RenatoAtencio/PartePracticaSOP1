#include "../include/funciones.h"

usuario crearUsuario(string nombreUser, string passwordUser, string numerosString,string permisos){
    vector<int> vectorNumeros = separarStringPorComaVectorInt(numerosString);
    vector<int> vectorPermisos = separarStringPorComaVectorInt(permisos);
    // el -1 indica que aun no selecciona una opcion
    usuario user(nombreUser,passwordUser,-1,vectorNumeros,vectorPermisos);
    return user;
}