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
#include "Jugador.h"



#define MAX 80
#define PORT 8080
#define SA struct sockaddr



class TCPserver {

private:
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;
    char buff[MAX];
    ArchivoTexto recibido;

    Partida *partida;


public:

    void castearLista_a_Char(Lista* listaCast){
        for(int i=0;i<listaCast->tamano();i++){
            char data = (char)listaCast->obtener_dato(i);
            listaCast->cambiar_Dato_a_char(i,data);
        }
     }

    void leerPaquete(int sockfd){
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));


        if (strncmp("iniciar", buff, 4) == 0) {
            //crearJugador(sockfd);

            partida=new Partida();
            Jugador* jugador=new Jugador(1);



            partida->Jugadores->anadir_final(jugador);
            partida->repartir_letras();



            Lista* l = partida->Jugadores->obtener_dato(0)->fichas;
            l->print_lista();
            l->anadir_Inicio(0);

            string lista=partida->castear(l);
            char elemento[200];
            strcpy(elemento,lista.c_str());

            write(sockfd, elemento, sizeof(buff));


        }
        else{
            std::string retornar = buff;

            Lista* ista = partida->castear_Lista_to_String(retornar);
            ista->print_lista();
            // print buffer which contains the client contents
            //printf("cliente envia >>> : %s\t");

                if(partida->encontraryasignar(ista)){
                    Lista* lista = partida->obtener_letras();
                    lista->anadir_Inicio(1);
                string l=partida->castear(lista);
                char elemento[200];
                strcpy(elemento,l.c_str());
                write(sockfd, elemento, sizeof(buff));

            }else{
                partida->reintentar(ista);
                //bzero(buff, MAX);
                notificarError(sockfd);
                //write(sockfd,"error",sizeof(buff));

            }

        }

    }

    void notificarError(int sockfd){
        bzero(buff, MAX);
        write(sockfd, "error", sizeof(buff));
    }

    void enviarPaquete(int sockfd){
        bzero(buff, MAX);
        printf("Enviar al cliente >>> : ", buff);
        bzero(buff, MAX);
        int n=0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
    }

    void enviarSalir(int sockfd){
        bzero(buff, MAX);

        write(sockfd, "exit", sizeof(buff));
    }

    bool terminarConexion(){
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Finalizado...\n");
            return true;
        }
        return false;
    }



    void crearJugador(int sockfd){
        //if (strncmp("jugador", buff, 4) == 0) {
            printf("se solicita crear un jugador...\n");
            write(sockfd, "el servidor creara un nuevo jugador \n", sizeof(buff));

       // }
    }


    void puerto(int sockfd){
        // infinite loop for chat
        for (;;) {

            leerPaquete(sockfd);
            //enviarPaquete(sockfd);

            if(terminarConexion()){
                break;
            }
        }
        // After chatting close the socket
        close(sockfd);
    };


    void aceptarConexion(int sockfd){

        //while(true) {
            connfd = accept(sockfd, (SA *) &cli, &len);
            if (connfd < 0) {
                printf("server acccept failed...\n");
                exit(0);
            } else {
                printf("server acccept the client...\n");


                    leerPaquete(connfd);



            //}

            // Function for chatting between client and server
            puerto(connfd);
        }


    };


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


        // Accept the data packet from client and verification
        aceptarConexion(sockfd);

        //puerto(connfd);

    };




};



#endif //SERVIDOR_TCPSERVER_H
