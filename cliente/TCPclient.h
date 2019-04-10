//
// Created by manuel on 01/04/19.
//

#ifndef CLIENTE_TCPCLIENT_H
#define CLIENTE_TCPCLIENT_H

#include <iostream>

// Write CPP code here
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>

#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr
///clase donde se maneja el cliente que se conectara con el servidor 
class TCPclient {

private:

    char buff[MAX];

public:
    ///metodo que lee el dato proveniente del servidor por medio de la comuncacion socket
    void leerPaquete(int sockfd){

        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));

        printf("Server envia >>> : %s", buff);
    }
    ///metodo que envia el dato proveniente del cliente y lo envia al servidor
    void enviarPaquete(int sockfd){

        bzero(buff, sizeof(buff));
        printf("    Enviar al servidor >>> : ");
        int n = 0;
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
    }
    ///metodo booleano donde se termina la concexion del socket
    bool terminarConexion(){
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Cliente finalizado...\n");
            return true;
        }
        return false;
    }

    ///metodo donde se crea un loop que mantiene viva la conexion entre el server y el cliente
    void puerto(int sockfd) {

        for (;;) {

            enviarPaquete(sockfd);
            if(terminarConexion()){
                break;
            }

            leerPaquete(sockfd);
        }
    };

    ///metodo donde se crea el socket desde cero y se inicia la comunicacion del server al cliente
    int iniciar(){

        int sockfd, connfd;
        struct sockaddr_in servaddr, cli;

        // socket create and varification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
            exit(0);
        }
        else
            printf("Socket exitosamente creado ...\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // connect the client socket to server socket
        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("conexion con el server fallida...\n");
            exit(0);
        }
        else
            printf("se ha conectado al server..\n");

        // function for chat
        puerto(sockfd);

        // close the socket
        close(sockfd);


    };

};


#endif //CLIENTE_TCPCLIENT_H
