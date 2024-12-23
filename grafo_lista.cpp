#include "grafo_lista.h"

grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

grafo_lista::~grafo_lista()
{
    vertice *p = inicio;
    while(p != NULL)
    {
        edge *e = p->getAresta();
        while(e != NULL)
        {
            edge *aux = e;
            e = e->getProx();
            delete aux;
        }
        vertice *aux = p;
        p = p->getProx();
        delete aux;
    }
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
        while (p->getProx() != NULL)
        {
            p = p->getProx();
        }
        p->setProx(v);        
    }
}

void grafo_lista::insere_aresta(unsigned int v, unsigned int w, int peso)
{
    vertice *p = inicio;
    edge *e = new edge(v, w);
    e->Peso() = peso;
    e->ID() = this->Tamanho();    
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            p->insereAresta(e);
            std::cout << "Aresta inserida!" << std::endl<< std::endl;
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
            edge *ep = p->getAresta();
            while(ep != NULL)
            {
                if(ep->W() == w)
                {
                    return ep->Peso();
                }
                ep = ep->getProx();
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

edge* grafo_lista::getAresta(unsigned int idAresta)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        edge *e = p->getAresta();
        while(e != NULL)
        {
            if(e->ID() == idAresta)
            {
                return e;
            }
            e = e->getProx();
        }
        p = p->getProx();
    }
    std::cout << "Aresta nao encontrada" << std::endl;
    return NULL;
}

bool grafo_lista::buscaVertice(unsigned int idVertice)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == idVertice)
        {
            return true;
        }
        p = p->getProx();
    }
    return false;
}

bool grafo_lista::buscaAresta(unsigned int v, unsigned int w)
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
                    return true;
                }
                e = e->getProx();
            }
        }
        p = p->getProx();
    }
    return false;
}

