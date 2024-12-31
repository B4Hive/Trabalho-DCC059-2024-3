#include "grafo_matriz.h"
using namespace std;

grafo_matriz::grafo_matriz()
{
    //m = NULL;
}

grafo_matriz::~grafo_matriz()
{
    delete m;
}

void grafo_matriz::inicializa()
{
    if(getDirecionado() == 0) // matriz  triangular infeiror 
    {
        tamanho_vetor = (getOrdem() * (getOrdem() + 1)) / 2;
        cout << "Tamanho: " << tamanho_vetor << endl;
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
        cout << "Tamanho: " << tamanho_vetor << endl;
            for(int i = 0; i < tamanho_vetor; i++)
            {
                m[i] = 0;
            }
    }
}

int &grafo_matriz::operator()(unsigned int v, unsigned int w)
{
    int i = v;
    int j = w;
    if(!getDirecionado())
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
    
    //cout << "Vertice inserido" << endl;
}

void grafo_matriz::insere_aresta(unsigned int v, unsigned int w, int peso)
{

    this->operator()(v-1,w-1) = peso;
    
    cout << "Aresta inserida" << endl;
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
    cout << "Aresta nao encontrada" << endl;
    return 0;
}

// B4Hive-begin
bool grafo_matriz::auxArestaPonte() {
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
                return true;
            }
        }
    }
    return false;
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

bool grafo_matriz::auxVerticeArticulacao() {
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
            return true;
        }
    }
    return false;
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

int grafo_matriz::auxSetGrau(){
    int grau = 0;
    int v = 1;
    while (v <= getOrdem()){
        int g = 0;
        int e = 1;
        while (e <= getOrdem()){
            if(this->operator()(v, e) != 0 && v != e){
                g++;
            }
            e++;
        }
        if (g > grau){
            grau = g;
        }
        v++;
    }
    return grau;
}
// B4Hive-end

void grafo_matriz::imprime()
{
    cout << "Imprimindo matriz" << endl;
    if(!getDirecionado())
    {
        for(int i = 0; i < getOrdem(); i++)
        {
            for(int j = 0; j < getOrdem(); j++)
            {
                if(i < j)
                {
                    cout << m[i * (i - 1) / 2 + j] << " ";
                }
                else
                {
                    cout << m[j * (j - 1) / 2 + i] << " ";
                }
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < getOrdem(); i++)
        {
            for(int j = 0; j < getOrdem(); j++)
            {
                cout << m[i * getOrdem() + j] << " ";
            }
            cout << endl;
        }
    }
}
