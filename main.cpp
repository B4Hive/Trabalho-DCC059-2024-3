#include <iostream>
#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"


int main(int argc, char *argv[])
{

    std::cout << "Programa iniciado " << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for(int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    std::cout << std::endl;
    std::string filename;
    std::string parametro1 = argv[1];
    std::string parametro2 = argv[2];
    std::cout << "Parametro1: " << parametro1 << std::endl;
    std::cout << "Parametro2: " << parametro2 << std::endl;
    filename = argv[3];
    std::cout << "Filename: " << filename << std::endl << std::endl;

    Grafo *g;

    if(parametro1 == "-d")
    {
        if(parametro2 == "-l") {
            g = new grafo_lista;
        }
        if(parametro2 == "-m") {
            g = new grafo_matriz; 
        }
        g->carrega_grafo(argv[2], filename);
        g->imprime();
        g->exportDesc();
    }
    if(parametro2 == "-c") 
    {
        if(parametro1 == "-l") {
            g = new grafo_lista;
        }
        if(parametro1 == "-m") {
            g = new grafo_matriz; 
        }
        // g->novo_grafo(argv[1], filename);
        g->imprime();
        g->exportInfo();
    }
    
    delete g;
    
    return 0;
}