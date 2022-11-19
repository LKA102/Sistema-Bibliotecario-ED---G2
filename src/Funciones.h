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
};

static Estudiante student;

struct LibrosRegistrados{
    Libros libro;
    struct LibrosRegistrados* sgt;
};
typedef LibrosRegistrados* bookListRegister;

void menuPrincipal(void);
void sistemaBibliotecario(void);
void sistemaEstudiante(void);
void menuEstudiante(void);
int ingresarSistemaBibliotecario(std::string, std::string);
int ingresarSistemaEstudiante(std::string);
void registrarEstudiante(std::string,std::string,std::string);

//Funciones Bibliotecario
void menuBibliotecario();
bookListRegister crearNodo ();
void RegistrarLibro(bookListRegister &listaRegistro);
void RegistrarLibroArchivo(bookListRegister &listaRegistro);

