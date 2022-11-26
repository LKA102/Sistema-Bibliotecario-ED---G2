#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaRegistro;

void buscarLibro(){

    system("cls");
    bookListRegister p = listaRegistro;
    while( p != NULL){
		cout<<p->libro.autor<<" "<<p->libro.titulo<<" "<<p->libro.anio_publicacion<<" "<<p->libro.num_paginas<<" "<<endl;
		p=p->sgt;
	}
    system("pause");

}