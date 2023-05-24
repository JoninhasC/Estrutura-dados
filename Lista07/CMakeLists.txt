cmake_minimum_required(VERSION 3.24)
project(Lista07 C)

set(CMAKE_C_STANDARD 11)

include_directories(ProjArvoreBinaria/ProjArvoreBinaria)

add_executable(Lista07
        ProjArvoreBinaria/ProjArvoreBinaria/ArvoreBinaria.c
        ProjArvoreBinaria/ProjArvoreBinaria/ArvoreBinaria.h
        ProjArvoreBinaria/ProjArvoreBinaria/main.c)
