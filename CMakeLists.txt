cmake_minimum_required(VERSION 3.13)
project(CE2103_Proyecto1_Scrabble_)

set(CMAKE_CXX_STANDARD 14)

add_executable(CE2103_Proyecto1_Scrabble_ main.cpp ServerSocket.cpp ServerSocket.h ClientSocket.cpp ClientSocket.h SocketException.cpp SocketException.h Socket.cpp Socket.h simple_server_main.cpp simple_server_main.h simple_client_main.cpp simple_client_main.h)


