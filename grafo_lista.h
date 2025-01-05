#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "grafo.h"

class grafo_lista : public Grafo {
    public:
        grafo_lista();
        ~grafo_lista();

        void insere_vertice(int id, int peso);
        //void remove_vertice(int id);

        void insere_aresta(int v, int w, int peso);
       // void remove_aresta(int v, int w);

        int  pesoVertice(int id);
        bool buscaVertice(int id);
        int  grauVertice(int id); 
        int *vizinhosVertice(int id);

        int  pesoAresta(int v, int w);
        bool buscaAresta(int v, int w);

        edge *getAresta(int v, int w);

        //B4Hive
        bool auxArestaPonte();
        void BPPonte(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV, int ignoredW);
        bool auxVerticeArticulacao();
        void BPArticulacao(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV);
        int auxSetGrau();

        void inicializa();
        void imprime();
        
    private:
        vertice *inicio;
        vertice *getInicio();
        vertice *getVertice(int v);
};

#endif