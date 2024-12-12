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



class Grafo
{
    public:
    Grafo(std::string filename);
    Grafo();
    ~Grafo();

    void readInfo(char *tipo);
    //void readDesc(char *tipo);
    //void exportInfo();
    void exportDesc();

    virtual void insere_vertice(unsigned int id, int peso) = 0;
    //virtual void remove_vertice(unsigned int id) = 0; calma que vamos impelementar aindaa

    virtual void insere_aresta(unsigned int v, unsigned int w, int peso) = 0;
    //virtual void remove_aresta(unsigned int v, unsigned int w) = 0; esse tambem, talvez....


    virtual int  pesoAresta(unsigned int v, unsigned int w) = 0;
    virtual int  pesoVertice(unsigned int idVertice) = 0;
    virtual bool buscaVertice(unsigned int idVertice) = 0;
    virtual bool buscaAresta(unsigned int v, unsigned int w) = 0;


    unsigned int &Grau()                {return info[0];}
    unsigned int &Ordem()               {return info[1];}
    bool &Direcionado()                 {return dpp[0]; }
    unsigned int &Componentes_conexas() {return info[2];}
    bool &Vertices_ponderados()         {return dpp[1]; }
    bool &Arestas_ponderadas()          {return dpp[2]; }
    bool &Completo()                    {return dpp[3]; }
    bool &Bipartido()                   {return dpp[4]; }
    bool &Arvore()                      {return dpp[5]; }
    bool &Aresta_Ponte()                {return dpp[6]; }
    bool &Vertice_de_Articulacao()      {return dpp[7]; }

    //B4Hive
    virtual void auxArestaPonte(bool *result) = 0;
    virtual void auxVerticeArticulacao(bool *result) = 0;

    private:

    Grafo *grafo; // grafo_lista ou grafo_matriz

    std::string filename;

    //unsigned int n_vertices;
    unsigned int info[3]{1,2,3}; //[Grau, Ordem, Componentes_conexas]
    bool dpp[8] = {0,1,0,1,0,1,0,1};
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