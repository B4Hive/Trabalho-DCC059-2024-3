#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"

class grafo_matriz : public Grafo
{
    public:
        grafo_matriz(unsigned int ordem);
        ~grafo_matriz();
        
    private:
        edge *m;
        unsigned int ordem;
};

#endif