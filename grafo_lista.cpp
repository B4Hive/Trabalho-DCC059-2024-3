#include "grafo_lista.h"
using namespace std;

grafo_lista::grafo_lista()
{
    this->inicio = NULL;
}

grafo_lista::~grafo_lista()
{
    vertice *p = inicio;
    while(p != NULL)
    {
        edge *e = p->getAresta();
        while(e != NULL)
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
    if(inicio == NULL)
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

void grafo_lista::insere_aresta(int v, int w, int peso)
{
    if(buscaAresta(v, w)){
        return;
    }
    vertice *p = inicio;
    edge *e = new edge(v, w);
    e->Peso() = peso;
    e->ID() = this->Tamanho();    
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            p->insereAresta(e);
        }   
        if(p->ID() == w && !getDirecionado())
        {
            edge *e2 = new edge(w, v);
            e2->Peso() = peso;
            e2->ID() = this->Tamanho();
            p->insereAresta(e2);
        }
        p = p->getProx();
    }
}

int grafo_lista::pesoVertice(int id)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == id)
        {
            return p->Peso();
        }
        p = p->getProx();
    }
    cout << "Vertice nao encontrado" << endl;
    return 0;
}

int grafo_lista::pesoAresta(int v, int w)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            edge *ep = p->getAresta();
            while(ep != NULL)
            {
                if(ep->W() == w)
                {
                    return ep->Peso();
                }
                ep = ep->getProx();
            }
        }
        p = p->getProx();
    }
    cout << "Aresta nao encontrada" << endl;
    return 0;
}

vertice* grafo_lista::getInicio()
{
    return inicio;
}

vertice* grafo_lista::getVertice(int v)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            return p;
        }
        p = p->getProx();
    }
    return NULL;
}

edge* grafo_lista::getAresta(int idAresta)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        edge *e = p->getAresta();
        while(e != NULL)
        {
            if(e->ID() == idAresta)
            {
                return e;
            }
            e = e->getProx();
        }
        p = p->getProx();
    }
    cout << "Aresta nao encontrada" << endl;
    return NULL;
}

bool grafo_lista::buscaVertice(int id)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == id)
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
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            edge *e = p->getAresta();
            while(e != NULL)
            {
                if(e->W() == w)
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

int* grafo_lista::vizinhosVertice(int id)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == id)
        {
            if(p->Grau() == 0)
            {
                cout << "Vertice sem vizinhos" << endl;
                return NULL;
            }
            int *vizinhos = new int[p->Grau()];
            edge *e = p->getAresta();
            for(int i = 0; e != NULL; i++)
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
    while(p != NULL)
    {
        if(p->ID() == id)
        {
            return p->Grau();
        }
        p = p->getProx();
    }
    cout << "Vertice nao encontrado" << endl;
    return 0;
}
// B4Hive-begin

int grafo_lista::auxSetGrau(){
    int grau = 0;
    vertice *v = getInicio();
    while (v != NULL){
        int g = 0;
        edge *e = v->getAresta();
        while (e != NULL){
            g++;
            e = e->getProx();
        }
        if (g > grau){
            grau = g;
        }
        v = v->getProx();
    }
    return grau;
}

void grafo_lista::inicializa() {
    // eu sei como evitar essa função mas é mais fácil deixar por enquanto
}

void grafo_lista::imprime() {
    cout << endl << "Imprimindo lista" << endl;
    cout << "vertice(peso do vertice) -> vizinho(peso da aresta) - vizinho(peso da aresta)..." << endl;
    vertice *v = getInicio();
    while (v != NULL){
        cout << v->ID() << "(" << v->Peso() << ") -> ";
        edge *e = v->getAresta();
        while (e != NULL){
            cout << e->W() << "(" << e->Peso() << ") - ";
            e = e->getProx();
        }
        cout << endl;
        v = v->getProx();
    }
}
// B4Hive-end