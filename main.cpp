#include <iostream>
#include "grafo.h"

int main(int argc, char *argv[])
{
    if(argc < 3 || argc > 4){
        std::cout << "Input error: missing arguments" << std::endl;
        return 1;
    }
    
    std::string filename;
    filename = argv[3];
    Grafo *g = new Grafo(filename);

    if(argv[1] == "-d")
    {
        g->readInfo(argv[2]);
        g->exportDesc();
    }
    if(argv[1] == "-i")
    {
        g->readDesc(argv[2]);
        g->exportInfo();
    }
    

    
    delete g;
    return 0;
}