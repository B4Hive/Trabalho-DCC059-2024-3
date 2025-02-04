#ifndef DATA_STRC_H
#define DATA_STRC_H

#include <iostream>

class edge
{
public:
    edge(int v, int w);
    edge();
    ~edge();

    int &V() { return v; }
    int &W() { return w; }
    int &ID() { return id; }
    int &Peso() { return peso; }

    edge *getProx();
    void setProx(edge *ep) { prox = ep; }

private:
    int id;
    int v, w;
    int peso;

    edge *prox;
};

class vertice
{
public:
    vertice();
    ~vertice();

    int &ID();
    int &Grau();
    int &Peso();
    edge *getAresta() { return init_aresta; }
    vertice *getProx();
    void setProx(vertice *p);
    void insereAresta(edge *e);

private:
    int id;
    int grau;
    int peso;
    vertice *prox;
    edge *init_aresta;
};

#endif