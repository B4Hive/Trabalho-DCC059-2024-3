#include "grafo_matriz.h"
using namespace std;

grafo_matriz::grafo_matriz()
{
    m = NULL;
    ordem_matriz = 0;
    exp_ordem = 0;
}

grafo_matriz::~grafo_matriz()
{
    delete[] m;
}

void grafo_matriz::inicializa()
{
    for(int i = 0; ordem_matriz <= getOrdem(); i++)
    {
        exp_ordem = i;
        ordem_matriz = 10 * (pow(2,exp_ordem));
    }
    cout << "Ordem da matriz: " << ordem_matriz << endl;
    cout << "Ordem do grafo: " << getOrdem() << endl;
    int tamanho_vetor = 0;
    if (!getDirecionado()) // matriz  triangular infeiror
    {
        tamanho_vetor = (ordem_matriz * (ordem_matriz + 1)) / 2;
    }
    
    if (getDirecionado())
    {
        tamanho_vetor = ordem_matriz * ordem_matriz;    
    }

    //cout << "Tamanho do vetor: " << tamanho_vetor << endl;
    m = new float[tamanho_vetor];
    for (int i = 0; i < tamanho_vetor; i++)
    {
        m[i] = 0;
    }

}

void grafo_matriz::realoca()
{
    cout << "Realocando" << endl;
    if(Debug())cout << "DEBUG Realoca" << endl;
    // Armazenamento das arestas e do pesos dos vertices;
    int cont = 0;
    int qtd_arestas;;
    if(!getDirecionado())    
        qtd_arestas = Tamanho()*2;
    else
        qtd_arestas = Tamanho();

    edge *arestas = new edge[qtd_arestas];
    int peso_vertices[getOrdem()];
    if(Debug())cout << "Tamnho: " << Tamanho() << endl;
    for(int i = 0; i < ordem_matriz; i++)
    {
        peso_vertices[i] = pesoVertice(i+1);

        int grau = grauVertice(i+1);
        if(Debug())cout << "Grau do vertice " << i+1 << ": " << grau << endl;
        if(grau > 0)
        {
            int *vizinhos = vizinhosVertice(i+1);
            for(int j = 0; j < grau; j++)
            {
                arestas[cont].V() = i+1;
                arestas[cont].W() = vizinhos[j];
                arestas[cont].Peso() = pesoAresta(i+1, vizinhos[j]);
                cont++;
            }
            delete[] vizinhos;
        }
    }
    if(Debug())
    {
        for(int i = 0; i < Tamanho(); i++)
        {
            cout << arestas[i].V() << " " << arestas[i].W() << " " << arestas[i].Peso() << endl;
        }
    }

    // Realocando a matriz
    delete[] m;
    exp_ordem++;
    ordem_matriz = 10 * (pow(2,exp_ordem));
    int tamanho_vetor = 0;
    
    if(!getDirecionado())
    {
        tamanho_vetor = (( ordem_matriz * (ordem_matriz + 1) ) / 2);
    }
    else
    {
        tamanho_vetor = ordem_matriz * ordem_matriz;
    }
    
    cout << "Tamanho do vetor: " << tamanho_vetor << endl;
    cout << "Ordem da matriz: " << ordem_matriz << endl;
    this->m = NULL;
    //if (Debug())
        //cout << "DEBUG " << endl;
    this->m = new float[tamanho_vetor];

    for(int i = 0; i < tamanho_vetor; i++)
    {
        m[i] = 0;
    }
    //this->m = m_aux;

    // Inserindo os vertices e arestas

    for(int i = 0; i < getOrdem(); i++)
    {
        insere_vertice(i+1, peso_vertices[i]);
    }

    for(int i = 0; i < Tamanho(); i++)
    {
        insere_aresta(arestas[i].V(), arestas[i].W(), arestas[i].Peso());
    }
    
    if(Debug())cout << " END DEBUG Realoca" << endl;

    delete[] arestas;

}

