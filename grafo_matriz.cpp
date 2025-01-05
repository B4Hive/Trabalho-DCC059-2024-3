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

int &grafo_matriz::operator()(int v, int w)
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

void grafo_matriz::insere_vertice(int id, int peso)
{
    this->operator()(id-1, id-1) = peso;
}

void grafo_matriz::insere_aresta(int v, int w, int peso)
{
    this->operator()(v-1,w-1) = peso;
}

int grafo_matriz::pesoAresta(int v, int w)
{
    return this->operator()(v-1,w-1);
}

int grafo_matriz::pesoVertice(int id)
{
    return this->operator()(id-1, id-1);
}

bool grafo_matriz::buscaVertice(int id)
{
    if(this->operator()(id-1, id-1) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool grafo_matriz::buscaAresta(int v, int w)
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

edge *grafo_matriz::getAresta(int idAresta)
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

int * grafo_matriz::vizinhosVertice(int id)
{
    vertice *v_inicio = new vertice();
    vertice *p = new vertice();
    vertice *aux = new vertice();
    unsigned int grau = 0;
    v_inicio->ID() = id;
    v_inicio->setProx(p);
    for(int i = 0; i < getOrdem(); i++)
    {
        if(this->operator()(id-1, i) != 0)
        {
            p->ID() = i+1;
            p = p->getProx();
            grau++;
        }
    }

    int* vizinhos = new int[grau];
    p = v_inicio->getProx();
    for(int i = 0; p != NULL; i++)
    {
        vizinhos[i] = p->ID();
        aux = p;
        p = p->getProx();
        delete aux;
    }

    delete v_inicio;
    return vizinhos;

}

int grafo_matriz::grauVertice(int id)
{
    int grau = 0;
    for(int i = 0; i < getOrdem(); i++)
    {
        if(this->operator()(id-1, i) != 0)
        {
            grau++;
        }
    }
    return grau;
}
// B4Hive-begin

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
    cout << endl << "Imprimindo matriz" << endl;
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
