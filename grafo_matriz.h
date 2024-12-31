#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"

class grafo_matriz : public Grafo
{
public:
    grafo_matriz();
    ~grafo_matriz();

    void insere_vertice(unsigned int id, int peso);
    // void remove_vertice(unsigned int id);

    void insere_aresta(unsigned int v, unsigned int w, int peso);
    // void remove_aresta(unsigned int v, unsigned int w);

    int pesoAresta(unsigned int v, unsigned int w);
    int pesoVertice(unsigned int idVertice);
    bool buscaVertice(unsigned int idVertice);
    bool buscaAresta(unsigned int v, unsigned int w);

    edge *getAresta(unsigned int idAresta);

    int &operator()(unsigned int v, unsigned int w);
    
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
    unsigned int tamanho_vetor;
};

#endif