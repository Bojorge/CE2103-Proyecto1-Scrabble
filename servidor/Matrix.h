//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_MATRIX_H
#define SERVIDOR_MATRIX_H

#include <clocale>
#include "Lista.h"
#include "Nodo.h"



class Matrix{

    Lista* Root = NULL;

public: Matrix* matrix;

/// Funcion que retorna el tamano de la lista
/// \return int, cantidad de elementos en la lista
public:int tamano(){
        Lista* temp = Root;
        int i = 1;
        if (Root == NULL) {
            return 0;
        }
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
            i++;
        }
        return i;
    }


public: Lista * mostrarLista(int indice) {
        if(Root == NULL) {
            return NULL;
        }
        Lista* temp = Root;

        for (int i = 0; i <= (indice - 1); i++){
            temp = temp->siguiente;
        }
        return temp;
    }

public: int mostrarDato(int x, int y) {
        return matrix->mostrarLista(x)->obtener_dato(y);
    }

public: void cambiarDatoenMatrix(int x, int y, int dato) {
        matrix->mostrarLista(x)->cambiar_Dato(y,dato);
    }

public: void borrarDatoenMatrix(int x, int y) {
        matrix->mostrarLista(x)->cambiar_Dato(y,0);
    }

public: void rellenarMatrix() {
        Lista lista;
        lista.rellenarLista();
        int x = 0;
        int y = 0;
        while (x != 15) {
            while(y!= 15) {
                matrix->mostrarLista(x)->cambiar_Dato(y, 0);
                y++;
            }
            x++;
        }
        return;
    }

public:void printMatrix(){
        Lista* temp = Root;
        while(temp->siguiente != NULL){
            temp->print_lista();
            temp = temp->siguiente;

        }
        return ;
    }


};



#endif //SERVIDOR_MATRIX_H
