#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"

using namespace std;

Grafo::Grafo(string filename)
{
    this->filename = filename;
}


Grafo::Grafo(){}

Grafo::~Grafo(){}

void Grafo::readInfo( char *tipo)
{
    cout << "Lendo a lista" << endl;
    ifstream file;
    string line;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
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
    cout << "Exportando descritor" << endl;
    ofstream file;
    file.open("grafo_out.txt", ofstream::out);
    if(!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }

    writeGraphProperties(file);

    file.close();
}

void Grafo::writeGraphProperties(ofstream &file) {
    file << filename << '\n' << '\n';
    file << "Grau: " << Grau() << '\n';
    file << "Ordem: " << Ordem() << '\n';
    file << "Direcionado: " << (Direcionado() ? "Sim" : "Não") << '\n';
    file << "Componentes conexas: " << Componentes_conexas() << '\n';
    file << "Vertices ponderados: " << (Vertices_ponderados() ? "Sim" : "Não") << '\n';
    file << "Arestas ponderadas: " << (Arestas_ponderadas() ? "Sim" : "Não") << '\n';
    file << "Completo: " << (Completo() ? "Sim" : "Não") << '\n';
    file << "Bipartido: " << (Bipartido() ? "Sim" : "Não") << '\n';
    file << "Arvore: " << (Arvore() ? "Sim" : "Não") << '\n';
    file << "Aresta Ponte: " << (Aresta_Ponte() ? "Sim" : "Não") << '\n';
    file << "Vertice de Articulação: " << (Vertice_de_Articulacao() ? "Sim" : "Não") << '\n';
}

/*----------B4Hive----------*/
bool &Grafo::Aresta_Ponte(){
    //for(aresta e : grafo){
    //    create subgraph - e;
    //    if(subgraph is not connected)
    //        return true;
    //}
    //return false;
}
bool &Grafo::Vertice_de_Articulacao(){
    //for(vertice v : grafo){
    //    create subgraph - v;
    //    if(subgraph is not connected)
    //        return true;
    //}
    //return false;
}
//complexidade tá O(n^3), depois eu pego um método mais rápido
/*----------B4Hive----------*/