cmake_minimum_required(VERSION 3.24)
project(Lista05 C)

set(CMAKE_C_STANDARD 11)

include_directories(ProjListaDinEncad)

add_executable(Lista05
        ProjListaDinEncad/ListaDinEncad.c
        ProjListaDinEncad/ListaDinEncad.h
        ProjListaDinEncad/main.c )
