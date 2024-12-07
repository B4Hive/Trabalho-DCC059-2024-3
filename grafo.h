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

    


    int pesoAresta_lista(unsigned int v, unsigned int w);
    int pesoAresta_lista(unsigned int idAresta);

    int pesoAresta_matriz(unsigned int v, unsigned int w);
    int pesoAresta_matriz(unsigned int idAresta);

    unsigned int pesoVertice_lista(unsigned int idVertice);
    unsigned int pesoVertice_matriz(unsigned int idVertice);


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

    private:

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