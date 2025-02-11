/**
 * @file data_strc.cpp
 * @brief Arquivo de implementação das classes egde e vertice
 * @version 1.1.0
 * @date 2025-02-10
 */

#include "../include/data_strc.h"

/*-------------------------- Vertice -----------------------------*/

/**
 * @brief Construtor padrão da classe vertice.
 * Inicializa um vértice com ID, grau e peso iguais a zero,
 * sem arestas e sem próximo vértice.
 */
vertice::vertice()
{
    this->id = 0;
    this->grau = 0;
    this->peso = 0;
    this->prox = NULL;
    this->init_aresta = NULL;
}

/**
 * @brief Destrutor da classe vertice.
 */
vertice::~vertice() {};

/**
 * @brief Retorna uma referência ao ID do vértice.
 * @return Referência para o ID do vértice.
 */
int &vertice::ID()
{
    return id;
}

/**
 * @brief Retorna uma referência ao grau do vértice.
 * @return Referência para o grau do vértice.
 */
int &vertice::Grau()
{
    return grau;
}

/**
 * @brief Retorna uma referência ao peso do vértice.
 * @return Referência para o peso do vértice.
 */
int &vertice::Peso()
{
    return peso;
}

/**
 * @brief Retorna um ponteiro para o próximo vértice na lista.
 * @return Ponteiro para o próximo vértice.
 */
vertice *vertice::getProx()
{
    return prox;
}

/**
 * @brief Define o próximo vértice na lista.
 * @param p Ponteiro para o próximo vértice.
 */
void vertice::setProx(vertice *p)
{
    prox = p;
}

/**
 * @brief Insere uma aresta na lista de arestas do vértice.
 * @param e Ponteiro para a aresta a ser inserida.
 */
void vertice::insereAresta(edge *e)
{
    if (init_aresta == NULL)
    {
        init_aresta = e;
    }
    else
    {
        edge *ep = init_aresta;
        while (ep->getProx() != NULL)
        {
            ep = ep->getProx();
        }
        ep->setProx(e);
    }
}

/*-------------------------- Aresta -----------------------------*/

/**
 * @brief Construtor da classe edge.
 * @param v Vértice de origem.
 * @param w Vértice de destino.
 */
edge::edge(int v, int w)
{
    this->v = v;
    this->w = w;
    this->peso = 0;
    this->prox = NULL;
}

/**
 * @brief Destrutor da classe edge.
 */
edge::~edge() {};

/**
 * @brief Construtor padrão da classe edge.
 * Inicializa uma aresta com ID, peso e ponteiros nulos.
 */
edge::edge()
{
    id = 0;
    v = 0;
    w = 0;
    peso = 0;
    prox = NULL;
}

/**
 * @brief Retorna um ponteiro para a próxima aresta na lista.
 * @return Ponteiro para a próxima aresta.
 */
edge *edge::getProx()
{
    return this->prox;
}
