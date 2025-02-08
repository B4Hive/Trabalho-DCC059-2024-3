cmake_minimum_required(VERSION 3.10)
project(solver LANGUAGES CXX)
project(MeuProjeto)

# Define os diretórios de include e src
include_directories(include)
set(SOURCE_FILES
    ../main.cpp
    src/grafo.cpp
    src/grafo_lista.cpp
    src/grafo_matriz.cpp
    src/data_strc.cpp
)

# Cria o executável
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(main ${SOURCE_FILES}) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")