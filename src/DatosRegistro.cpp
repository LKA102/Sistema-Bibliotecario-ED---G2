#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;


using namespace std;

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

int ingresarSistemaEstudiante(string cod){
    int flag = 0;
    ifstream archivo(NOMBRE_ESTUDIANTE);
    string linea;
    char delimitador = ',';
    while (getline(archivo, linea)){
        stringstream stream(linea);
        string codE;
        getline(stream, codE, delimitador);
        if(cod == codE){
            estudiante = new (struct Estudiante);
            estudiante->codigo = codE;
            getline(stream, estudiante->nombre, delimitador);
            getline(stream, estudiante->correo, delimitador);
            flag = 1;
            break;
        }
    }
    archivo.close();
    return flag;
}

void registrarEstudiante(string nombre, string correo, string codigo){
    fstream archivo;
    archivo.open(NOMBRE_ESTUDIANTE,ios::app);
    archivo<<codigo<<","<<nombre<<","<<correo<<endl;
    archivo.close();
}