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

    grafo_lista *gl;
    grafo_matriz *gm;

    if(parametro1 == "-d")
    {
        if(parametro2 == "-l")
        {
            gl = new grafo_lista;
            gl->carrega_grafo(argv[2], filename);
            gl->exportDesc();
            gl->exportInfo();
        }
        if(parametro2 == "-m")
        {
            gm = new grafo_matriz; 
            gm->carrega_grafo(argv[2], filename);
            gm->imprime_matriz();
            gm->exportDesc();
            gm->exportInfo(); 
        }
    }
    if(parametro2 == "-c") 
    {
        if(parametro1 == "-l")
        {
            gl = new grafo_lista;
            gl->carrega_grafo(argv[1], filename);
            gl->exportInfo();
        }
        if(parametro1 == "-m")
        {
            gm = new grafo_matriz; 
            gm->carrega_grafo(argv[1], filename);
            gm->exportInfo();
        }
    }
    
    return 0;
}