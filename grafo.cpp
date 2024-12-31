#include "grafo.h"

#include "grafo_lista.h"
#include "grafo_matriz.h"

void Grafo::setGrau(unsigned int grau)
{
    if(grau < 0)
    {
        std::cout << "Grau invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        info[0] = grau;
    }
}

void Grafo::setOrdem(unsigned int ordem)
{
    if(ordem < 0)
    {
        std::cout << "Ordem invalida!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        info[1] = ordem;
    }
}

void Grafo::setDirecionado(bool direcionado)
{
    if(direcionado != 0 && direcionado != 1)
    {
        std::cout << "Direcionado invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[0] = direcionado;
    }
}

void Grafo::setComponentes_conexas(unsigned int componentes_conexas)
{
    if(componentes_conexas < 0)
    {
        std::cout << "Componentes conexas invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        info[2] = componentes_conexas;
    }
}

void Grafo::setVertices_ponderados(bool vertices_ponderados)
{
    if(vertices_ponderados != 0 && vertices_ponderados != 1)
    {
        std::cout << "Vertices ponderados invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[1] = vertices_ponderados;
    }
}

void Grafo::setArestas_ponderadas(bool arestas_ponderadas)
{
    if(arestas_ponderadas != 0 && arestas_ponderadas != 1)
    {
        std::cout << "Arestas ponderadas invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[2] = arestas_ponderadas;
    }
}

void Grafo::setCompleto(bool completo)
{
    if(completo != 0 && completo != 1)
    {
        std::cout << "Completo invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[3] = completo;
    }
}

void Grafo::setBipartido(bool bipartido)
{
    if(bipartido != 0 && bipartido != 1)
    {
        std::cout << "Bipartido invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[4] = bipartido;
    }
}

void Grafo::setArvore(bool arvore)
{
    if(arvore != 0 && arvore != 1)
    {
        std::cout << "Arvore invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[5] = arvore;
    }
}

void Grafo::setAresta_Ponte(bool aresta_ponte)
{
    if(aresta_ponte != 0 && aresta_ponte != 1)
    {
        std::cout << "Aresta ponte invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[6] = aresta_ponte;
    }
}

void Grafo::setVertice_de_Articulacao(bool vertice_de_articulacao)
{
    if(vertice_de_articulacao != 0 && vertice_de_articulacao != 1)
    {
        std::cout << "Vertice de articulacao invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        dpp[7] = vertice_de_articulacao;
    }
}

void Grafo::setTamanho(unsigned int tamanho)
{
    if(tamanho < 0)
    {
        std::cout << "Tamanho invalido!" << std::endl;
        std::cout << "Encerrando programa..." << std::endl;
        exit(1);
    }
    else
    {
        info[3] = tamanho;
    }
}

unsigned int Grafo::getGrau()
{
    return info[0];
}

unsigned int Grafo::getOrdem()
{
    return info[1];
}

bool Grafo::getDirecionado()
{
    return dpp[0];
}

unsigned int Grafo::getComponentes_conexas()
{
    return info[2];
}

bool Grafo::getVertices_ponderados()
{
    return dpp[1];
}

bool Grafo::getArestas_ponderadas()
{
    return dpp[2];
}

bool Grafo::getCompleto()
{
    return dpp[3];
}

bool Grafo::getBipartido()
{
    return dpp[4];
}

bool Grafo::getArvore()
{
    return dpp[5];
}

bool Grafo::getAresta_Ponte()
{
    return auxArestaPonte();
}

bool Grafo::getVertice_de_Articulacao()
{
    return auxVerticeArticulacao();
}

unsigned int Grafo::getTamanho()
{
    return info[3];
}

void Grafo::carrega_grafo(char *tipo, std::string dataFileName)
{
    std::cout << "Carregando Grafo..." << std::endl;
    std::ifstream file;
    std::string line;
    this->filename = dataFileName;
    file.open(filename, std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return ;
    }

    unsigned int ordem;
    bool direcionado;
    bool vertices_ponderados;
    bool arestas_ponderadas;

    file >> ordem;
    file >> direcionado;
    file >> vertices_ponderados;
    file >> arestas_ponderadas;

    setOrdem(ordem);
    setDirecionado(direcionado);
    setVertices_ponderados(vertices_ponderados);
    setArestas_ponderadas(arestas_ponderadas);

    getline(file, line);

    std::cout << "Ordem: " << getOrdem() << std::endl;
    std::cout << "Direcionado: " << getDirecionado() << std::endl;
    std::cout << "Vertices ponderados: " << getVertices_ponderados() << std::endl;
    std::cout << "Arestas ponderadas: " << getArestas_ponderadas() << std::endl<< std::endl;

    inicializa();

    for (int i = 1; i <= getOrdem(); i++)
    {
        int peso;
        if (getVertices_ponderados())
        {
            file >> peso;
        }
        insere_vertice(i, peso);
    }
    getline(file, line);
    while (!file.eof())
    {
        unsigned int v, w;
        int peso = 0;
        file >> v; // vertice orígem
        file >> w; // vertice destino
        if (getArestas_ponderadas())
        {
            file >> peso;
        }
        Tamanho()++;
        std::cout << "Inserindo Aresta "<< Tamanho() <<": "<<std::endl;
        std::cout << "V: " << v << " W: " << w << " Peso: " << peso << std::endl;
        insere_aresta(v, w, peso);

        getline(file, line);
    }

    setGrau(auxSetGrau());

    file.close();

    std::cout << "Grafo carregado!" << std::endl<<std::endl;
}

