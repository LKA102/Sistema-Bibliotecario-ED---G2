#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;

void rellenarListaDisponible(bookListRegister &listaDisponible){
    bookListRegister aux = NULL;
    ifstream archivo (LISTA_DISPONIBLES);
    string linea, anio, paginas;
    char delimitador = ',';
    if (archivo.is_open()){
        while (getline(archivo, linea)){
            stringstream stream(linea);
            if (listaDisponible == NULL){
                listaDisponible = new (struct LibrosDisponibles);
                getline(stream, listaDisponible->libro->autor,delimitador);
                getline(stream, listaDisponible->libro->titulo,delimitador);
                getline(stream, anio,delimitador);
                getline(stream, paginas,delimitador);
                listaDisponible->libro->anio_publicacion = std::stoi(anio);
                listaDisponible->libro->num_paginas = std::stoi(paginas);
                aux = listaDisponible;
            }
            else{
            aux -> sgt = new (struct LibrosDisponibles);
            getline(stream, aux->sgt->libro->autor,delimitador);
            getline(stream, aux->sgt->libro->titulo,delimitador);
            getline(stream, anio,delimitador);
            getline(stream, paginas,delimitador);
            aux->sgt->libro->anio_publicacion = std::stoi(anio);
            aux->sgt->libro->num_paginas = std::stoi(paginas);
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

void rellenarListaSolicitado (bookListRequest &listaSolicitado){
    bookListRequest aux = NULL;
    ifstream archivo (LISTA_SOLICITADOS);
    string linea, anio, paginas;
    char delimitador = ',';
    if (archivo.is_open()){
        while (getline(archivo, linea)){
            stringstream stream(linea);
            if (listaSolicitado == NULL){
                listaSolicitado = new (struct LibrosSolicitados);
                getline(stream, listaSolicitado->libro->autor,delimitador);
                getline(stream, listaSolicitado->libro->titulo,delimitador);
                getline(stream, anio,delimitador);
                getline(stream, paginas,delimitador);
                getline(stream, listaSolicitado->student->codigo,delimitador);
                getline(stream, listaSolicitado->student->nombre,delimitador);
                getline(stream, listaSolicitado->student->correo,delimitador);
                listaSolicitado->libro->anio_publicacion = std::stoi(anio);
                listaSolicitado->libro->num_paginas = std::stoi(paginas);
                aux = listaSolicitado;
            }
            else{
            aux -> sgt = new (struct LibrosSolicitados);
            getline(stream, aux->sgt->libro->autor,delimitador);
            getline(stream, aux->sgt->libro->titulo,delimitador);
            getline(stream, anio,delimitador);
            getline(stream, paginas,delimitador);
            getline(stream, aux->sgt->student->codigo,delimitador);
            getline(stream, aux->sgt->student->nombre,delimitador);
            getline(stream, aux->sgt->student->correo,delimitador);
            aux->sgt->libro->anio_publicacion = std::stoi(anio);
            aux->sgt->libro->num_paginas = std::stoi(paginas);
            aux = aux->sgt;
            }

        }
    }
    archivo.close();
}

void rellenarListaPrestado (bookListLent &listaPrestado){
    bookListLent aux = NULL;
    ifstream archivo (LISTA_PRESTADOS);
    string linea, anio, paginas;
    char delimitador = ',';
    if (archivo.is_open()){
        while (getline(archivo, linea)){
            stringstream stream(linea);
            if (listaPrestado == NULL){
                listaPrestado = new (struct LibrosPrestados);
                getline(stream, listaPrestado->libro->autor,delimitador);
                getline(stream, listaPrestado->libro->titulo,delimitador);
                getline(stream, anio,delimitador);
                getline(stream, paginas,delimitador);
                getline(stream, listaPrestado->student->codigo,delimitador);
                getline(stream, listaPrestado->student->nombre,delimitador);
                getline(stream, listaPrestado->student->correo,delimitador);
                listaPrestado->libro->anio_publicacion = std::stoi(anio);
                listaPrestado->libro->num_paginas = std::stoi(paginas);
                aux = listaPrestado;
            }
            else{
            aux -> sgt = new (struct LibrosPrestados);
            getline(stream, aux->sgt->libro->autor,delimitador);
            getline(stream, aux->sgt->libro->titulo,delimitador);
            getline(stream, anio,delimitador);
            getline(stream, paginas,delimitador);
            getline(stream, aux->sgt->student->codigo,delimitador);
            getline(stream, aux->sgt->student->nombre,delimitador);
            getline(stream, aux->sgt->student->correo,delimitador);
            aux->sgt->libro->anio_publicacion = std::stoi(anio);
            aux->sgt->libro->num_paginas = std::stoi(paginas);
            aux = aux->sgt;
            }

        }
    }
    archivo.close();
}


void ActualizarLibroDisponibleArchivo(bookListRegister &listaDisponible){
    bookListRegister aux = listaDisponible;
    ofstream archivo (LISTA_DISPONIBLES);
    if (archivo.is_open()){
        while (aux!=NULL){
            archivo<<aux->libro->autor<<","<<aux->libro->titulo<<","<<aux->libro->anio_publicacion<<","<<aux->libro->num_paginas<<endl;
            aux = aux->sgt;
        }

        archivo.close();
    }
    else{
        cout<<"Hubo problemas para abrir archivo"<<endl;
    }
    

}

void ActualizarLibroSolicitadoArchivo(bookListRequest &listaSolicitado){
    bookListRequest aux = listaSolicitado;
    ofstream archivo (LISTA_SOLICITADOS);
    if(archivo.is_open()){
        while (aux!=NULL){
            archivo<<aux->libro->autor<<","<<aux->libro->titulo<<","<<aux->libro->anio_publicacion<<","<<aux->libro->num_paginas<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
            aux = aux->sgt;
        }

        archivo.close();
    }
    else{
        cout<<"Hubo problemas para abrir archivo"<<endl;
    }
}



void ActualizarLibroPrestadoArchivo(bookListLent &listaPrestado){
    bookListLent aux = listaPrestado;
    ofstream archivo (LISTA_PRESTADOS);
    if(archivo.is_open()){
        while (aux!=NULL){
            archivo<<aux->libro->autor<<","<<aux->libro->titulo<<","<<aux->libro->anio_publicacion<<","<<aux->libro->num_paginas<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
            aux = aux->sgt;
        }

        archivo.close();
    }
    else{
        cout<<"Hubo problemas para abrir archivo"<<endl;
    }
}