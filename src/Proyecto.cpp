#include "Funciones.h"

using namespace std;

int main(){
    int opc, opcEst, opcReg;
    string nomUsu,pasUsu,codEst,nomEst,corEst;
    do{
        menuPrincipal();
        gotoxy(30,10);
        cout<<"opcion -->";cin>>opc;        
        gotoxy(30,11);
        switch(opc){
            case 1:{
                system("cls");
                gotoxy(30,0);
                cout<<"Ingrese usuario"<<endl;
                gotoxy(30,1);
                cin>>nomUsu;
                gotoxy(30,2);
                cout<<"Ingrese password"<<endl;
                gotoxy(30,3);
                //cin>>pasUsu;
                char key;
                pasUsu="";
                key = getch();
                while (key != 13){
                    if (key != 8){
                        pasUsu.push_back(key);
                        cout<<"*";
                    }
                    else{
                        if (pasUsu.length()>0){
                            cout<<"\b \b";
                            pasUsu = pasUsu.substr(0, pasUsu.length()-1);
                        }
                    }
                    key = getch();
                }
                cout<<endl;
                if(ingresarSistemaBibliotecario(nomUsu,pasUsu) == 1){
                    system("cls");
                    Sleep(1000);
                    sistemaBibliotecario();
                }
                else{
                    gotoxy(30,5);
                    cout<<"Sus credenciales no son correctas"<<endl;
                    gotoxy(30,6);
                    system("pause");
                }
                break;
            }               
            case 2:{                                  
                system("cls");
                do{
                    menuEstudiante(); 
                    gotoxy(30,10);
                    cout<<"opcion -->";cin>>opcEst;
                    switch(opcEst){
                        case 1:{
                            system("cls");
                            gotoxy(30,0);
                            cout<<"Ingrese su codigo de estudiante"<<endl;
                            gotoxy(30,1);
                            cin>>codEst;
                            gotoxy(30,2);
                            if(ingresarSistemaEstudiante(codEst) == 1){
                                system("cls");
                                sistemaEstudiante();
                            }
                            else
                                cout<<"No esta registrado en el sistema"<<endl;
                            gotoxy(30,3);
                            system("pause");
                            break;
                        }
                        case 2:{
                            system("cls");
                            gotoxy(30,0);
                            cout<<"Ingrese nombre de usuario"<<endl;
                            gotoxy(30,1);
                            cin>>nomEst;
                            gotoxy(30,2);
                            cout<<"Ingrese correo institucional"<<endl;
                            gotoxy(30,3);
                            cin>>corEst;
                            gotoxy(30,4);
                            cout<<"Ingrese codigo de estudiante"<<endl;
                            gotoxy(30,5);
                            cin>>codEst;
                            gotoxy(30,6);
                            cout<<"Presione 1 para registrar o 0 para cancelar"<<endl;
                            gotoxy(30,7);
                            cin>>opcReg;
                            gotoxy(30,8);
                            if(opcReg == 1){
                                registrarEstudiante(nomEst,corEst,codEst);                               
                                cout<<"Usted se acaba de registrar"<<endl;
                            }
                            gotoxy(30,9);
                            system("pause");
                            break;
                        }
                    }
                }while(opcEst != 0);               
                //system("pause");
                break;
            }    
        }       
    }while(opc != 0);
    system("pause");
    return 0;
}