//
// Created by manuel on 02/04/19.
//

#ifndef SERVIDOR_SERIAL_H
#define SERVIDOR_SERIAL_H


#include <cstdio>

class Serial {

    struct Persona{
        char nombre[256];
        int edad;
        float salario;
        char email[256];
    };



public:
    int crearArchivoBinaro(void){

        Persona empleados[] = {
                {"Maria ", 21, 1000000, "email de Maria"},
                {"Manuel", 666, 10000000000, "email de Manuel"}
        };

        const int cantidadEmpleados = sizeof(empleados)/ sizeof(Persona);
        Persona lecturaInformacion[cantidadEmpleados];
        char nombreArchivo[] = "Serializado.txt";
        int x;



        //escribe un archivo binario
        FILE *archivo = fopen(nombreArchivo, "wb");

        if (archivo == NULL){
            fprintf(stderr, "Error: No se puede abrir el archivo\n");
            return -1;
        }

        for (x = 0; x < cantidadEmpleados; ++x){
            fwrite(&empleados[x], sizeof(Persona), 1, archivo);
        }
        fclose(archivo);

        return 0;

    };

    int leerArchivoBinario(){

        Persona empleados[] = {
                {"Maria ", 21, 1000000, "email de Maria"},
                {"Manuel", 666, 10000000000, "email de Manuel"}
        };

        const int cantidadEmpleados = sizeof(empleados)/ sizeof(Persona);
        Persona lecturaInformacion[cantidadEmpleados];
        char nombreArchivo[] = "Serializado.txt";
        int x;


        FILE *archivo = fopen(nombreArchivo, "rb");
        if (archivo == NULL){
            fprintf(stderr, "Error: No se puede abrir el archivo\n");
            return  -2;
        }
        for (x = 0; x < cantidadEmpleados; ++x){
            fread(&lecturaInformacion[x], sizeof(Persona), 1, archivo);
        }
        fclose(archivo);
        for (x = 0; x < cantidadEmpleados; ++x) {
            printf("Nombre: %s\n", lecturaInformacion[x].nombre);
            printf("Edad: %d\n", lecturaInformacion[x].edad);
            printf("Salario: %f\n", lecturaInformacion[x].salario);
            printf("correo: %s\n", lecturaInformacion[x].email);
            printf("\n");
        }
        printf("\n");
        return  0;

    }

};


#endif //SERVIDOR_SERIAL_H
