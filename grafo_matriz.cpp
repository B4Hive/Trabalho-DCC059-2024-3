#include "grafo_matriz.h"

grafo_matriz::grafo_matriz(unsigned int ordem)
{
    this->m = new edge[ordem * ordem];
}

grafo_matriz::~grafo_matriz()
{
    delete m;
}