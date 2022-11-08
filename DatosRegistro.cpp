#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#define NOMBRE_BIBLIOTECARIO "Bibliotecario.csv"
#define NOMBRE_ESTUDIANTE "Estudiantes.csv"

using namespace std;

int ingresarSistemaBibliotecario(string usu, string pas){
    int flag = 0;
    ifstream archivo(NOMBRE_BIBLIOTECARIO);
    string linea;
    char delimitador = ',';
    getline(archivo, linea);
    while (getline(archivo, linea)){
        stringstream stream(linea);
        string usuB, pasB;
        getline(stream, usuB, delimitador);
        getline(stream, pasB, delimitador);
        if(usu == usuB && pas == pasB){
            flag = 1;
            break;
        }
    }
    archivo.close();
    return flag;
}

int ingresarSistemaEstudiante(string cod){
    int flag = 0;
    ifstream archivo(NOMBRE_ESTUDIANTE);
    string linea;
    char delimitador = ',';
    getline(archivo, linea);
    while (getline(archivo, linea)){
        stringstream stream(linea);
        string codE;
        getline(stream, codE, delimitador);
        getline(stream, codE, delimitador);
        getline(stream, codE, delimitador);
        if(cod == codE){
            flag = 1;
            break;
        }
    }
    archivo.close();
    return flag;
}

int registrarEstudiante(string nombre, string correo, string codigo){
    
}