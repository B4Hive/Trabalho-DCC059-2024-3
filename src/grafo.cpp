/**
 * @file grafo.cpp
 *
 * @brief Arquivo de implementação da classe Grafo que é pai das classes grafo_matriz e grafo_lista
 * @version 1.1.0
 * @date 2025-02-10
 */

#include "../include/grafo.h"
#include "../include/grafo_lista.h"
#include "../include/grafo_matriz.h"
using namespace std;

// << Getters and Setters >>

/**
 * @brief Altera o grau do grafo.
 * @details Esta função verifica se o grau inserido atende às condições. Caso seja maior ou igual a 0, altera o valor do grau. Senão, imprime uma mensagem informando que o valor é inválido.
 * @param grau é a variável com o valor que pretendemos inserir.
 */
// Função auxiliar para realizar a busca em profundidade
void Grafo::setGrau(int grau)
{
    if (grau < 0)
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

/**
 * @brief Altera o valor da propriedade Ordem
 *
 * @details Esta função faz uma breve verificação se a ordem passada por parâmetro é valida,
 * checando se ela é maior que zero, e em seguida sobrescreve o campo Ordem com o parâmetro passado.
 * @param ordem Número que será salvo como a Ordem do Grafo.
 */
void Grafo::setOrdem(int ordem)
{
    if (ordem < 0)
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

/**
 * @brief Altera se o grafo é direcionado
 *
 * @details Esta função realiza uma breve verifiação se o valor do parametro "direcionado" é valido.
 * Caso não seja, uma mensagem é exibida indicando que o valor é invalido e que o programa será encerrado.
 * Caso seja válido, o valor é atribuido a dpp[0].
 * @param direcionado Variável que com o valor esperado de 0 ou 1.
 */
void Grafo::setDirecionado(bool direcionado)
{
    if (direcionado != 0 && direcionado != 1)
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

/**
 * @brief Altera a quantidade de componentes conexas do grafo
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro componentes_conexas é valido.
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o valor ao info[2].
 * @param componentes_conexas variável inteira com valor esperado maior ou igual zero
 */
void Grafo::setComponentes_conexas(int componentes_conexas)
{
    if (componentes_conexas < 0)
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

/**
 * @brief Altera se os vertices do grafo são ponderados.
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro vertices_ponderados é valido.
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o valor ao dpp[1].
 * @param vertices_ponderados variável booleana de valor 0 ou 1
 */
void Grafo::setVertices_ponderados(bool vertices_ponderados)
{
    if (vertices_ponderados != 0 && vertices_ponderados != 1)
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

/**
 * @brief Altera se as arestas do grafo são ponderadas
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro arestas_ponderadas é valido.
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o valor ao dpp[2].
 * @param arestas_ponderadas variável booleana de valor 0 ou 1
 */
void Grafo::setArestas_ponderadas(bool arestas_ponderadas)
{
    if (arestas_ponderadas != 0 && arestas_ponderadas != 1)
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

/**
 * @brief Altera se o grafo é completo
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro completo é valido (0 ou 1).
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o dpp[3].
 * @param completo variável booleana de valor 0 ou 1
 */
void Grafo::setCompleto(bool completo)
{
    if (completo != 0 && completo != 1)
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

/**
 * @brief Altera se o grafo é bipartido
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro bipartido é valido (0 ou 1).
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o valor ao dpp[4].
 * @param bipartido variável booleana de valor 0 ou 1
 */
void Grafo::setBipartido(bool bipartido)
{
    if (bipartido != 0 && bipartido != 1)
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

/**
 * @brief Altera se o grafo é uma arvore
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro arvore é valido (0 ou 1).
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado e sai da função. Caso o valor seja
 * válido, atribui o valor ao dpp[5].
 * @param arvore variavel booleana contendo 0 ou 1
 */
void Grafo::setArvore(bool arvore)
{
    if (arvore != 0 && arvore != 1)
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

/**
 * @brief Altera se o grafo possúi aresta ponte.
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro aresta_ponte é valido (0 ou 1).
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado e sai da função. Caso o valor seja
 * válido, atribui o valor ao dpp[6].
 * @param aresta_ponte variável booleana de valor 0 ou 1
 */
void Grafo::setAresta_Ponte(bool aresta_ponte)
{
    if (aresta_ponte != 0 && aresta_ponte != 1)
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

/**
 * @brief Altera se o grafo possui vertice de articulação
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro vertice_de_articulacao é valido.
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado e sai da função.
 * Caso o valor seja válido, atribui o valor ao dpp[7].
 * @param componentes_conexas variável booleana de valor 0 ou 1
 */
void Grafo::setVertice_de_Articulacao(bool vertice_de_articulacao)
{
    if (vertice_de_articulacao != 0 && vertice_de_articulacao != 1)
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

/**
 * @brief Altera a quantidade de arestas do grafo
 *
 * @details Esta função realiza uma breve verificação para confirmar se o parametro tamanho é valido (maior ou igual a 0).
 * Caso não seja, imprime uma mensagem de que o valor é invalido e que o programa será encerrado. Caso o valor seja
 * válido, atribui o valor ao info[3].
 * @param componentes_conexas
 */
void Grafo::setTamanho(int tamanho)
{
    if (tamanho < 0)
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

/**
 * @brief Retorna o grau do grafo;
 * @return Retorna a informação na posição referente ao grau do Grafo.
 */
int Grafo::getGrau()
{
    return info[0];
}

/**
 * @brief Retorna a ordem do grafo;
 * @return Retorna a informação na posição referente à ordem do Grafo.
 */
int Grafo::getOrdem()
{
    return info[1];
}

/**
 * @brief Retorna se o grafo é direcionado;
 * @return Retorna a informação na posição referente se o Grafo é direcionado.
 */
bool Grafo::getDirecionado()
{
    return dpp[0];
}

/**
 * @brief Retorna quantas componentes conexas possui grafo
 * @return Retorna a informação na posição referente às componentes conexas do Grafo.
 */
int Grafo::getComponentes_conexas()
{
    info[2] = BPConexo();
    return info[2];
}

/**
 * @brief Retorna se os vertices do grafo são ponderados
 *
 * @details A função retorna uma variável booleana que indica se o vértice é ponderado ou não.
 *
 * @return Retorna valor booleano da dpp[1]
 */
bool Grafo::getVertices_ponderados()
{
    return dpp[1];
}

/**
 * @brief Retorna se as arestas do grafo são ponderadas
 *
 * @details Esta função retorna uma variável booleana que indica se a aresta é ponderada ou não.
 *
 * @return Retorna valor booleano da dpp[2]
 */
bool Grafo::getArestas_ponderadas()
{
    return dpp[2];
}

/**
 * @brief Retorna se o grafo é completo
 *
 * @details Esta função retorna um valor booleano indicando se o grafo é completo ou não.
 *
 * @return Retorna um valor booleano;
 */
bool Grafo::getCompleto()
{
    return eh_completo();
    // return dpp[3];
}

/**
 * @brief Retorna se o grafo é bipartido
 *
 * @details Esta função retorna um valor booleano que indica se o grafo é ou não bipartido.
 *
 * @return Retorna um valor booleano
 */
bool Grafo::getBipartido()
{
    dpp[4] = BipartidoFB();
    return dpp[4];
}

/**
 * @brief Retorna se o grafo é uma arvore
 *
 * @details Esta função chama a função eh_arvore e retorna um valor booleano.
 *
 * @return Retorna um valor booleano.
 */
bool Grafo::getArvore()
{
    return eh_arvore();
    // return dpp[5];
}

/**
 * @brief Retorna se o grafo possui aresta ponte.
 *
 * @details Esta função chama a função auxArestaPonte e retorna um valor booleano que indica se o grafo possui ou não uma aresta ponte.
 *
 * @return Retorna um valor booleano.
 */
bool Grafo::getAresta_Ponte()
{
    return auxArestaPonte();
}

/**
 * @brief Retorna se o grafo possui vertice de articulação
 *
 * @details Esta função chama a auxVerticeArticulacao e retorna um valor booleano que indica se o grafo possui ou não um vértice de articulação.
 *
 * @return Retorna um valor booleano.
 */
bool Grafo::getVertice_de_Articulacao()
{
    return auxVerticeArticulacao();
}

/**
 * @brief Retorna quantas arestas possui o grafo
 * @details Esta função retorna uma variavel inteira que indica o tamanho do grafo.
 * @return Retorna um valor inteiro.
 */
int Grafo::getTamanho()
{
    return info[3];
}

// >>

// << BHive >>

/**
 * @brief Verifica se o grafo possui alguma aresta de ponte.
 *
 * @details Esta função utiliza uma busca em profundidade (DFS) para determinar se o grafo
 * possui alguma aresta de ponte. Uma aresta de ponte é uma aresta que, se removida,
 * aumenta o número de componentes conectados do grafo.
 *
 * @return true Se o grafo possui pelo menos uma aresta de ponte.
 * @return false Se o grafo não possui nenhuma aresta de ponte.
 */
bool Grafo::auxArestaPonte()
{
    int disc[getOrdem()];
    int low[getOrdem()];
    int pai = -1;
    bool visitado[getOrdem()];
    int tempo = 0;
    int qtdPonte = 0;
    for (int i = 0; i < getOrdem(); i++)
    {
        disc[i] = -1;
        low[i] = -1;
        visitado[i] = false;
    }

    for (int i = 1; i <= getOrdem(); i++)
    {
        if (disc[i - 1] == -1)
        {
            BPPonte(i, visitado, &tempo, disc, low, pai, &qtdPonte);
        }
    }

    return qtdPonte > 0;
}

/**
 * @brief Função recursiva que encontra e conta as pontes em um grafo.
 *
 * @details  Esta função utiliza a busca em profundidade (BP) para encontrar todas as pontes em um grafo.
 * Uma ponte é uma aresta que, se removida, aumenta o número de componentes conectados do grafo.
 *
 * @param v O vértice atual sendo visitado.
 * @param visitado Array booleano que indica se um vértice foi visitado.
 * @param tempo Ponteiro para o tempo de descoberta dos vértices.
 * @param disc Array que armazena o tempo de descoberta de cada vértice.
 * @param low Array que armazena o menor tempo de descoberta acessível a partir de cada vértice.
 * @param pai O vértice pai do vértice atual na árvore de busca em profundidade.
 * @param qtdPonte Ponteiro para a quantidade de pontes encontradas.
 */
void Grafo::BPPonte(int v, bool visitado[], int *tempo, int disc[], int low[], int pai, int *qtdPonte)
{
    (*tempo)++;
    disc[v - 1] = *tempo;
    low[v - 1] = *tempo;
    visitado[v - 1] = true;
    int *vizinhos = vizinhosVertice(v);
    for (int i = 0; i < grauVertice(v); i++)
    {
        int w = vizinhos[i];
        if (!visitado[w - 1])
        {
            pai = v;
            BPPonte(w, visitado, tempo, disc, low, pai, qtdPonte);
            low[v - 1] = min(low[v - 1], low[w - 1]);
            if (low[w - 1] > disc[v - 1])
            {
                (*qtdPonte)++;
            }
        }
        else if (w != pai)
        {
            low[v - 1] = min(low[v - 1], disc[w - 1]);
        }
    }
    delete[] vizinhos;
}

/**
 * @brief Verifica se o grafo possui vértices de articulação.
 *
 * @details Essa função verifica se o grafo possui vértices de articulação utilizando uma
 * busca em profundidade modificada. Um vértice de articulação é um vértice que,
 * se removido, aumenta o número de componentes conectados do grafo.
 *
 * @return true se o grafo possui vértices de articulação, false caso contrário.
 */
bool Grafo::auxVerticeArticulacao()
{
    int ordem = getOrdem();
    int disc[ordem];
    int low[ordem];
    int pai[ordem];
    int tempo = 0;
    int qtdArticulacao = 0;

    for (int i = 0; i < ordem; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        pai[i] = -1;
    }

    for (int i = 1; i <= ordem; i++)
    {
        if (disc[i - 1] == -1)
        {
            BPArticulacao(i, &tempo, disc, low, pai, &qtdArticulacao);
        }
    }

    return qtdArticulacao > 0;
}

/**
 * @brief Realiza a busca em profundidade para encontrar pontos de articulação em um grafo.
 *
 * @details Esta função implementa o algoritmo de busca em profundidade (BP) para identificar pontos de articulação
 * em um grafo. Um ponto de articulação é um vértice que, se removido, aumenta o número de componentes
 * conectados do grafo.
 *
 * @param v O vértice atual sendo visitado.
 * @param tempo Ponteiro para o tempo atual da busca em profundidade.
 * @param disc Vetor que armazena o tempo de descoberta de cada vértice.
 * @param low Vetor que armazena o menor tempo de descoberta acessível a partir do vértice.
 * @param pai Vetor que armazena o pai de cada vértice na árvore de busca em profundidade.
 * @param qtdArticulacao Ponteiro para a quantidade de pontos de articulação encontrados.
 */
void Grafo::BPArticulacao(int v, int *tempo, int disc[], int low[], int pai[], int *qtdArticulacao)
{
    (*tempo)++;
    disc[v - 1] = *tempo;
    low[v - 1] = *tempo;
    int filhos = 0;
    bool isArticulation = false;
    int *vizinhos = vizinhosVertice(v);

    for (int i = 0; i < grauVertice(v); i++)
    {
        int w = vizinhos[i];
        if (disc[w - 1] == -1)
        { // w não foi visitado
            filhos++;
            pai[w - 1] = v;
            BPArticulacao(w, tempo, disc, low, pai, qtdArticulacao);
            low[v - 1] = min(low[v - 1], low[w - 1]);

            if (pai[v - 1] == -1 && filhos > 1)
            {
                isArticulation = true;
            }
            if (pai[v - 1] != -1 && low[w - 1] >= disc[v - 1])
            {
                isArticulation = true;
            }
        }
        else if (w != pai[v - 1])
        {
            low[v - 1] = min(low[v - 1], disc[w - 1]);
        }
    }

    if (isArticulation)
    {
        (*qtdArticulacao)++;
    }
    delete[] vizinhos;
}

/**
 * @brief Calcula o caminho mínimo entre dois vértices usando o algoritmo de Floyd-Warshall.
 *
 * @details Esta função calcula o caminho mínimo entre dois vértices em um grafo, utilizando o algoritmo de Floyd-Warshall.
 * Ela também trata ciclos negativos no grafo, ajustando os pesos das arestas conforme necessário.
 *
 * @param u Vértice de origem.
 * @param v Vértice de destino.
 *
 * @note A função imprime o caminho mínimo e a distância entre os vértices u e v.
 *       Se não houver caminho entre os vértices, uma mensagem apropriada será exibida.
 */
void Grafo::caminhoMinimoFloyd(int u, int v)
{
    // inicializando variáveis
    const double INF = INFINITY;
    int lower = 0;
    int n = getOrdem();
    double **dist = new double *[n];
    int **next = new int *[n];
    for (int i = 0; i < n; i++) {
        dist[i] = new double[n];
        next[i] = new int[n];
    }
    // inicializando matriz de distâncias e matriz de próximos
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i - 1][j - 1] = 0;
                next[i - 1][j - 1] = 0;
            }
            else if (buscaAresta(i, j)) {
                double peso = pesoAresta(i, j);
                if (peso < lower) { // tratamento pra ciclos negativos parte 1
                    lower = peso;
                }
                dist[i - 1][j - 1] = peso;
                next[i - 1][j - 1] = j;
            }
            else {
                dist[i - 1][j - 1] = INF;
                next[i - 1][j - 1] = -1;
            }
        }
    }
    // tratamento pra ciclos negativos parte 2
    if (lower < 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i - 1][j - 1] != INF) {
                    dist[i - 1][j - 1] += (abs(lower) + 1);
                }
            }
        }
    }
    //algoritmo de Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i-1][k-1] < INF && dist[k-1][j-1] < INF) {
                    if (dist[i-1][j-1] > dist[i-1][k-1] + dist[k-1][j-1]) {
                        dist[i-1][j-1] = dist[i-1][k-1] + dist[k-1][j-1];
                        next[i-1][j-1] = next[i-1][k-1];
                    }
                }
            }
        }
    }
    // tratamento pra ciclos negativos parte 3
    if (lower < 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i - 1][j - 1] != INF) {
                    dist[i - 1][j - 1] -= (abs(lower) + 1);
                }
            }
        }
    }
    // imprimindo caminho
    if (u <= 0 || v <= 0 || u > n || v > n){
        double higher = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (dist[i][j] > higher && dist[i][j] < INF){
                    higher = dist[i][j];
                    u = i + 1;
                    v = j + 1;
                }
            }
        cout << "Maior menor caminho: (" << u << ", " << v << ") = " << higher << endl;
    }
    else {
        cout << "Caminho de " << u << " para " << v << ": ";
        if (next[u-1][v-1] == -1) {
            cout << "Nao ha caminho de " << u << " para " << v << endl;
        }
        else {
            cout << "Distancia: " << dist[u - 1][v - 1] << endl;
            cout << u;
            while (u != v) {
                u = next[u - 1][v - 1];
                cout << " -> " << u;
            }
            cout << endl;
        }
    }
    
    // liberando memória
    for (int i = 0; i < n; i++) {
        delete[] dist[i];
        delete[] next[i];
    }
    delete[] dist;
    delete[] next;
}

