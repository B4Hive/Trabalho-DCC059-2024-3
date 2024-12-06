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
#include "grafo_lista.h"
#include "grafo_matriz.h"


class Grafo
{
    public:
    Grafo(std::string filename);
    Grafo();
    ~Grafo();

    void readInfo(char *tipo);
    void readDesc(char *tipo);
    void exportInfo();
    void exportDesc();

    private:

    std::string filename;

    unsigned int n_vertices;
    bool dpp[3]; //[direcionado, vertices ponderados, arestas ponderadas]
    
};

#endif