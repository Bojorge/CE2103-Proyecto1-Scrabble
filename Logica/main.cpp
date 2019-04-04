#include <iostream>
#include <gtk/gtk.h>
#include <string>
#include "cmake-build-debug/SRC/Lista.h"
#include "cmake-build-debug/SRC/Matriz.h"
#include "cmake-build-debug/SRC/Partida.h"

int main() {
    std::cout << " Prueba Listas " << std::endl;
    Lista* a = new Lista();
    a->anadir_final(5);
    a->anadir_final(7);
    a->anadir_final(8);
    a->print_lista();

    std::cout << " Prueba Matriz" << std::endl;
    Matriz *m = new Matriz(3, 3);
    m->poner_Dato(1,2,5);
    m->print_Matriz();

    std::cout << " Prueba Partida" << std::endl;
    Partida* p = new Partida();
    //AÑADIR PALABRA
    Lista* perro = new Lista();
    Lista* ayo = new Lista();
    Lista* g = new Lista();

    perro->anadir_final(5);perro->anadir_final(9);perro->anadir_final(18);
    perro->anadir_final(5);perro->anadir_final(10);perro->anadir_final(5);
    perro->anadir_final(5);perro->anadir_final(11);perro->anadir_final(20);
    perro->anadir_final(5);perro->anadir_final(12);perro->anadir_final(20);
    perro->anadir_final(5);perro->anadir_final(13);perro->anadir_final(17);

    ayo->anadir_final(6);ayo->anadir_final(12);ayo->anadir_final(1);
    ayo->anadir_final(7);ayo->anadir_final(12);ayo->anadir_final(27);
    ayo->anadir_final(8);ayo->anadir_final(12);ayo->anadir_final(17);
    g->anadir_final(4);g->anadir_final(12);g->anadir_final(23);

    //añadir a la matriz
    p->poner_lista_Matriz(perro);
    p->poner_lista_Matriz(ayo);


    p->print_matriz();
    std::cout << " Tamaño de la lista de letras: "<< p->lista_letras->listaLetras->tamano() << std::endl;
    p->lista_letras->tS.print_lista();
    std::cout << " " <<  std::endl;

    std::cout << " Prueba /Traductor/" << std::endl;
    std::cout << "Traducir num 18(p) = " <<  p->traducir(18) << std::endl;
    std::cout << "obtener puntaje num 18(p), deberia ser 3 puntos = " <<  p->obtener_Puntaje(18) << std::endl;


    std::cout << " " << std::endl;std::cout << " Prueba /Buscar letras/" << std::endl;
    std::string palabra1 = p->buscar_Palabras(perro);
    std::cout << " " << std::endl;std::cout << palabra1 << std::endl;
    std::string palabra2 = p->buscar_Palabras(ayo);
    std::cout << palabra2 <<std::endl;

    //añadir a la matriz
    p->poner_lista_Matriz(g);
    std::string palabra3 = p->buscar_Palabras(g);
    std::cout << palabra3 << std::endl;

    std::cout << " -------------------------------------" << std::endl;
    p->lista_letras->verificar_Palabra(palabra1);
    return 0;
};