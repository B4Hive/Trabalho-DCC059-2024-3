#include "grafo_matriz.h"

grafo_matriz::grafo_matriz()
{
    //m = NULL;
}

grafo_matriz::~grafo_matriz()
{
    delete m;
}

void grafo_matriz::inicializa_matriz()
{
    if(getDirecionado() == 0) // matriz  triangular infeiror 
    {
        unsigned int tamanho = (getOrdem() * (getOrdem() + 1)) / 2;
        std::cout << "Tamanho: " << tamanho << std::endl;
        m = new int [tamanho];
            for(int i = 0; i < tamanho; i++)
            {
                m[i] = 0;
            }
        std::cout << std::size_t(m) << std::endl;
    }
    
    if( getDirecionado() == 1)
    {
        unsigned int tamanho = getOrdem() * getOrdem();
        m = new int [tamanho];
        std::cout << "Tamanho: " << tamanho << std::endl;
            for(int i = 0; i < (this->getOrdem() * this->getOrdem()); i++)
            {
                m[i] = 0;
            }
    }
}

void grafo_matriz::carrega_grafo(char *tipo, std::string dataFileName)
{
    std::cout << "Lendo Grafo" << std::endl;
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

    file >>  ordem;
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
    std::cout << "Arestas ponderadas: " << getArestas_ponderadas() << std::endl;

    std::cout << "Iniciando matriz" << std::endl; 
    inicializa_matriz();
    std::cout << std::size_t(m) << std::endl;

    
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
        insere_aresta(v, w, peso);

        getline(file, line);
    }   

    file.close();

}



int &grafo_matriz::operator()(unsigned int v, unsigned int w)
{
    int i = v-1;
    int j = w-1;
    if(getDirecionado() == 0)
    {   if(i < j)
            return m[i * (i - 1) / 2 + j];
        else
            return m[j * (j - 1) / 2 + i];
    }
    else
    {
        return m[i * getOrdem() + j];
    }
}
void grafo_matriz::insere_vertice(unsigned int id, int peso)
{
    
    this->operator()(id, id) = peso;
    
    std::cout << "Vertice inserido" << std::endl;
}

void grafo_matriz::insere_aresta(unsigned int v, unsigned int w, int peso)
{

    this->operator()(v,w) = peso;
    this->Tamanho()++;
    
    std::cout << "Aresta inserida" << std::endl;
    std::cout << "valor: " << this->operator()(v,w) << std::endl;
}

int grafo_matriz::pesoAresta(unsigned int v, unsigned int w)
{
    
    return this->operator()(v,w);
    
}

int grafo_matriz::pesoVertice(unsigned int idVertice)
{
    
    return this->operator()(idVertice, idVertice);
}

bool grafo_matriz::buscaVertice(unsigned int idVertice)
{
    if(this->operator()(idVertice, idVertice) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool grafo_matriz::buscaAresta(unsigned int v, unsigned int w)
{
    if(this->operator()(v,w) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

edge *grafo_matriz::getAresta(unsigned int idAresta)
{
    int aux = 0;
    for(int i = 0; i<getOrdem(); i++)
    {
        for(int j = 0; j<getOrdem(); j++)
        {
            if(this->operator()(i,j) != 0)
            {
                aux++;
                if(aux == idAresta)
                {
                    edge *e = new edge(i,j);
                    e->Peso() = this->operator()(i,j);
                    return e;
                }
            }
        }
    }
    std::cout << "Aresta nao encontrada" << std::endl;
    return 0;
}

// B4Hive-begin
void grafo_matriz::auxArestaPonte(bool *result) {
    *result = false;
    int *visitado = new int[Ordem()];
    int *desc = new int[Ordem()];
    int *low = new int[Ordem()];
    int *pai = new int[Ordem()];
    int tempo = 0;
    for(int i = 0; i < Ordem(); i++) {
        visitado[i] = 0;
        desc[i] = 0;
        low[i] = 0;
        pai[i] = -1;
    }
    for(int i = 0; i < Ordem(); i++) {
        if(visitado[i] == 0) {
            BPPonte(i, visitado, desc, low, pai, &tempo, result);
        }
    }
    delete[] visitado;
    delete[] desc;
    delete[] low;
    delete[] pai;
}
// B4Hive-end