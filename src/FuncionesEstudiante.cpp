#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;

void buscarLibro(){

    system("cls");
    bookListRegister p = listaDisponible;
    cout<<"LISTA DE LIBROS DISPONIBLES"<<endl;
    while( p != NULL){
		cout<<p->libro->autor<<" "<<p->libro->titulo<<" "<<p->libro->anio_publicacion<<" "<<p->libro->num_paginas<<" "<<endl;
		p=p->sgt;
	}
    system("pause");
}

void SolicitarLibro(bookListRegister &listaDisponible, bookListRequest &listaSolicitado){
    
    bookListRegister aux1 = listaDisponible;
    bookListRequest aux2 = listaSolicitado;
    bookListRequest nuevo = new (struct LibrosSolicitados);
    bool encontrado = false;

    if (listaDisponible == NULL){
        cout<<"No existen libros disponibles para pedir prestado"<<endl;
    }
    else{
        cin.ignore(255, '\n');
        string libro;
        cout<<"Escriba el nombre del libro que desea solicitar: "<<endl;
        getline(cin, libro);
        while (aux1!= NULL){
            if (aux1->libro->titulo == libro){
                encontrado = true;
                break;
            }
            aux1 = aux1->sgt;
        }
        if (encontrado){
            if (listaSolicitado == NULL){
                if (estudiante->librosSolicitados[1] != "ESPERA"){
                    nuevo->libro = aux1->libro;
                    nuevo->student->nombre = estudiante->nombre; 
                    nuevo->student->correo = estudiante->correo; 
                    nuevo->student->codigo = estudiante->codigo;
                    listaSolicitado = nuevo; 
                    estudiante->librosSolicitados[0] = aux1->libro->titulo;
                    estudiante->librosSolicitados[1] = "ESPERA";
                    actualizarListaEstudiantes(estudiante);
                    ActualizarLibroSolicitadoArchivo(listaSolicitado);
                    EliminarLibroDisponible(nuevo, listaDisponible);
                    ActualizarLibroDisponibleArchivo(listaDisponible);
                }
                else{
                    cout<<"Ya tiene un solicitud de libro en espera"<<endl;
                    system("pause");
                }
            }
            else{
                while (aux2->sgt!=NULL)
                    aux2 = aux2->sgt;
                 if(estudiante->librosSolicitados[1] != "ESPERA"){
                    nuevo->libro = aux1->libro;
                    nuevo->student->nombre = estudiante->nombre; 
                    nuevo->student->correo = estudiante->correo; 
                    nuevo->student->codigo = estudiante->codigo;
                    aux2->sgt = nuevo;
                    estudiante->librosSolicitados[0] = aux1->libro->titulo;
                    estudiante->librosSolicitados[1] = "ESPERA";
                    actualizarListaEstudiantes(estudiante);
                    ActualizarLibroSolicitadoArchivo(listaSolicitado);
                    EliminarLibroDisponible(nuevo, listaDisponible);
                    ActualizarLibroDisponibleArchivo(listaDisponible);
                }
                else{
                    cout<<"Ya tiene un solicitud de libro en espera"<<endl;
                    system("pause");
                }
            }
        }
        else{
            cout<<"El libro no existe o no esta disponible"<<endl;
            system("pause");
        }
    }
}

void verEstadoSolicitud (){
    system("cls");
    unsigned opcion;
    cout<<"ESTADO DE SOLICITUD DE LIBRO"<<endl;
    cout<<estudiante->librosSolicitados[0]<<" -> "<<estudiante->librosSolicitados[1]<<endl;
    getch();
    if (estudiante->librosSolicitados[1] == "ACEPTADO"){
        cout<<"Desea devolver el libro? [1] Si, [2] No"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                DevolverLibro(listaPrestado, listaDisponible);
                estudiante->librosSolicitados[0] = " ";
                estudiante->librosSolicitados[1] = " ";
                ActualizarLibroDisponibleArchivo(listaDisponible);
                ActualizarLibroPrestadoArchivo(listaPrestado);
                actualizarListaEstudiantes(estudiante);
                cout<<"Libro Devuelto"<<endl;
                system("pause");
                break;
            case 2:
                cout<<"Ok"<<endl;
                system("pause");
                break;
       }
    }

}

void DevolverLibro(bookListLent &listaPrestado, bookListRegister &listaDisponible){
    bookListLent aux = listaPrestado;
    bookListLent aux2 = NULL;
    while (aux != NULL){
        if (aux->libro->titulo == estudiante->librosSolicitados[0])
            break;
        aux2 = aux;
        aux = aux->sgt;
    }
    if (aux2 == NULL){
        listaPrestado = listaPrestado->sgt;
        aux->sgt = NULL;
    }
    else{
        aux2->sgt = aux->sgt;
        aux->sgt = NULL;
    }

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


