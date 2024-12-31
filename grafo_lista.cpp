#include "grafo_lista.h"

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

void grafo_lista::insere_vertice(unsigned int id, int peso)
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

void grafo_lista::insere_aresta(unsigned int v, unsigned int w, int peso)
{
    vertice *p = inicio;
    edge *e = new edge(v, w);
    e->Peso() = peso;
    e->ID() = this->Tamanho();    
    while(p != NULL)
    {
        if(p->ID() == v)
        {
            p->insereAresta(e);
            std::cout << "Aresta inserida!" << std::endl<< std::endl;
            break;
        }

        p = p->getProx();
    }
}

int grafo_lista::pesoVertice(unsigned int idVertice)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == idVertice)
        {
            return p->Peso();
        }
        p = p->getProx();
    }
    std::cout << "Vertice nao encontrado" << std::endl;
    return 0;
}

int grafo_lista::pesoAresta(unsigned int v, unsigned int w)
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
    std::cout << "Aresta nao encontrada" << std::endl;
    return 0;
}

vertice* grafo_lista::getInicio()
{
    return inicio;
}

vertice* grafo_lista::getVertice(unsigned int v)
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

edge* grafo_lista::getAresta(unsigned int idAresta)
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
    std::cout << "Aresta nao encontrada" << std::endl;
    return NULL;
}

bool grafo_lista::buscaVertice(unsigned int idVertice)
{
    vertice *p = inicio;
    while(p != NULL)
    {
        if(p->ID() == idVertice)
        {
            return true;
        }
        p = p->getProx();
    }
    return false;
}

bool grafo_lista::buscaAresta(unsigned int v, unsigned int w)
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

// B4Hive-begin
bool grafo_lista::auxArestaPonte() {
    int tag[getOrdem()];
    for (int &t : tag) {
        t = -1;
    }
    bool visitado[getOrdem()];
    for (bool &vis : visitado) {
        vis = false;
    }
    vertice *v = getInicio();
    int count = 0;
    int tagCount = 0;
    while (v != NULL){
        if (!visitado[v->ID()-1]){
            count++;
            tagCount++;
            BPPonte(v, tag, visitado, tagCount, -1, -1);
        }    
        v = v->getProx();
    }

    for(int i = 1; i <= getOrdem(); i++){
        for(int j = 1; j <= getOrdem(); j++){
            for (int &t : tag) {
                t = -1;
            }
            for (bool &vis : visitado) {
                vis = false;
            }
            int counter = 0;
            int tagCounter = 0;
            v = getInicio();
            while (v != NULL){
                if (!visitado[v->ID()-1]){
                    counter++;
                    tagCounter++;
                    BPPonte(v, tag, visitado, tagCounter, i, j);
                }
                v = v->getProx();
            }
            if (counter > count) {
                return true;
            }
        }
    }
    return false;
}

void grafo_lista::BPPonte(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV, int ignoredW) {
    visitado[v->ID()-1] = true;
    tag[v->ID()-1] = currentTag;
    edge *e = v->getAresta();
    while (e != NULL){
        if ((e->V() != ignoredV && e->W() != ignoredW) || (!getDirecionado() && e->V() != ignoredW && e->W() != ignoredV)){
            vertice *w = getVertice(e->W());
            if (!visitado[w->ID()-1] && w->ID() != ignoredV){
                BPPonte(w, tag, visitado, currentTag, ignoredV, ignoredW);
            }
        }
        e = e->getProx();
    }
}

bool grafo_lista::auxVerticeArticulacao() {
    int tag[getOrdem()];
    for (int &t : tag) {
        t = -1;
    }
    bool visitado[getOrdem()];
    for (bool &vis : visitado) {
        vis = false;
    }
    vertice *v = getInicio();
    int count = 0;
    int tagCount = 0;
    while (v != NULL){
        if (!visitado[v->ID()-1]){
            count++;
            tagCount++;
            BPArticulacao(v, tag, visitado, tagCount, -1);
        }    
        v = v->getProx();
    }
    
    for (int w = 1; w <= getOrdem(); w++) {
        for (int &t : tag) {
            t = -1;
        }
        for (bool &vis : visitado) {
            vis = false;
        }
        int counter = 0;
        int tagCounter = 0;
        v = getInicio();
        while (v != NULL){
            if (!visitado[v->ID()-1]){
                counter++;
                tagCounter++;
                BPArticulacao(v, tag, visitado, tagCounter, w);
            }
            v = v->getProx();
        }
        if (counter > count) {
            return true;
        }
    }
    return false;
}

void grafo_lista::BPArticulacao(vertice *v, int tag[], bool visitado[], int currentTag, int ignoredV) {
    if(visitado[v->ID()-1] || v->ID() == ignoredV){
        return;
    }
    visitado[v->ID()-1] = true;
    tag[v->ID()-1] = currentTag;
    edge *e = v->getAresta();
    while (e != NULL){
        vertice *w = getVertice(e->W());
        if (!visitado[w->ID()-1] && w->ID() != ignoredV){
            BPArticulacao(w, tag, visitado, currentTag, ignoredV);
        }
        e = e->getProx();
    }
}

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
    // gambiarra, eu sei
}

void grafo_lista::imprime() {
    std::cout << "Imprimindo lista" << std::endl;
    vertice *v = getInicio();
    while (v != NULL){
        std::cout << v->ID() << "(" << v->Peso() << ") -> ";
        edge *e = v->getAresta();
        while (e != NULL){
            std::cout << e->W() << "(" << e->Peso() << ") - ";
            e = e->getProx();
        }
        std::cout << std::endl;
        v = v->getProx();
    }
}
// B4Hive-end