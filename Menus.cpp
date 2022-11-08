#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"

using namespace std;

void menuPrincipal(){
    system("cls");
    cout<<"Sistema bibliotecario "<<endl;
    cout<<"1.- Bibliotecario"<<endl;
    cout<<"2.- Estudiante"<<endl;
    cout<<"0.- salir"<<endl;
}

void sistemaBibliotecario(){
    cout<<"Bienvenido bibliotecario"<<endl;
}

void sistemaEstudiante(){
    cout<<"Bienvenidos Estudiantes"<<endl;
}

void menuEstudiante(){
    system("cls");
    cout<<"Sistema bibliotecario del estudiante"<<endl;
    cout<<"1.- Ingresar al sistema"<<endl;
    cout<<"2.- Registrar nuevo estudiante"<<endl;
    cout<<"0.- volver"<<endl;
}