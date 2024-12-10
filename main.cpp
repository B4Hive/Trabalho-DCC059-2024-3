#include <iostream>
#include "grafo.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3 || argc > 4){
        cout << "Error: missing/too many arguments" << endl;
        return 4;
    }
    cout << "Programa iniciado " << endl;
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
    string parametro1 = argv[1];
    string parametro2 = argv[2];
    string filename = argv[3];
    cout << "Parametro1: " << parametro1 << endl;
    cout << "Parametro2: " << parametro2 << endl;
    cout << "Filename: " << filename << endl;
    Grafo *g = new Grafo(filename);

    if(parametro1 == "-d")
    {
        cout << "Entrou no if que eu pedi" << endl;
        g->readInfo(argv[2]);
        g->exportDesc();
    }
    if(parametro2 == "-i")
    {
        //g->readDesc(argv[2]);
        //g->exportInfo();
    }

    delete g;
    return 0;
}