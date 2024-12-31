#include <iostream>
#include "grafo.h"
#include "grafo_lista.h"
#include "grafo_matriz.h"
using namespace std;

int main(int argc, char *argv[])
{

    cout << "Programa iniciado " << endl;
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
    cout << endl;
    string filename;
    string parametro1 = argv[1];
    string parametro2 = argv[2];
    cout << "Parametro1: " << parametro1 << endl;
    cout << "Parametro2: " << parametro2 << endl;
    filename = argv[3];
    cout << "Filename: " << filename << endl << endl;

    Grafo *g;

    if(parametro1 == "-d")
    {
        if(parametro2 == "-l") {
            g = new grafo_lista;
        }
        if(parametro2 == "-m") {
            g = new grafo_matriz; 
        }
        g->carrega_grafo(argv[2], filename);
        g->imprime();
        g->exportDesc();
    }
    if(parametro2 == "-c") 
    {
        if(parametro1 == "-l") {
            g = new grafo_lista;
        }
        if(parametro1 == "-m") {
            g = new grafo_matriz; 
        }
        g->novo_grafo(argv[1], filename);
        g->imprime();
        g->exportInfo();
    }
    
    delete g;
    
    return 0;
}