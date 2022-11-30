#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#define NOMBRE_BIBLIOTECARIO "Bibliotecario.csv"
#define NOMBRE_ESTUDIANTE "Estudiantes.csv"

using namespace std;

//esta funcion me permite verificar las credenciales del bibliotecario para que pueda ingresar al sistema
int ingresarSistemaBibliotecario(string usu, string pas){
    int flag = 0;
    fstream archivo(NOMBRE_BIBLIOTECARIO, ios::in|ios::out|ios::trunc);
    if(archivo.is_open()){
        archivo<<"administrador,password"<<endl;
        archivo<<"Adrian,123"<<endl;
        archivo.seekg(0);
        string linea;
        char delimitador = ',';
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
    }
    else{
        cout<<"Error al abrir el archivo"<<endl;
    }
    
    return flag;
}

//esta funcion me permite verificar el codigo del estudiante para que pueda ingresar al sistema
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

//esta funcion me permite guardar un nuevo estudiante para que pueda acceder al sistema
void registrarEstudiante(string nombre, string correo, string codigo){
    fstream archivo;
    archivo.open(NOMBRE_ESTUDIANTE,ios::in|ios::app);
    archivo<<nombre<<","<<correo<<","<<codigo<<endl;
    archivo.close();
}