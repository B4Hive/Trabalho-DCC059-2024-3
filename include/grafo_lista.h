#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "grafo.h"

class grafo_lista : public Grafo
{
public:
    grafo_lista();
    ~grafo_lista();

    
    void insere_vertice(int id, int peso);
    void novo_no(int peso);
    void deleta_no(int id);

    void insere_aresta(int v, int w, float peso);
    void nova_aresta(int v, int w, float peso);
    void deleta_aresta(int v, int w);

    int pesoVertice(int id);
    bool buscaVertice(int id);
    int grauVertice(int id);
    int *vizinhosVertice(int id);

    float pesoAresta(int v, int w);
    bool buscaAresta(int v, int w);

    edge *getAresta(int v, int w);

    void inicializa();
    void imprime();

private:
    vertice *inicio;
    vertice *getInicio();
    vertice *getVertice(int v);
};

#endif