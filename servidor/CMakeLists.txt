cmake_minimum_required(VERSION 3.13)
project(servidor)

set(CMAKE_CXX_STANDARD 14)

add_executable(servidor main.cpp TCPserver.cpp TCPserver.h ArchivoTexto.cpp ArchivoTexto.h Serial.cpp Serial.h)