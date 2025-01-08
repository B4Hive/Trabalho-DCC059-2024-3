#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"
using namespace std;
// << Getters and Setters >>

void Grafo::setGrau(int grau)
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

void Grafo::setOrdem(int ordem)
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

void Grafo::setComponentes_conexas(int componentes_conexas)
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

void Grafo::setTamanho(int tamanho)
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


int Grafo::getGrau()
{
    return info[0];
}

int Grafo::getOrdem()
{
    return info[1];
}

bool Grafo::getDirecionado()
{
    return dpp[0];
}

int Grafo::getComponentes_conexas()
{
    info[2] = BPConexo();
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
    return eh_completo();
    //return dpp[3];
}

bool Grafo::getBipartido()
{
    dpp[4] = BipartidoFB();
    return dpp[4];
}

bool Grafo::getArvore()
{
    return eh_arvore();
    //return dpp[5];
}

bool Grafo::getAresta_Ponte()
{
    return auxArestaPonte();
}

bool Grafo::getVertice_de_Articulacao()
{
    return auxVerticeArticulacao();
}

int Grafo::getTamanho()
{
    return info[3];
}

// >>

// << BHive >>

bool Grafo::auxArestaPonte() {
    int disc[getOrdem()];
    int low[getOrdem()];
    int pai = -1;
    bool visitado[getOrdem()];
    int tempo = 0;
    int qtdPonte = 0;
    for (int i = 0; i < getOrdem(); i++){
        disc[i] = -1;
        low[i] = -1;
        visitado[i] = false;
    }

    for (int i = 1; i <= getOrdem(); i++){
        if (disc[i-1] == -1){
            BPPonte(i, visitado, &tempo, disc, low, pai, &qtdPonte);
        }
    }

    return qtdPonte > 0;
}

void Grafo::BPPonte(int v, bool visitado[], int *tempo, int disc[], int low[], int pai, int *qtdPonte) {
    (*tempo)++;
    disc[v-1] = *tempo;
    low[v-1] = *tempo;
    visitado[v-1] = true;
    int *vizinhos = vizinhosVertice(v);
    for (int i = 0; i < grauVertice(v); i++){
        int w = vizinhos[i];
        if (!visitado[w-1]){
            pai = v;
            BPPonte(w, visitado, tempo, disc, low, pai, qtdPonte);
            low[v-1] = min(low[v-1], low[w-1]);
            if (low[w-1] > disc[v-1]){
                (*qtdPonte)++;
            }
        } else if (w != pai){
            low[v-1] = min(low[v-1], disc[w-1]);
        }
    }
}

bool Grafo::auxVerticeArticulacao() {
    int ordem = getOrdem();
    int disc[ordem];
    int low[ordem];
    int pai[ordem];
    int tempo = 0;
    int qtdArticulacao = 0;

    for (int i = 0; i < ordem; i++) {
        disc[i] = -1;
        low[i] = -1;
        pai[i] = -1;
    }

    for (int i = 1; i <= ordem; i++) {
        if (disc[i-1] == -1) {
            BPArticulacao(i, &tempo, disc, low, pai, &qtdArticulacao);
        }
    }

    return qtdArticulacao > 0;
}

void Grafo::BPArticulacao(int v, int *tempo, int disc[], int low[], int pai[], int *qtdArticulacao) {
    (*tempo)++;
    disc[v-1] = *tempo;
    low[v-1] = *tempo;
    int filhos = 0;
    bool isArticulation = false;
    int *vizinhos = vizinhosVertice(v);

    for (int i = 0; i < grauVertice(v); i++) {
        int w = vizinhos[i];
        if (disc[w-1] == -1) { // w não foi visitado
            filhos++;
            pai[w-1] = v;
            BPArticulacao(w, tempo, disc, low, pai, qtdArticulacao);
            low[v-1] = min(low[v-1], low[w-1]);

            if (pai[v-1] == -1 && filhos > 1) {
                isArticulation = true;
            }
            if (pai[v-1] != -1 && low[w-1] >= disc[v-1]) {
                isArticulation = true;
            }
        } else if (w != pai[v-1]) {
            low[v-1] = min(low[v-1], disc[w-1]);
        }
    }

    if (isArticulation) {
        (*qtdArticulacao)++;
    }
}

// >>

// << Rodrigo >>

