#include "../include/funciones.h"


// devuelve un vector vacio si no encontro el user en DB_USERS, 
// si lo encuentra devuelve el un vector <user,password>
vector<string> verificarUserInDB(string nombre){
    string lineaTxt;
    vector<string> userYpassword;
    ifstream archivoTxt(getenv("DB_USERS"));
    if (archivoTxt.is_open()) {
        while (getline(archivoTxt, lineaTxt)) {
            userYpassword = separarStringPorPuntoComaVectorStr(lineaTxt);
            if (userYpassword[0] == nombre){
                // encontro el user y devuelve el user;password
                return userYpassword;
            }
        }
        archivoTxt.close();
    }
    // no encontro user en DB
    userYpassword.clear();
    return userYpassword;
}