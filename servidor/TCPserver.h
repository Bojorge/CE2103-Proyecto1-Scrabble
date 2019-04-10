//
// Created by manuel on 01/04/19.
//

#ifndef SERVIDOR_TCPSERVER_H
#define SERVIDOR_TCPSERVER_H

#include <zconf.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <zconf.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#include "ArchivoTexto.h"
#include "Partida.h"

#include <pthread.h>



#define MAX 80
#define PORT 8080
#define SA struct sockaddr


///clase que provee el servidor que genera la aplicacion
class TCPserver {

private:
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;
    char buff[MAX];
    ArchivoTexto recibido;

    Partida *p;

public:
    ///metodo donde recibe como parametro una lista y castea esa lista a un char
    void castearLista_a_Char(Lista listaCast){
        for(int i=0;i<listaCast.tamano();i++){
            char data = (char)listaCast.obtener_dato(i);
            listaCast.cambiar_Dato_a_char(i,data);
        }
     }
    ///metodo donde se lee el dato que viene proveniente del socket
    void leerPaquete(int sockfd){
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));


        if (strncmp("iniciar", buff, 4) == 0) {
            //crearJugador(sockfd);
            p=new Partida();
        }
        else{
            // print buffer which contains the client contents
            printf("cliente envia >>> : %s\t");
        }

    }
    ///metodo que envia el dato proveniente del socket
    void enviarPaquete(int sockfd){
        bzero(buff, MAX);
        printf("Enviar al cliente >>> : ", buff);
        bzero(buff, MAX);
        int n=0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));


    }
    ///metodo boooleano que se usa para terminar la conexion entre el servidor y el cliente por medio de los sockets
    bool terminarConexion(){
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Finalizado...\n");
            return true;
        }
        return false;
    }
    
    ///metodo que crea un nuevo jugador, osea que establece un nuevo cliente que pide datos del servidor
    void crearJugador(int sockfd){
        //if (strncmp("jugador", buff, 4) == 0) {
            printf("se solicita crear un jugador...\n");
            write(sockfd, "el servidor creara un nuevo jugador \n", sizeof(buff));

       // }
    }

    ///metodo que mantiene viva la conexion del socket hasta que se llame a la funcion terminaqrconexion();
    void puerto(int sockfd){
        // infinite loop for chat
        for (;;) {

            leerPaquete(sockfd);
            enviarPaquete(sockfd);

            if(terminarConexion()){
                break;
            }
        }

    };
    ///metodo donde el servidor acepta la conexion de un cliente y se prepara para iniciar la conexion
    void aceptarConexion(){


        connfd = accept(sockfd, (SA *) &cli, &len);
        if (connfd < 0) {
            printf("server acccept failed...\n");
            exit(0);
        } else
            printf("server acccept the client...\n");

        // Function for chatting between client and server
        puerto(connfd);
    };

    ///metodo sin parametros donde se crea el socket desde cero e inicializa la aplicacion y la comunicacion entre servidor y cliente
    int iniciar() {

        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
            exit(0);
        } else
            printf("Socket exitosamente creado ...\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        //permite seguir usando la direccion a la que esta unido el servidor (aunque no se haya cerrando el socket con la funcion close)
        int activado;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));



        // Binding newly created socket to given IP and verification
        if ((bind(sockfd, (SA *) &servaddr, sizeof(servaddr))) != 0) {
            printf("Fallo el enlace al socket ...\n");
            exit(0);
        } else
            printf("Socket exitosamente enlazado..\n");

        // Now server is ready to listen and verification
        if ((listen(sockfd, 5)) != 0) {
            printf("Listen failed...\n");
            exit(0);
        } else
            printf("Server listening..\n");
        len = sizeof(cli);


/*
        pthread_t hilo1;
        pthread_create(&hilo1, NULL, &aceptarConexion(algo), algo);
        pthread_join(hilo1,NULL);

        pthread_t hilo2;
        pthread_create(&hilo2, NULL,(void*)puerto,1);
*/

        // Accept the data packet from client and verification
        aceptarConexion();


        // After chatting close the socket
        close(sockfd);
    };




};



#endif //SERVIDOR_TCPSERVER_H
