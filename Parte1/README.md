# Parte 1 del trabajo

## Compilacion
Antes de compilar se debe usar en la consola los siguentes comandos: 
    set -o allexport 
    source config/.env
    export
Los primeros 2 comandos son para cargar las variables de entorno, el export muestra todas esta variables y permite verificar si este proceso fue exitoso (deberia aparece DB_USERS en la lista)
Para compilar se debe usar make en la consola, asegurarse que este el la carpeta correspondiente a la parte1.

## Ejecucion
Para ejecutar usar 
    ./app -u username -p password -v vector
Donde:
    username: Nombre del usuario
    password: Password del usuario
    vector: vector de números en el siguiente formato -> ej: 1,4,2,5,2,1
Ej completo:
    ./app -u Pol -p password1 -v 4,12,5,2,3,1,4

## La aplicacion
El programa es un sistema de usuarios que muestra la siguiente salida
    Sistema 1 (PID = pid del proceso )
    ##################
    Respuesta de la ejecucion
    ------------------
    ##################
    0) Salir
    1) Crear Usuario
    2) Imprimir mensaje para el usuario
    3) Ordenar vector
    Ingrese Opcion: 
La opcion 1 solo puede ser usada por el admin, las opciones 2 y 3 son accesibles para todos los usuarios
Si se ingresa un usuario que no existe en la DB o que se ingreso la contraseña incorrecta se indica.
Dependiendo de la seleccion indica una respuesta acorde, para la opcion 2 y 3 muestra el PID del proceso externo

## El codigo
En el main principalmente se llama las funciones para verificar si un usuario existe en la DB, y el menu
Las verificaciones son asi
    1° Ver si es admin --(si)-> modo admin
    2° Ver si el user esta en la DB
    3° Ver si la contraseña es correcta --(si)--> modo userNormal
Se usa un objeto usuario con 4 atributos, nombre, password, vector numeros, vector permisos, y tiene como metodos para crear user, imprimir msg, ordenar vector y funciones get y set
Luego se tienen 4 archivos .cpp para las funciones que se usan en el programa
    funcionesCreacion -> crearUsuario
    funcionesMenu -> verSeleccion, mostrarMenu, mostrarSeleccion
    funcionesParse -> separarStringPorComaVectorInt,separarStringPorPuntoComaVectorStr
    funcionesVerificacion -> verificarUserInDB
Se tiene una estructura donde
    carpeta Parte1
        carpeta config -> contiene el .env
        carpeta data -> databases
        carpeta include -> .h
        carpeta obj -> .o resultantes de compilar
        carpeta src -> .cpp
    Makefile
    README.md
    