// >>

// << Rodrigo >>

/**
 * @brief Função para verificar se o grafo é Completo
 * @details A função verifica se o grafo é completo percorrendo todos os vértices e validando o número de arestas ligados a cada um.
 * @return Retorna um booleano False, caso o grau de algum vértice seja diferente da ordem do grafo -1, ou True, caso a repetição chegue ao fim e garanta que todos os vértices atendem à exigência.
 */
bool Grafo::eh_completo()
{
    // para um grafo ser completo, cada vértice deve ter V-1 arestas. Então, se um deles não tiver v-1 arestas, o grafo não é completo
    for (int i = 1; i <= getOrdem(); i++)
    {
        if (grauVertice(i) != getOrdem() - 1)
            return false;
    }

    return true;
}

/**
 * @brief Função auxiliar para verificar se o grafo é uma Árvore
 * @details A verificação dos ciclos consiste em armazenar quais vértices foram visitados em um vetor e retorna true caso ele encontre um vértice que já tenha sido visitado.
 * @param v Vértice inicial de onde começa a busca.
 * @param visitado Vetor de booleanos que mantém um controle de quais vértices já foram visitados ou não.
 * @param pai Armazena o ID do vértice pai do vértice atual.
 * @param resultado Ponteiro pra variável que armazena se foi detectado algum ciclo.
 */
