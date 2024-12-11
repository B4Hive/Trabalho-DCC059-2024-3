#include "grafo_lista.h"

grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

grafo_lista::~grafo_lista()
{
    delete inicio;
}

void grafo_lista::insere_vertice(unsigned int id, int peso)
{
    vertice *v = new vertice();
    v->ID() = id;
    v->Peso() = peso;
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

void grafo_lista::insere_aresta(unsigned int v, unsigned int w, int peso)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            edge *e = new edge(v, w);
            e->Peso() = peso;
            p->insereAresta(e);
            break;
        }
        p = p->getProx();
    }
}

int grafo_lista::pesoVertice(unsigned int idVertice)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == idVertice)
        {
            return p->Peso();
        }
        p = p->getProx();
    }
    std::cout << "Vertice nao encontrado" << std::endl;
    return 0;
}

int grafo_lista::pesoAresta(unsigned int v, unsigned int w)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            edge *e = p->getAresta();
            while(e != NULL)
            {
                if(e->W() == w)
                {
                    return e->Peso();
                }
                e = e->getProx();
            }
        }
        p = p->getProx();
    }
    std::cout << "Aresta nao encontrada" << std::endl;
    return 0;
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

