#ifndef DATA_STRC_H
#define DATA_STRC_H

#include <iostream>


class edge
{
    public:
    edge(unsigned int v, unsigned int w);
    edge();
    ~edge();

    unsigned int &V() {return v;}
    unsigned int &W() {return w;}
    unsigned int &ID(){return id;}
    int &Peso()       {return peso;}

    edge *getProx();
    void setProx(edge *p){prox = p;}

    private:
    unsigned int id;
    unsigned int v, w;
    int peso;
    
    edge *prox;
};

class vertice
{
    public:
    vertice();
    ~vertice();

    unsigned int &ID();
    unsigned int &Grau();
    int &Peso();
    edge *getAresta() {return aresta;}
    vertice *getProx();
    void setProx(vertice *p);
    void insereAresta(edge *e);

    private:
    unsigned int id;
    unsigned int grau;
    int peso;
    vertice *prox;
    edge *aresta;
};


#endif