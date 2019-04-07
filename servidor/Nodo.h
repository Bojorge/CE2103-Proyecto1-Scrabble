//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_NODO_H
#define SERVIDOR_NODO_H


#include <clocale>

/// Clase necesaria para que lla clase lista funcione
class Nodo {

public: Nodo* siguiente;
public: int Dato;


    Nodo (int dato){
        Dato = dato;
        siguiente = NULL;
    }
};


#endif //SERVIDOR_NODO_H
