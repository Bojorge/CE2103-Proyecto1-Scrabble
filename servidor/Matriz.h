//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_MATRIZ_H
#define SERVIDOR_MATRIZ_H


#include <malloc.h>
#include <iostream>
#include <string>
#include "ListaLetras.h"

/// clase que contiene una matriz de numeros, que representa el tablero del juego
class Matriz {

public:
    int **matriz;
private:
    int filas;
private:
    int columnas;

public:
    Matriz(int x, int y) {
        int **m = (int **) malloc(sizeof(int *) * x);
        for (int i = 0; i < x; i++) {
            m[i] = (int *) malloc(sizeof(int) * y);
        }
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                m[j][k] = 0;
            }
        }
        this->matriz = m;
        filas = x;
        columnas = y;

    }

public:
    void poner_Dato(int x, int y, int dato) {
        if (matriz[x][y] != 0) {
            return;
        }
        matriz[x][y] = dato;
    }

public:
    void borrar_Dato(int x, int y) {
        this->matriz[x][y] = 0;
    }

public:
    int retornar_Dato(int x, int y) {
        return matriz[x][y];
    }

/// Fucion que dada una lista de letras, imprimira la matriz cambiando cada numero por
/// su letra correspondiente
/// \param l, lista de letras que representan los numeros
public:
    void print_Matriz(ListaLetras *l) {
        std::cout << " " << std::endl;
        for (int i = 0; i < filas; i++) {
            std::cout << " " << std::endl;
            for (int j = 0; j < filas; j++) {
                if (matriz[i][j] == 0) {
                    std::cout << matriz[i][j] << "  " << std::flush;
                    continue;
                }
                std::cout << l->traducir(matriz[i][j]) << "  " << std::flush;
            }
        }
        std::cout << " " << std::endl;
    }

///Fucnion que imprime la matriz, esta impresion solo sera de numeros
public:
    void print_Matriz() {
        std::cout << " " << std::endl;
        for (int i = 0; i < filas; i++) {
            std::cout << " " << std::endl;
            for (int j = 0; j < filas; j++) {
                std::cout << matriz[i][j] << "  " << std::flush;
            }
        }
        std::cout << " " << std::endl;
    }

};

#endif //SERVIDOR_MATRIZ_H