void Grafo::temCiclo(int v, bool visitado[], int pai, bool *resultado)
{
    int *vizinhos = vizinhosVertice(v);
    if (visitado[v - 1] == false)
    {
        visitado[v - 1] = true;

        for (int i = 0; i < grauVertice(v); i++)
        {
            if (vizinhos[i] != pai)
                temCiclo(vizinhos[i], visitado, v, resultado);
        }
    }
    else
    {
        *resultado = true;
    }
    delete[] vizinhos;
}

/**
 * @brief Função para verificar se o grafo é uma Árvore
 * @details A função verifica se o grafo é uma árvore ao validar três condições específicas: se o grafo é conexo, se o total de arestas é igual ao total de vértices -1 e não tem ciclos.
A verificação dos ciclos é feita por uma função auxiliar temCiclo()
O total de arestas é verificado por uma repetição que soma os graus de cada vértice em uma variável.
E, por fim, a verificação da conexidade é feita a partir da função BPConexo, que retorna 1, caso seja conexo.
 * @return Retorna um booleano True, caso as três condições sejam atendidas e retorna False, caso a função chegue ao final.
 */
bool Grafo::eh_arvore()
{
    int arestas = 0;

    // contabiliza o total de arestas do grafo
    for (int i = 0; i < getOrdem(); i++)
    {
        arestas += grauVertice(i + 1);
    }
    if (!getDirecionado())
    {
        arestas = arestas / 2;
    }
    bool resultado = false;
    bool visitado[getOrdem()];
    for (bool &vis : visitado)
        vis = false;

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

/**
 * @brief Carrega as informações de um grafo a partir de um arquivo .txt
 * @details
 * @param tipo Define o tipo da estrutura de armazenamento do grafo.
 * @param dataFileName Nome do arquivo a ser lido.
 */
void Grafo::carrega_grafo(char *tipo, string dataFileName)
{
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
    if (getVertices_ponderados())
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

    for (int i = 1; i <= getOrdem(); i++)
    {
        if (grauVertice(i) > getGrau())
        {
            setGrau(grauVertice(i));
        }
    }

    file.close();
}

/**
 * @brief Imprime as informaçãoes do grafo na tela
 * @details Esta função através de verificações básicas e de uso de funções get, como getOrdem(), getVertices_ponderados(), getDirecionado(), etc. Recebe e imprime as informações do Grafo na tela.
 */
void Grafo::exportInfo()
{
    cout << "Exportando Info" << endl;
    ofstream file;
    file.open("Grafo_infoOut.txt", ofstream::out);
    if (!file.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }
    file << getOrdem() << " " << getDirecionado() << " " << getVertices_ponderados() << " " << getArestas_ponderadas() << '\n';
    if (getVertices_ponderados())
    {
        for (int i = 1; i <= getOrdem(); i++)
        {
            file << pesoVertice(i) << " ";
        }
        file << '\n';
    }

    for (int i = 1; i <= getOrdem(); i++)
    {
        int aux = grauVertice(i);
        int *vizinhos = vizinhosVertice(i);
        for (int j = 0; j < aux; j++)
        {
            file << i << " " << vizinhos[j] << " " << pesoAresta(i, vizinhos[j]) << '\n';
        }
        delete[] vizinhos;
    }
}

/**
 * @brief Cria um novo grafo a partir das informações lidas
 * @details Cria um grafo com base nas especificações fornecidas em um arquivo de entrada. O grafo pode ser de diferentes tipos, incluindo completo, bipartido, árvore, ou um grafo genérico.
 * O código lê as propriedades do grafo, como grau, ordem, direção, ponderação de vértices e arestas, e valida as condições para cada tipo de grafo.
 * Dependendo das propriedades, o código gera o grafo correspondente, inserindo vértices e arestas no arquivo de saída.
 * Se as condições para a criação do grafo não forem atendidas, o programa encerra com mensagens de erro apropriadas.
 * @param descFileName Arquivo contendo a descrição do grafo
 * @param outFileName arquivo de saída para as informações do grafo
 */
void Grafo::novo_grafo(string descFileName, string outFileName)
{
    ifstream file;
    string line;
    this->filename = descFileName;
    this->outFile = outFileName;
    file.open(filename.c_str());
    if (!file.is_open())
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

    file >> grau;
    getline(file, line);
    file >> ordem;
    getline(file, line);
    file >> direcionado;
    getline(file, line);
    file >> componentes_conexas;
    getline(file, line);
    file >> vertices_ponderados;
    getline(file, line);
    file >> arestas_ponderadas;
    getline(file, line);
    file >> completo;
    getline(file, line);
    file >> bipartido;
    getline(file, line);
    file >> arvore;
    getline(file, line);
    file >> aresta_ponte;
    getline(file, line);
    file >> vertice_de_articulacao;
    getline(file, line);

    file.close();

    setGrau(grau);
    setOrdem(ordem);
    setDirecionado(direcionado);

    setComponentes_conexas(componentes_conexas);
    setVertices_ponderados(vertices_ponderados);
    setArestas_ponderadas(arestas_ponderadas);

    if (componentes_conexas > ordem && componentes_conexas <= 0)
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

    if (completo == 1)
    {
        if (grau != ordem - 1)
        {
            cout << "Grafo completo deve ter grau = ordem - 1!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (componentes_conexas != 1)
        {
            cout << "Grafo completo deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (bipartido == 1 && ordem != 2)
        {
            cout << "Grafo de ordem diferente de 2 não pode ser completo e bipartido ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (arvore == 1 && ordem > 2)
        {
            cout << "Grafo de ordem > 2 não pode ser completo e arvore ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (aresta_ponte == 1 && ordem != 2)
        {
            cout << "Grafo de ordem > 2 não pode ser completo e ter aresta ponte ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (vertice_de_articulacao == 1 && ordem != 2)
        {
            cout << "Grafo de ordem > 2 não pode ser completo e ter vertice de articulacao ao mesmo tempo!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        // --------------------------Criando Grafo Completo-------------------------- //

        inicializa();

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if (!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        // Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        // Criando Vertices ---------------------------
        for (int i = 1; i <= ordem; i++)
        {
            int _peso_vertice = 0;
            if (vertices_ponderados == 1)
            {
                _peso_vertice = rand();
                fileOut << _peso_vertice << " ";
            }
            insere_vertice(i, _peso_vertice);
        }
        fileOut << '\n';

        // Criando Arestas ----------------------------
        for (int i = 1; i <= ordem; i++)
        {
            for (int j = 1; j <= ordem; j++)
            {
                if (i != j)
                {
                    fileOut << i << " " << j;
                    int _peso_aresta = 0;
                    if (arestas_ponderadas == 1)
                    {
                        _peso_aresta = rand();
                        fileOut << " " << _peso_aresta;
                    }

                    insere_aresta(i, j, _peso_aresta);

                    if (direcionado == 1)
                    {
                        fileOut << '\n';
                        fileOut << j << " " << i;
                        if (arestas_ponderadas == 1)
                        {
                            _peso_aresta = rand();
                            fileOut << " " << _peso_aresta;
                        }

                        insere_aresta(j, i, _peso_aresta);
                    }
                    if (i != ordem || j != ordem - 1)
                        fileOut << '\n';
                }
            }
        }

        fileOut.close();
    }
    // Fim Grafo Completo -------------------------

    // Bipartido -----------------------

    if (bipartido == 1)
    {
        if (ordem < 2)
        {
            cout << "Grafo bipartido deve ter ordem >= 2!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }
        if (grau > ordem - 1)
        {
            cout << "Grafo bipartido deve ter grau < ordem!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (componentes_conexas > ordem / 2)
        {
            cout << "Grafo bipartido deve ter no maximo ordem/2 componentes conexas!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (arvore == 1 && componentes_conexas != 1)
        {
            cout << "Grafo bipartido e arvore deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        //----------------------------------Criando Grafo Bipartido Arvore----------------------------------

        if (arvore == 1)
        {
            inicializa();

            ofstream fileOut;
            fileOut.open(outFileName.c_str());
            if (!fileOut.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
                exit(2);
            }

            // Cabeçalho ----------------------------------
            fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

            // Criando Vertices ---------------------------

            for (int i = 1; i <= ordem; i++)
            {
                int _peso_vertice = 0;
                if (vertices_ponderados == 1)
                {
                    _peso_vertice = rand();
                    fileOut << _peso_vertice << " ";
                }
                insere_vertice(i, _peso_vertice);
            }
            fileOut << '\n';

            // Criando Arestas ----------------------------
            int peso_aresta = 0;
            for (int i = 0; i < grau - 1; i++)
            {
                fileOut << 1 << " " << grau - i;
                if (arestas_ponderadas == 1)
                {
                    peso_aresta = rand();
                    fileOut << " " << peso_aresta;
                }
                insere_aresta(1, grau - i, peso_aresta);
                if (grau != ordem)
                    fileOut << '\n';
            }
            for (int i = grau; i < ordem; i++)
            {

                fileOut << i << " " << i + 1;
                if (arestas_ponderadas == 1)
                {
                    peso_aresta = rand();
                    fileOut << " " << peso_aresta;
                }
                insere_aresta(i, i + 1, peso_aresta);
                if (i != ordem)
                    fileOut << '\n';
            }
        }
        // Fim Grafo Bipartido Arvore -------------------------

        // ----------------------------------Criando Grafo Bipartido ----------------------------------

        if (arvore == 0)
        {
            inicializa();

            ofstream fileOut;
            fileOut.open(outFileName.c_str());
            if (!fileOut.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
                exit(2);
            }

            // Cabeçalho ----------------------------------
            fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

            // Criando Vertices ---------------------------
            for (int i = 1; i <= ordem; i++)
            {
                int _peso_vertice = 0;
                if (vertices_ponderados == 1)
                {
                    _peso_vertice = rand();
                    fileOut << _peso_vertice << " ";
                }
                insere_vertice(i, _peso_vertice);
            }
            fileOut << '\n';

            // Criando Arestas ----------------------------
            int peso_aresta = 0;
            if (componentes_conexas > 1)
            {
                int ordemLocal = ordem / componentes_conexas;
                int resto = ordem % componentes_conexas;
                if (grau >= ordemLocal - 1)
                {
                    cout << "Os subgrafos conexos devem ter grau < ordem!" << endl;
                    cout << "Encerrando programa..." << endl;
                    exit(1);
                }

                for (int i = 0; i < componentes_conexas; i++)
                {
                    if (i == componentes_conexas - 1)
                    {
                        ordemLocal += resto;
                    }

                    int vertice_1 = i * ordemLocal + 1;
                    for (int j = 0; j < grau - 1; j++)
                    {
                        int vertice_2 = vertice_1 + j + 1;
                        fileOut << vertice_1 << " " << vertice_2;
                        if (arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " " << peso_aresta;
                        }
                        insere_aresta(vertice_1, vertice_2, peso_aresta);
                        if (i != componentes_conexas - 1 || j != grau - 2)
                            fileOut << '\n';
                    }
                    if (grau + 1 != ordemLocal)
                    {
                        for (int j = grau; j < ordemLocal; j++)
                        {

                            fileOut << j << " " << j + 1;
                            if (arestas_ponderadas == 1)
                            {
                                peso_aresta = rand();
                                fileOut << " " << peso_aresta;
                            }
                            insere_aresta(j, j + 1, peso_aresta);
                            if (i != componentes_conexas - 1 || j + 1 != ordemLocal)
                                fileOut << '\n';
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
                        fileOut << " " << peso_aresta;
                    }
                    insere_aresta(1, grau - i, peso_aresta);
                    if (grau != ordem)
                        fileOut << '\n';
                }
                for (int i = grau; i < ordem; i++)
                {

                    fileOut << i << " " << i + 1;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " " << peso_aresta;
                    }
                    insere_aresta(i, i + 1, peso_aresta);
                    if (i != ordem)
                        fileOut << '\n';
                }
            }
        }
    }
    // Fim Grafo Bipartido -------------------------

    if (arvore == 1 && bipartido == 0)
    {
        if (componentes_conexas != 1)
        {
            cout << "Grafo arvore deve ter apenas uma componente conexa!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (grau > ordem - 1)
        {
            cout << "Grafo arvore não pode ter grau > ordem - 1!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (aresta_ponte == 0 && ordem >= 2)
        {
            cout << "Grafo arvore de ordem >= 2 naturalmente tem uma aresta ponte!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (vertice_de_articulacao == 0 && ordem >= 3)
        {
            cout << "Grafo arvore de ordem >= 3 naturalmente tem um vertice de articulacao!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        inicializa();

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if (!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        // Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        // Criando Vertices ---------------------------
        for (int i = 1; i <= ordem; i++)
        {
            int _peso_vertice = 0;
            if (vertices_ponderados == 1)
            {
                _peso_vertice = rand();
                fileOut << _peso_vertice << " ";
            }
            insere_vertice(i, _peso_vertice);
        }
        fileOut << '\n';

        // Criando Arestas ----------------------------

        int peso_aresta = 0;
        for (int i = 0; i < grau - 1; i++)
        {
            fileOut << 1 << " " << grau - i;
            if (arestas_ponderadas == 1)
            {
                peso_aresta = rand();
                fileOut << " " << peso_aresta;
            }
            insere_aresta(1, grau - i, peso_aresta);
            if (grau != ordem)
                fileOut << '\n';
        }
        for (int i = grau; i < ordem; i++)
        {

            fileOut << i << " " << i + 1;
            if (arestas_ponderadas == 1)
            {
                peso_aresta = rand();
                fileOut << " " << peso_aresta;
            }
            insere_aresta(i, i + 1, peso_aresta);
            if (i != ordem)
                fileOut << '\n';
        }
    }
    // Fim Grafo Arvore -------------------------

    if (completo == 0 && arvore == 0 && bipartido == 0)
    {
        if (ordem <= 3)
        {
            cout << "Grafo grafo não possível!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        if (aresta_ponte == 0 && vertice_de_articulacao == 1)
        {

            cout << "Grafo não pode ser criado!" << endl;
            cout << "Encerrando programa..." << endl;
            exit(1);
        }

        //--------------------------Criando Grafo Não Completo-------------------------- //

        inicializa();
        cout << "Exportando Info" << endl;

        ofstream fileOut;
        fileOut.open(outFileName.c_str());
        if (!fileOut.is_open())
        {
            cout << "Erro ao abrir arquivo" << endl;
            exit(2);
        }

        // Cabeçalho ----------------------------------
        fileOut << ordem << " " << direcionado << " " << vertices_ponderados << " " << arestas_ponderadas << '\n';

        // Criando Vertices ---------------------------
        for (int i = 1; i <= ordem; i++)
        {
            int _peso_vertice = 0;
            if (vertices_ponderados == 1)
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
        // Não é complto, bipartido, arvore, não possúi aresta ponte nem vértice de articulação e conexidade 1

        fileOut << 1 << " " << 2;
        if (arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " " << peso_aresta;
        }
        fileOut << '\n';

        fileOut << 1 << " " << 3;
        if (arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " " << peso_aresta;
        }
        fileOut << '\n';
        fileOut << 1 << " " << 4;
        if (arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " " << peso_aresta;
        }
        fileOut << '\n';
        fileOut << 2 << " " << 3;
        if (arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " " << peso_aresta;
        }
        fileOut << '\n';

        fileOut << 3 << " " << 4;
        if (arestas_ponderadas == 1)
        {
            peso_aresta = rand();
            fileOut << " " << peso_aresta;
        }
        if (ordem > 4)
        {
            fileOut << '\n';
            if (aresta_ponte == 1)
            {
                if (vertice_de_articulacao == 1)
                {
                    for (int i = 4; i <= ordem; i++)
                    {
                        fileOut << i << " " << i + 1;
                        if (arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " " << peso_aresta;
                        }
                        insere_aresta(i, i + 1, peso_aresta);
                        if (i + 1 != ordem)
                            fileOut << '\n';
                    }
                }
                else
                {
                    for (int i = 4; i < ordem; i++)
                    {
                        fileOut << i + 1 << " " << i;
                        if (arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " " << peso_aresta;
                        }
                        insere_aresta(i + 1, i, peso_aresta);
                        if (i + 1 != ordem)
                            fileOut << '\n';

                        fileOut << i + 1 << " " << i - 1;
                        if (arestas_ponderadas == 1)
                        {
                            peso_aresta = rand();
                            fileOut << " " << peso_aresta;
                        }
                        insere_aresta(i + 1, i - 1, peso_aresta);
                        fileOut << '\n';
                    }
                    fileOut << ordem << " " << ordem - 1;
                    if (peso_aresta == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " " << peso_aresta;
                    }
                }
            }

            if (aresta_ponte == 0)
            {
                for (int i = 4; i <= ordem; i++)
                {
                    fileOut << i + 1 << " " << i;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " " << peso_aresta;
                    }
                    insere_aresta(i + 1, i, peso_aresta);
                    if (i + 1 != ordem)
                        fileOut << '\n';

                    fileOut << i + 1 << " " << i - 1;
                    if (arestas_ponderadas == 1)
                    {
                        peso_aresta = rand();
                        fileOut << " " << peso_aresta;
                    }
                    insere_aresta(i + 1, i - 1, peso_aresta);
                    if (i + 1 != ordem)
                        fileOut << '\n';
                }
            }
        }
    }
}

/**
 * @brief Cria um arquivo com a informações do grafo;
 * @details Através de verificação de funções booleanas e inteiras de retorno preenche as informações do Grafo na tela.
 */
void Grafo::exportDesc()
{
    cout << "Grau: " << getGrau() << endl;
    cout << "Ordem: " << getOrdem() << endl;
    cout << "Direcionado: ";
    if (getDirecionado())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Componentes conexas: " << getComponentes_conexas() << endl;
    cout << "Vertices ponderados: ";
    if (getVertices_ponderados())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Arestas ponderadas: ";
    if (getArestas_ponderadas())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Completo: ";
    if (getCompleto())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Bipartido: ";
    if (getBipartido())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Arvore: ";
    if (getArvore())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Aresta Ponte: ";
    if (getAresta_Ponte())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    cout << "Vertice de Articulacao: ";
    if (getVertice_de_Articulacao())
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }

    // Temp test

    // caminhoMinimoFloyd(1, getOrdem());
}

// >>

// << ufjoao-init >>

/**
 * @brief Função para verificar se o grafo é Bipartido
 * @details Usa um algorítimo de força bruta baseado em designar uma cor para cada vértice e garantir ao menos uma solução onde nenhum vértice tenha arestas em vértices de mesma cor.
 * @return Retorna um Booleano True ou False referente ao grafo ser ou não Bipartido
 */
bool Grafo::BipartidoFB()
{
    int n = getOrdem();
    if (n <= 1)
    {
        return true;
    }

    for (int i = 0; i < (1 << n); ++i)
    { // Itera sobre todas as 2^n combinações de cores
        bool bipartido = true;
        bool cores[n] = {false};

        // Atribui cores aos vértices de acordo com 'i'
        for (int j = 0; j < n; ++j)
        {
            cores[j] = (i & (1 << j)) != 0;
        }
        for (int k = 1; k <= n; k++)
        {
            int *vizinhos = vizinhosVertice(k);
            int grau = grauVertice(k);

            for (int l = 0; l < grau; l++)
            {
                int w = vizinhos[l];
                if (cores[k - 1] == cores[w - 1])
                {
                    bipartido = false;
                    break;
                }
            }
            delete[] vizinhos;
            if (!bipartido)
            {
                break;
            }
        }
        if (bipartido)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Função auxiliar para realizar a Busca em profundidade para a função BPConexo()
 * @details Usa um algorítimo de Busca em profundidade para percorrer as arestas de cada vértice e marcar um vetor de booleanos que representam cada vértice alcançado pela busca na atual chamada da função.
 * @param v O vértice de início da Busca em profundidade
 * @param visitado Vetor de booleanos que representam os vértices que já foram visitados ou não
 */
// Função auxiliar para realizar a busca em profundidade
void Grafo::auxBPConexos(int v, bool *visitado)
{
    visitado[v] = true;
    int *vizinhos = vizinhosVertice(v); // Obtém os vizinhos do vértice
    int grau = grauVertice(v);          // Obtém o grau do vértice

    for (int i = 0; i < grau; i++)
    {
        int w = vizinhos[i];
        if (!visitado[w])
        {
            auxBPConexos(w, visitado); // Realiza DFS recursivamente nos vizinhos não visitados
        }
    }
    delete[] vizinhos;
}

/**
 * @brief Função usada para calcular e retornar a quantidade de componentes conexas de um grafo
 * @details Usa um loop que passa em todos os vértices para verificar se todas as posições do vetor visitados[n] já foi preenchida aumentando em 1 a quantidade toda vez que a função itera após a chamada da função auxiliar auxBPConexos().
 * @return Número de componentes conexas que esse grafo possui
 */
// Função para contar componentes conexos
unsigned int Grafo::BPConexo()
{
    int n = getOrdem(); // Ordem do grafo (número de vértices)
    if (n <= 0)
    {
        return 0;
    }

    bool visitado[n]; // Array de visitados (considerando vértices de 1 a n)
    for (int i = 1; i <= n; i++)
    {
        visitado[i] = false; // Inicializa todos os vértices como não visitados
    }

    int componentesConexos = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visitado[i])
        {                              // Se o vértice não foi visitado
            componentesConexos++;      // Aumenta o número de componentes conexos
            auxBPConexos(i, visitado); // Realiza DFS a partir do vértice não visitado
        }
    }

    return componentesConexos;
}

// >> ufjoao-final