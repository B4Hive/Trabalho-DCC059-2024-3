#ifndef DATA_STRC_H
#define DATA_STRC_H

#include <iostream>



class vertice
{
    public:
    vertice(){}
    ~vertice(){}

    unsigned int &ID(){return id;}
    unsigned int &Grau(){return grau;}
    int &Peso(){return peso;}
    vertice *getProx(){return prox;}
    void setProx(vertice *p){prox = p;}
    void insereAresta(edge *e);

    private:
    unsigned int id;
    unsigned int grau;
    int peso;
    vertice *prox;
    edge *aresta;
};

class edge
{
    public:
    edge(unsigned int v, unsigned int w);
    edge();
    ~edge();

    unsigned int &V(){return v;}
    unsigned int &W(){return w;}
    int &Peso(){return peso;}

    edge *getProx();
    void setProx(edge *p){prox = p;}

    private:
    unsigned int id;
    unsigned int v, w;
    int peso;
    
    edge *prox;
};

#endif