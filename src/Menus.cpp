#include "Funciones.h"

using namespace std;

void menuPrincipal(){
    system("cls");
    cout<<"Sistema bibliotecario "<<endl;
    cout<<"1.- Bibliotecario"<<endl;
    cout<<"2.- Estudiante"<<endl;
    cout<<"0.- salir"<<endl;
}

void sistemaBibliotecario(){
    int opc;
    do{
        system("cls");
        menuBibliotecario();
        cin>>opc;
        switch(opc){
            
        } 
    }while (opc!=0);

}

void sistemaEstudiante(){
    
}

void menuEstudiante(){
    system("cls");
    cout<<"Sistema bibliotecario del estudiante"<<endl;
    cout<<"1.- Ingresar al sistema"<<endl;
    cout<<"2.- Registrar nuevo estudiante"<<endl;
    cout<<"0.- volver"<<endl;
}