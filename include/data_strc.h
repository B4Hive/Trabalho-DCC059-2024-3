/**
 * @file data_strc.h
 * @brief Arquivo de cabeçalho das classes egde e vertice
 * @version 1.1.0
 * @date 2025-02-10
 */

#ifndef DATA_STRC_H
#define DATA_STRC_H

#include <iostream>

/**
 * @class edge
 * @brief Representa uma aresta de um grafo.
 *
 * A classe `edge` contém informações sobre uma aresta, incluindo os vértices que conecta,
 * seu peso e um ponteiro para a próxima aresta na lista de adjacência.
 */
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
    int id;     ///< Identificador da aresta.
    int v, w;   ///< Vértices conectados pela aresta.
    int peso;   ///< Peso da aresta.
    edge *prox; ///< Ponteiro para a próxima aresta na lista de adjacência.
};

class vertice
{
public:
    vertice();
    ~vertice();

    int &ID();
    int &Grau();
    int &Peso();
    edge *get_init_aresta() { return init_aresta; }
    void set_init_aresta(edge *e) { init_aresta = e; }
    vertice *getProx();
    void setProx(vertice *p);
    void insereAresta(edge *e);

private:
    int id;            ///< Identificador do vértice.
    int grau;          ///< Grau do vértice.
    int peso;          ///< Peso do vértice.
    vertice *prox;     ///< Ponteiro para o próximo vértice na lista encadeada.
    edge *init_aresta; ///< Ponteiro para a primeira aresta do vértice.
};

#endif