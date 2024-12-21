#include "data_strc.h"


/*-------------------------- Vertice -----------------------------*/

vertice::vertice()
{
    this->id = 0;
    this->grau = 0;
    this->peso = 0;
    this->prox = NULL;
    this->init_aresta = NULL;
}

vertice::~vertice(){};

unsigned int &vertice::ID()
{
    return id;
}

unsigned int &vertice::Grau()
{
    return grau;
}

int &vertice::Peso()
{
    return peso;
}

vertice *vertice::getProx()
{
    return prox;
}

void vertice::setProx(vertice *p)
{
    prox = p;
}

void vertice::insereAresta(edge *e)
{
    if(init_aresta == NULL)
    {
        init_aresta = e;
    }
    else
    {
        edge *ep = init_aresta;
        while(ep->getProx() != NULL)
        {
            ep = ep->getProx();
        }
        ep->setProx(e);
    }
}

/*-------------------------- Aresta -----------------------------*/

edge::edge(unsigned int v, unsigned int w)
{
    this->v = v;
    this->w = w;
    this->peso = 0;
    this->prox = NULL;
}

edge::~edge(){};

edge::edge()
{
    id = 0;
    v = 0;
    w = 0;
    peso = 0;
    prox = NULL;
}

edge *edge::getProx()
{
    return this->prox;
}


/*-------------------------- No -----------------------------

No::No(){}

No::~No(){};

No *No::getProx()
{
    return this->prox;
}

No *No::getAnt()
{
    return this->ant;
}

vertice *No::getVertice()
{
    return &v;
}



void No::setProx(No *p)
{
    this->prox = p;
}

void No::setAnt(No *a)
{
    this->ant = a;
}

void No::setVertice(vertice v)
{
    this->v = v;
}

/*-------------------------- Lista -----------------------------

Lista::Lista()
{
    this->tam = 0;
    this->primeiro = NULL;
    this->ultimo = NULL;
}

Lista::~Lista(){};

void Lista::insereInicio(vertice v)
{
    No *p = new No();
    p->setVertice(v);
    p->setProx(primeiro);
    p->setAnt(NULL);
    if(tam == 0)
    {
        ultimo = p;
    }
    else
    {
        primeiro->setAnt(p);
    }
    primeiro = p;
    tam++;
}

void Lista::removeInicio()
{
    No *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = primeiro->getProx();
        delete p;
        tam--;
        if(tam == 0)
        {
            ultimo = NULL;
        }
        else
        {
            primeiro->setAnt(NULL);
        }
    }   
    else
    {
        std::cout << "Lista vazia" << std::endl;
    }
}

void Lista::insereFim(vertice v)
{
    No *p = new No();
    p->setVertice(v);
    p->setProx(NULL);
    p->setAnt(ultimo);
    if(tam == 0)
    {
        primeiro = p;
    }
    else
    {
        ultimo->setProx(p);
    }
    ultimo = p;
    tam++;
}

void Lista::removeFim()
{
    No *p;
    if(ultimo != NULL)
    {
        p = ultimo;
        ultimo = ultimo->getAnt();
        delete p;
        tam--;
        if(tam == 0)
        {
            primeiro = NULL;
        }
        else
        {
            ultimo->setProx(NULL);
        }
    }
    else
    {
        std::cout << "Lista vazia" << std::endl;
    }
}

bool Lista::busca(vertice v)
{
    No *p = primeiro;
    while(p != NULL)
    {
        if(p->getVertice()->ID() == v.ID())
        {
            return true;
        }
        p = p->getProx();
    }
    return false;
}

/*-------------------------- Matriz -----------------------------

Matriz::Matriz(unsigned int ordem)
{
    this->adj = new edge[ordem*ordem];
}

Matriz::~Matriz()
{
    delete[] adj;
}

edge Matriz::operator()(unsigned int v, unsigned int w)
{
    return adj[((v * this->ordem) + w)];
}


*/
