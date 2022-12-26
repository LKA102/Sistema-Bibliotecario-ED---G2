#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;

void verSolicitudes (bookListRequest &listaSolicitado){
bookListRequest aux = listaSolicitado;
cout<<"LISTA DE LIBROS SOLICITADOS"<<endl;
while (aux != NULL){
    cout<<aux->libro->titulo<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
    aux = aux->sgt;
}
system("pause");
}


void verPrestados (bookListLent &listaPrestado){
bookListLent aux = listaPrestado;
cout<<"LISTA DE LIBROS PRESTADOS"<<endl;
while (aux != NULL){
    cout<<aux->libro->titulo<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
    aux = aux->sgt;
}
system("pause");
}


void EliminarLibroDisponible(bookListRequest &LibroEliminar, bookListRegister &listaDisponible){
    Libro nombreLibro = LibroEliminar->libro;
    bookListRegister aux = listaDisponible, aux2 = NULL;
    while (aux->libro != nombreLibro){
        aux2 = aux;
        aux = aux->sgt;
    }
    if (aux2==NULL){
        if (aux->sgt == NULL){
            delete(aux);
            listaDisponible = NULL;
        }
        else{
            listaDisponible = aux->sgt;
            delete(aux);
        }
    }
    else{
        aux2->sgt = aux->sgt;
        delete(aux);
    }
}

void TrasladarLibroSolicitudAPrestado(bookListRequest &LibroSolicitudEliminar, bookListLent &listaPrestado){
    bookListLent p = listaPrestado;
    if (listaPrestado == NULL){
        listaPrestado = (bookListLent)LibroSolicitudEliminar;
    }
    else{
        while (p->sgt != NULL)
            p = p->sgt;
        p->sgt = (bookListLent)LibroSolicitudEliminar;

    }
}

void EliminarLibroSolicitud(bookListRequest &LibroAnterior, bookListRequest &LibroActual, bookListRequest &listaSolicitado){
    if (LibroAnterior == NULL){
        listaSolicitado = listaSolicitado->sgt;
        LibroActual->sgt = NULL;
    }
    else{
        LibroAnterior->sgt = LibroActual->sgt;
        LibroActual->sgt = NULL;
    }
}

void RetornarLibro(bookListRequest &LibroEliminar, bookListRegister &listaDisponible){
    bookListRequest aux = LibroEliminar;
    if (listaDisponible == NULL){
        listaDisponible = new (struct LibrosDisponibles);
        listaDisponible->libro = aux->libro;
        aux->libro = NULL;
        delete(aux);
    }
    else{
        bookListRegister p = listaDisponible;
        bookListRegister nuevo = new (struct LibrosDisponibles);
        while (p->sgt != NULL)
            p = p->sgt;
        nuevo->libro = aux->libro;
        p->sgt = nuevo;
        aux->libro = NULL;
        delete(aux);
    }
}