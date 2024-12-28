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
        tamanho_vetor = (getOrdem() * (getOrdem() + 1)) / 2;
        std::cout << "Tamanho: " << tamanho_vetor << std::endl;
        m = new int [tamanho_vetor];
            for(int i = 0; i < tamanho_vetor; i++)
            {
                m[i] = 0;
            }
    }
    
    if( getDirecionado() == 1)
    {
        tamanho_vetor = getOrdem() * getOrdem();
        m = new int [tamanho_vetor];
        std::cout << "Tamanho: " << tamanho_vetor << std::endl;
            for(int i = 0; i < tamanho_vetor; i++)
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
        Tamanho()++;
        std::cout << "Inserindo Aresta "<< Tamanho() <<": "<<std::endl;
        std::cout << "V: " << v << " W: " << w << " Peso: " << peso << std::endl<< std::endl;
        insere_aresta(v, w, peso);

        getline(file, line);
    }   

    file.close();

}



int &grafo_matriz::operator()(unsigned int v, unsigned int w)
{
    int i = v;
    int j = w;
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
    
    this->operator()(id-1, id-1) = peso;
    
    //std::cout << "Vertice inserido" << std::endl;
}

void grafo_matriz::insere_aresta(unsigned int v, unsigned int w, int peso)
{

    this->operator()(v-1,w-1) = peso;
    
    std::cout << "Aresta inserida" << std::endl;
}

int grafo_matriz::pesoAresta(unsigned int v, unsigned int w)
{
    
    return this->operator()(v-1,w-1);
    
}

int grafo_matriz::pesoVertice(unsigned int idVertice)
{
    
    return this->operator()(idVertice-1, idVertice-1);
}

bool grafo_matriz::buscaVertice(unsigned int idVertice)
{
    if(this->operator()(idVertice-1, idVertice-1) != 0)
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
    if(this->operator()(v-1,w-1) != 0)
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
    edge *e = new edge();
    for(int i = 0; i<getOrdem(); i++)
    {
        for(int j = 0; j<getOrdem(); j++)
        {  
            if(this->operator()(i,j) != 0 && i != j)
            {
                aux++;
                if(aux == idAresta)
                {
                    e->V() = i+1;
                    e->W() = j+1;
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
    int tag[getOrdem()];
    for (int &t : tag) {
        t = -1;
    }
    bool visitado[getOrdem()];
    for (bool &vis : visitado) {
        vis = false;
    }
    int v = 0;
    int count = 0;
    int tagCount = 0;
    while (v < getOrdem()){
        if (!visitado[v]){
            count++;
            tagCount++;
            BPPonte(v, tag, visitado, tagCount, -1, -1);
        }    
        v++;
    }

    for(int i = 0; i < getOrdem(); i++){
        for(int j = 0; j < getOrdem(); j++){
            for (int &t : tag) {
                t = -1;
            }
            for (bool &vis : visitado) {
                vis = false;
            }
            int counter = 0;
            int tagCounter = 0;
            v = 0;
            while (v < getOrdem()){
                if (!visitado[v]){
                    counter++;
                    tagCounter++;
                    BPPonte(v, tag, visitado, tagCounter, i, j);
                }
                v++;
            }
            if (counter > count) {
                *result = true;
                return;
            }
        }
    }
}

void grafo_matriz::BPPonte(int v, int tag[], bool visitado[], int currentTag, int ignoredV, int ignoredW) {
    visitado[v] = true;
    tag[v] = currentTag;
    int e = 0;
    while (e < getOrdem()){
        if (this->operator()(v, e) != 0){
            if ((v != ignoredV && e != ignoredW) || (!getDirecionado() && v != ignoredW && e != ignoredV)){
                if (!visitado[e] && e != ignoredV){
                    BPPonte(e, tag, visitado, currentTag, ignoredV, ignoredW);
                }
            }
        }
        e++;
    }
}

void grafo_matriz::auxVerticeArticulacao(bool *result) {
    *result = false;
    int tag[getOrdem()];
    for (int &t : tag) {
        t = -1;
    }
    bool visitado[getOrdem()];
    for (bool &vis : visitado) {
        vis = false;
    }
    int v = 0;
    int count = 0;
    int tagCount = 0;
    while (v < getOrdem()){
        if (!visitado[v]){
            count++;
            tagCount++;
            BPArticulacao(v, tag, visitado, tagCount, -1);
        }    
        v++;
    }
    
    for (int w = 0; w < getOrdem(); w++) {
        for (int &t : tag) {
            t = -1;
        }
        for (bool &vis : visitado) {
            vis = false;
        }
        int counter = 0;
        int tagCounter = 0;
        v = 0;
        while (v < getOrdem()){
            if (!visitado[v]){
                counter++;
                tagCounter++;
                BPArticulacao(v, tag, visitado, tagCounter, w);
            }
            v++;
        }
        if (counter > count) {
            *result = true;
            return;
        }
    }
}

void grafo_matriz::BPArticulacao(int v, int tag[], bool visitado[], int currentTag, int ignoredV) {
    if (visitado[v] || v == ignoredV){
        return;
    }
    visitado[v] = true;
    tag[v] = currentTag;
    int e = 0;
    while (e < getOrdem()){
        if (this->operator()(v, e) != 0){
            if (!visitado[e] && e != ignoredV){
                BPArticulacao(e, tag, visitado, currentTag, ignoredV);
            }
        }
        e++;
    }
}
// B4Hive-end

void grafo_matriz::imprime_matriz()
{
    std::cout << "Imprimindo matriz" << std::endl;
    if(getDirecionado() == 0)
    {
        for(int i = 0; i < getOrdem(); i++)
        {
            for(int j = 0; j < getOrdem(); j++)
            {
                if(i < j)
                {
                    std::cout << m[i * (i - 1) / 2 + j] << " ";
                }
                else
                {
                    std::cout << m[j * (j - 1) / 2 + i] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for(int i = 0; i < getOrdem(); i++)
        {
            for(int j = 0; j < getOrdem(); j++)
            {
                std::cout << m[i * getOrdem() + j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
