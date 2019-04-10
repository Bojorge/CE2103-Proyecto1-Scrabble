//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_LISTAT_H
#define SERVIDOR_LISTAT_H

#include <iostream>
#include "NodoT.h"

//Clase que representa una lista enlazada de elementos genericos
template <class T> class ListaT {

    NodoT<T> *Inicio = NULL;


public:
    void anadir_final(T dato) {
        if (Inicio == NULL) {
            Inicio = new NodoT<T>(dato);
        } else {
            NodoT<T> *temp = Inicio;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = new NodoT<T>(dato);
        }
    }
/// Fucnion que calcula el tamano de la lista
/// \return int, tamano de la lista
public:
    int tamano() {
        NodoT<T> *temp = Inicio;
        int i = 1;
        if (Inicio == NULL) {
            return 0;
        }
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
            i++;
        }
        return i;
    }
/// Fucion que elimina el dato en una posion indicada
/// \param posicion, lugar en la lista que se desea desechar
public:
    void borrar_Dato(int posicion) {
        if (Inicio == NULL) {
            return;
        }
        if (tamano() < posicion) {
            return;
        }
        NodoT<T> *temp = Inicio;
        for (int i = 0; i <= (posicion - 2); i++) {
            temp = temp->siguiente;
        }
        if (temp->siguiente != NULL) {
            NodoT<T> *temp2 = temp->siguiente;
            if (temp2->siguiente != NULL) {
                temp->siguiente = temp2->siguiente;
            } else if (temp2->siguiente == NULL) {
                temp->siguiente = NULL;
            }
        }
        return;
    }

public:
    void anadir_Inicio(int dato) {
        if (Inicio == NULL) {
            NodoT<T> *nuevo = new NodoT<T>(dato);
            Inicio = nuevo;
        } else {
            NodoT<T> *nuevo = new NodoT<T>(dato);
            NodoT<T> *temp = Inicio;
            Inicio = nuevo;
            nuevo->siguiente = temp;
        }
        return;
    }

/// Fucnion que retorna el dato en una posicion indicada
/// \param posicion, posicion de la lista que se desea conocer el dato
/// \return T, dato generico encontrado en la posicion
public:
    T obtener_dato(int posicion) {
        try {
            NodoT<T> *temp = Inicio;
            for (int i = 0; i <= (posicion - 1); i++) {
                temp = temp->siguiente;
            }
            return temp->Dato;
        } catch (...) {
            std::cout << " No hay Elementos disponibles" << std::endl;
        }
    }

/// fucnion que modifica el dato en un lugar indicado de la lista
/// \param posicion, lugar que se desea modificar
/// \param dato, nuevo dato que estara en la posicion
public:
    void cambiar_Dato(int posicion, T dato) {
        if (Inicio == NULL) {
            return;
        }
        NodoT<T> *temp = Inicio;
        for (int i = 0; i <= (posicion - 1); i++) {
            temp = temp->siguiente;
        }
        temp->Dato = dato;
    }

public:
    void print_lista() {
        NodoT<T> *temp = Inicio;
        for (int i = 0; i < tamano(); i++) {
            std::cout << temp->Dato << " " << std::flush;
            temp = temp->siguiente;
        }
        std::cout << " " << std::endl;
        return;
    }

};



#endif //SERVIDOR_LISTAT_H
