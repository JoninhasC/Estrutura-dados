cmake_minimum_required(VERSION 3.24)
project(Lista06 C)

set(CMAKE_C_STANDARD 11)

include_directories(ProjListaDinEncad)

add_executable(Lista06
        ProjListaDinEncad/ListaDinEncad.c
        ProjListaDinEncad/ListaDinEncad.h
        ProjListaDinEncad/main.c)