bool Grafo::eh_completo() 
{
    //para um grafo ser completo, cada vértice deve ter V-1 arestas. Então, se um deles não tiver v-1 arestas, o grafo não é completo
    for (int i = 1; i <= getOrdem(); i++) 
	{
        if (grauVertice(i) != getOrdem()-1)
            return false; 
    }

    return true;
}

void Grafo::temCiclo(int v, bool visitado[], int pai, bool *resultado)
{
    if(visitado[v-1] == false)
    {
        visitado[v-1] = true;
        int *vizinhos = vizinhosVertice(v);

        for (int i = 0; i < grauVertice(v); i++)
        {
            if(vizinhos[i] != pai)
                temCiclo(vizinhos[i], visitado, v, resultado);
        }
    }
    else
    {
        *resultado = true;
    }
}

bool Grafo::eh_arvore() 
{
	int arestas = 0;

    //contabiliza o total de arestas do grafo
    for (int i = 0; i < getOrdem(); i++)
    {
        arestas += grauVertice(i+1);
    }
	if(!getDirecionado()){
        arestas = arestas/2;
    }
    bool resultado = false;
    bool visitado[getOrdem()];
    for (bool &vis : visitado) vis = false;

    temCiclo(1, visitado, -1, &resultado);

    // Verifica se o grafo eh conexo, se o numero de arestas eh igual ao numero de vertices-1 e se tem ciclos
    if (BPConexo() == 1 && arestas == getOrdem() - 1 && !resultado)
	{
        return true;
    }

    return false;
}

// >>

// << Abner >>

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

    int ordem;
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
        int peso = 1;
        if (getVertices_ponderados())
        {
            file >> peso;
        }
        insere_vertice(i, peso);
    }
    if(getVertices_ponderados())
    {
        getline(file, line);
    }
    while (!file.eof())
    {
        int v, w;
        int peso = 1;
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

    for(int i = 1; i <= getOrdem(); i++)
    {
       if(grauVertice(i) > getGrau())
       {
           setGrau(grauVertice(i));
       }
    }


    file.close();
}

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


    for(int i = 1; i<=getOrdem(); i++)
    {
       int aux = grauVertice(i);
       int *vizinhos = vizinhosVertice(i);
       for(int j = 0; j < aux; j++)
       {
           file << i << " " << vizinhos[j] << " " << pesoAresta(i, vizinhos[j]) << '\n';
       }
    }

}

