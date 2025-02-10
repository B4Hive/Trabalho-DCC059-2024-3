/**
 * @file grafo_lista.cpp
 *
 * @brief Arquivo de implementação da classe grafo_lista que é filha da classe Grafo.
 * @version 1.1.0
 * @date 2025-02-10
 */

#include "grafo_lista.h"
using namespace std;

/**
 * @brief Construtor da classe grafo_lista.
 * @details Este construtor inicializa a lista de vértices do grafo como uma lista vazia, ou seja, o ponteiro `inicio` é definido como `NULL`.
 * Isso prepara a estrutura de dados para a inserção de vértices e arestas subsequentes.
 */
grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

/**
 * @brief Destruidor da classe grafo_lista.
 * @details Este destruidor percorre todos os vértices do grafo, removendo cada aresta associada a cada vértice e, em seguida, deleta o vértice.
 * A memória alocada para os vértices e arestas é liberada, evitando vazamentos de memória.
 * O processo ocorre da seguinte forma:
 * 1. Para cada vértice na lista, as arestas associadas a ele são removidas.
 * 2. Cada aresta é deletada antes de deletar o vértice em si.
 * 3. Ao final, o vértice é deletado e o próximo vértice na lista é processado.
 */
grafo_lista::~grafo_lista()
{
    vertice *p = inicio;
    while (p != NULL)
    {
        edge *e = p->get_init_aresta();
        while (e != NULL)
        {
            edge *aux = e;
            e = e->getProx();
            delete aux;
        }
        vertice *aux = p;
        p = p->getProx();
        delete aux;
    }
}

/**
 * @brief Insere um novo vértice na estrutura;
 * @details Insere um novo vértice na lista de vértices do grafo. O vértice é criado com um identificador único (id) e um peso associado.
 * Se a lista estiver vazia, o novo vértice se torna o primeiro da lista.
 * Caso contrário, o vértice é inserido no final da lista, mantendo a ordem de inserção.
 * @param id Indice do novo vértice;
 * @param peso Peso do novo vertice;
 */
void grafo_lista::insere_vertice(int id, int peso)
{
    vertice *v = new vertice();
    v->ID() = id;
    v->Peso() = peso;
    if (inicio == NULL)
    {
        inicio = v;
    }
    else
    {
        vertice *p = inicio;
        while (p->getProx() != NULL)
        {
            p = p->getProx();
        }
        p->setProx(v);
    }
}

/**
 * @brief Insere um novo vértice na estrutura e se necessário aumenta o espaço de armazenamento reservado
 * @details Cria um novo nó (vértice) no grafo, incrementando a ordem do grafo e inserindo o vértice com o peso especificado.
 * A ordem do grafo é atualizada antes da inserção do vértice, garantindo que o novo vértice seja inserido corretamente
 * na estrutura de dados do grafo, com o peso fornecido.
 * @param peso Peso do novo Nó / Vértice;
 */
void grafo_lista::novo_no(int peso)
{
    setOrdem(getOrdem() + 1);
    insere_vertice(getOrdem(), peso);
}

/**
 * @brief Função que recebe um Nó, o deleta e ajusta a lista de adjacências.
 * @details
 * Remove um vértice do grafo, incluindo as arestas associadas a ele. Se o grafo for direcionado, a função também remove
 * as arestas direcionadas de outros vértices para o vértice a ser deletado. Após a remoção, a ordem do grafo é atualizada,
 * ajustando os índices dos vértices restantes. Além disso, a função lida com a exclusão de arestas entre vértices sucessores
 * e antecessores, garantindo a integridade da estrutura de dados do grafo.
 * @param id Id para identificação do Nó a ser deletado.
 */
