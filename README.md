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
$ ./main.exe <operacao> <tipo_armazenamento> <arquivoIn> <arquivoOut>
```

### Parâmetros
- **`<operacao>`**
  - `-d`: Carrega o grafo de um arquivo e imprime sua descrição.
  - `-c`: Cria um novo grafo com as condições especificadas no arquivo de entrada (`<arquivoIn>`) e exporta para o arquivo de saída (`<arquivoOut>`).

- **`<tipo_armazenamento>`**
  - `-l`: Utiliza armazenamento como lista encadeada.
  - `-m`: Utiliza armazenamento como matriz.

- **`<arquivoIn>`**: Arquivo de entrada.
- **`<arquivoOut>`**: Arquivo de saída (necessário apenas para a operação `-c`).

### Exemplos de Uso
1. Para carregar e descrever um grafo de um arquivo chamado `grafo.txt`:
   ```bash
   $ ./main -d -l grafo.txt
   ```

2. Para criar um grafo com as condições especificadas em `entrada.txt` e salvar em `saida.txt`:
   ```bash
   $ ./main -c -m entrada.txt saida.txt
   ```
