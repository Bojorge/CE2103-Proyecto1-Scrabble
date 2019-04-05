/*
 * @file Partida.h
 */

#ifndef TC_PARTIDA_H
#define TC_PARTIDA_H

#include <random>
#include <string>
#include "Lista.h"
#include "Matriz.h"
#include "ListaT.h"
#include "Jugador.h"
#include "ListaLetras.h"

/// Clase partida
/// Maneja el las funciones generales de la logica del servidor

class Partida {

public: ListaLetras* lista_letras;
public: Matriz* matriz;
public: ListaT<Jugador>* Jugadores;

public: Partida(){
        matriz = new Matriz(15,15);
        Jugadores = new ListaT<Jugador>();
        lista_letras = new ListaLetras();
    }

/// Funcion que ontiene la lista de jugadores y le da 7 letras aleatrias a cada jugador

public: void repartir_letras(){
    for (int i = 0; i < Jugadores->tamano(); i++){
        int cant = (7 - Jugadores->obtener_dato(i).fichas->tamano());
        for (int j = 0; j < cant; j++ ){
            int limite = lista_letras->listaLetras->tamano() - 1;
            if (limite == 0 ){
                std::cout << " No hay Fichas disponibles" << std::endl;
                return;
            }
            int num = rand() % limite;
            int letra = lista_letras->listaLetras->obtener_dato(num);
            lista_letras->listaLetras->borrar_Dato(num);
            Jugadores->obtener_dato(i).fichas->anadir_final(letra);
        }
    }

}

public: void print_matriz(){
    matriz->print_Matriz(lista_letras);
    }

///Fucnion que dado un numero, muestra su representacion en la matriz
/// \param num, numero que se desea saber
/// \return string letra que se representa
public: std::string traducir(int num){
    return lista_letras->traducir(num);
}
///Fucnion que dado un numero, muestra su puntaje
/// \param num, numero que se desea saber
/// \return int puntaje
public: int obtener_Puntaje(int num){
    return lista_letras->obtener_puntaje(num);
}
/// Funcion que busca el la matriz del juego las posibles palabras que el cliente puso
/// retorna "" si no encontro palabra
/// \param p, lista con las letras que el cliente puto
/// \return string, posible palabra
public: std::string buscar_Palabras(Lista* p){
        std::string texto = "";
        if (p->tamano() == 3) {
            std::string tV = "";
            std::string tH = "";
            //Buscar horizontal
            tH = buscar_Horizontal(p);
            //Buscar Vertical
            tV = buscar_Vertical(p);
            if (tV.length() < tH.length()) {
                texto = tH;
            } else if (tV.length() > tH.length()) {
                texto = tV;
            }
        } else {
            int x1 = p->obtener_dato(0);
            int y1 = p->obtener_dato(1);
            int x2 = p->obtener_dato(3);
            int y2 = p->obtener_dato(4);
            if ((x1 - x2) == 0 && (y1 - y2) != 0) {
                //Buscar horizontal
                texto = buscar_Horizontal(p);

            }
            if ((x1 - x2) != 0 && (y1 - y2) == 0) {
                //Buscar Vertical
                texto = buscar_Vertical(p);
            }
        }
    return texto;
}
/// Funcion que busca hotizontalmente en la matriz, una posible palabra
/// retorna "" si no encontro palabra
/// \param p, lista de letras que el cliente puso
/// \return strign si encontro una palabra
private: std::string buscar_Horizontal(Lista* p){
        std::string texto = "";
        int x = p->obtener_dato(0);
        //Hacia DERECHA
        int i =  p->obtener_dato(1);
        while (matriz->matriz[x][i] != 0){
            texto = concatenar(texto, matriz->matriz[x][i], 1);
            i--;
            // HACIA LA IZQUIERDA
        }int j =  (p->obtener_dato(1)+ 1);
        while (matriz->matriz[x][j] != 0){
            texto = concatenar(texto, matriz->matriz[x][j], 2);
            j++;
        }
        return texto;
    }
///Funcion que busca verticalmente en la matriz, una posible palabra
/// retorna "" si no encontro palabra
/// \param p, lista de letras que el cliente puso
/// \return strign si encontro una palabra
private: std::string buscar_Vertical(Lista* p){
        std::string texto = "";
        int y = p->obtener_dato(1);
        //Hacia arriba
        int i = p->obtener_dato(0);
        while (matriz->matriz[i][y] != 0){
            texto = concatenar(texto, matriz->matriz[i][y], 1);
            i--;
        // HACIA abajo
        }int j = (p->obtener_dato(0) + 1);
        while (matriz->matriz[j][y] != 0){
            texto = concatenar(texto, matriz->matriz[j][y], 2);
            j++;
        }
        return texto;
    }
/// Funcion que concatena una letra con un texto
/// \param string, texto que se desea
/// \param letra, letra que se le desea anadir
/// \param direc, si direc es 1 concatena la letra a la derecha, si es 2 a la izquierda
/// \return string, con la palabra final
    // Direccion de concatenacion: 1 concatena a la derecha
    //                             2 concatena a la izquierda
private: std::string concatenar(std::string texto,int letra, int direc ){
    if (direc == 1){
        //Hacia la derecha
        texto = traducir(letra) + texto;
    }else if (direc == 2){
        texto = texto + traducir(letra);
    }
    return texto;
    }
///Fucion que dada una lista con untamano divisible entre 3, coloca las letras en las posiciones indicadas
/// \param p, lista con las letras y posiciones que se desean
public: void poner_lista_Matriz(Lista* p){
        try {
        for(int i = 0; i < (p->tamano()); i++){
            matriz->poner_Dato(p->obtener_dato(i),
                    p->obtener_dato(i+1),
                    p->obtener_dato(i+2));
            i++;
            i++;
        }
    }catch (...){
        std::cout << " Error " << std::endl;
    }
}
///Fucion que dada una lista con untamano divisible entre 3, coloca las letras en las posiciones indicadas
/// Luego busca la posible palabra en el tablero
/// luego verifica la palabra encontrada
/// por ultimo, asgina puntaje
/// \param p, lista con las letras y posiciones que se desean
/// \return bool, true, si todo fue corecto, false, si hay algun error
public: bool encontraryasignar(Lista* p){
    if (p->tamano() < 3){
        std::cout << " Error " << std::endl;
        return false;
    }
    try {
        poner_lista_Matriz(p);
        std:string palabra = buscar_Palabras(p);
        bool verif = lista_letras->verificar_Palabra(palabra);
        if (verif != true){
            return false;
        }else{
            int puntaje = lista_letras->obtener_puntaje(palabra);
            std::cout<<"Putaje es : " << puntaje <<std::endl;
        }
        //Asignar puntaje
    }catch(...){
        std::cout << " Error " << std::endl;
        return false;
    }

    return true;
}
///Fucion que dada una lista con untamano divisible entre 3, borra las letras en las posiciones indicadas
/// \param p, lista con las letras y posiciones que se desean
public: void reintentar(Lista* p){
    std::string palabra = "";
        try {
            for(int i = 0; i < (p->tamano()); i++){
                matriz->borrar_Dato(p->obtener_dato(i),
                                   p->obtener_dato(i+1));
                palabra = palabra + lista_letras->traducir(p->obtener_dato(i+2));
                i++;
                i++;
            }
            std::cout << " Se borro la(s) letras: " << palabra << " del tablero"<< std::endl;
        }catch (...){
            std::cout << " Error " << std::endl;
        }
}
};


#endif //TC_PARTIDA_H
