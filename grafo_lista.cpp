#include "grafo_lista.h"

grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

grafo_lista::~grafo_lista()
{
    delete inicio;
}

void grafo_lista::insere(vertice *v)
{
    if(inicio == NULL)
    {
        inicio = v;
    }
    else
    {
        vertice *p = inicio;
        while(p->getProx() != NULL)
        {
            p = p->getProx();
        }
        p->setProx(v);
    }
}

vertice* grafo_lista::getInicio()
{
    return inicio;
}

vertice* grafo_lista::getVertice(unsigned int v)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            return p;
        }
        p = p->getProx();
    }
    return NULL;
}


bool grafo_lista::busca(unsigned int v)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            return true;
        }
        p = p->getProx();
    }
    return false;
}
