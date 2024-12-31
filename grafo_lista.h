#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "grafo.h"

class grafo_lista : public Grafo {
    public:
        grafo_lista();
        ~grafo_lista();

        void insere_vertice(unsigned int id, int peso);
        //void remove_vertice(unsigned int id);

        void insere_aresta(unsigned int v, unsigned int w, int peso);
       // void remove_aresta(unsigned int v, unsigned int w);

        int  pesoAresta(unsigned int v, unsigned int w);
        int  pesoVertice(unsigned int idVertice);
        bool buscaVertice(unsigned int idVertice);
        bool buscaAresta(unsigned int v, unsigned int w);

        edge *getAresta(unsigned int idAresta);

        //B4Hive
        bool auxArestaPonte();
        void BPPonte(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV, int ignoredW);
        bool auxVerticeArticulacao();
        void BPArticulacao(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV);
        int auxSetGrau();

        void inicializa();
        void imprime();
        
    private:
        vertice* inicio;
        vertice *getInicio();
        vertice *getVertice(unsigned int v);
};

#endif