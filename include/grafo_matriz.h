#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"



class grafo_matriz : public Grafo
{
public:
    grafo_matriz();
    ~grafo_matriz();

    
    void insere_vertice(int id, int peso);
    void novo_no(int peso);
    void deleta_no(int id);
    void realoca();
    
    void insere_aresta(int v, int w, int peso);
    void nova_aresta(int v, int w, int peso);
    void deleta_aresta(int v, int w);

    int pesoVertice(int idV);
    bool buscaVertice(int id);
    int *vizinhosVertice(int id);
    int grauVertice(int id);

    int pesoAresta(int v, int w);
    bool buscaAresta(int v, int w);

    edge *getAresta(int v, int w);
    int &operator()(int v, int w);

    // B4Hive
    void inicializa();
    void imprime();

private:
    int *m;
    int ordem_matriz;
    unsigned int exp_ordem = 0;
};

#endif