#include "Funciones.h"

//esta funcion me permite invocar el menu que es exclusivo para el bibliotecario
void menuBibliotecario(){
    gotoxy(30,0);
    std::cout<<"****************************************************"<<std::endl;
    gotoxy(30,1);
    std::cout<<"*                 MENU BIBLIOTECARIO               *"<<std::endl;
    gotoxy(30,2);
    std::cout<<"****************************************************"<<std::endl<<std::endl<<std::endl;
    gotoxy(30,5);
    std::cout<<"----------------------------------------------------"<<std::endl;
    gotoxy(30,6);
    std::cout<<"|    [1] Registrar Libros                          |"<<std::endl;
    gotoxy(30,7);
    std::cout<<"|    [2] Registrar Prestamos                       |"<<std::endl;
    gotoxy(30,8);
    std::cout<<"|    [3] Consultar Prestamos                       |"<<std::endl;
    gotoxy(30,9);
    std::cout<<"|    [4] Aceptar o Rechazar solicitud de Prestamo  |"<<std::endl;
    gotoxy(30,10);
    std::cout<<"|    [5] Eliminar Libro                            |"<<std::endl;
    gotoxy(30,11);
    std::cout<<"----------------------------------------------------"<<std::endl;
    gotoxy(30,12);
    std::cout<<"Ingrese una opcion: "; 
}