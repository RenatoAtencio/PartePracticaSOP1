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
    vector <int> vectorNumeros;
    while ((c = getopt(argc, argv, "u:p:v:")) != -1) {
        switch (c) {
        case 'u': { // user
            nombreUsuario = optarg;
            break;
        }
        case 'p':{
            password = optarg;
            break;
        }
        case 'v': { // string de los numeros
            NumerosStr = optarg;
            vectorNumeros = separarStringPorComaVectorInt(NumerosStr);
            break;
        }
        }
    }

    // hay que ver si el user es admin y si la contraseña es admin, si es asi entonces entra en modo administrador
    if ((nombreUsuario == "admin") && (password == "admin")){
        // entro como admin
    }else{
        // ver si el usuario esta en la base de datos
    }


    // se crea el usuario "user"
    usuario user(nombreUsuario,password,vectorNumeros);




    return 0;
}