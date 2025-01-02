#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"
using namespace std;
// << Getters and Setters >>

void Grafo::setGrau(unsigned int grau)
{
    if(grau < 0)
    {
        cout << "Grau invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        info[0] = grau;
    }
}

void Grafo::setOrdem(unsigned int ordem)
{
    if(ordem < 0)
    {
        cout << "Ordem invalida!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        info[1] = ordem;
    }
}

void Grafo::setDirecionado(bool direcionado)
{
    if(direcionado != 0 && direcionado != 1)
    {
        cout << "Direcionado invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[0] = direcionado;
    }
}

void Grafo::setComponentes_conexas(unsigned int componentes_conexas)
{
    if(componentes_conexas < 0)
    {
        cout << "Componentes conexas invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        info[2] = componentes_conexas;
    }
}

void Grafo::setVertices_ponderados(bool vertices_ponderados)
{
    if(vertices_ponderados != 0 && vertices_ponderados != 1)
    {
        cout << "Vertices ponderados invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[1] = vertices_ponderados;
    }
}

void Grafo::setArestas_ponderadas(bool arestas_ponderadas)
{
    if(arestas_ponderadas != 0 && arestas_ponderadas != 1)
    {
        cout << "Arestas ponderadas invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[2] = arestas_ponderadas;
    }
}

void Grafo::setCompleto(bool completo)
{
    if(completo != 0 && completo != 1)
    {
        cout << "Completo invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[3] = completo;
    }
}

void Grafo::setBipartido(bool bipartido)
{
    if(bipartido != 0 && bipartido != 1)
    {
        cout << "Bipartido invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[4] = bipartido;
    }
}

void Grafo::setArvore(bool arvore)
{
    if(arvore != 0 && arvore != 1)
    {
        cout << "Arvore invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[5] = arvore;
    }
}

void Grafo::setAresta_Ponte(bool aresta_ponte)
{
    if(aresta_ponte != 0 && aresta_ponte != 1)
    {
        cout << "Aresta ponte invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[6] = aresta_ponte;
    }
}

void Grafo::setVertice_de_Articulacao(bool vertice_de_articulacao)
{
    if(vertice_de_articulacao != 0 && vertice_de_articulacao != 1)
    {
        cout << "Vertice de articulacao invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        dpp[7] = vertice_de_articulacao;
    }
}

void Grafo::setTamanho(unsigned int tamanho)
{
    if(tamanho < 0)
    {
        cout << "Tamanho invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }
    else
    {
        info[3] = tamanho;
    }
}

unsigned int Grafo::getGrau()
{
    return info[0];
}

unsigned int Grafo::getOrdem()
{
    return info[1];
}

bool Grafo::getDirecionado()
{
    return dpp[0];
}

unsigned int Grafo::getComponentes_conexas()
{
    return info[2];
}

bool Grafo::getVertices_ponderados()
{
    return dpp[1];
}

bool Grafo::getArestas_ponderadas()
{
    return dpp[2];
}

bool Grafo::getCompleto()
{
    return dpp[3];
}

bool Grafo::getBipartido()
{
    return dpp[4];
}

bool Grafo::getArvore()
{
    return dpp[5];
}

bool Grafo::getAresta_Ponte()
{
    return auxArestaPonte();
}

bool Grafo::getVertice_de_Articulacao()
{
    return auxVerticeArticulacao();
}

unsigned int Grafo::getTamanho()
{
    return info[3];
}

// >

void Grafo::carrega_grafo(char *tipo, string dataFileName){
    ifstream file;
    string line;
    this->filename = dataFileName;
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        exit(2);
    }

    unsigned int ordem;
    bool direcionado;
    bool vertices_ponderados;
    bool arestas_ponderadas;

    file >> ordem;
    file >> direcionado;
    file >> vertices_ponderados;
    file >> arestas_ponderadas;

    setOrdem(ordem);
    setDirecionado(direcionado);
    setVertices_ponderados(vertices_ponderados);
    setArestas_ponderadas(arestas_ponderadas);

    getline(file, line);

    inicializa();

    for (int i = 1; i <= getOrdem(); i++)
    {
        int peso;
        if (getVertices_ponderados())
        {
            file >> peso;
        }
        insere_vertice(i, peso);
    }
    getline(file, line);
    while (!file.eof())
    {
        unsigned int v, w;
        int peso = 0;
        file >> v; // vertice orígem
        file >> w; // vertice destino
        if (getArestas_ponderadas())
        {
            file >> peso;
        }
        Tamanho()++;
        insere_aresta(v, w, peso);

        getline(file, line);
    }

    setGrau(auxSetGrau());

    file.close();
}

//exportInfo precisa de parametro "filename" que vai estar em argv[4]
void Grafo::exportInfo()
{
    cout << "Exportando Info" << endl;
    ofstream file;
    file.open("Grafo_infoOut.txt", ofstream::out);
    if(!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }
    file << getOrdem() << " " << getDirecionado() << " " << getVertices_ponderados() << " " << getArestas_ponderadas() << '\n';
    if(getVertices_ponderados())
    {
        for(int i = 1; i <= getOrdem(); i++)
        {
            file << pesoVertice(i) << " ";
        }
        file << '\n';
    }


    for(int i = 1; i<=getTamanho(); i++)
    {
        edge *e = new edge(); 
        e =getAresta(i);
        file << e->V() << " " << e->W() << " ";
        if(getArestas_ponderadas())
        {
            file << e->Peso() << " ";
        }
        file << '\n';
    }

}

