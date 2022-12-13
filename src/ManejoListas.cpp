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

//EliminarLibroDisponible();
//TrasladarLibroSolicitudAPrestado()