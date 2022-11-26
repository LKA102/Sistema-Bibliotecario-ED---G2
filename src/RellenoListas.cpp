#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaRegistro;

void rellenarListaRegistrados(bookListRegister &listaRegistro){
    bookListRegister aux = NULL;
    ifstream archivo (LISTA_REGISTRADOS);
    string linea, anio, paginas;
    char delimitador = ',';
    if (archivo.is_open()){
        while (getline(archivo, linea)){
            stringstream stream(linea);
            if (listaRegistro == NULL){
                listaRegistro = new (struct LibrosRegistrados);
                getline(stream, listaRegistro->libro.autor,delimitador);
                getline(stream, listaRegistro->libro.titulo,delimitador);
                getline(stream, anio,delimitador);
                getline(stream, paginas,delimitador);
                listaRegistro->libro.anio_publicacion = std::stoi(anio);
                listaRegistro->libro.num_paginas = std::stoi(paginas);
                aux = listaRegistro;
            }
            else{
            aux -> sgt = new (struct LibrosRegistrados);
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