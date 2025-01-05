#include <iostream>
#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 4 || argc > 5){
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
    cout << "Programa iniciado " << endl;
    /*
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
     */
    cout << endl;
    string filename;
    string parametro1 = argv[1];
    string parametro2 = argv[2];
    cout << "Parametro 1: " << parametro1 << endl;
    cout << "Parametro 2: " << parametro2 << endl;
    filename = argv[3];
    cout << "Arquivo de entrada: " << filename << endl << endl;

    Grafo *g;

    if(parametro1 == "-d")
    {
        if(parametro2 == "-l") {
            g = new grafo_lista;
        }
        else if(parametro2 == "-m") {
            g = new grafo_matriz; 
        }
        g->carrega_grafo(argv[2], filename);
        g->exportDesc();
        g->imprime();

        // Exemplo de percurso por todo o grafo;
        for(int i = 0; i < g->getOrdem(); i++)
        {
            cout << "Vertice " << i+1 << " : "<<endl;
            cout << "Peso: " << g->pesoVertice(i+1) << endl;
            cout << "Grau: " << g->grauVertice(i+1) << endl;
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
            cout << endl;
        }

    }
    else if(parametro1 == "-c") 
    {
        if(parametro2 == "-l") {
            g = new grafo_lista;
        }
        else if(parametro2 == "-m") {
            g = new grafo_matriz; 
        }
        g->novo_grafo(argv[1], filename);
        g->exportInfo();
        g->imprime();
    }
    
    delete g;
    
    return 0;
}