void Grafo::novo_grafo(string descFileName, string outFileName)
{
    ifstream file;
    string line;
    this->filename = descFileName;
    this->outFile  = outFileName;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        exit(2);
    }

    int grau;
    int ordem;
    bool direcionado;
    int componentes_conexas;
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

    file.close();


    setGrau(grau);
    setOrdem(ordem);
    setDirecionado(direcionado);

    setComponentes_conexas(componentes_conexas);
    setVertices_ponderados(vertices_ponderados);
    setArestas_ponderadas(arestas_ponderadas);
    

    if(componentes_conexas > ordem && componentes_conexas <= 0)
    {
        cout << "Componentes conexas invalido!" << endl;
        cout << "Encerrando programa..." << endl;
        exit(1);
    }

    setCompleto(completo);
    setBipartido(bipartido);
    setArvore(arvore);

    setAresta_Ponte(aresta_ponte);
    setVertice_de_Articulacao(vertice_de_articulacao);


    if(completo == 1)
    {
        if(grau != ordem - 1)
        {
            cout << "Grafo completo deve ter grau = ordem - 1!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(componentes_conexas != 1 )
        {
            cout << "Grafo completo deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(bipartido == 1 && ordem != 2 )
        {
            cout << "Grafo de ordem diferente de 2 não pode ser completo e bipartido ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(arvore == 1 && ordem > 2 )
        {
            cout << "Grafo de ordem > 2 não pode ser completo e arvore ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(aresta_ponte == 1 && ordem != 2 )
        {
            cout << "Grafo de ordem > 2 não pode ser completo e ter aresta ponte ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(vertice_de_articulacao == 1 && ordem !=2 )
        {
            cout << "Grafo de ordem > 2 não pode ser completo e ter vertice de articulacao ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }


        // --------------------------Criando Grafo Completo-------------------------- //

        inicializa();

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if(!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        
        
        //Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        //Criando Vertices ---------------------------
        for(int i = 1; i <= ordem; i++)
        {
            int _peso_vertice = 0;
            if(vertices_ponderados == 1)
            {
                _peso_vertice = rand();
                fileOut << _peso_vertice << " ";
            }
            insere_vertice(i, _peso_vertice);
        }
        fileOut << '\n';
        
        //Criando Arestas ----------------------------
        for(int i = 1; i <= ordem; i++)
        {
            for(int j = 1; j <= ordem; j++)
            {
                if(i != j)
                {
                    fileOut << i << " " << j;
                    int _peso_aresta = 0;
                    if(arestas_ponderadas == 1)
                    {
                        _peso_aresta = rand();
                        fileOut << " "<<_peso_aresta;
                    }

                    insere_aresta(i, j, _peso_aresta);

                    if(direcionado == 1)
                    {
                        fileOut << '\n';
                        fileOut << j << " " << i;
                        if(arestas_ponderadas == 1)
                        {
                            _peso_aresta = rand();
                            fileOut << " "<<_peso_aresta;
                        }

                        insere_aresta(j, i, _peso_aresta);
                    }
                    if(i != ordem || j != ordem - 1) fileOut << '\n';
                    
                }
            }
        }

        fileOut.close();
    }
    // Fim Grafo Completo -------------------------

    // Bipartido -----------------------

    if(bipartido == 1)
    {
        if(ordem < 2)
        {
            cout << "Grafo bipartido deve ter ordem >= 2!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }
        if(grau > ordem-1)
        {
            cout << "Grafo bipartido deve ter grau < ordem!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(componentes_conexas > ordem/2)
        {
            cout << "Grafo bipartido deve ter no maximo ordem/2 componentes conexas!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(arvore == 1 && componentes_conexas != 1)
        {
            cout << "Grafo bipartido e arvore deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        //----------------------------------Criando Grafo Bipartido Arvore----------------------------------

        if(arvore == 1)
        {
            inicializa();

            ofstream fileOut;
            fileOut.open(outFileName.c_str());
            if(!fileOut.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
                exit(2);
            }

            //Cabeçalho ----------------------------------
            fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

            //Criando Vertices ---------------------------

            for(int i = 1; i <= ordem; i++)
            {
                int _peso_vertice = 0;
                if(vertices_ponderados == 1)
                {
                    _peso_vertice = rand();
                    fileOut << _peso_vertice << " ";
                }
                insere_vertice(i, _peso_vertice);
            }
            fileOut << '\n';

            //Criando Arestas ----------------------------
            int peso_aresta = 0;
            for (int i = 0; i < grau - 1; i++)
                {
                    fileOut << 1 << " " << grau - i;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(1, grau - i, peso_aresta);
                    if(grau != ordem ) fileOut << '\n';
                }
                for(int i = grau; i<ordem; i++)
                {
                
                    fileOut << i << " " << i + 1;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(i, i + 1, peso_aresta);
                    if(i != ordem) fileOut << '\n';
                    
                }

        }
        // Fim Grafo Bipartido Arvore -------------------------

        // ----------------------------------Criando Grafo Bipartido ----------------------------------

        if(arvore == 0)
        {
            inicializa();

            ofstream fileOut;
            fileOut.open(outFileName.c_str());
            if(!fileOut.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
                exit(2);
            }

            //Cabeçalho ----------------------------------
            fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

            //Criando Vertices ---------------------------
            for(int i = 1; i<=ordem; i++)
            {
                int _peso_vertice = 0;
                if(vertices_ponderados == 1)
                {
                    _peso_vertice = rand();
                    fileOut << _peso_vertice << " ";
                }
                insere_vertice(i, _peso_vertice);
            }
            fileOut << '\n';

            //Criando Arestas ----------------------------
            int peso_aresta = 0;
            if(componentes_conexas >1)
            {
                int ordemLocal= ordem / componentes_conexas;
                int resto = ordem % componentes_conexas;
                if(grau >= ordemLocal-1)
                {
                    cout << "Os subgrafos conexos devem ter grau < ordem!" << endl;
                    cout << "Encerrando programa..." << endl;
                    exit(1);
                }

                for (int i = 0; i < componentes_conexas; i++)
                {
                    if(i == componentes_conexas-1)
                    {
                        ordemLocal += resto;
                    }

                    int vertice_1 = i * ordemLocal + 1;
                    for(int j = 0; j<grau-1; j++)
                    {
                        int vertice_2 = vertice_1 + j + 1;
                        fileOut << vertice_1 << " " << vertice_2;
                        if (arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " "<<peso_aresta;
                        }
                        insere_aresta(vertice_1, vertice_2, peso_aresta);
                        if(i != componentes_conexas-1 || j != grau-2) fileOut << '\n';                        
                    }
                    if(grau + 1 != ordemLocal)
                    {
                        for(int j = grau; j< ordemLocal; j++)
                        {
                            
                            fileOut << j << " " << j+1;
                            if (arestas_ponderadas == 1)
                            {
                                peso_aresta = rand();
                                fileOut << " "<<peso_aresta;
                            }
                            insere_aresta(j, j+1, peso_aresta);
                            if(i != componentes_conexas-1 || j +1 != ordemLocal) fileOut << '\n';                        
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < grau - 1; i++)
                {
                    fileOut << 1 << " " << grau - i;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(1, grau - i, peso_aresta);
                    if(grau != ordem ) fileOut << '\n';
                }
                for(int i = grau; i<ordem; i++)
                {
                
                    fileOut << i << " " << i + 1;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(i, i + 1, peso_aresta);
                    if(i != ordem) fileOut << '\n';
                    
                }
            }
        }
    }
    // Fim Grafo Bipartido -------------------------

    if(arvore == 1 && bipartido == 0)
    {
        if(componentes_conexas != 1)
        {
            cout << "Grafo arvore deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(grau > ordem-1)
        {
            cout << "Grafo arvore não pode ter grau > ordem - 1!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(aresta_ponte == 0 && ordem >= 2)
        {
            cout << "Grafo arvore de ordem >= 2 naturalmente tem uma aresta ponte!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(vertice_de_articulacao == 0 && ordem >= 3)
        {
            cout << "Grafo arvore de ordem >= 3 naturalmente tem um vertice de articulacao!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        inicializa();

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if(!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        //Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        //Criando Vertices ---------------------------
        for(int i = 1; i<=ordem; i++)
        {
            int _peso_vertice = 0;
            if(vertices_ponderados == 1)
            {
                _peso_vertice = rand();
                fileOut << _peso_vertice << " ";
            }
            insere_vertice(i, _peso_vertice);
        }
        fileOut << '\n';

        //Criando Arestas ----------------------------

        int peso_aresta = 0;
        for (int i = 0; i < grau - 1; i++)
        {
            fileOut << 1 << " " << grau - i;
            if (arestas_ponderadas == 1)
            {
                peso_aresta = rand();
                fileOut << " "<<peso_aresta;
            }
            insere_aresta(1, grau - i, peso_aresta);
            if(grau != ordem ) fileOut << '\n';
        }
        for(int i = grau; i<ordem; i++)
        {
        
            fileOut << i << " " << i + 1;
            if (arestas_ponderadas == 1)
            {
                peso_aresta = rand();
                fileOut << " "<<peso_aresta;
            }
            insere_aresta(i, i + 1, peso_aresta);
            if(i != ordem) fileOut << '\n';
            
        }    

    }
    // Fim Grafo Arvore -------------------------

    if(completo == 0 && arvore == 0 && bipartido == 0)
    {
        if(ordem <= 3)
        {
            cout << "Grafo grafo não possível!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if(aresta_ponte == 0 && vertice_de_articulacao == 1)
        {
            
            cout << "Grafo não pode ser criado!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        //--------------------------Criando Grafo Não Completo-------------------------- //

        inicializa();
        cout<< "Exportando Info" << endl;

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if(!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        //Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        //Criando Vertices ---------------------------
        for(int i = 1; i<=ordem; i++)
        {
            int _peso_vertice = 0;
            if(vertices_ponderados == 1)
            {
                _peso_vertice = rand();
                fileOut << _peso_vertice << " ";
            }
            insere_vertice(i, _peso_vertice);
        }
        fileOut << '\n';

        // Criando Arestas ----------------------------
        int peso_aresta = 0;

        // Quadrado base                        1 *-----* 4
        //                                        | \   |
        //                                        |   \ |
        //                                      2 *-----* 3
        //Não é complto, bipartido, arvore, não possúi aresta ponte nem vértice de articulação e conexidade 1

        fileOut << 1 << " " << 2;
        if(arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " "<<peso_aresta;
        }
        fileOut << '\n';

         fileOut << 1 << " " << 3;
        if(arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " "<<peso_aresta;
        }
        fileOut << '\n';
         fileOut << 1 << " " << 4;
        if(arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " "<<peso_aresta;
        }
        fileOut << '\n';
         fileOut << 2 << " " << 3;
        if(arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " "<<peso_aresta;
        }
        fileOut << '\n';

         fileOut << 3 << " " << 4;
        if(arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " "<<peso_aresta;
        }
        if(ordem > 4)
        {
            fileOut << '\n';
            if(aresta_ponte == 1)
            {
                if(vertice_de_articulacao == 1)
                {
                    for(int i = 4; i <= ordem; i++)
                    {
                        fileOut << i << " " << i + 1;
                        if(arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " "<<peso_aresta;
                        }
                        insere_aresta(i, i + 1, peso_aresta);
                        if(i + 1 != ordem) fileOut << '\n';
                    }
                }
                else
                {
                    for(int i = 4; i < ordem; i++)
                    {
                        fileOut << i + 1 << " " << i;
                        if(arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " "<<peso_aresta;
                        }
                        insere_aresta(i + 1, i, peso_aresta);
                        if(i + 1 != ordem) fileOut << '\n';

                        fileOut << i + 1 << " " << i - 1;
                        if(arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " "<<peso_aresta;
                        }
                        insere_aresta(i + 1, i - 1, peso_aresta);
                        fileOut << '\n';
                    }
                    fileOut << ordem << " " << ordem - 1;
                    if(peso_aresta == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                }
            }

            if(aresta_ponte == 0)
            {
                for(int i = 4; i <= ordem; i++)
                {
                    fileOut << i + 1 << " " << i;
                    if(arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(i + 1, i, peso_aresta);
                    if(i + 1 != ordem) fileOut << '\n';

                    fileOut << i + 1 << " " << i - 1;
                    if(arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " "<<peso_aresta;
                    }
                    insere_aresta(i + 1, i - 1, peso_aresta);
                    if(i + 1 != ordem) fileOut << '\n';
                }

            }

        } 
            
            
        



    }

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

// >>

// << ufjoao-init >>

bool Grafo::BipartidoFB(){
    int n = getOrdem(); 
    if (n <= 1) {
        return true;
    }

    for (int i = 0; i < (1 << n); ++i) { // Itera sobre todas as 2^n combinações de cores
        bool bipartido = true;
        bool cores[n] = {false};

        // Atribui cores aos vértices de acordo com 'i'
        for (int j = 0; j < n; ++j) {
            cores[j] = (i & (1 << j)) != 0;
        }
        for(int k =1; k <= n; k++){
            int *vizinhos =  vizinhosVertice(k);
            int grau = grauVertice(k);
            
            for(int l=0; l < grau; l++){
                int w = vizinhos[l];
                if (cores[k - 1] == cores[w - 1]) { 
                    bipartido = false; 
                    break; 
                }
            }
            if (!bipartido) {
                break;  
            }
        }
        if (bipartido) {
            return true; 
        }
    }


    return false;

}

// Função auxiliar para realizar a busca em profundidade
void Grafo::auxBPConexos(int v, bool* visitado) {
    visitado[v] = true;
    int* vizinhos = vizinhosVertice(v);  // Obtém os vizinhos do vértice
    int grau = grauVertice(v);  // Obtém o grau do vértice

    for (int i = 0; i < grau; i++) {
        int w = vizinhos[i];
        if (!visitado[w]) {
            auxBPConexos(w, visitado);  // Realiza DFS recursivamente nos vizinhos não visitados
        }
    }
}

// Função para contar componentes conexos
unsigned int Grafo::BPConexo() {
    int n = getOrdem();  // Ordem do grafo (número de vértices)
    if (n <= 0) {
        return 0;
    }

    bool visitado[n];  // Array de visitados (considerando vértices de 1 a n)
    for (int i = 1; i <= n; i++) {
        visitado[i] = false;  // Inicializa todos os vértices como não visitados
    }

    int componentesConexos = 0;

    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {  // Se o vértice não foi visitado
            componentesConexos++;  // Aumenta o número de componentes conexos
            auxBPConexos(i, visitado);  // Realiza DFS a partir do vértice não visitado
        }
    }

    return componentesConexos;
}

// >> ufjoao-final
