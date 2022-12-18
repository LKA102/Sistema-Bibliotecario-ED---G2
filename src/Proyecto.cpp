#include "Funciones.h"

 Student estudiante = NULL;
 bookListRegister listaDisponible = NULL;
 bookListRequest listaSolicitado = NULL;
 bookListLent listaPrestado = NULL;




int main(){
    int opc, opcEst, opcReg;
    string nomUsu,pasUsu,codEst,nomEst,corEst;
    rellenarListaDisponible(listaDisponible);
    rellenarListaSolicitado(listaSolicitado);
    rellenarListaPrestado(listaPrestado);
    do{
        menuPrincipal();
        cin>>opc;
        switch(opc){
            case 1:{
                system("cls");
                cout<<"Ingrese usuario"<<endl;
                cin>>nomUsu;
                cout<<"Ingrese password"<<endl;
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
                    cout<<"Bienvenido bibliotecario"<<endl;
                    Sleep(1000);
                    sistemaBibliotecario();
                }
                else{
                    cout<<"Sus credenciales no son correctas"<<endl;
                    system("pause");
                }
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
                            cin.ignore(255,'\n');
                            cout<<"Ingrese nombre de usuario"<<endl;
                            getline(cin,nomEst);
                            cout<<"Ingrese correo institucional"<<endl;
                            getline(cin,corEst);
                            cout<<"Ingrese codigo de estudiante"<<endl;
                            getline(cin,codEst);
                            cout<<"Presione 1 para registrar o 0 para cancelar"<<endl;
                            cin>>opcReg;
                            if(opcReg == 1){
                                registrarEstudiante(nomEst,corEst,codEst);
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