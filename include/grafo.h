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

class Grafo
{
public:
    Grafo() {}
    ~Grafo() {}

    void carrega_grafo(char *tipo, string dataFileName);
    void novo_grafo(string descFileName, string outFileName);
    void exportInfo();
    void exportDesc();

    virtual void inicializa() = 0;
    virtual void imprime() = 0;

    virtual void insere_vertice(int id, int peso) = 0;
    // virtual void remove_vertice(int id) = 0; calma que vamos impelementar aindaa

    virtual void insere_aresta(int v, int w, int peso) = 0;
    // virtual void remove_aresta(int v, int w) = 0; esse tambem, talvez....

    virtual int pesoVertice(int id) = 0;
    virtual bool buscaVertice(int id) = 0;
    virtual int grauVertice(int id) = 0;      // retorna o grau de um vertice
    virtual int *vizinhosVertice(int id) = 0; // retorna um vetor com os ídices dos vertices vizinhos

    virtual int pesoAresta(int v, int w) = 0;
    virtual edge *getAresta(int v, int w) = 0; // alterar funcao
    virtual bool buscaAresta(int v, int w) = 0;
    // retono dos vizinho;
    // Metodos pra acesso externo;

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

protected:
    // Metodos pra acesso interno;
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
    string filename;
    string outFile;
    int info[4]{0, 0, 0, 0}; //[Grau, Ordem, Componentes_conexas, Tamanho]
    bool dpp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // direcionado             [0]
    // vertices ponderados     [1]
    // arestas ponderadas      [2]
    // completo                [3]
    // Bipartido               [4]
    // Arvore                  [5]
    // Aresta Ponte            [6]
    // Vertice de Articulação  [7]
};

#endif