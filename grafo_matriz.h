#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"

class grafo_matriz : public Grafo
{
public:
    grafo_matriz();
    ~grafo_matriz();

    void insere_vertice(int id, int peso);
    // void remove_vertice(int id);

    void insere_aresta(int v, int w, int peso);
    // void remove_aresta(int v, int w);

    int pesoAresta(int v, int w);
    int pesoVertice(int idVertice);
    bool buscaVertice(int idVertice);
    bool buscaAresta(int v, int w);

    edge *getAresta(int idAresta);

    int &operator()(int v, int w);
    
    //B4Hive
    bool auxArestaPonte();
    void BPPonte(int v, int tag[], bool visitado[], int currentTag, int ignoredV, int ignoredW);
    bool auxVerticeArticulacao();
    void BPArticulacao(int v, int tag[], bool visitado[], int currentTag, int ignoredV);
    int auxSetGrau();

    void inicializa();
    void imprime();

private:
    int *m;
    int tamanho_vetor;
};

#endif