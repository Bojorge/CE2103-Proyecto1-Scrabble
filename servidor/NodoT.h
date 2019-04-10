//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_NODOT_H
#define SERVIDOR_NODOT_H

#include <clocale>

///Clase necesaria para que la clase ListaT funcione
///Guarda los datos de la lista
template <class T> class NodoT {

public: NodoT<T>* siguiente;
public: T Dato;


    NodoT (T dato){
        Dato = dato;
        siguiente = NULL;
    }
};

#endif //SERVIDOR_NODOT_H
