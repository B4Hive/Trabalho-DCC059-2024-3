# Trabalho-DCC059-2024-3

## Compilando

### Usando CMake
Compile o programa rodando os seguintes comandos:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make         # Linux
$ mingw32-make # Windows
```

### Sem CMake

Compile o programa rodando o seguinte comando:

```bash
$ g++ src/*.cpp main.cpp -o main
```

## Executando

O programa é executado a partir do terminal com os seguintes parâmetros:

```bash
$ ./main <operacao> <tipo_armazenamento> <arquivoIn>
```

### Parâmetros
- **`<operacao>`**
  - `-d`: Carrega o grafo de um arquivo e imprime sua descrição.
  - `-p`: Executa a solução do probrema alvo (coloração de vértices).

- **`<tipo_armazenamento>`**
  - `-l`: Utiliza armazenamento como lista encadeada.
  - `-m`: Utiliza armazenamento como matriz.

- **`<arquivoIn>`**: Arquivo de entrada.

### Exemplos de Uso
1. Para carregar e descrever um grafo de um arquivo chamado `grafo.txt`:
   ```bash
   $ ./main -d -l grafo.txt
   ```

2. Para carregar um grafo e imprimir as soluções dos algoritmos gulosos em relação ao problema alvo:
   ```bash
   $ ./main -p -m grafo.txt
   ```
