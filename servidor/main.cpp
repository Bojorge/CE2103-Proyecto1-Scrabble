#include <iostream>
#include "TCPserver.h"
#include "ArchivoTexto.h"
#include "Serial.h"


#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <zconf.h>



#include <sys/types.h>
#include <sys/socket.h>

int main() {

    TCPserver servidor;

    servidor.iniciar();

    //ArchivoTexto datos;
    //datos.escribir("Mae estos son los datos que escribi");
    //datos.leer("datosServer.txt");

    //Serial serial;
    //serial.crearArchivoBinaro();




    //return 0;
}