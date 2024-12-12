#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"

Grafo::Grafo(std::string filename)
{
    this->filename = filename;
}

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::readInfo(char *tipo)
{
    std::cout << "Lendo a lista" << std::endl;
    std::ifstream file;
    std::string line;
    file.open(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return ;
    }

    file >> Ordem();
    file >> Direcionado();
    file >> Vertices_ponderados();
    file >> Arestas_ponderadas();
    getline(file, line);

    if (tipo == "-l")
    {
        this->grafo = new grafo_lista;
    }
    else if (tipo == "-m")
    {
        this->grafo = new grafo_matriz;
    }
    for (int i = 1; i <= Ordem(); i++)
    {
        int peso;
        if (Vertices_ponderados())
        {
            file >> peso;
        }
        grafo->insere_vertice(i, peso);
    }
    getline(file, line);
    while (!file.eof())
    {
        unsigned int v, w;
        int peso = 0;
        file >> v; // vertice orígem
        file >> w; // vertice destino
        if (Arestas_ponderadas())
        {
            file >> peso;
        }
        grafo->insere_aresta(v, w, peso);

        getline(file, line);
    }   

    file.close();

}

void Grafo::exportInfo()
{
    std::cout << "Exportando Info" << std::endl;
    std::ofstream file;
    file.open("Grafo.txt", std::ofstream::out);
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    file << Ordem() << " " << Direcionado() << " " << Vertices_ponderados() << " " << Arestas_ponderadas() << '\n';
    if(Vertices_ponderados())
    {
        for(int i = 1; i <= Ordem(); i++)
        {
            file << grafo->pesoVertice(i) << " ";
        }
        file << '\n';
    }


    for(int i = 1; i<=this->Tamanho(); i++)
    {
        edge *e = new edge(); 
        e =grafo->getAresta(i);
        file << e->V() << " " << e->W() << " ";
        if(Arestas_ponderadas())
        {
            file << e->Peso() << " ";
        }
        file << '\n';
    }

}

void Grafo::readDesc()
{
    std::cout << "Lendo Decrição" << std::endl;
    std::ifstream file;
    std::string line;
    file.open("Descricao.txt");
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file >> Grau();                   getline(file, line);
    file >> Ordem();                  getline(file, line);
    file >> Direcionado();            getline(file, line);
    file >> Componentes_conexas();    getline(file, line);
    file >> Vertices_ponderados();    getline(file, line);
    file >> Arestas_ponderadas();     getline(file, line);
    file >> Completo();               getline(file, line);
    file >> Bipartido();              getline(file, line);
    file >> Arvore();                 getline(file, line);
    file >> Aresta_Ponte();           getline(file, line);
    file >> Vertice_de_Articulacao(); getline(file, line);

    file.close();
}

void Grafo::exportDesc()
{
    std::cout << "Exportando descritor" << std::endl;
    std::ofstream file;
    file.open("grafo_out.txt", std::ofstream::out);
    if (!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file << filename << '\n'
         << '\n';

    file << "Grau: " << Grau() << '\n';
    file << "Ordem: " << Ordem() << '\n';
    if (Direcionado())
    {
        file << "Direcionado: Sim" << '\n';
    }
    else
    {
        file << "Direcionado: Não" << '\n';
    }

    file << "Componentes conexas: " << Componentes_conexas() << '\n';

    if (Vertices_ponderados())
    {
        file << "Vertices ponderados: Sim" << '\n';
    }
    else
    {
        file << "Vertices ponderados: Não" << '\n';
    }

    if (Arestas_ponderadas())
    {
        file << "Arestas ponderadas: Sim" << '\n';
    }
    else
    {
        file << "Arestas ponderadas: Não" << '\n';
    }

    if (Completo())
    {
        file << "Completo: Sim" << '\n';
    }
    else
    {
        file << "Completo: Não" << '\n';
    }

    if (Bipartido())
    {
        file << "Bipartido: Sim" << '\n';
    }
    else
    {
        file << "Bipartido: Não" << '\n';
    }

    if (Arvore())
    {
        file << "Arvore: Sim" << '\n';
    }
    else
    {
        file << "Arvore: Não" << '\n';
    }

    if (Aresta_Ponte())
    {
        file << "Aresta Ponte: Sim" << '\n';
    }
    else
    {
        file << "Aresta Ponte: Não" << '\n';
    }

    if (Vertice_de_Articulacao())
    {
        file << "Vertice de Articulação: Sim" << '\n';
    }
    else
    {
        file << "Vertice de Articulação: Não" << '\n';
    }

    file.close();
}
