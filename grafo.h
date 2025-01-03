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
    ~Grafo(){}

    void carrega_grafo(char *tipo, string dataFileName);
    void novo_grafo(char *tipo, string descFileName);
    void exportInfo();
    void exportDesc();

    virtual void inicializa() = 0;
    virtual void imprime() = 0;

    virtual void insere_vertice(int id, int peso) = 0;
    //virtual void remove_vertice(int id) = 0; calma que vamos impelementar aindaa

    virtual void insere_aresta(int v, int w, int peso) = 0;
    //virtual void remove_aresta(int v, int w) = 0; esse tambem, talvez....

    virtual int  pesoAresta(int v, int w) = 0;
    virtual int  pesoVertice(int idVertice) = 0;
    virtual edge *getAresta(int idAresta) = 0; 
    virtual bool buscaVertice(int idVertice) = 0;
    virtual bool buscaAresta(int v, int w) = 0;

    //Metodos pra acesso externo;

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

    protected:

    //Metodos pra acesso interno;
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

    int &Tamanho()             {return info[3];} // Quantidade de arestas que o grafo tem

    //B4Hive
    virtual bool auxArestaPonte() = 0;
    virtual bool auxVerticeArticulacao() = 0;
    virtual int auxSetGrau() = 0;
    
    //Variaveis internas
    string filename;
    int info[4]{0,0,0,0}; //[Grau, Ordem, Componentes_conexas, Tamanho]
    bool dpp[8] = {0,0,0,0,0,0,0,0};
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