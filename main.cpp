#include <iostream>
#include "grafo.h"


int main(int argc, char *argv[])
{

    std::cout << "Programa iniciado " << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for(int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    std::string filename;
    std::string parametro1 = argv[1];
    std::string parametro2 = argv[2];
    std::cout << "Parametro1: " << parametro1 << std::endl;
    std::cout << "Parametro2: " << parametro2 << std::endl;
    filename = argv[3];
    std::cout << "Filename: " << filename << std::endl;
    Grafo *g = new Grafo(filename);

    if(parametro1 == "-d")
    {
        std::cout << "Entrou no if que eu pedi" << std::endl;
        g->readInfo(argv[2]);
        g->exportDesc();
    }
    if(parametro2 == "-i")
    {
        //g->readDesc(argv[2]);
        //g->exportInfo();
    }
    

    
    delete g;
    return 0;
}