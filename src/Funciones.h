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
#define LISTA_REGISTRADOS "LibrosRegistrados.csv"

using namespace std;

//Estructuras creadas

struct Libros{
    string autor;
    string titulo;
    unsigned anio_publicacion;
    unsigned num_paginas;
};

struct Estudiante{
    string nombre;
    string correo;
    string codigo;
    unsigned cantLibros;
};

typedef Estudiante* Student;



//Lista de libros registrados por el bibliotecario
struct LibrosRegistrados{
    Libros libro;
    struct LibrosRegistrados* sgt = NULL;
};
typedef LibrosRegistrados* bookListRegister;


//Lista de solicitudes de libros para prestar
struct LibrosSolicitados{
    Libros libro;
    Student estudiante;
    struct LibrosSolicitados* sgt;
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
void rellenarListaRegistrados(bookListRegister &listaRegistro);

//Funciones Bibliotecario
void menuBibliotecario();
bookListRegister crearNodo ();
void RegistrarLibro(bookListRegister &listaRegistro);
void RegistrarLibroArchivo(bookListRegister &listaRegistro);

//Funciones Estudiante

void buscarLibro();
