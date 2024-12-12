#include "grafo_matriz.h"

grafo_matriz::grafo_matriz()
{

    if(this->Direcionado() == 0) // matriz  triangular superior 
    {
        this->m = new int [this->Ordem()];
            for(int i = 0; i < this->Ordem(); i++)
            {
                m[i] = 0;
            }
    }
    
    if( this->Direcionado() == 1)
    {
        this->m = new int [(this->Ordem() * this->Ordem())];
            for(int i = 0; i < (this->Ordem() * this->Ordem()); i++)
            {
                m[i] = 0;
            }
    }


}

grafo_matriz::~grafo_matriz()
{
    delete m;
}


int &grafo_matriz::operator()(unsigned int v, unsigned int w)
{
    if(this->Direcionado() == 0)
    {
        if(v > w)
        {
            return m[w * Grafo::Ordem() + v];
        }
        else
        {
            return m[v * Grafo::Ordem() + w];
        }
    }
    else
    {
        return m[v * Grafo::Ordem() + w];
    }
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
        this->Tamanho()++;
    }
    else
    {
        this->operator()(v,w) = 1;
        this->Tamanho()++;
    }
}

int grafo_matriz::pesoAresta(unsigned int v, unsigned int w)
{
    if(Arestas_ponderadas())
    {
        return this->operator()(v,w);
    }
    else
    {
        return 0;
    }
}

int grafo_matriz::pesoVertice(unsigned int idVertice)
{
    if(Vertices_ponderados())
    {
        return this->operator()(idVertice, idVertice);
    }
    else
    {
        return 0;
    }
}

bool grafo_matriz::buscaVertice(unsigned int idVertice)
{
    if(this->operator()(idVertice, idVertice) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool grafo_matriz::buscaAresta(unsigned int v, unsigned int w)
{
    if(this->operator()(v,w) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

edge *grafo_matriz::getAresta(unsigned int idAresta)
{
    edge *e = new edge();
    unsigned int id = idAresta;
    e->ID() = idAresta;
    for(int i = 0; i < this->Ordem(); i++)
    {
        for(int j = 0; j < this->Ordem(); j++)
        {
            if(this->operator()(i,j) != 0)
            {
                id--;
            }
            if(id == 0)
            {
                e->V() = i;
                e->W() = j;
                if(Arestas_ponderadas())
                {
                    e->Peso() = this->operator()(i,j);
                }
                return e;
            }
        }
    }
    std::cout << "Aresta nao encontrada" << std::endl;
    delete e;
    return NULL;
}