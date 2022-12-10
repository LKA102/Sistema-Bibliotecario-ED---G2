#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;

void rellenarListaRegistrados(bookListRegister &listaDisponible){
    bookListRegister aux = NULL;
    ifstream archivo (LISTA_DISPONIBLES);
    string linea, anio, paginas;
    char delimitador = ',';
    if (archivo.is_open()){
        while (getline(archivo, linea)){
            stringstream stream(linea);
            if (listaDisponible == NULL){
                listaDisponible = new (struct LibrosDisponibles);
                getline(stream, listaDisponible->libro.autor,delimitador);
                getline(stream, listaDisponible->libro.titulo,delimitador);
                getline(stream, anio,delimitador);
                getline(stream, paginas,delimitador);
                listaDisponible->libro.anio_publicacion = std::stoi(anio);
                listaDisponible->libro.num_paginas = std::stoi(paginas);
                aux = listaDisponible;
            }
            else{
            aux -> sgt = new (struct LibrosDisponibles);
            getline(stream, aux->sgt->libro.autor,delimitador);
            getline(stream, aux->sgt->libro.titulo,delimitador);
            getline(stream, anio,delimitador);
            getline(stream, paginas,delimitador);
            aux->sgt->libro.anio_publicacion = std::stoi(anio);
            aux->sgt->libro.num_paginas = std::stoi(paginas);
            aux = aux->sgt;
            }

        }
    }
    archivo.close();
}

void actualizarListaEstudiantes(Student estudiante){

    fstream archivo;
    archivo.open(NOMBRE_ESTUDIANTE,ios::in|ios::out);
    string texto;
    vector<string> lineas;
    texto = estudiante->codigo + "," + estudiante->nombre + "," + estudiante->correo + "," + estudiante->librosSolicitados[0] + "," + estudiante->librosSolicitados[1];
    if (archivo.is_open()){
        string linea;

        while (getline(archivo, linea)){
            lineas.push_back(linea);
        }
        archivo.close();
    }
    else{
        cout<<"No se ha podido abrir el archivo"<<endl;
        system("pause");
    }

    ofstream reescribir;
    reescribir.open(NOMBRE_ESTUDIANTE);
    if (reescribir.is_open()){
        for (int i=0; i<lineas.size(); i++){
            if (lineas[i].find(estudiante->codigo) != std::string::npos)
                reescribir<<texto<<endl;
            else
                reescribir<<lineas[i]<<endl;
        }
        reescribir.close();
    }
    else{
        cout<<"No se ha podido abrir el archivo"<<endl;
        system("pause");
    }
}