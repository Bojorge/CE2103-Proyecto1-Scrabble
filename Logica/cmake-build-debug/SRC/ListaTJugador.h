//
// Created by adrian on 10/04/19.
//

#ifndef TC_LISTATJUGADOR_H
#define TC_LISTATJUGADOR_H

class NodoTJugador {

public: NodoTJugador* siguiente;
public: Jugador* Dato;


    NodoTJugador (Jugador* dato){
        Dato = dato;
        siguiente = NULL;
    }
};

class ListaTJugador {
    NodoTJugador* Inicio = NULL;


public: void anadir_final (Jugador *dato){
        if(Inicio == NULL){
            Inicio = new NodoTJugador(dato);
        } else{
            NodoTJugador* temp = Inicio;
            while(temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = new NodoTJugador(dato);
        }
    }
/// Fucnion que calcula el tamano de la lista
/// \return int, tamano de la lista
public:int tamano(){
        NodoTJugador* temp = Inicio;
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
/// Fucion que elimina el dato en una posion indicada
/// \param posicion, lugar en la lista que se desea desechar
public:void borrar_Dato(int posicion){
        if (Inicio == NULL) {
            return;
        }
        if(tamano() < posicion){
            return;
        }
        NodoTJugador* temp = Inicio;
        for (int i = 0; i <= (posicion - 2); i++){
            temp = temp->siguiente;
        }
        if (temp->siguiente != NULL){
            NodoTJugador* temp2 = temp->siguiente;
            if(temp2->siguiente != NULL){
                temp->siguiente = temp2->siguiente;
            }else if(temp2->siguiente == NULL){
                temp->siguiente = NULL;
            }
        }
        return;
    }



public:Jugador* obtener_dato(int posicion){
        try {
            NodoTJugador* temp = Inicio;
            for (int i = 0; i <= (posicion - 1); i++){
                temp = temp->siguiente;
            }
            return temp->Dato;
        }catch (...){
            std::cout << " No hay Elementos disponibles" << std::endl;
        }
    }
};


#endif //TC_LISTATJUGADOR_H
