//
// Created by adrian on 25/03/19.
//

#ifndef TC_LISTA_H
#define TC_LISTA_H


#include "Nodo.h"

/// Clase de una lista enlazada de numeros
class Lista {

public: Lista* siguiente;
public: Lista lista;
Nodo* Inicio = NULL;

public:void anadir_final (int dato){
        if(Inicio == NULL){
            Inicio = new Nodo(dato);
        } else{
            Nodo* temp = Inicio;
            while(temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = new Nodo(dato);
        }
    }
/// Funcion que retorna el tamano de la lista
/// \return int, cantidad de elementos en la lista
public:int tamano(){
        Nodo* temp = Inicio;
        int i = 1;
        if (Inicio == NULL) {
            return 0;
        }
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
            i++;
        }
        return i;
    }

/// Fucion que elimina un dato en la posicion indicada
/// \param posicion, posicion en la lista del dato que se desea eliminar
public:void borrar_Dato(int posicion){
        if (Inicio == NULL) {
            return;
        }
        if(tamano() < posicion){
            return;
        }
        Nodo* temp = Inicio;
        for (int i = 0; i <= (posicion - 2); i++){
            temp = temp->siguiente;
        }
        if (temp->siguiente != NULL){
            Nodo* temp2 = temp->siguiente;
            if(temp2->siguiente != NULL){
                temp->siguiente = temp2->siguiente;
            }else if(temp2->siguiente == NULL){
                temp->siguiente = NULL;
            }
        }
        return;
    }

public:void anadir_Inicio(int dato){
        if (Inicio == NULL){
            Nodo* nuevo = new Nodo(dato);
            Inicio = nuevo;
        }else{
            Nodo* nuevo = new Nodo(dato);
            Nodo* temp = Inicio;
            Inicio = nuevo;
            nuevo->siguiente = temp;
        }
        return;
    }

/// Fucnion que retorna el dato que encuentra en una posicion indicada
/// \param psocion, lugador del que se desea saber el darto
/// \return int retorna el dato encontrado
public:int obtener_dato(int posicion){
        if (Inicio == NULL) {
            return NULL;
        }
        Nodo* temp = Inicio;
        for (int i = 0; i <= (posicion - 1); i++){
            temp = temp->siguiente;
        }
        return temp->Dato;
    }

/// funcion que modifica un dato es una posicion indicada
/// \param posicon, lugar donde se quiere llegar
/// \param dato, intiger que se desea sustituir
public:void cambiar_Dato (int posicion, int dato){
        if (Inicio == NULL) {
            return;
        }
        Nodo* temp = Inicio;
        for (int i = 0; i <= (posicion - 1); i++){
            temp = temp->siguiente;
        }
        temp->Dato = dato;
    }

public:void print_lista(){
        Nodo* temp = Inicio;
        for(int i = 0; i < tamano();i++){
            std::cout << temp->Dato << " "<< std::flush;
            temp = temp->siguiente;
        }
        std::cout << " " << std::endl;
        return ;
    }

public:void rellenarLista(){
    int val = 15;
    int i = 0;
    while(val > 0){
        lista.cambiar_Dato(i,0);
        i++;
        val--;
    }
    return;
}

/// Funcion que aplica insetion sort, a una lista ingresada
/// \param list, lista que se desea ordenar
/// \return lista ordenada
public :Lista* ordenar(Lista* list){
        int n = list->tamano();
        for (int i = 0; i < (n-1); i++) {
            int mIndex = i;
            for(int j = i+1; j < (n); j++){
                if (list->obtener_dato(j) < list->obtener_dato(mIndex)){
                    mIndex = j;
                }
            }
            int temp = list->obtener_dato(mIndex);
            list->cambiar_Dato(mIndex, list->obtener_dato(i));
            list->cambiar_Dato(i, temp);
        }
        return list;
    }

};


#endif //TC_LISTA_H