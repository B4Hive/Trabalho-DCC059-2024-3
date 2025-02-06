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
    if (getDirecionado() == 0) // matriz  triangular infeiror
    {
        tamanho_vetor = (getOrdem() * (getOrdem() + 1)) / 2;
        cout << "Tamanho: " << tamanho_vetor << endl;
        m = new int[tamanho_vetor];
        for (int i = 0; i < tamanho_vetor; i++)
        {
            m[i] = 0;
        }
    }

    if (getDirecionado() == 1)
    {
        tamanho_vetor = getOrdem() * getOrdem();
        m = new int[tamanho_vetor];
        cout << "Tamanho: " << tamanho_vetor << endl;
        for (int i = 0; i < tamanho_vetor; i++)
        {
            m[i] = 0;
        }
    }
}

int &grafo_matriz::operator()(int v, int w)
{
    int i = v;
    int j = w;
    if (!getDirecionado())
    {
        if (i >= j)
        {
            return m[i * (i + 1) / 2 + j];
        }
        else
        {
            return m[j * (j + 1) / 2 + i];
        }
    }
    else
    {
        return m[i * getOrdem() + j];
    }
    return m[0];
}

void grafo_matriz::insere_vertice(int id, int peso)
{
    this->operator()(id - 1, id - 1) = peso;
}

void grafo_matriz::insere_aresta(int v, int w, int peso)
{
    if(this->operator()(v-1,w-1) == 0)
    {
        this->operator()(v-1,w-1) = peso;
    }
    
}
void grafo_matriz::remove_aresta(int v, int w)
{
    if (v != w)
    {
        this->operator()(v - 1, w - 1) = 0;
    }
}

int grafo_matriz::pesoAresta(int v, int w)
{
    return this->operator()(v - 1, w - 1);
}

int grafo_matriz::pesoVertice(int id)
{
    return this->operator()(id - 1, id - 1);
}

bool grafo_matriz::buscaVertice(int id)
{
    if (this->operator()(id - 1, id - 1) != 0)
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
    if (this->operator()(v - 1, w - 1) != 0 && v != w)
    {
        return true;
    }
    else
    {
        return false;
    }
}

edge *grafo_matriz::getAresta(int v, int w)
{
    if (this->operator()(v - 1, w - 1) != 0 && v != w)
    {
        edge *e = new edge();
        e->V() = v;
        e->W() = w;
        e->Peso() = this->operator()(v - 1, w - 1);
        return e;
    }
    else
    {
        cout << "Aresta nao encontrada" << endl;
        return 0;
    }

    return 0;
}

int *grafo_matriz::vizinhosVertice(int id)
{
    int grau = grauVertice(id);
    int *vizinhos = new int[grau];
    int aux = 0;

    if (grau == 0)
    {
        // cout << "Vertice sem vizinhos" << endl;
        return 0;
    }
    for (int j = 0; j < getOrdem(); j++)
    {
        if (this->operator()(id - 1, j) != 0 && id - 1 != j)
        {
            vizinhos[aux] = j + 1;
            aux++;
        }
    }

    return vizinhos;
}

int grafo_matriz::grauVertice(int id)
{
    int grau = 0;
    for (int j = 1; j <= getOrdem(); j++)
    {
        if (this->operator()(id - 1, j - 1) != 0 && id != j)
        {
            grau++;
        }
    }
    return grau;
}

void grafo_matriz::imprime()
{
    if (!getDirecionado())
    {
        for (int i = 0; i < getOrdem(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i >= j)
                {
                    cout << m[i * (i + 1) / 2 + j] << " ";
                }
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < getOrdem(); i++)
        {
            for (int j = 0; j < getOrdem(); j++)
            {
                cout << m[i * getOrdem() + j] << " ";
            }
            cout << endl;
        }
    }
}
