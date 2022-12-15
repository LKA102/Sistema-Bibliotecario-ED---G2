#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;

void verSolicitudes (bookListRequest &listaSolicitado){
bookListRequest aux = listaSolicitado;
cout<<"LISTA DE LIBROS SOLICITADOS"<<endl;
while (aux != NULL){
    cout<<aux->libro<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
    aux = aux->sgt;
}
system("pause");
}


void verPrestados (bookListLent &listaPrestado){
bookListLent aux = listaPrestado;
cout<<"LISTA DE LIBROS PRESTADOS"<<endl;
while (aux != NULL){
    cout<<aux->libro<<","<<aux->student->codigo<<","<<aux->student->nombre<<","<<aux->student->correo<<endl;
    aux = aux->sgt;
}
system("pause");
}


void EliminarLibroDisponible(bookListRequest &LibroEliminar, bookListRegister &listaDisponible){
    string nombreLibro = LibroEliminar->libro;
    bookListRegister aux = listaDisponible, aux2 = NULL;
    while (aux->libro.titulo != nombreLibro){
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

//TrasladarLibroSolicitudAPrestado()