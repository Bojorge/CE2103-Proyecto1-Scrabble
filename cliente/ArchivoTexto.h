//
// Created by manuel on 03/04/19.
//

#ifndef CLIENTE_ARCHIVOTEXTO_H
#define CLIENTE_ARCHIVOTEXTO_H

#include <fstream>
#include <iostream>


using namespace std;


class ArchivoTexto {


public:

    void escribir(string texto){
        std::ofstream archivo;

        archivo.open("datosServer.txt",std::ios::out);

        if (archivo.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);

        }

        archivo<<"\n"<<texto<<"\n";

        archivo.close();

    };

    void leer(string nombreArchivo){

        ifstream archivo;
        string texto;
        //archivo.open("datosServer.txt",ios::in);
        archivo.open(nombreArchivo,ios::in);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        while(!archivo.eof()){// mientras no se haya terminado el archivo
            getline(archivo,texto);
            cout<<texto<<endl;
        }
        archivo.close();

    };



};

#endif //CLIENTE_ARCHIVOTEXTO_H
