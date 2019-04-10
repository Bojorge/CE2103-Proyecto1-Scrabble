//
// Created by aaron on 8/04/19.
//
#include "Lista.h"
#include "Nodo.h"
#ifndef PRUEBA_UTILES_H
#define PRUEBA_UTILES_H


class utiles {
public: bool encadenado(Lista* n,Lista* m, int x, int y){
        Lista* p = new Lista();
        for (int c = 0 ; c < n->tamano();c++){
            p->anadir_final(n->obtener_dato(c));
        }for (int f = 0 ; f < m->tamano();f++){
            p->anadir_final(m->obtener_dato(f));
        }
        if (x == 7 && y == 7){
            return true;
        }
        // revisar si esta sobre otra ficha
        for (int k = 0; k < p->tamano(); k++){
            int x2 = p->obtener_dato(k);
            int y2 = p->obtener_dato(k+1);
            if (x == x2 && y == y2){
                return false;
            }
            k++;k++;
        }
        int arr = x + 1;int aba = x - 1;
        int der = y + 1;int izq = y - 1;
        //revidar en x's
        for (int i = 0; i < (p->tamano()); i++) {
            int x1 = p->obtener_dato(i);
            int y1 = p->obtener_dato(i + 1);
            //arriba
            if (arr == x1 && y1 == y) {
                return true;
                //abajo
            }if (aba == x1 && y1 == y){
                return true;
            }
            i++;i++;
            //revidar en y's
        }for (int j = 1; j < (p->tamano()); j++){
            int y3 = p->obtener_dato(j);
            int x3 = p->obtener_dato(j-1);
            //derecha
            if (der == y3 && x == x3){
                return true;
                //izquierda
            }if (izq == y3 && x == x3){
                return true;
            }

            j++;j++;
        }
        return false;
    }
public: string castear(Lista* p){
        string conca = to_string(p->obtener_dato(0));
        for (int i = 1; i < p->tamano();i++){
            string signo = to_string(p->obtener_dato(i));
            conca = conca + "," + signo;
        }
        return conca;
    }
public: Lista* castear_Lista_to_String(std::string p){
        Lista* L = new Lista();
        int j = 1;
        string dato = "";
        for(int i = 0; i < p.length();i++){
            string letra1 = p.substr(i,j);
            if (letra1 == ","){
                L->anadir_final(atoi(dato.c_str()));
                dato = "";
            }else{
                if (dato == "") {
                    dato = letra1;
                }else{
                    dato = dato + letra1;
                }
            }

        }
        L->anadir_final(atoi(dato.c_str()));

        return L;
    }
};


#endif //PRUEBA_UTILES_H