void grafo_lista::deleta_no(int id)
{
    vertice *p = inicio;
    vertice *ant = NULL;
    int *vizinhos = new int;
    while (p != NULL)
    {
        if (getDirecionado()) // Remoção para arcos dos vertices antecessores;
        {
            vizinhos = vizinhosVertice(p->ID());
            for (int i = 0; i < grauVertice(p->ID()); i++)
            {
                if (vizinhos[i] == id)
                {
                    deleta_aresta(p->ID(), id);
                }
            }
        }
        if (p->ID() == id) // Remoção para arcos dos vertices sucessores;
        {
            vizinhos = vizinhosVertice(id);
            for (int i = 0; i < grauVertice(id); i++)
            {
                deleta_aresta(id, vizinhos[i]);
                if (getDirecionado())
                {
                    deleta_aresta(vizinhos[i], id);
                }
            }
            break;
        }
        ant = p;
        p = p->getProx();
    }

    // --------- Atualização dos indices ------ //

    p = inicio;
    while (p != NULL)
    {
        if (p->ID() == id)
        {
            if (ant == NULL)
            {
                inicio = p->getProx();
            }
            else
            {
                ant->setProx(p->getProx());
            }
            delete p;
        }
        else
        {
            if (p->ID() > id)
            {
                p->ID()--;
            }
            edge *e = p->get_init_aresta();
            while (e != NULL)
            {
                if (e->W() > id)
                {
                    e->W()--;
                }
                e = e->getProx();
            }
        }
        ant = p;
        p = p->getProx();
    }
    setOrdem(getOrdem() - 1);
}

/**
 * @brief Insere uma aresta entre dois nós enviados por parâmetro.
 * @details
 * Insere uma aresta entre os vértices `v` e `w` no grafo. Se a aresta já existir, a função retorna sem realizar nenhuma alteração.
 * Caso contrário, uma nova aresta é criada e associada ao vértice `v`. Se o grafo não for direcionado, uma aresta adicional é
 * criada entre `w` e `v`. Para cada vértice afetado pela inserção, o grau do vértice é incrementado. A aresta recebe um identificador
 * único, que é gerado com base no tamanho atual do grafo.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @param peso Peso da aresta
 */
void grafo_lista::insere_aresta(int v, int w, int peso)
{
    if (buscaAresta(v, w))
    {
        return;
    }
    vertice *p = inicio;
    edge *e = new edge(v, w);
    e->Peso() = peso;
    e->ID() = this->Tamanho();
    while (p != NULL)
    {

        if (p->ID() == v)
        {
            p->insereAresta(e);
            p->Grau()++;
        }
        if (p->ID() == w && !getDirecionado())
        {
            edge *e2 = new edge(w, v);
            e2->Peso() = peso;
            e2->ID() = this->Tamanho();
            p->insereAresta(e2);
            p->Grau()++;
        }
        p = p->getProx();
    }
}

/**
 * @brief Cria uma nova aresta entre dois nós com parâmetros enviados pelo usuário;
 * @details Utiliza a função insere_aresta() para fazer a inserção
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @param peso Peso da aresta
 */
void grafo_lista::nova_aresta(int v, int w, int peso)
{
    insere_aresta(v, w, peso);
}

/**
 * @brief Remove uma aresta do grafo.
 * @details Essa função remove a aresta entre dois vértices `v` e `w` do grafo. Se o grafo for não direcionado, a aresta (v, w) é removida de ambos os vértices. Caso contrário, apenas a aresta (v, w) é removida do vértice `v`.
 * @param v O vértice de origem da aresta.
 * @param w O vértice de destino da aresta.
 * @note Se a aresta não existir, a função não faz nada.
 * @warning Em grafos direcionados, a aresta (v, w) será removida, mas a aresta (w, v) não será, a menos que seja chamada explicitamente.
 */
