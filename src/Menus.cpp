#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;


void menuPrincipal(){
    system("cls");
    cout<<"Sistema bibliotecario "<<endl;
    cout<<"1.- Bibliotecario"<<endl;
    cout<<"2.- Estudiante"<<endl;
    cout<<"0.- salir"<<endl;
}


//Menu del Bibliotecario después de iniciar sesion
void sistemaBibliotecario(){
    int opc;
    
    do{
        system("cls");
        menuBibliotecario();
        cin>>opc;
        switch(opc){
            case 1:
                system("cls");
                RegistrarLibro(listaDisponible);
                ActualizarLibroDisponibleArchivo(listaDisponible);
                break;
            case 2:
                system("cls");
                analizarSolicitud(listaDisponible, listaSolicitado, listaPrestado);
            
               
        } 
    }while (opc!=0);

}

//Menu para el estudiante después de iniciar sesion
void sistemaEstudiante(){
    int opc;
    
    do{
        system("cls");
        menuEstudiante2();
        cin>>opc;
        switch(opc){
            case 1: 
                buscarLibro();
                break;
            case 2:
                SolicitarLibro(listaDisponible, listaSolicitado);
                break;
            case 3:
                verEstadoSolicitud();
                break;
            case 0:
                delete(estudiante);
                estudiante = NULL;
                break;

        } 
    } while (opc!=0);
    
}

void menuEstudiante(){
    system("cls");
    cout<<"Sistema bibliotecario del estudiante"<<endl;
    cout<<"1.- Ingresar al sistema"<<endl;
    cout<<"2.- Registrar nuevo estudiante"<<endl;
    cout<<"0.- volver"<<endl;
}

void menuEstudiante2(){
    system("cls");
    cout<<"Sistema bibliotecario del estudiante"<<endl;
    cout<<"1.- Buscar Libros Disponibles"<<endl;
    cout<<"2.- Solicitar Libro"<<endl;
    cout<<"3.- Ver Estado de Libro Solicitado"<<endl;
    cout<<"0.- volver"<<endl;
}

