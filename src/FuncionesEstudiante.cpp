#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;

void buscarLibro(){

    system("cls");
    bookListRegister p = listaDisponible;
    while( p != NULL){
		cout<<p->libro.autor<<" "<<p->libro.titulo<<" "<<p->libro.anio_publicacion<<" "<<p->libro.num_paginas<<" "<<endl;
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
            if (aux1->libro.titulo == libro){
                encontrado = true;
                break;
            }
            aux1 = aux1->sgt;
        }
        if (encontrado){
            if (listaSolicitado == NULL){
                nuevo->libro = aux1->libro.titulo;
                nuevo->student->nombre = estudiante->nombre; 
                nuevo->student->correo = estudiante->correo; 
                nuevo->student->codigo = estudiante->codigo;
                listaSolicitado = nuevo; 
                estudiante->librosSolicitados[0] = aux1->libro.titulo;
                estudiante->librosSolicitados[1] = "ESPERA";
                actualizarListaEstudiantes(estudiante);

            }
            else{
                while (aux2->sgt!=NULL)
                    aux2 = aux2->sgt;
                nuevo->libro = aux1->libro.autor;
                nuevo->student->nombre = estudiante->nombre; 
                nuevo->student->correo = estudiante->correo; 
                nuevo->student->codigo = estudiante->codigo;
                aux2->sgt = nuevo;
                estudiante->librosSolicitados[0] = aux1->libro.titulo;
                estudiante->librosSolicitados[1] = "ESPERA";
                actualizarListaEstudiantes(estudiante);
            }
        }
        else{
            cout<<"El libro no existe o no esta disponible"<<endl;
        }
    }
}