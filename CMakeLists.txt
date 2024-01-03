cmake_minimum_required(VERSION 3.26)
project(ASN5 C)

set(CMAKE_C_STANDARD 11)

add_executable(ASN5 main.c
        datatype.h
        datatype.c
        bstree.h
        bstree.c
        matrix.h
        matrix.c)
