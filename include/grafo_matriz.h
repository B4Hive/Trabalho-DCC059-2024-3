/**
 * @file grafo_matriz.h
 *
 * @brief Arquivo de cabeçalho da classe grafo_matriz que é filha da classe Grafo.
 * @version 1.1.0
 * @date 2025-02-10
 */

#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "grafo.h"

/**
 * @class grafo_matriz
 * @brief Implementação de um grafo utilizando matriz de adjacência.
 *
 * A classe `grafo_matriz` herda da classe base `Grafo` e implementa seus métodos
 * usando uma matriz para armazenar as arestas e os vértices do grafo.
 */
class grafo_matriz : public Grafo
{
public:
    grafo_matriz();
    ~grafo_matriz();

    void insere_vertice(int id, int peso);
    void novo_no(int peso);
    void deleta_no(int id);
    void realoca();

    void insere_aresta(int v, int w, float peso);
    void nova_aresta(int v, int w, float peso);

    void deleta_aresta(int v, int w);

    int pesoVertice(int idV);
    bool buscaVertice(int id);
    int *vizinhosVertice(int id);
    int grauVertice(int id);

    float pesoAresta(int v, int w);
    bool buscaAresta(int v, int w);

    edge *getAresta(int v, int w);
    float &operator()(int v, int w);

    // B4Hive
    void inicializa();
    void imprime();

private:

    float *m;                     ///< Ponteiro para a matriz de adjacência representada em um array unidimensional.

    int ordem_matriz;           ///< Número de vértices no grafo.
    unsigned int exp_ordem = 0; ///< Variável auxiliar para realocação da matriz.
};

#endif