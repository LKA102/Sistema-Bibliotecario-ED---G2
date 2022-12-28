#include "Funciones.h"

//Declarando la matriz de adyacencia de nuestro grafo
int matriz_pesos[7][7] = {
{0, 3, 3, 6, 999, 999, 999},
{3, 0, 999, 1, 999, 7, 999}, 
{3, 999, 0, 999, 5, 7, 999},
{6, 1, 999, 0, 3, 4, 999},
{999, 999, 5, 3, 0, 999, 6},
{999, 7, 7, 4, 999, 0, 4},
{999, 999, 999, 999, 6, 4, 0}
}; 

//Declarando las zonas de nuestra biblioteca
string ubicaciones [7] = {"Banio", "Entrada", "Sala de Informatica", "Cubiculos", "Sala de Hemeroteca", "Sala de Lectura", "Recepcion"};

//Funcion para obtener el nodo con menor distancia en el arreglo que aun no ha sido visitado
int Nodo_Min(int distancia[] , bool visitados[]){ 
    int key = 0; 
    int min = INT_MAX; //INT_MAX es una constante que representa el valor maximo que puede tener un entero
	for(int i = 0; i<NUM_NODOS; i++){
		//La expresión !visitados[i] se utiliza a menudo para comprobar si un nodo ha sido visitado o no 
        if(!visitados[i] && distancia[i]<min){
            min = distancia[i]; //Se quiere encontrar el minimo valor pero de las distancias
            key = i; 
        }
    }
    return key; 
}

//Funcion para mostrar en pantalla
void display(int distancia[] , int par[] ){
   for(int i = 0; i < NUM_NODOS; i++){
       int temp = par[i]; //"temp" variable 
       cout<<endl<<ubicaciones[i]<< " <- ";
       
	   while(temp != -1){
           cout<<ubicaciones[temp] << " <- ";
           temp = par[temp]; 
       }
       
       cout<<endl; 
       cout<<"\tDistancia = " <<distancia[i]<<endl; 
       cout<<endl; 
   } 
}

//Funcion Dijkstra para nuestro grafo
void Dijkstra(int nodoEntrada){
    int par[100] , distancia[100]; 
    bool visitados[100] = {0}; 
    /* Sintaxis: fill(primer_elemento, último_elemento, valor);*/
    fill(distancia, distancia + NUM_NODOS, INT_MAX); 

    distancia[nodoEntrada] = 0; 
    par[nodoEntrada] = -1;
    
    for(int g = 0; g<NUM_NODOS-1; g++){
        int u = Nodo_Min(distancia ,  visitados); 
        visitados[u] = true;
        for(int v = 0; v< NUM_NODOS; v++){
            if(!visitados[v] && (distancia[u]+ matriz_pesos[u][v]) <  distancia[v] && matriz_pesos[u][v]!=999){
                par[v] = u; 
                distancia[v] = distancia[u] + matriz_pesos[u][v]; 
            }
        }
    }
    display(distancia , par) ; 
}

void verMapa(){
    cout<<"\t\t\t================================================"<<endl;
	cout<<"\t\t\t| BIENVENIDO AL MAPA DEL SISTEMA BIBLIOTECARIO |"<<endl;
	cout<<"\t\t\t================================================"<<endl;
	cout<<"\t\t\tNota: Usted podra ubicar las diferentes localizaciones"<<endl;
	cout<<"\t\t\t      de acuerdo a las siguientes designaciones."<<endl<<endl;
	cout<<"\tNodo 0 ---> [Banio]"<<endl;
	cout<<"\tNodo 1 ---> [Entrada]"<<endl;
	cout<<"\tNodo 2 ---> [Sala de Informatica]"<<endl;
	cout<<"\tNodo 3 ---> [Cubiculos]"<<endl;
	cout<<"\tNodo 4 ---> [Sala de Hemeroteca]"<<endl;
	cout<<"\tNodo 5 ---> [Sala de Lectura]"<<endl;
	cout<<"\tNodo 6 ---> [Recepcion]"<<endl;
	cout<<"\t----------------------------------------------------------------------------------"<<endl<<endl;
	
    cout<<"\tMatriz de adyacencia: Mapa del Sistema Bibliotecario"<<endl<<endl;
    cout<<"\t"<<setw(5)<<"0"<<setw(5)<<"1"<<setw(5)<<"2"<<setw(5)<<"3"<<setw(5)<<"4"<<setw(5)<<"5"<<setw(5)<<"6"<<endl;
    cout<<"    ---------------------------------------"<<endl;
   
    for(int i = 0 ;i < NUM_NODOS ; i++){
    	cout<<setw(5)<<i<<"|  ";
        for(int j = 0 ; j< NUM_NODOS ; j++)
			cout<<setw(5)<<matriz_pesos[i][j];
		cout<<endl;
    }
    
    int nodoEntrada; //Nodo de inicio nodoEntrada = nodo inicial
	cout<<"\nIngrese su localizacion actual de acuerdo a los nodos designados --> ";  
	cin>>nodoEntrada;
    Dijkstra(nodoEntrada);
    getch();
    system("cls");
}

