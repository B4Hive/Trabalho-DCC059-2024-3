/**
 * @file grafo.h
 *
 * @brief Arquivo de cabeçalho da classe Grafo que é pai das classes grafo_matriz e grafo_lista
 * @version 1.1.0
 * @date 2025-02-10
 */

#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include "data_strc.h"
using namespace std;

/**
 * @class Grafo
 * @brief Classe base para implementação de grafos.
 * Essa classe fornece uma estrutura genérica para representação de grafos,
 * sendo estendida pelas classes `grafo_matriz` e `grafo_lista`.
 */
class Grafo
{
public:
    Grafo() {}
    virtual ~Grafo() {}

    void carrega_grafo(char *tipo, string dataFileName);
    void novo_grafo(string descFileName, string outFileName);
    void exportInfo();
    void exportDesc();

    virtual void inicializa() = 0;
    virtual void imprime() = 0;

    virtual void insere_vertice(int id, int peso) = 0;
    virtual void novo_no(int peso) = 0;
    virtual void deleta_no(int id) = 0;

    virtual void insere_aresta(int v, int w, float peso) = 0;
    virtual void nova_aresta(int v, int w, float peso) = 0;

    virtual void deleta_aresta(int v, int w) = 0;

    virtual int pesoVertice(int id) = 0;
    virtual bool buscaVertice(int id) = 0;
    virtual int grauVertice(int id) = 0;
    virtual int *vizinhosVertice(int id) = 0;

    virtual float pesoAresta(int v, int w) = 0;

    virtual edge *getAresta(int v, int w) = 0;
    virtual bool buscaAresta(int v, int w) = 0;

    virtual void setCor(int id, int cor) = 0;
    virtual int getCor(int id) = 0;

    // virtual void nova_aresta(int v, int w, int peso) = 0;

    int getGrau();
    int getOrdem();
    int getComponentes_conexas();
    int getTamanho();
    bool getDirecionado();
    bool getVertices_ponderados();
    bool getArestas_ponderadas();
    bool getCompleto();
    bool getBipartido();
    bool getArvore();
    bool getAresta_Ponte();
    bool getVertice_de_Articulacao();

    // B4Hive
    void caminhoMinimoFloyd(int u, int v);

    int coloracaoGuloso();
    void coloracaoRecursivo(int cores[], int i);

    int coloracaoRandomizado();
    bool colorido(int cores[], int n);
    
    int coloracaoReativo();
    void coloracaoReativoRecursivo(int cores[], int i, int n);
    int maiorCor(int cores[], int n);
    void trocaCor(int cores[], int n, bool *trocou);

    void exportarCores(int cores[], int n, int c, string filename);


    bool &Debug() { return debug; }

protected:
    void setGrau(int);
    void setOrdem(int);
    void setDirecionado(bool);
    void setComponentes_conexas(int);
    void setVertices_ponderados(bool);
    void setArestas_ponderadas(bool);
    void setCompleto(bool);
    void setBipartido(bool);
    void setArvore(bool);
    void setAresta_Ponte(bool);
    void setVertice_de_Articulacao(bool);
    void setTamanho(int);
    int &Tamanho() { return info[3]; } // Quantidade de arestas que o grafo tem

    // Rodrigo
    void temCiclo(int v, bool visitado[], int pai, bool *resultado);
    bool eh_completo();
    bool eh_arvore();

    // B4Hive
    bool auxArestaPonte();
    void BPPonte(int v, bool visitado[], int *tempo, int disc[], int low[], int pai, int *qtdPonte);
    bool auxVerticeArticulacao();
    void BPArticulacao(int v, int *tempo, int disc[], int low[], int pai[], int *qtdArticulacao);

    // ufjoao
    unsigned int BPConexo(); // info[2]
    void auxBPConexos(int v, bool *visitado);
    bool BipartidoFB();

    

    // Variaveis internas
    string filename; ///< Variável que armazena o nome do arquivo utilizado para carregar o grafo.
    string outFile;  ///< Variável que armazena o nome do arquivo onde os resultados ou informações do grafo serão exportados.

    /**
     * @brief Array de informações do grafo.
     *
     * Variável que mantém algumas propriedades importantes do grafo:
     * - info[0] -> Grau do grafo.
     * - info[1] -> Ordem do grafo.
     * - info[2] -> Componentes conexos do grafo.
     * - info[3] -> Tamanho (número de arestas) do grafo.
     */
    int info[4]{0, 10, 0, 0}; ///<[Grau, Ordem, Componentes_conexas, Tamanho]

    /**
     * @brief Array de flags para propriedades do grafo.
     *
     * Variável que mantém flags (booleanos) para indicar características do grafo:
     * - dpp[0] -> Grafo direcionado.
     * - dpp[1] -> Vértices ponderados.
     * - dpp[2] -> Arestas ponderadas.
     * - dpp[3] -> Grafo completo.
     * - dpp[4] -> Grafo bipartido.
     * - dpp[5] -> Grafo é uma árvore.
     * - dpp[6] -> Aresta ponte.
     * - dpp[7] -> Vértice de articulação.
     */
    bool dpp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // direcionado             [0]
    // vertices ponderados     [1]
    // arestas ponderadas      [2]
    // completo                [3]
    // Bipartido               [4]
    // Arvore                  [5]
    // Aresta Ponte            [6]
    // Vertice de Articulação  [7]

    bool debug = 0; ///< Variável booleana que ativa ou desativa a depuração de processos do grafo.
};

#endif