#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"

using namespace std;

int main(){
    int opc, opcEst, opcReg;
    string nomUsu,pasUsu,codEst,nomEst,corEst;
    do{
        menuPrincipal();
        cin>>opc;
        switch(opc){
            case 1:{
                system("cls");
                cout<<"Ingrese usuario"<<endl;
                cin>>nomUsu;
                cout<<"Ingrese password"<<endl;
                cin>>pasUsu;
                if(ingresarSistemaBibliotecario(nomUsu,pasUsu) == 1){
                    system("cls");
                    sistemaBibliotecario();
                }
                else
                    cout<<"Sus credenciales no son correctas"<<endl;
                system("pause");
                break;
            }               
            case 2:{                                  
                system("cls");
                do{
                    menuEstudiante(); 
                    cin>>opcEst;
                    switch(opcEst){
                        case 1:{
                            system("cls");
                            cout<<"Ingrese su codigo de estudiante"<<endl;
                            cin>>codEst;
                            if(ingresarSistemaEstudiante(codEst) == 1){
                                system("cls");
                                sistemaEstudiante();
                            }
                            else
                                cout<<"No esta registrado en el sistema"<<endl;
                            system("pause");
                            break;
                        }
                        case 2:{
                            system("cls");
                            cout<<"Ingrese nombre de usuario"<<endl;
                            cin>>nomEst;
                            cout<<"Ingrese correo institucional"<<endl;
                            cin>>corEst;
                            cout<<"Ingrese codigo de estudiante"<<endl;
                            cin>>codEst;
                            cout<<"Presione 1 para registrar o 0 para cancelar"<<endl;
                            cin>>opcReg;
                            if(opcReg == 1){
                                cout<<"Usted se acaba de registrar"<<endl;
                            }
                            system("pause");
                            break;
                        }
                    }
                }while(opcEst != 0);               
                system("pause");
                break;
            }    
        }
        
    }while(opc != 0);
    system("pause");
    return 0;
}