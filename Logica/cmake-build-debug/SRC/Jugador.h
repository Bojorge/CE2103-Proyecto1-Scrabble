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

public: std::string Nombre;
public: int ip;
public: Lista* fichas = new Lista();
public: int Puntaje = 0;


public:int getIp() const {
        return ip;
    }

public:void setIp(int ip) {
        Jugador::ip = ip;
    }

public:const std::string &getNombre() const {
        return Nombre;
    }

public:void setNombre(const std::string &Nombre) {
        Jugador::Nombre = Nombre;
    }

public: int &getPuntaje() {
        return Puntaje;
    }

public:void setPuntaje(int puntaje) {
        Jugador::Puntaje = Puntaje + puntaje;
    }

};


#endif //TC_JUGADOR_H
