#include "grafo_matriz.h"

grafo_matriz::grafo_matriz()
{

    this->m = new int[Grafo::Ordem() * Grafo::Ordem()];
    for(int i = 0; i < Grafo::Ordem(); i++)
    {
        for(int j = 0; j < Grafo::Ordem(); j++)
        {
            m[i * Grafo::Ordem() + j] = 0;
        }
    }
}

grafo_matriz::~grafo_matriz()
{
    delete m;
}


int &grafo_matriz::operator()(unsigned int v, unsigned int w)
{
    return m[v * Grafo::Ordem() + w];
}