#include "Funciones.h"
extern Student estudiante;
extern bookListRegister listaDisponible;
extern bookListRequest listaSolicitado;
extern bookListLent listaPrestado;


void menuPrincipal(){
    system("cls");
    cout<<"\t\t\t*************************************"<<endl;
    cout<<"\t\t\t*-------SISTEMA BIBLIOTECARIO-------*"<<endl;
    cout<<"\t\t\t*************************************"<<endl;
    cout<<"\t\t\t*************************************"<<endl;
    cout<<"\t\t\t*         [1] Bibliotecario         *"<<endl;
    cout<<"\t\t\t*         [2] Estudiante            *"<<endl;
    cout<<"\t\t\t*         [0] Salir                 *"<<endl;
    cout<<"\t\t\t*************************************"<<endl;
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
                break;
            case 3:
                system("cls");
                verPrestados(listaPrestado);
                break;
            case 4:
                system("cls");
                eliminarLibro(listaDisponible);
                break;
        } 
    } while (opc!=0);
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
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t*-------SISTEMA BIBLIOTECARIO DEL ESTUDIANTE-------*"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t*           [1] Ingresar al sistema                *"<<endl;
    cout<<"\t\t\t*           [2] Registrar nuevo estudiante         *"<<endl;
    cout<<"\t\t\t*           [0] Volver                             *"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
}

void menuEstudiante2(){
    system("cls");
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t*-------SISTEMA BIBLIOTECARIO DEL ESTUDIANTE-------*"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"\t\t\t*        [1] Buscar Libros Disponibles             *"<<endl;
    cout<<"\t\t\t*        [2] Solicitar Libro                       *"<<endl;
    cout<<"\t\t\t*        [3] Ver Estado de Libro Solicitado        *"<<endl;
    cout<<"\t\t\t*        [0] Volver                                *"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
}

