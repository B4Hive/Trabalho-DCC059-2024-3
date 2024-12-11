#include "grafo_matriz.h"

grafo_matriz::grafo_matriz()
{

    this->m = new int[this->Ordem() * this->Ordem()];
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

void grafo_matriz::insere_vertice(unsigned int id, int peso)
{
    if(Vertices_ponderados())
    {
        this->operator()(id, id) = peso;
    }
}

void grafo_matriz::insere_aresta(unsigned int v, unsigned int w, int peso)
{
    if(Arestas_ponderadas())
    {
        this->operator()(v,w) = peso;
    }
    else
    {
        this->operator()(v,w) = 1;
    }
}