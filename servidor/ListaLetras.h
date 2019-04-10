//
// Created by manuel on 07/04/19.
//

#ifndef SERVIDOR_LISTALETRAS_H
#define SERVIDOR_LISTALETRAS_H


#include <string>
#include <fstream>
#include "Lista.h"
#include "ListaT.h"

using namespace std;

/// Funcion que maneja la lista de letras que quedan en el juego
/// traduce letras de intiger a string
/// verifca el puntaje obtenido con una cantidad de palabras
/// busca en un diccionario las posibles palabras que se le ingresen

class ListaLetras {

public:
    Lista *listaLetras;
public:
    ListaT<std::string> tS;
public:
    ListaT<int> tP;

/// Constructor que anadira 100 piesas en total
/// llena la lista de letras (TS) con las letras posibles en el juego
/// llena la lista de puntajes (tp) con los puntajes de cada letra
public:
    ListaLetras() {
        listaLetras = new Lista();
        for (int i = 0; i < 12; i++) {
            listaLetras->anadir_final(1);
            listaLetras->anadir_final(5);
        }
        for (int j = 0; j < 9; j++) {
            listaLetras->anadir_final(17);
        }
        for (int i = 0; i < 6; i++) {
            listaLetras->anadir_final(10);
            listaLetras->anadir_final(22);
        }
        for (int k = 0; k < 5; k++) {
            listaLetras->anadir_final(4);
            listaLetras->anadir_final(15);
            listaLetras->anadir_final(20);
            listaLetras->anadir_final(24);
        }
        for (int n = 0; n < 4; n++) {
            listaLetras->anadir_final(3);
            listaLetras->anadir_final(12);
            listaLetras->anadir_final(23);
        }
        for (int l = 0; l < 2; l++) {
            listaLetras->anadir_final(7);
            listaLetras->anadir_final(2);
            listaLetras->anadir_final(8);
            listaLetras->anadir_final(14);
            listaLetras->anadir_final(18);
            listaLetras->anadir_final(29);
        }
        listaLetras->anadir_final(6);
        listaLetras->anadir_final(9);
        listaLetras->anadir_final(11);
        listaLetras->anadir_final(13);
        listaLetras->anadir_final(16);
        listaLetras->anadir_final(19);
        listaLetras->anadir_final(21);
        listaLetras->anadir_final(25);
        listaLetras->anadir_final(26);
        listaLetras->anadir_final(27);
        listaLetras->anadir_final(28);

        listaLetras->ordenar(listaLetras);

        tS.anadir_final("");
        tS.anadir_final("a");
        tS.anadir_final("b");
        tS.anadir_final("c");
        tS.anadir_final("d");
        tS.anadir_final("e");
        tS.anadir_final("f");
        tS.anadir_final("g");
        tS.anadir_final("h");
        tS.anadir_final("ch");
        tS.anadir_final("i");
        tS.anadir_final("j");
        tS.anadir_final("l");
        tS.anadir_final("ll");
        tS.anadir_final("m");
        tS.anadir_final("n");
        tS.anadir_final("ñ");
        tS.anadir_final("o");
        tS.anadir_final("p");
        tS.anadir_final("q");
        tS.anadir_final("r");
        tS.anadir_final("rr");
        tS.anadir_final("s");
        tS.anadir_final("t");
        tS.anadir_final("u");
        tS.anadir_final("v");
        tS.anadir_final("x");
        tS.anadir_final("y");
        tS.anadir_final("z");
        tS.anadir_final(" ");

        tP.anadir_final(0);
        tP.anadir_final(1);
        tP.anadir_final(3);
        tP.anadir_final(3);
        tP.anadir_final(2);
        tP.anadir_final(1);
        tP.anadir_final(4);
        tP.anadir_final(2);
        tP.anadir_final(4);
        tP.anadir_final(5);
        tP.anadir_final(1);
        tP.anadir_final(8);
        tP.anadir_final(1);
        tP.anadir_final(8);
        tP.anadir_final(3);
        tP.anadir_final(1);
        tP.anadir_final(8);
        tP.anadir_final(1);
        tP.anadir_final(3);
        tP.anadir_final(5);
        tP.anadir_final(1);
        tP.anadir_final(8);
        tP.anadir_final(1);
        tP.anadir_final(1);
        tP.anadir_final(1);
        tP.anadir_final(4);
        tP.anadir_final(8);
        tP.anadir_final(4);
        tP.anadir_final(10);
        tP.anadir_final(0);

    }


/// funcion que compara un numero ingresado con una lista con las letras
/// el numero ingresado representa la poscion de la letra deseada
/// \param num, letra que se desea traducuir
/// \return string, letra que representa el numero
public:
    string traducir(int num) {
        return tS.obtener_dato(num);
    }
/// Funcion que dado un numero asigna un puntaja, comparando con una lista
/// \param num, letra en su representacion numerica que se desea conocer el puntaje
/// \return int, puntaje de la letra
public:
    int obtener_puntaje(int num) {
        return tP.obtener_dato(num);
    }
/// Funcion que dado un numero asigna un puntaja, comparando con una lista
/// \param string, letra que se desea conocer el puntaje
/// \return int, puntaje de la letra
public:
    int obtener_puntaje(string pal) {
        int puntaje = 0;
        int j = 1;
        for (int i = 0; i < pal.length(); i++) {
            string p = pal.substr(i, j);
            puntaje = puntaje + obtener_puntaje(traducir_string_int(p));
        }
        return puntaje;
    }

/// Fucion que busca en un archivo de texto la palabra ingresada
/// \param pal, string con la letra que se desea buscar
/// \return bool, true si encuentra palabra, false si no
public:
    bool verificar_Palabra(string pal) {
        cout << " verificar: " << pal << endl;
        string p = pal.substr(0, 1);
        string letra = p + ".text";
        letra = "Diccionario/" + letra;
        letra = (char) 34 + letra + (char) 34;


        ifstream diccionario;
        diccionario.open("Listado.txt");
        string line;
        int offset;
        if (!diccionario.is_open()) {
            cout << "  No se pudo abrir el archivo " << endl;
        }
        if (diccionario.is_open()) {
            while (!diccionario.eof()) {
                getline(diccionario, line);
                if ((offset = line.find(pal, 0)) != string::npos) {
                    diccionario.close();
                    cout << "  La palabra se encontro " << endl;
                    return true;
                }
            }
        }
        cout << "  ERROR - La palabra no se encontro " << endl;
        return false;
    }
/// funcion que compara un string ingresado con una lista con las letras
/// el string se compara para determinar la posicion en donde esta la palabra
/// \param string, letra que se desea traducuir
/// \return int, numero que representa la letra
public:
    int traducir_string_int(string a) {
        int letra = 0;
        for (int i = 0; i < listaLetras->tamano(); i++) {
            if (tS.obtener_dato(i) == a) {
                return i;
            }
        }
        return letra;
    }
};



#endif //SERVIDOR_LISTALETRAS_H
