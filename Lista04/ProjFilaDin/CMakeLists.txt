cmake_minimum_required(VERSION 3.24)
project(ProjFilaDin C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjFilaDin
        FilaDin.c
        FilaDin.h
        main.c aviao.c "fila de filas.c" " Pilha de filas.c" "Fila de pilhas.c" PilhaDin.c)