void Grafo::exportInfo()
{
    std::cout << "Exportando Info" << std::endl;
    std::ofstream file;
    file.open("Grafo_infoOut.txt", std::ofstream::out);
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    file << getOrdem() << " " << getDirecionado() << " " << getVertices_ponderados() << " " << getArestas_ponderadas() << '\n';
    if(getVertices_ponderados())
    {
        for(int i = 1; i <= getOrdem(); i++)
        {
            file << pesoVertice(i) << " ";
        }
        file << '\n';
    }


    for(int i = 1; i<=getTamanho(); i++)
    {
        edge *e = new edge(); 
        e =getAresta(i);
        file << e->V() << " " << e->W() << " ";
        if(getArestas_ponderadas())
        {
            file << e->Peso() << " ";
        }
        file << '\n';
    }

}

void Grafo::novo_grafo(char *tipo, std::string descFileName)
{
    std::cout << "Lendo Decrição" << std::endl;
    std::ifstream file;
    std::string line;
    this->filename = descFileName;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    unsigned int grau;
    unsigned int ordem;
    bool direcionado;
    unsigned int componentes_conexas;
    bool vertices_ponderados;
    bool arestas_ponderadas;
    bool completo;
    bool bipartido;
    bool arvore;
    bool aresta_ponte;
    bool vertice_de_articulacao;

    file >> grau;                   getline(file, line);
    file >> ordem;                  getline(file, line);
    file >> direcionado;            getline(file, line);
    file >> componentes_conexas;    getline(file, line);
    file >> vertices_ponderados;    getline(file, line);
    file >> arestas_ponderadas;     getline(file, line);
    file >> completo;               getline(file, line);
    file >> bipartido;              getline(file, line);
    file >> arvore;                 getline(file, line);
    file >> aresta_ponte;           getline(file, line);
    file >> vertice_de_articulacao; getline(file, line);

    // from here
    Grafo *g;
    
    g->setGrau(grau);
    g->setOrdem(ordem);
    g->setDirecionado(direcionado);
    g->setComponentes_conexas(componentes_conexas);
    g->setVertices_ponderados(vertices_ponderados);
    g->setArestas_ponderadas(arestas_ponderadas);
    g->setCompleto(completo);
    g->setBipartido(bipartido);
    g->setArvore(arvore);
    g->setAresta_Ponte(aresta_ponte);
    g->setVertice_de_Articulacao(vertice_de_articulacao);

    if (*tipo == 'l') {
        g = new grafo_lista;
        for(int i = 1; i <= ordem; i++) {
            int peso = 1;
            if (vertices_ponderados)
                peso = rand() % 100;
            g->insere_vertice(i, peso);
        }
    } else if (*tipo == 'm') {
        /*
        grafo_matriz *gm = new grafo_matriz;
        gm->inicializa_matriz();
        g = gm;
        for (int i = 1; i <= ordem; i++) {
            int peso = 1;
            if (vertices_ponderados)
                peso = rand() % 100;
            gm->insere_vertice(i, peso);
        }
        */
    }
    // agora gambiarra com 300 ifs
    if(completo) {
        for(int i = 1; i <= ordem; i++){
            for(int j = 1; j <= ordem; j++){
                if(i != j){
                    int peso = 1;
                    if(arestas_ponderadas)
                        peso = rand() % 100;
                    g->insere_aresta(i, j, peso);
                }
            }
        }
    } else if (bipartido) {
        // cria 2 conjuntos de vertices ordem/2
        // insere arestas entre os conjuntos
    } else if (arvore) {
        // cria uma arvore
    } else if (aresta_ponte) {
        // cria 2 grafos conexos ordem/2
        // insere uma aresta ponte
    } else if (vertice_de_articulacao) {
        // cria 2 grafos conexos (ordem-1)/2
        // insere um vertice de articulacao
    }
    // until here

    file.close();
}
// @bhive tem que tirar esse texto extras do exportDesc
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

    file << "Grau: " << getGrau() << '\n';
    file << "Ordem: " << getOrdem() << '\n';
    if (getDirecionado())
    {
        file << "Direcionado: Sim" << '\n';
    }
    else
    {
        file << "Direcionado: Não" << '\n';
    }

    file << "Componentes conexas: " << getComponentes_conexas() << '\n';

    if (getVertices_ponderados())
    {
        file << "Vertices ponderados: Sim" << '\n';
    }
    else
    {
        file << "Vertices ponderados: Não" << '\n';
    }

    if (getArestas_ponderadas())
    {
        file << "Arestas ponderadas: Sim" << '\n';
    }
    else
    {
        file << "Arestas ponderadas: Não" << '\n';
    }

    if (getCompleto())
    {
        file << "Completo: Sim" << '\n';
    }
    else
    {
        file << "Completo: Não" << '\n';
    }

    if (getBipartido())
    {
        file << "Bipartido: Sim" << '\n';
    }
    else
    {
        file << "Bipartido: Não" << '\n';
    }

    if (getArvore())
    {
        file << "Arvore: Sim" << '\n';
    }
    else
    {
        file << "Arvore: Não" << '\n';
    }

    if (getAresta_Ponte())
    {
        file << "Aresta Ponte: Sim" << '\n';
    }
    else
    {
        file << "Aresta Ponte: Não" << '\n';
    }

    if (getVertice_de_Articulacao())
    {
        file << "Vertice de Articulação: Sim" << '\n';
    }
    else
    {
        file << "Vertice de Articulação: Não" << '\n';
    }

    file.close();
}
