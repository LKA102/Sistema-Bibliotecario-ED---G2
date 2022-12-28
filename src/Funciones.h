#pragma once

#include <iostream> //cout y cin
#include <conio.h> //Uso funcion getch
#include <vector> //Usamos sus funciones para actualizar archivo estudiantes
#include <stdlib.h>
#include <fstream> //Uso de archivos
#include <time.h> //Funcion sleep
#include <sstream> //Tipo de dato stringstream
#include <string> //Uso de strings en CPP
#include <windows.h> //Funciones System
#include <iomanip> //Funcion setw

//Apodos de los archivos (constantes)
#define NOMBRE_BIBLIOTECARIO "Bibliotecario.csv"
#define NOMBRE_ESTUDIANTE "Estudiantes.csv"
#define LISTA_DISPONIBLES "LibrosDisponibles.csv"
#define LISTA_SOLICITADOS "LibrosSolicitados.csv"
#define LISTA_PRESTADOS "LibrosPrestados.csv"
#define NUM_NODOS 7


using namespace std;


//Estructuras creadas

struct Libros{
    string autor;
    string titulo;
    unsigned anio_publicacion;
    unsigned num_paginas;
};
typedef Libros* Libro;

struct Estudiante{
    string codigo;
    string nombre;
    string correo;
    string librosSolicitados[2] = {" "," "};
};

typedef Estudiante* Student;

//Lista de libros disponibles por el bibliotecario
struct LibrosDisponibles{
    Libro libro = new (struct Libros);
    struct LibrosDisponibles* sgt = NULL;
};
typedef LibrosDisponibles* bookListRegister;

//Lista de solicitudes de libros para prestar
struct LibrosSolicitados{
    Libro libro = new (struct Libros);
    Student student = new (struct Estudiante);
    struct LibrosSolicitados* sgt = NULL;
};
typedef LibrosSolicitados* bookListRequest;


struct LibrosPrestados{
     Libro libro = new (struct Libros);
    Student student = new (struct Estudiante);
    struct LibrosPrestados* sgt = NULL;
};
typedef LibrosPrestados* bookListLent;



//Funciones Sistema: EYSEN
void menuPrincipal(void);
void sistemaBibliotecario(void);
void sistemaEstudiante(void);
void menuEstudiante(void);
void menuEstudiante2();
int ingresarSistemaBibliotecario(std::string, std::string);
int ingresarSistemaEstudiante(std::string);
void registrarEstudiante(std::string,std::string,std::string);

//Funciones automaticas : Stefano
void rellenarListaDisponible(bookListRegister &listaDisponible);
void rellenarListaSolicitado (bookListRequest &listaSolicitado);
void rellenarListaPrestado (bookListLent &listaPrestado);
void ActualizarLibroDisponibleArchivo(bookListRegister &listaDisponible);
void ActualizarLibroSolicitadoArchivo(bookListRequest &listaSolicitado);
void ActualizarLibroPrestadoArchivo(bookListLent &listaPrestado);

//Funciones Bibliotecario: Adrian 
void menuBibliotecario();
bookListRegister crearNodo ();
void RegistrarLibro(bookListRegister &listaDisponible);
void analizarSolicitud(bookListRegister &listaDisponible, bookListRequest &listaSolicitado, bookListLent &listaPrestado);
void eliminarLibro(bookListRegister &listaDisponible);

//Funciones Estudiante: Rosmeri

void buscarLibro();
void SolicitarLibro(bookListRegister &listaDisponible, bookListRequest &listaSolicitado);
void actualizarListaEstudiantes(Student estudiante);
void verEstadoSolicitud ();
void DevolverLibro(bookListLent &listaPrestado, bookListRegister &listaDisponible);


//ManejoListas: Stefano
void verSolicitudes (bookListRequest &listaSolicitado);
void verPrestados (bookListLent &listaPrestado);
void RetornarLibro(bookListRequest &LibroEliminar, bookListRegister &listaDisponible);
void EliminarLibroDisponible(bookListRequest &LibroEliminar, bookListRegister &listaDisponible);
void TrasladarLibroSolicitudAPrestado(bookListRequest &LibroSolicitudEliminar, bookListLent &listaPrestado);
void EliminarLibroSolicitud(bookListRequest &LibroAnterior, bookListRequest &LibroActual, bookListRequest &listaSolicitado);

//Dijkstra
void verMapa();
int Nodo_Min(int[], bool[]);
void display(int[], int[]);
void Dijkstra(int);
