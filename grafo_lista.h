#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "grafo.h"

class grafo_lista : public Grafo {
    public:
        grafo_lista();
        ~grafo_lista();

        void insere(vertice *v);
        void remove();
        bool busca(unsigned int v);
        vertice *getInicio();
        vertice *getVertice(unsigned int v);
        
    private:
        vertice* inicio;
};

#endif