void grafo_lista::deleta_aresta(int v, int w)
{
    if (!buscaAresta(v, w))
    {
        return;
    }
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == v)
        {
            edge *e = p->get_init_aresta();
            edge *ant = NULL;
            while (e != NULL)
            {
                if (e->W() == w)
                {
                    if (ant == NULL)
                    {
                        p->set_init_aresta(e->getProx());
                    }
                    else
                    {
                        ant->setProx(e->getProx());
                    }
                    delete e;
                    p->Grau()--;
                    if (getDirecionado())
                        break;
                }
                ant = e;
                e = e->getProx();
            }
        }
        if (p->ID() == w && !getDirecionado())
        {
            edge *e = p->get_init_aresta();
            edge *ant = NULL;
            while (e != NULL)
            {
                if (e->W() == v)
                {
                    if (ant == NULL)
                    {
                        p->set_init_aresta(e->getProx());
                    }
                    else
                    {
                        ant->setProx(e->getProx());
                    }
                    delete e;
                }
                ant = e;
                e = e->getProx();
            }
        }

        p = p->getProx();
    }
}

/**
 * @brief Retorna o peso do vértice;
 * @details Percorre a lista de adjacências a procura de um vértice com o mesmo id que o passado como parâmetro, caso encontre, retorna seu respectivo peso, caso não ache, retorna 0.
 * @param id id do vértice que queremos saber o peso
 * @return Retorna o peso de um vértice passado como parâmetro
 */
int grafo_lista::pesoVertice(int id)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == id)
        {
            return p->Peso();
        }
        p = p->getProx();
    }
    // cout << "Vertice nao encontrado" << endl;
    return 0;
}

/**
 * @brief Retorna o peso da Aresta;
 * @details
 * Retorna o peso da aresta entre os vértices `v` e `w`. A função percorre a lista de vértices até encontrar `v`
 * e então busca na lista de arestas associadas a esse vértice. Se a aresta for encontrada, retorna seu peso.
 * Caso contrário, retorna 0, indicando que a aresta não existe no grafo.
 * @param v id do vértice de início.
 * @param w id do vértice de chegada.
 * @return Retorna o peso da aresta entre os vértices passados como parâmetro.
 */
int grafo_lista::pesoAresta(int v, int w)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == v)
        {
            edge *ep = p->get_init_aresta();
            while (ep != NULL)
            {
                if (ep->W() == w)
                {
                    return ep->Peso();
                }
                ep = ep->getProx();
            }
        }
        p = p->getProx();
    }
    // cout << "Aresta nao encontrada" << endl;
    return 0;
}

/**
 * @brief Retorna o inicio da lista.
 *
 * @details Esta função retorna um vertice *grafo_lista que é o inicio da lista.
 * @return Retorna vertice *grafo_lista que é o inicio da lista.
 */
vertice *grafo_lista::getInicio()
{
    return inicio;
}

/**
 * @brief Retorna um ponteiro com o id do vétice;
 *
 * @details Esta função recebe como parâmetro um valor inteiro v, caso o valor do id seja igual ao valor de v,
 * a função retorna um *p que contem o id do vértice.
 * @param v Uma variável de valor inteiro
 * @return Retorna vertice *grafo_lista que é o inicio da lista.
 */
vertice *grafo_lista::getVertice(int v)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == v)
        {
            return p;
        }
        p = p->getProx();
    }
    return NULL;
}

/**
 * @brief Retorna uma aresta entre os vértices passados como parâmetro
 * @details
 * Busca e retorna um ponteiro para a aresta que conecta os vértices `v` e `w` na lista de adjacência.
 * A função percorre a lista de vértices até encontrar `v` e, em seguida, percorre suas arestas para localizar `w`.
 * Se a aresta for encontrada, retorna um ponteiro para ela; caso contrário, retorna NULL.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @return Retorna uma aresta do Tipo edge, e caso não encontre, retorna NULL.
 */
edge *grafo_lista::getAresta(int v, int w)
{
    vertice *p = inicio;
    edge *e = new edge();
    while (p != NULL)
    {
        if (p->ID() == v)
        {
            e = p->get_init_aresta();
            while (e != NULL)
            {
                if (e->W() == w)
                {
                    return e;
                }
                e = e->getProx();
            }
        }
    }
    // cout << "Aresta nao encontrada" << endl;
    return NULL;
}

