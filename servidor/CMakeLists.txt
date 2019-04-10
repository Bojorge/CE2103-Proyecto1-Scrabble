cmake_minimum_required(VERSION 3.13)
project(servidor)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package(Threads)


set(CMAKE_CXX_STANDARD 14)

add_executable(servidor main.cpp TCPserver.h ArchivoTexto.cpp ArchivoTexto.h Serial.h JsonDoc.h Jugador.h Lista.h ListaLetras.h ListaT.h Matriz.h Nodo.h NodoT.h Partida.h ThreadPool.h)
