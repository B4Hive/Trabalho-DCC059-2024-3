#include <iostream>
#include "grafo.h"

int main(int argc, char *argv[])
{

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