#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"

class grafo_matriz : public Grafo
{
    public:
        grafo_matriz();
        ~grafo_matriz();

        int &operator()(unsigned int v, unsigned int w);
        
    private:
        int *m;
};

#endif