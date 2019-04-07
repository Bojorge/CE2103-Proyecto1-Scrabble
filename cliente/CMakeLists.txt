cmake_minimum_required(VERSION 3.13)
project(cliente)

set(CMAKE_CXX_STANDARD 14)

add_executable(cliente main.cpp TCPclient.cpp TCPclient.h Serial.cpp Serial.h ArchivoTexto.cpp ArchivoTexto.h)