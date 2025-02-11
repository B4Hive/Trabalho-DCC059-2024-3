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

void grafo_lista::novo_no(int peso)
{
    setOrdem(getOrdem() + 1);
    insere_vertice(getOrdem(), peso);
}

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
void grafo_lista::insere_aresta(int v, int w, float peso)
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
void grafo_lista::nova_aresta(int v, int w, float peso)
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
float grafo_lista::pesoAresta(int v, int w)
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

vertice *grafo_lista::getInicio()
{
    return inicio;
}

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
