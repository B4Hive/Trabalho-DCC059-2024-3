#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"

Grafo::Grafo(std::string filename)
{
    this->filename = filename;
}


Grafo::Grafo(){}

Grafo::~Grafo(){}

void Grafo::readInfo( char *tipo)
{
    std::cout << "Lendo a lista" << std::endl;
    std::ifstream file;
    std::string line;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file >> Ordem();
        file >> Direcionado();
        file >> Vertices_ponderados();
        file >> Arestas_ponderadas();
        getline(file, line);

    /*------------------------------------ Tipo Lista ------------------------------------*/

    if(tipo == "-l")
    {
        grafo_lista* gl = new grafo_lista;

        for(int i = 1; i <= Ordem(); i++)
        {
            vertice *v = new vertice;
            v->ID() = i;
            if(Vertices_ponderados())
            {
                file >> v->Peso();
            }
            gl->insere(v);
        }
        getline(file, line);
        while(!file.eof())
        {
            edge *e = new edge;
            file >> e->V(); // vertice orígem
            file >> e->W(); // vertice destino
            if(Arestas_ponderadas())
            {
                file >> e->Peso();
            }
            gl->getVertice(e->V())->insereAresta(e);
            //gl->getVertice(e->W())->insereAresta(e);

            getline(file, line);
        }
    }

    /*------------------------------------ Tipo Matriz ------------------------------------*/

    if(tipo == "-m")
    {  
        grafo_matriz gm;

        if(Vertices_ponderados())
        {
            for(int i = 0; i< Ordem(); i++)
            {
                file >> gm(i,i);
            }
        }
        getline(file, line);

        while(!file.eof())
        {
            unsigned int v, w;
            file >> v;
            file >> w;
            if(Arestas_ponderadas())
            {
                file >> gm(v,w);
            }
            else
            {
                gm(v,w) = 1;
            }
            getline(file, line);
        }



    }
    


    file.close();
}

void Grafo::exportDesc()
{
    std::cout << "Exportando descritor" << std::endl;
    std::ofstream file;
    file.open("grafo_out.txt", std::ofstream::out);
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file << filename << '\n' << '\n';
    
    file << "Grau: " << Grau() << '\n';
    file << "Ordem: " << Ordem() << '\n';
    if(Direcionado())
    {
        file << "Direcionado: Sim" << '\n';
    }
    else
    {
        file << "Direcionado: Não" << '\n';
    }

    file << "Componentes conexas: " << Componentes_conexas() << '\n';

    if(Vertices_ponderados())
    {
        file << "Vertices ponderados: Sim" << '\n';
    }
    else
    {
        file << "Vertices ponderados: Não" << '\n';
    }

    if(Arestas_ponderadas())
    {
        file << "Arestas ponderadas: Sim" << '\n';
    }
    else
    {
        file << "Arestas ponderadas: Não" << '\n';
    }

    if(Completo())
    {
        file << "Completo: Sim" << '\n';
    }
    else
    {
        file << "Completo: Não" << '\n';
    }

    if(Bipartido())
    {
        file << "Bipartido: Sim" << '\n';
    }
    else
    {
        file << "Bipartido: Não" << '\n';
    }

    if(Arvore())
    {
        file << "Arvore: Sim" << '\n';
    }
    else
    {
        file << "Arvore: Não" << '\n';
    }

    if(Aresta_Ponte())
    {
        file << "Aresta Ponte: Sim" << '\n';
    }
    else
    {
        file << "Aresta Ponte: Não" << '\n';
    }

    if(Vertice_de_Articulacao())
    {
        file << "Vertice de Articulação: Sim" << '\n';
    }
    else
    {
        file << "Vertice de Articulação: Não" << '\n';
    }

    file.close();
}

