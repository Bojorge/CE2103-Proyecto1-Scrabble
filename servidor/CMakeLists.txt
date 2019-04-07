cmake_minimum_required(VERSION 3.13)
project(servidor)

set(CMAKE_CXX_STANDARD 14)

add_executable(servidor main.cpp TCPserver.cpp TCPserver.h ArchivoTexto.cpp ArchivoTexto.h Serial.cpp Serial.h JsonDoc.cpp JsonDoc.h Jugador.h Lista.h ListaLetras.h ListaT.h Matrix.h Matriz.h Nodo.h NodoT.h Partida.h)