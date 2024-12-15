#include "grafo_matriz.h"

grafo_matriz::grafo_matriz()
{

    if(this->Direcionado() == 0) // matriz  triangular infeiror 
    {
        int tamanho = (this->Ordem() * (this->Ordem() + 1)) / 2;
        this->m = new int [tamanho];
            for(int i = 0; i < tamanho; i++)
            {
                m[i] = 0;
            }
        std::cout << std::size_t(m) << std::endl;
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
    int i = v-1;
    int j = w-1;
    if(this->Direcionado() == 0)
    {   if(i < j)
            return m[i * (i - 1) / 2 + j];
        else
            return m[j * (j - 1) / 2 + i];
    }
    else
    {
        return m[i * Grafo::Ordem() + j];
    }
}

void grafo_matriz::insere_vertice(unsigned int id, int peso)
{
    
    this->operator()(id, id) = peso;
    
    std::cout << "Vertice inserido" << std::endl;
}

void grafo_matriz::insere_aresta(unsigned int v, unsigned int w, int peso)
{

    this->operator()(v,w) = peso;
    this->Tamanho()++;
    
    std::cout << "Aresta inserida" << std::endl;
    std::cout << "valor: " << this->operator()(v,w) << std::endl;
}

int grafo_matriz::pesoAresta(unsigned int v, unsigned int w)
{
    
    return this->operator()(v,w);
    
}

int grafo_matriz::pesoVertice(unsigned int idVertice)
{
    
    return this->operator()(idVertice, idVertice);
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