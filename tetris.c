#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

// Struct para representar cada peça do Tetris
struct Peca {
    char tipo;
    int id;
};

// Variáveis globais para a fila
struct Peca fila[TAMANHO_FILA];
int inicio = 0;
int fim = 0;
int totalPecas = 0;
int proximoId = 0;