/**
 * @brief Retorna o valor contido na matriz
 *
 * @details Esta função realiza uma breve verificação para confirmar se o grafo é direcionado.
 * Em seguida faz algumas verificações nos if e else e retorna o valor da matriz.
 * @param v, w
 * @return retorna uma referência ao valor armazenado na matriz m para o par de vértices.
 */
float &grafo_matriz::operator()(int v, int w)
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
        return m[i * ordem_matriz + j];
    }
    return m[0];
}

void grafo_matriz::insere_vertice(int id, int peso)
{
    this->operator()(id - 1, id - 1) = peso;
}

void grafo_matriz::novo_no(int peso)
{
    int ordem_grafo = getOrdem();
    ordem_grafo ++;
    if(ordem_grafo > ordem_matriz)
    {
        cout << "Matriz Cheia!" << endl;
        realoca();
    }
    insere_vertice(ordem_grafo, peso);
    setOrdem(ordem_grafo);
}

void grafo_matriz::deleta_no(int id)
{
    if(getDirecionado())
    {
        for(int i = id; i < getOrdem(); i++)
        {
            for(int j = 0; j < getOrdem(); j++)
            {
                this->operator()(i-1,j) = this->operator()(i,j);
            }
        }
        
        for(int j = id; j < getOrdem(); j++)
        {
            for(int i = 0; i < getOrdem(); i++)
            {
                this->operator()(i,j-1) = this->operator()(i,j);
            }
        }
    }
    else
    {
        // deslocando para a esquerda
        for(int i = id+1; i<=getOrdem(); i++)
        {
            for(int j = id; j < i; j++)
            {
                this->operator()(i-1,j-1) = this->operator()(i-1,j);
            }
        }

        // deslocando para cima

        for(int i = id; i< getOrdem(); i++)
        {
            for(int j = 1; j<=i; j++)
            {
                this->operator()(i-1,j-1) = this->operator()(i,j-1);
            }
        }
    }
    
    setOrdem(getOrdem() - 1);
}

/**
 * @brief Insere uma aresta entre dois Nós passados por parâmetro e seu respectivo peso.
 * @details
 * Insere uma aresta entre os vértices `v` e `w` na matriz de adjacência do grafo. Se a posição correspondente na matriz de adjacência
 * já estiver ocupada (valor diferente de 0), a função não faz nenhuma alteração. Caso contrário, o peso da aresta é atribuído à posição
 * correspondente na matriz. A matriz de adjacência é baseada em índices 0-base, então os índices `v` e `w` são ajustados para refletir
 * isso.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @param peso Peso da aresta
 */
void grafo_matriz::insere_aresta(int v, int w, float peso)
{
    if(this->operator()(v-1,w-1) == 0)
    {
        this->operator()(v-1,w-1) = peso;
    }
}

/**
 * @brief Insere uma nova aresta.
 * @details
 *A função nova_aresta(int v, int w, int peso) tem como objetivo adicionar uma aresta entre os vértices v e w de um grafo
 *representado por uma matriz de adjacência. Essa função também associa um peso a aresta.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @param peso Peso da aresta
 */
void grafo_matriz::nova_aresta(int v, int w, float peso)
{
    if(v != w)
    {
        this->operator()(v-1,w-1) = peso;
    }
}

void grafo_matriz::deleta_aresta(int v, int w)
{
    if (v != w)
    {
        this->operator()(v - 1, w - 1) = 0;
    }
}

/**
 * @brief Retorna o peso da Aresta;
 * @param v id do vértice de início.
 * @param w id do vértice de chegada.
 * @return Retorna o peso da aresta entre os vértices passados como parâmetro.
 */
float grafo_matriz::pesoAresta(int v, int w)
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
            for (int j = 0; j < getOrdem(); j++)
            {   
                if (i >= j)
                {
                    if(this->operator()(i,j) != 0)
                    {
                        cout << m[i * (i + 1) / 2 + j] << " ";
                    }
                    else
                    {
                        cout << "00 ";
                    }
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
                if(this->operator()(i,j) != 0)
                {
                    cout << this->operator()(i,j) << " ";
                }
                else
                {
                    cout << "00 ";
                }
            }
            cout << endl;
        }
    }
    
}