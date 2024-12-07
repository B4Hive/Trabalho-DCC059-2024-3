# Trabalho-DCC059-2024-3

## Compilando

Requisitos: Cmake instalado 

Compile programa rodado

```bash
  $ cmake -S. -Bbuild
```

O executavel vai estar dentro da pasta build. O arquivo que será lido pelo programa deve ser copiado para dentro da pasta build antes da execução (em breve vou corrigir isso) .

Se não quiser instalar o Cmake ai é só rodar pele terminal na mão msm 

```bash
  $ g++ main.cpp grafo.cpp data_strc.cpp grafo_lista.cpp grafo_matriz.cpp -o main.o
```