#include <iostream>
#include <locale.h>
#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese");

    if (argc < 4 || argc > 5)
    {
        cout << "Numero de argumentos invalido" << endl;
        cout << "Uso: " << argv[0] << " <operacao> <tipo_armazenamento> <arquivoIn> <arquivoOut>" << endl;
        cout << "Onde:" << endl;
        cout << "<operacao> -d para carregar grafo de um arquivo e imprimir a descricao" << endl;
        cout << "           -c para criar um novo grafo com as condicoes especificadas em arquivoIn e exporta-lo em arquivoOut" << endl;
        cout << "<tipo_armazenamento> -l para armazenamento como lista encadeada ou -m para matriz" << endl;
        cout << "<arquivo> o arquivo de entrada" << endl;
        cout << "<arquivoOut> o arquivo de saida utilizado apenas caso a operacao selecionada seja -c" << endl;
        exit(4);
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Programa iniciado " << endl;
    cout << "--------------------------------------------------" << endl;
    /*
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
     */
    string filename;
    string fileOut;
    string parametro1 = argv[1];
    string parametro2 = argv[2];
    cout << "Parametro 1: " << parametro1 << endl;
    cout << "Parametro 2: " << parametro2 << endl;
    filename = argv[3];
    filename = ".\\entradas\\" + filename;
    cout << "Arquivo de entrada: " << filename << endl;

    if (argc == 5)
    {
        fileOut = argv[4];
        cout << "Arquivo de saida: " << fileOut << endl;
    }

    Grafo *g;

    if (parametro1 == "-d")
    {
        if (parametro2 == "-l")
        {
            g = new grafo_lista;
        }
        else if (parametro2 == "-m")
        {
            g = new grafo_matriz;
        }
        g->carrega_grafo(argv[2], filename);
        g->exportDesc();
        cout << "--------------------------------------------------" << endl;
        cout << "Imprimindo grafo" << endl;
        cout << "--------------------------------------------------" << endl<<endl;
        g->novo_no(60);
        g->novo_no(66);
        g->novo_no(70);
        g->novo_no(80);
        g->novo_no(90);
        
        g->imprime();
        
        while (true)
        {
            cout << "--------------------------------------------------" << endl<<endl;
            cout << "SELECIONE UMA OPCAO:" << endl<<endl;
            cout << " 1 - Deletar No" << endl;
            cout << " 2 - Deletar Aresta" << endl;
            cout << " 3 - Novo No" << endl;
            cout << " 4 - Nova Aresta" << endl;
            cout << " 5 - Sair" << endl<<endl;
    
            cout << "OPCAO: ";
    
            int opcao = 0;
            cin >> opcao;

            if (opcao == 1)
            {
                cout << "Digite o ID do no (1 a " << g->getOrdem()<<"): "<<endl;
                int no;
                cin >> no;
                if(no < 1 || no > g->getOrdem())
                {
                    cout << "No invalido" << endl;
                    continue;
                }
                g->deleta_no(no);
                cout << endl;
                g->imprime();
                cout << endl;
            }
            else if (opcao == 2)
            {
                cout << "Indices dos nos disponiveis: 1 a "<< g->getOrdem()<<endl;
                cout << "Digite o No de origem: ";
                int v=0;
                cin >> v;
                cout << "Digite o No de destino: ";
                int w = 0;
                cin >> w;
                if(v < 1 || v > g->getOrdem() || w < 1 || w > g->getOrdem() || v == w)
                {
                    cout << "Par invalido!" << endl;
                    continue;
                }
                g->deleta_aresta(v, w);
                cout<<endl;
                g->imprime();
                cout<<endl;
            }
            else if (opcao == 3)
            {
                cout << "Digite o peso do novo no: ";
                int peso;
                cin >> peso;
                g->novo_no(peso);
                cout<<endl;
                g->imprime();
                cout<<endl;
            }
            else if (opcao == 4)
            {
                cout << "Indices dos nos disponiveis: 1 a "<< g->getOrdem()<<endl;
                cout << "Digite o No de origem: ";
                int v=0;
                cin >> v;
                cout << "Digite o No de destino: ";
                int w = 0;
                cin >> w;
                cout << "Digite o peso da aresta: ";
                int peso = 0;
                cin >> peso;
                if(v < 1 || v > g->getOrdem() || w < 1 || w > g->getOrdem() || v == w)
                {
                    cout << "Par invalido!" << endl;
                    continue;
                }
                g->nova_aresta(v, w, peso);
                cout<<endl;
                g->imprime();
                cout<<endl;
            }
            else if (opcao == 5)
            {
                break;
            }
            else
            {
                cout << "Opcao invalida" << endl;
                continue;
            }
            
        }
        




        cout << "Fim do programa" << endl<<endl<<endl;

        /*  //DEBUG

                cout << "Percorrendo grafo e imprimindo informa��es" << endl;

                cout << " -------Vertices-------"<<endl;
                // Exemplo de percurso por todo o grafo;
                //if(g->getDirecionado())
                //{
                //    cout << "OBS: A no��o de vizinhan�a de v�rtices � associada a grafos n�o orientado (GOLDBARG 2012, pg.10)" << endl<<endl;
                //}
                for(int i = 0; i < g->getOrdem(); i++)
                {
                    cout << "Vertice " << i+1 << " : "<<endl;
                    cout << "Peso: " << g->pesoVertice(i+1) << endl;
                    cout << "Grau: " << g->grauVertice(i+1) << endl;

                   // if(!g->getDirecionado())
                   // {
                        cout << "Vizinhos: ";
                        int *vizinhos = g->vizinhosVertice(i+1);
                        if(vizinhos != NULL)
                        {
                            for(int j = 0; j < g->grauVertice(i+1); j++)
                            {
                                cout << vizinhos[j] << " ";
                            }
                            cout << endl;
                        }
                        else
                        {
                            cout << "Nao possui vizinhos" << endl;
                        }

                   // }
                    cout << endl;
                }

                cout << " -------Arestas-------"<<endl;
                for(int i = 0; i < g->getOrdem(); i++)
                {
                    for(int j = 0; j < g->getOrdem(); j++)
                    {
                        if(i != j)
                        {
                            if(g->buscaAresta(i+1, j+1))
                            {
                                cout << "Aresta " << i+1 << " --- " << j+1 << " : Peso  = " << g->pesoAresta(i+1, j+1) << endl;
                            }
                        }
                    }
                }
                cout << "--------------------------------------------" << endl;


        */
    }
    else if (parametro1 == "-c")
    {
        if (parametro2 == "-l")
        {
            g = new grafo_lista;
        }
        else if (parametro2 == "-m")
        {
            g = new grafo_matriz;
        }
        g->novo_grafo(filename, fileOut);
        // g->imprime();
    }

    delete g;

    return 0;
}