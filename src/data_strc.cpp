#include "data_strc.h"

/*-------------------------- Vertice -----------------------------*/

vertice::vertice()
{
    this->id = 0;
    this->grau = 0;
    this->peso = 0;
    this->prox = NULL;
    this->init_aresta = NULL;
}

vertice::~vertice() {};

int &vertice::ID()
{
    return id;
}

int &vertice::Grau()
{
    return grau;
}

int &vertice::Peso()
{
    return peso;
}

vertice *vertice::getProx()
{
    return prox;
}

void vertice::setProx(vertice *p)
{
    prox = p;
}

void vertice::insereAresta(edge *e)
{
    if (init_aresta == NULL)
    {
        init_aresta = e;
    }
    else
    {
        edge *ep = init_aresta;
        while (ep->getProx() != NULL)
        {
            ep = ep->getProx();
        }
        ep->setProx(e);
    }
}

/*-------------------------- Aresta -----------------------------*/

edge::edge(int v, int w)
{
    this->v = v;
    this->w = w;
    this->peso = 0;
    this->prox = NULL;
}

edge::~edge() {};

edge::edge()
{
    id = 0;
    v = 0;
    w = 0;
    peso = 0;
    prox = NULL;
}

edge *edge::getProx()
{
    return this->prox;
}
