//
// Created by adrian on 25/03/19.
//

#ifndef TC_NODOT_H
#define TC_NODOT_H


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


#endif //TC_NODOT_H
