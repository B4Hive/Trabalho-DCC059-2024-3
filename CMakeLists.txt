
cmake_minimum_required(VERSION 3.10)
project(solver LANGUAGES CXX)
add_executable(main.o grafo.h
                    grafo.cpp
                    grafo_lista.cpp
                    grafo_matriz.cpp
                    data_strc.cpp
                    main.cpp)