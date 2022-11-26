#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaRegistro;


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
                RegistrarLibro(listaRegistro);
                RegistrarLibroArchivo(listaRegistro);
                break;

            case 4:
                delete(estudiante);
                estudiante = NULL;
                opc = 0;
                break;
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
    cout<<"1.- Buscar Libro"<<endl;
    cout<<"2.- Registrar nuevo estudiante"<<endl;
    cout<<"0.- volver"<<endl;
}

