#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;

void rellenarListaRegistrados(bookListRegister &listaDisponible){
    bookListRegister aux = NULL;
    ifstream archivo (LISTA_REGISTRADOS);
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