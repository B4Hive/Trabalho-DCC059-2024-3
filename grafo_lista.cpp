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
// B4Hive-begin
void grafo_lista::auxArestaPonte(bool *result) {
    *result = false;
    vertice *p = inicio;
    int *visitado = new int[Ordem()];
    int *desc = new int[Ordem()];
    int *low = new int[Ordem()];
    int *pai = new int[Ordem()];
    int *tempo = new int;
    *tempo = 0;
    for(int i = 0; i < Ordem(); i++) {
        visitado[i] = 0;
        desc[i] = 0;
        low[i] = 0;
        pai[i] = -1;
    }
    while(p != NULL) {
        if(visitado[p->ID()-1] == 0) {
            BPPonte(p, visitado, desc, low, pai, tempo, result);
        }
        p = p->getProx();
    }
}

void grafo_lista::BPPonte(vertice *v, int *visitado, int *desc, int *low, int *pai, int *tempo, bool *result) {
    visitado[v->ID()-1] = 1;
    *tempo++;
    desc[v->ID()-1] = *tempo;
    low[v->ID()-1] = desc[v->ID()-1];
    edge *e = v->getAresta();
    while(e != NULL) {
        if(visitado[e->W()] == 0) {
            pai[e->W()] = v->ID();
            BPPonte(getVertice(e->W()), visitado, desc, low, pai, tempo, result);
            low[v->ID()-1] = std::min(low[v->ID()-1], low[e->W()]);
            if(low[e->W()] > desc[v->ID()-1]) {
                *result = true;
            }
        }
        else if(e->W() != pai[v->ID()-1]) {
            low[v->ID()-1] = std::min(low[v->ID()-1], desc[e->W()]);
        }
        e = e->getProx();
    }
}

void grafo_lista::auxVerticeArticulacao(bool *result) {
    *result = false;
    vertice *p = inicio;
    int *visitado = new int[Ordem()];
    int *desc = new int[Ordem()];
    int *low = new int[Ordem()];
    int *pai = new int[Ordem()];
    int *tempo = new int;
    *tempo = 0;
    for(int i = 0; i < Ordem(); i++) {
        visitado[i] = 0;
        desc[i] = 0;
        low[i] = 0;
        pai[i] = -1;
    }
    while(p != NULL) {
        if(visitado[p->ID()-1] == 0) {
            //BPArticulacao(p, visitado, desc, low, pai, tempo, result);
        }
        p = p->getProx();
    }
}
// B4Hive-end
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