/**
 * @brief  Busca se um vértice está na lista de adjacência.
 * @details Percorre a lista de adjacências a procura de um vértice com o mesmo id que o passado como parâmetro, caso encontre, retorna true, caso não ache, retorna false.
 * @param id id do vértice que queremos saber se está na lista.
 * @return true caso exista um vértice de mesmo id que o passado por parâmetro na lista de adjacência.
 * @return false caso não.
 */
bool grafo_lista::buscaVertice(int id)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == id)
        {
            return true;
        }
        p = p->getProx();
    }
    return false;
}

/**
 * @brief Busca uma aresta no grafo entre dois vértices passados como parâmetro;
 * @details
 * Verifica se existe uma aresta entre os vértices `v` e `w` na lista de adjacência.
 * Percorre a lista de vértices até encontrar `v` e, em seguida, percorre suas arestas buscando `w`.
 * Retorna `true` se a aresta existir e `false` caso contrário.
 * @param v id do vértice de origem;
 * @param w id do vértice de destino;
 * @return true caso encontre uma aresta entre os dois vértices.
 * @return false, caso não.
 */
bool grafo_lista::buscaAresta(int v, int w)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == v)
        {
            edge *e = p->get_init_aresta();
            while (e != NULL)
            {
                if (e->W() == w)
                {
                    return true;
                }
                e = e->getProx();
            }
        }
        p = p->getProx();
    }
    return false;
}

/**
 * @brief Função que retorna um vetor contendo os Id's dos Vértices Vizinhos.
 * @details
 * Retorna um vetor contendo os IDs dos vizinhos do vértice com o ID especificado. A função percorre a lista de vértices do grafo
 * e, ao encontrar o vértice correspondente ao `id`, aloca um vetor e preenche com os IDs dos vértices adjacentes. Se o vértice não
 * tiver vizinhos (grau 0) ou não for encontrado no grafo, a função retorna `NULL`. Caso contrário, retorna o vetor com os vizinhos.
 * @param id id do vértice que queremos saber o grau.
 * @return Vetor contendo os ids dos vértices vizinhos ao vértice passado como parâmetro.
 * @return Null, caso o vértice passado como parâmetro não tenha vizinhos.
 */
int *grafo_lista::vizinhosVertice(int id)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == id)
        {
            if (p->Grau() == 0)
            {
                // cout << "Vertice sem vizinhos" << endl;
                return NULL;
            }
            int *vizinhos = new int[p->Grau()];
            edge *e = p->get_init_aresta();
            for (int i = 0; e != NULL; i++)
            {
                vizinhos[i] = e->W();
                e = e->getProx();
            }
            return vizinhos;
        }
        p = p->getProx();
    }
    return NULL;
}

/**
 * @brief Retorna o grau do vertice;
 * @details
 * Retorna o grau do vértice com o ID especificado. A função percorre a lista de vértices do grafo e, ao encontrar o vértice
 * correspondente ao `id`, retorna o seu grau (número de arestas conectadas a ele). Caso o vértice não seja encontrado, a função
 * retorna 0, indicando que o vértice não existe no grafo.
 * @param id id do vértice que queremos saber o grau.
 * @return O valor do grau do vértice.
 */
int grafo_lista::grauVertice(int id)
{
    vertice *p = inicio;
    while (p != NULL)
    {
        if (p->ID() == id)
        {
            return p->Grau();
        }
        p = p->getProx();
    }
    return 0;
}

void grafo_lista::inicializa()
{
}

/**
 * @brief Imprime a estrutura do grafo;
 */
void grafo_lista::imprime()
{
    vertice *v = getInicio();
    while (v != NULL)
    {
        cout << v->ID() << "(" << v->Peso() << ") -> ";
        edge *e = v->get_init_aresta();
        while (e != NULL)
        {
            cout << e->W() << "(" << e->Peso() << ") - ";
            e = e->getProx();
        }
        cout << endl;
        v = v->getProx();
    }
}
