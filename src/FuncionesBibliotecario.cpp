#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;


void menuBibliotecario(){
    std::cout<<"\t\t\t*****************************************"<<endl;
    std::cout<<"\t\t\t*-----------MENU BIBLIOTECARIO----------*"<<endl;
    std::cout<<"\t\t\t*****************************************"<<endl;
    std::cout<<"\t\t\t*****************************************"<<endl;
    std::cout<<"\t\t\t*         [1] Registrar Libros          *"<<endl;
    std::cout<<"\t\t\t*         [2] Evaluar Prestamos         *"<<endl;
    std::cout<<"\t\t\t*         [3] Consultar Prestamos       *"<<endl;
    std::cout<<"\t\t\t*         [4] Eliminar Libro            *"<<endl;
    std::cout<<"\t\t\t*         [0] Volver al Menu principal  *"<<endl;
    std::cout<<"\t\t\t*****************************************"<<endl;
    std::cout<<"\t\t\tIngrese una opcion: ";
    
}


bookListRegister crearNodo (){
    bookListRegister nuevo = new (struct LibrosDisponibles);
    cin.ignore(255, '\n');
    cout<<"Introduzca el nombre del autor del libro"<<endl;
    getline(cin, nuevo->libro->autor);
    cout<<"Introduzca el titulo del libro"<<endl;
    getline(cin, nuevo->libro->titulo);
    cout<<"Introduzca el anio de publicacion"<<endl;
    cin>>nuevo->libro->anio_publicacion;
    cout<<"Introduzca la cantidad de paginas del libro"<<endl;
    cin>>nuevo->libro->num_paginas;
    return nuevo;
}

void RegistrarLibro(bookListRegister &listaDisponible){
    bookListRegister nuevo = crearNodo();
    bookListRegister p = listaDisponible;
    if (listaDisponible == NULL){
        listaDisponible = nuevo;
    }
    else{
        nuevo->sgt = listaDisponible;
        listaDisponible = nuevo;
    }
    cout<<"Registrando libro...."<<endl;
    Sleep(1000);
    cout<<"Libro registrado con exito"<<endl;
    system("pause");
}


void analizarSolicitud(bookListRegister &listaDisponible, bookListRequest &listaSolicitado, bookListLent &listaPrestado){
    verSolicitudes(listaSolicitado);
    bool encontrado = false;
    bookListRequest auxR = listaSolicitado, auxR2 = NULL;
    if (listaSolicitado == NULL)
        cout<<"No existe ningun registro de solicitud"<<endl;
    else{
        cin.ignore(255, '\n');
        string libroSolicitado, libroEnLista;
        cout<<"Escriba el nombre del libro a analizar"<<endl; getline(cin,libroSolicitado);
        for (auto & c: libroSolicitado) 
            c = toupper(c);
        while (auxR != NULL){
            //Para eliminar el nodo de la lista de solicitudes, hacer lo mismo que hiciste en la lista Disponible con aux1 y aux2
            libroEnLista = auxR->libro->titulo;
            for (auto & c: libroEnLista) 
                c = toupper(c);
            if (libroSolicitado == libroEnLista){
                encontrado = true;
                break;
            }
            auxR2 = auxR;
            auxR = auxR->sgt;
        }
        if (encontrado){
            unsigned opc;
            cout<<"Presione [1] para Aceptar Solicitud o [2] para Rechazar Solicitud"<<endl;
            cin>>opc;
            switch (opc){
            case 1:
                EliminarLibroSolicitud(auxR2, auxR, listaSolicitado);
                TrasladarLibroSolicitudAPrestado(auxR, listaPrestado);
                ActualizarLibroSolicitadoArchivo(listaSolicitado);
                ActualizarLibroPrestadoArchivo(listaPrestado);
                estudiante = auxR->student;
                estudiante->librosSolicitados[0] = auxR->libro->titulo;
                estudiante->librosSolicitados[1] = "ACEPTADO";
                actualizarListaEstudiantes(estudiante);
                estudiante = NULL;
                cout<<"Solicitud aceptada"<<endl;
                system("pause");
                break;
                //Trasladar nodo auxR a la lista de libros Prestados (modificar listaLibroSolicitado para ello)
                /*//Actualiza estado de la solicitud de libro del estudiante que lo solicito
                //Actualizar archivos csv de las listas
                //Mostrar mensaje que ya se aceptó el préstamo
                break;*/
            
            case 2:

                EliminarLibroSolicitud(auxR2, auxR, listaSolicitado);
                ActualizarLibroSolicitadoArchivo(listaSolicitado);
                estudiante = auxR->student;
                estudiante->librosSolicitados[0] = auxR->libro->titulo;
                estudiante->librosSolicitados[1] = "RECHAZADO";
                actualizarListaEstudiantes(estudiante);
                estudiante = NULL;
                RetornarLibro(auxR, listaDisponible);
                ActualizarLibroDisponibleArchivo(listaDisponible);
                cout<<"Solicitud rechazada"<<endl;
                system("pause");
                break;
                //Se elimina el nodo auxR de la lista de libros solicitados
                //Actaliza estado de la solicitud de libro deñ estudiante
                //Actualizar archivos csv de las listas (solo solicitados)
                //Mostrar mensaje que ya se rechazó el prestamo
            }
        }
        else{
            cout<<"El libro no se encuentra en la lista de solicitudes"<<endl;
        }
    }
}

void eliminarLibro(bookListRegister &listaDisponible){
    buscarLibro();
    bookListRegister aux = listaDisponible, aux2 = NULL;
    bool encontrado = false;
    if (listaDisponible == NULL)
        cout<<"No existe ningun libro disponible"<<endl;
    else{
        cin.ignore(255, '\n');
        string libroEliminar, libroEnLista;
        cout<<"Escriba el nombre del libro a eliminar"<<endl; getline(cin,libroEliminar);
        for (auto & c: libroEliminar) 
            c = toupper(c);
        while (aux != NULL){           
            libroEnLista = aux->libro->titulo;
            for (auto & c: libroEnLista) 
                c = toupper(c);
            if (libroEliminar == libroEnLista){
                encontrado = true;
                break;
            }
            aux2 = aux;
            aux = aux->sgt;
        }
        if (encontrado){
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
            ActualizarLibroDisponibleArchivo(listaDisponible);
            cout<<"\nRPTA: Libro eliminado"<<endl;
            system("pause");
        }
        else{
            cout<<"\nRPTA: El libro no existe"<<endl;
            system("pause");
        }
    }

}
