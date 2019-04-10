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

#include "Lista.h"
#include "Matriz.h"
#include "Partida.h"
#include "JsonDoc.h"

#include <sys/types.h>
#include <sys/socket.h>

#include <pthread.h>

/*
TCPserver servidor;

void *thread(void * algo){

    servidor.iniciar();
}

void *funcion2(void * algo){
    while (true){
        std::cout<<"-----------"<<std::endl;
    }
}

 */

int main() {

    TCPserver servidor;

    servidor.iniciar();

    //JsonDoc json;

    //json.sample_sendapi();


    //void * param;
    //void *algo2;


   // pthread_t hilo1;
    //pthread_create(&hilo1, NULL,thread,param);

    //pthread_t hilo2;
    //pthread_create(&hilo2, NULL,funcion2,algo);

    //pthread_join(hilo1, NULL);
    //pthread_join(hilo2, NULL);


    //std::thread t1(funcion1);
    //t1.join();
    //std::thread t2(funcion2);
    //t2.join();




    //ArchivoTexto datos;
    //datos.escribir("Mae estos son los datos que escribi");
    //datos.leer("datosServer.txt");

    //Serial serial;
    //serial.crearArchivoBinaro();


    //return 0;

}

/*
#include <mutex>
#include <thread>
#include <vector>
#include <functional>
#include <atomic>
#include <queue>

int main() {
//
    std::cout << "Threading map example" << std::endl;
    std::cout << "Concurrent threads: " << std::thread::hardware_concurrency() << std::endl;
    ThreadPool pool;
    std::vector<int> args{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto res = pool.map<std::function< int(int)>,int,int>
            (
                    [](int i) {
                        std::this_thread::sleep_for(std::chrono::seconds(rand() % 2));
                        return i + 10;
                    },
                    args
    );
    for (int& r: res)
    {
        std::cout << r << std::endl;
    }
    return 0;
}

*/