#include "grafo.h"


Grafo::Grafo(std::string filename)
{
    this->filename = filename;
}


Grafo::Grafo(){}

Grafo::~Grafo(){}

void Grafo::readInfo( char *tipo)
{
    std::ifstream file;
    std::string line;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    if(tipo == "-l")
    {
        file >> n_vertices;
        file >> dpp[0];
        file >> dpp[1];
        file >> dpp[2];
        getline(file, line);

        grafo_lista* gl = new grafo_lista();

        for(int i = 1; i <= n_vertices; i++)
        {
            vertice *v = new vertice;
            v->ID() = i;
            file >> v->Peso();
            gl->insere(v);
        }
        getline(file, line);
        while(!file.eof())
        {
            edge *e = new edge;
            file >> e->V();
            file >> e->W();
            file >> e->Peso();

            gl->getVertice(e->V())->insereAresta(e);
            gl->getVertice(e->W())->insereAresta(e);

            getline(file, line);
        }
    }
    


    file.close();
}