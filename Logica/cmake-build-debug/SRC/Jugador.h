//
// Created by adrian on 25/03/19.
//

#ifndef TC_JUGADOR_H
#define TC_JUGADOR_H

#include <string>
#include <iostream>
#include "Lista.h"

///Clase que maneja los datos de los jugadores en partida

class Jugador {

public: int Nombre;
public: Lista* fichas = new Lista();
public: int Puntaje = 0;

public: Jugador(int nombre){
    setNombre(nombre);
}

public:const int &getNombre() const {
        return Nombre;
    }

public:void setNombre(const int &Nombre) {
        Jugador::Nombre = Nombre;
    }

public: int getPuntaje() {
        return Puntaje;
    }

public:void setPuntaje(int puntaje) {
        Jugador::Puntaje = Puntaje + puntaje;
    }

};


#endif //TC_JUGADOR_H
