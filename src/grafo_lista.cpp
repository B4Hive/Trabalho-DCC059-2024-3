/**
 * @file grafo_lista.cpp
 * 
 * @brief Arquivo de implementação da classe grafo_lista que é filha da classe Grafo.
 * @version 1.1.0
 * @date 2025-02-10
 */

#include "grafo_lista.h"
using namespace std;

grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

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
        if(getDirecionado()) // Remoção para arcos dos vertices antecessores; 
        {
            vizinhos = vizinhosVertice(p->ID());
            for(int i = 0; i < grauVertice(p->ID()); i++)
            {
                if(vizinhos[i] == id)
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
                if(getDirecionado())
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
        if(p->ID() == id)
        {
            if(ant == NULL)
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
            if(p->ID() > id)
            {
                p->ID()--;
            }
            edge *e = p->get_init_aresta();
            while(e != NULL)
            {
                if(e->W() > id)
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

void grafo_lista::deleta_aresta(int v, int w)
{
    if(!buscaAresta(v,w))
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
                if (e->W ()== w)
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
                    if(getDirecionado())break;
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
    //cout << "Vertice nao encontrado" << endl;
    return 0;
}

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
    //cout << "Aresta nao encontrada" << endl;
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
    //cout << "Aresta nao encontrada" << endl;
    return NULL;
}

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
