#include "Funciones.h"

using namespace std;

//esta funcion me permite centrar el texto a una posicion dada
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

//esta funcion me permite invocar el principal donde interactua el bibliotecario y el estudiante
void menuPrincipal(){
    system("cls");
    gotoxy(30,0);
    cout<<"*************************************"<<endl;
    gotoxy(30,1);
    cout<<"*-------SISTEMA BIBLIOTECARIO-------*"<<endl;
    gotoxy(30,2);
    cout<<"*************************************"<<endl<<endl<<endl;
    gotoxy(30,5);
    cout<<"*************************************"<<endl;
    gotoxy(30,6);
    cout<<"*         [1] Bibliotecario         *"<<endl;
    gotoxy(30,7);
    cout<<"*         [2] Estudiante            *"<<endl;
    gotoxy(30,8);
    cout<<"*         [0] Salir                 *"<<endl;
    gotoxy(30,9);
    cout<<"*************************************"<<endl;
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

//esta funcion me permite invocar el menu que es exclusivo para el estudiante
void menuEstudiante(){
    system("cls");
    gotoxy(30,0);
    cout<<"*********************************************"<<endl;
    gotoxy(30,1);
    cout<<"*   SISTEMA BIBLIOTECARIO DEL ESTUDIANTE    *"<<endl;
    gotoxy(30,2);
    cout<<"*********************************************"<<endl<<endl<<endl;
    gotoxy(30,5);
    cout<<"---------------------------------------------"<<endl;
    gotoxy(30,6);
    cout<<"|      [1] Ingresar al sistema              |"<<endl;
    gotoxy(30,7);
    cout<<"|      [2] Registrar nuevo estudiante       |"<<endl;
    gotoxy(30,8);
    cout<<"|      [0] Volver                           |"<<endl;
    gotoxy(30,9);
    cout<<"---------------------------------------------"<<endl;
}