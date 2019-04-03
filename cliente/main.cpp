#include <iostream>
#include "TCPclient.h"


#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>

#include <arpa/inet.h>


#include <cstdio>
#include <sys/param.h>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <strings.h>
#include <zconf.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

#include <cstdio>
#include <sys/param.h>


int main() {

    TCPclient cliente;

    cliente.iniciar();

    return 0;
}