#include "Funciones.h"
#define LISTA_REGISTRADOS "LibrosRegistrados.csv"

void menuBibliotecario(){
    std::cout<<"\t\tMENU BIBLIOTECARIO"<<std::endl;
    std::cout<<"[1] Registrar Libros"<<std::endl;
    std::cout<<"[2] Registrar Prestamos"<<std::endl;
    std::cout<<"[3] Consultar Prestamos"<<std::endl;
    std::cout<<"[4] Aceptar o Rechazar solicitud de Prestamo"<<std::endl;
    std::cout<<"[5] Eliminar Libro"<<std::endl;
    std::cout<<"[0] Volver al Menu principal"<<std::endl;
    std::cout<<"Ingrese una opcion: "; 
}


bookListRegister crearNodo (){
    bookListRegister nuevo = new (struct LibrosRegistrados);
    cin.ignore(255, '\n');
    cout<<"Introduzca el nombre del autor del libro"<<endl;
    getline(cin, nuevo->libro.autor);
    cout<<"Introduzca el titulo del libro"<<endl;
    getline(cin, nuevo->libro.titulo);
    cout<<"Introduzca el anio de publicacion"<<endl;
    cin>>nuevo->libro.anio_publicacion;
    cout<<"Introduzca la cantidad de paginas del libro"<<endl;
    cin>>nuevo->libro.num_paginas;
    nuevo->sgt = NULL;
    return nuevo;
}

void RegistrarLibro(bookListRegister &listaRegistro){
    bookListRegister aux = NULL;
    if (listaRegistro == NULL){
        listaRegistro = crearNodo();
    }
    else{
        aux = crearNodo();
        aux->sgt = listaRegistro;
        listaRegistro = aux;
    }
    cout<<"Registrando libro...."<<endl;
    Sleep(1000);
    cout<<"Libro registrado con exito"<<endl;
    system("pause");
}

void RegistrarLibroArchivo(bookListRegister &listaRegistro){
    bookListRegister aux = listaRegistro;
    ofstream archivo (LISTA_REGISTRADOS);
    if (archivo.is_open()){
        while (aux!=NULL){
            archivo<<aux->libro.autor<<","<<aux->libro.titulo<<","<<aux->libro.anio_publicacion<<","<<aux->libro.num_paginas<<endl;
            aux = aux->sgt;
        }
    }
    else{
        cout<<"Hubo problemas para abrir archivo"<<endl;
    }
    archivo.close();

}