void Grafo::novo_grafo(char *tipo, string descFileName)
{
    ifstream file;
    string line;
    this->filename = descFileName;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        exit(2);
    }

    unsigned int grau;
    unsigned int ordem;
    bool direcionado;
    unsigned int componentes_conexas;
    bool vertices_ponderados;
    bool arestas_ponderadas;
    bool completo;
    bool bipartido;
    bool arvore;
    bool aresta_ponte;
    bool vertice_de_articulacao;

    file >> grau;                   getline(file, line);
    file >> ordem;                  getline(file, line);
    file >> direcionado;            getline(file, line);
    file >> componentes_conexas;    getline(file, line);
    file >> vertices_ponderados;    getline(file, line);
    file >> arestas_ponderadas;     getline(file, line);
    file >> completo;               getline(file, line);
    file >> bipartido;              getline(file, line);
    file >> arvore;                 getline(file, line);
    file >> aresta_ponte;           getline(file, line);
    file >> vertice_de_articulacao; getline(file, line);

    this->setOrdem(ordem);
    this->setDirecionado(direcionado);
    this->setVertices_ponderados(vertices_ponderados);
    this->setArestas_ponderadas(arestas_ponderadas);
    this->inicializa();

    for (int i = 1; i <= getOrdem(); i++){
        int peso = 1;
        if (getVertices_ponderados())
            peso = rand() % 100 + 1;
        this->insere_vertice(i, peso);
    }
    if(completo){
        if(ordem > 2){
            if(bipartido
            || arvore
            || aresta_ponte
            || vertice_de_articulacao
            || componentes_conexas > 1
            || grau != ordem - 1){
                cout << "Grafo impossivel" << endl;
                cout << "Um grafo completo de ordem > 2 nao pode:" << endl <<
                "ser arvore ou bipartido;" << endl <<
                "conter aresta ponte ou vertice articulacao;" << endl <<
                "ter mais de uma componente conexa;" << endl <<
                "ter grau diferente de ordem - 1." << endl;
                exit(3);
            }
        }
        for (int i = 1; i <= ordem; i++){
            for (int j = 1; j <= ordem; j++){
                if (i != j){
                    int peso = 1;
                    if (arestas_ponderadas){
                        peso = rand() % 100 + 1;
                    }
                    this->insere_aresta(i, j, peso);
                }
            }
        }
        return;
    }
    if(arvore){
        if(!bipartido
        || componentes_conexas > 1
        || (ordem >= 2 && !aresta_ponte)
        || (ordem > 2 && !vertice_de_articulacao)
        || grau != ordem-1){
            cout << "Grafo impossivel" << endl;
            cout << "Uma arvore nao pode:" << endl <<
            "ser bipartida;" << endl <<
            "ter mais de uma componente conexa;" << endl <<
            "ter aresta ponte;" << endl <<
            "ter vertice de articulacao;" << endl <<
            "ter grau diferente de ordem - 1." << endl;
            exit(3);
        }
        int auxGrau[ordem];
        for (int a = 0; a < ordem; a++)
            auxGrau[a] = 0;
        int i = 0;
        int j = i+1;
        while(i < ordem){
            while(auxGrau[i] <= grau){
                if(j == ordem)
                    break;
                if(auxGrau[j] <= grau){
                    int peso = 1;
                    if (arestas_ponderadas)
                        peso = rand() % 100 + 1;
                    this->insere_aresta(i+1, j+1, peso);
                    auxGrau[i]++;
                    auxGrau[j]++;
                }
                j++;
            }
            i++;
        }
        return;
    }
    
    // << Não completo e não arvore
    if(aresta_ponte){
        if(!vertice_de_articulacao){
            cout << "Grafo impossivel" << endl;
            cout << "Uma aresta ponte implica em um vertice de articulacao." << endl;
            exit(3);
        }
    }
    if(vertice_de_articulacao){
        componentes_conexas++;
    }
    int *subgrafo[2]; // 2 vetores de tamanho (componentes_conexas), cada um indicando o indice de inicio e fim de cada subgrafo
    subgrafo[0] = new int[componentes_conexas];
    subgrafo[1] = new int[componentes_conexas];
    for (int i = 0; i < componentes_conexas; i++){
        subgrafo[0][i] = (i*ordem/componentes_conexas)+1; // inicio do subgrado i
        subgrafo[1][i] = (i+1)*ordem/componentes_conexas; // fim do subgrafo i
    }
    subgrafo[1][componentes_conexas-1] = ordem; // ajuste para o ultimo subgrafo
    if(vertice_de_articulacao && !aresta_ponte){
        // considerar 1 vertice como interseção entre 2 componentes conexas
    }
    if(bipartido){
        // cria um grafo bipartido pra cada componente conexa, obedecendo as condições de ponte e articulação
    } else{
        // cria um grafo não bipartido pra cada componente conexa, obedecendo as condições de ponte e articulação
    }
    if(aresta_ponte){
        // incluir uma aresta ponte entre 2 componentes conexas
    }
    // else if(vertice_de_articulacao){ // já vai ter sido tratado corretamente se eu fizer direito
    //considerando que já vai ter um vértice dentro de 2 comps conexas
    // >>
    file.close();
}

void Grafo::exportDesc(){
    cout << "Grau: " << getGrau() << endl;
    cout << "Ordem: " << getOrdem() << endl;
    cout << "Direcionado: ";
    if (getDirecionado()){
        cout << "Sim" << endl;
    }
    else{
        cout << "Nao" << endl;
    }
    cout << "Componentes conexas: " << getComponentes_conexas() << endl;
    cout << "Vertices ponderados: ";
    if (getVertices_ponderados()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Arestas ponderadas: ";
    if (getArestas_ponderadas()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Completo: ";
    if (getCompleto()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Bipartido: ";
    if (getBipartido()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Arvore: ";
    if (getArvore()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Aresta Ponte: ";
    if (getAresta_Ponte()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
    cout << "Vertice de Articulacao: ";
    if (getVertice_de_Articulacao()){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
    }
}
