/**
 * @file grafo_matriz.cpp
 * 
 * @brief Arquivo de implementação da classe grafo_matriz que é filha da classe Grafo.
 * @version 1.1.0
 * @date 2025-02-10
 */

#include "grafo_matriz.h"
using namespace std;


/**
 * @brief Construtor da classe
 * 
 * @details Inicia as variáveis m, ordem_matriz e exp_ordem.
 */
grafo_matriz::grafo_matriz()
{
    m = NULL;
    ordem_matriz = 0;
    exp_ordem = 0;
}


/**
 * @brief Destrutor da classe
 * 
 * @details deleta m, que é o ponteiro para a matriz de adjacência representada em um array unidimensional
 */
grafo_matriz::~grafo_matriz()
{
    delete[] m;
}


/**
 * @brief Inicializa a estrutura de armazenamento;
 * @details Inicializa a matriz de adjacências para o grafo, calculando a ordem da matriz com base na ordem do grafo e configurando o tamanho adequado para o vetor de representação. 
 * A ordem da matriz é determinada pela potência de 2 mais próxima do valor da ordem do grafo. 
 * Se o grafo não for direcionado, é alocada uma matriz triangular inferior, caso contrário, uma matriz quadrada é alocada.
 * O vetor é inicializado com zeros, representando a ausência de arestas entre os vértices do grafo.
 */
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

    cout << "Tamanho do vetor: " << tamanho_vetor << endl;
    m = new int[tamanho_vetor];
    for (int i = 0; i < tamanho_vetor; i++)
    {
        m[i] = 0;
    }

}


/**
 * @brief Realoca a matriz de adjacência para o dobro do tamanho
 * 
 * @details Esta função tem como objetivo realocar a matriz de adjacência de um grafo, que é armazenada no vetor m. 
 * Ela faz isso ao expandir a ordem da matriz, armazenar novamente as arestas e pesos do grafo, e reconfigurar os 
 * dados da estrutura interna de maneira eficiente.
 *
 */
void grafo_matriz::realoca()
{
    cout << "Realocando" << endl;
    if(Debug())cout << "DEBUG Realoca" << endl;
    // Armazenamento das arestas e do pesos dos vertices;
    int cont = 0; 
    edge *arestas = new edge[Tamanho()];
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
    if(Debug()) cout<< "DEBUG " << endl;
    this->m = new int[tamanho_vetor];

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
        return m[i * ordem_matriz + j];
    }
    return m[0];
}


/**
 * @brief Insere um novo vértice na estrutura;
 * @details
 * Insere um novo vértice na matriz de adjacência do grafo. A função utiliza a operação de acesso da matriz para atribuir o peso do vértice
 * à posição correspondente na matriz, com base no identificador do vértice (id).
 * O índice na matriz é ajustado para começar em zero, subtraindo 1 do id fornecido.
 * @param id Indice do novo vértice;
 * @param peso Peso do novo vertice;
 */
void grafo_matriz::insere_vertice(int id, int peso)
{
    this->operator()(id - 1, id - 1) = peso;
}


/**
 * @brief Insere um novo nó na estrutura;
 * @details tem como objetivo adicionar um novo vértice ao grafo, representado por uma matriz de adjacência.
 * Ela realiza uma série de etapas para garantir que o novo vértice seja inseridoincluindo 
 * a verificação de capacidade da matriz de adjacência e a realocação, caso necessário.
 * @param peso Peso do novo nó;
 */
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


/**
 * @brief Função que recebe um Nó, o deleta e ajusta a Matriz de adjacências.
 * @details
 * Remove um vértice do grafo, incluindo as arestas associadas a ele. Se o grafo for direcionado, a função também remove
 * as arestas direcionadas de outros vértices para o vértice a ser deletado. Após a remoção, a ordem do grafo é atualizada,
 * ajustando os índices dos vértices restantes. Além disso, a função lida com a exclusão de arestas entre vértices sucessores
 * e antecessores, garantindo a integridade da estrutura de dados do grafo.
 *  @param id Id para identificação do Nó a ser deletado.
 */
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
void grafo_matriz::insere_aresta(int v, int w, int peso)
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
void grafo_matriz::nova_aresta(int v, int w, int peso)
{
    if(v != w)
    {
        this->operator()(v-1,w-1) = peso;
    }
}


/**
 * @brief Remove uma aresta.
 * @details 
 *A função tem como objetivo remover uma aresta entre os vértices v e w 
 *em um grafo representado por uma matriz de adjacência.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 */
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
int grafo_matriz::pesoAresta(int v, int w)
{
    return this->operator()(v - 1, w - 1);
}


/**
 * @brief Retorna o peso do vértice;
 * @param id id do vértice que queremos saber o peso
 * @return Retorna o peso de um vértice passado como parâmetro
 */
int grafo_matriz::pesoVertice(int id)
{
    return this->operator()(id - 1, id - 1);
}


/**
 * @brief  Busca se um vértice está na Matriz de adjacências.
 * @param id id do vértice que queremos saber se está na Matriz.
 * @return true caso exista um vértice de mesmo id que o passado por parâmetro na Matriz de adjacência.
 * @return false caso não.
 */
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


/**
 * @brief Busca uma aresta no grafo entre dois vértices passados como parâmetro;
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @return true caso encontre uma aresta entre os dois vértices.
 * @return false, caso não.
 */
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


/**
 * @brief Retorna uma aresta entre os vértices passados como parâmetro
 * @details
 * Retorna um ponteiro para um objeto `edge` representando a aresta entre os vértices `v` e `w` se existir.
 * A função verifica se há uma conexão entre os vértices na matriz de adjacência e, se encontrada, cria e retorna
 * um novo objeto `edge` com os dados da aresta. Caso contrário, imprime uma mensagem e retorna um ponteiro nulo.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @return Retorna uma aresta do Tipo edge, caso não encontre, retorna 0.
 */
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


/**
 * @brief Função que retorna um vetor contendo os Id's dos Vértices Vizinhos. 
 * @details
 * Retorna um vetor com os IDs dos vizinhos do vértice de índice `id`. A função percorre a matriz de adjacência do grafo e
 * identifica os vértices que têm uma aresta conectando-se ao vértice `id`. O vetor contém os IDs dos vizinhos, e o tamanho do
 * vetor é determinado pelo grau do vértice. A matriz de adjacência é baseada em índices 0-base, portanto, o índice `id` é ajustado
 * para refletir isso. 
 * @return Vetor contendo os ids dos vértices vizinhos ao vértice passado como parâmetro.
 * @return 0, caso o vértice passado como parâmetro não tenha vizinhos.
 */
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


/**
 * @brief Retorna o grau do vertice;
 * @details
 * Calcula e retorna o grau do vértice com o ID `id`. A função percorre a matriz de adjacência do grafo e conta o número de
 * conexões (arestas) do vértice especificado com outros vértices, desconsiderando a diagonal da matriz (o próprio vértice).
 * O grau é incrementado sempre que uma aresta (valor diferente de zero) é encontrada entre o vértice `id` e outro vértice.
 * O índice do vértice é ajustado para a base 0 da matriz de adjacência.
 * @param id id do vértice que queremos saber o grau.
 * @return O valor do grau do vértice.
 */
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


/**
 * @brief Imprime a estrutura do grafo;
 */
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