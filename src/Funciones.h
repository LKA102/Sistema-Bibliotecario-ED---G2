#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>
#include <windows.h>

#define NOMBRE_BIBLIOTECARIO "Bibliotecario.csv"
#define NOMBRE_ESTUDIANTE "Estudiantes.csv"
#define LISTA_REGISTRADOS "LibrosDisponibles.csv"


using namespace std;

//Estructuras creadas

struct Libros{
    string autor;
    string titulo;
    unsigned anio_publicacion;
    unsigned num_paginas;
};

struct Estudiante{
    string codigo;
    string nombre;
    string correo;
    string librosSolicitados[2] = {" "," "};
};

typedef Estudiante* Student;



//Lista de libros disponibles por el bibliotecario
struct LibrosDisponibles{
    Libros libro;
    struct LibrosDisponibles* sgt = NULL;
};
typedef LibrosDisponibles* bookListRegister;

//Lista de libros disponibles



//Lista de solicitudes de libros para prestar
struct LibrosSolicitados{
    string libro;
    Student student = new (struct Estudiante);
    struct LibrosSolicitados* sgt = NULL;
};
typedef LibrosSolicitados* bookListRequest;


//Funciones Sistema
void menuPrincipal(void);
void sistemaBibliotecario(void);
void sistemaEstudiante(void);
void menuEstudiante(void);
void menuEstudiante2();
int ingresarSistemaBibliotecario(std::string, std::string);
int ingresarSistemaEstudiante(std::string);
void registrarEstudiante(std::string,std::string,std::string);

//Funciones automaticas 
void rellenarListaRegistrados(bookListRegister &listaDisponible);

//Funciones Bibliotecario
void menuBibliotecario();
bookListRegister crearNodo ();
void RegistrarLibro(bookListRegister &listaDisponible);
void RegistrarLibroArchivo(bookListRegister &listaDisponible);

//Funciones Estudiante

void buscarLibro();
void SolicitarLibro(bookListRegister &listaDisponible, bookListRequest &listaSolicitado);
void actualizarListaEstudiantes(Student estudiante);
