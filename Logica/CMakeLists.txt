cmake_minimum_required(VERSION 3.13)
project(TC)

cmake_minimum_required (VERSION 2.4)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK2 REQUIRED gtk+-3.0)

include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK2_LIBRARY_DIRS})
add_executable (gtk-test main.cpp cmake-build-debug/SRC/Lista.h
        cmake-build-debug/SRC/Nodo.h
        cmake-build-debug/SRC/Matriz.h
        cmake-build-debug/SRC/Partida.h
        cmake-build-debug/SRC/Partida.h
        cmake-build-debug/SRC/ListaT.h
        cmake-build-debug/SRC/NodoT.h
        cmake-build-debug/SRC/Jugador.h
        cmake-build-debug/SRC/ListaLetras.h
        cmake-build-debug/SRC/ListaTJugador.h)
add_definitions (${GTK2_CFLAGS_OTHER})
target_link_libraries (gtk-test ${GTK2_LIBRARIES})


set(CMAKE_CXX_STANDARD 14)

add_executable(TC main.cpp)