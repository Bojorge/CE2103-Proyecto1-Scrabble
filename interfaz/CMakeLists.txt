cmake_minimum_required(VERSION 3.13)
project(prueba)
cmake_minimum_required (VERSION 2.4)

find_package (PkgConfig REQUIRED)
find_package(Threads)

pkg_check_modules (GTK2 REQUIRED gtk+-3.0)

include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK2_LIBRARY_DIRS})
add_executable (gtk-test main.cpp
        Lista.h
        Nodo.h
        ListaT.h
        NodoT.h
        ListaLetras.h
        utiles.h)
add_definitions (${GTK2_CFLAGS_OTHER})
target_link_libraries (gtk-test ${GTK2_LIBRARIES})
target_link_libraries (gtk-test ${CMAKE_THREAD_LIBS_INIT})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(prueba main.cpp)