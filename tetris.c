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

// Protótipos das funções
void gerarPeca();
void enfileirar(struct Peca novaPeca);
void desenfileirar();
void mostrarFila();
void limparBuffer();

int main() {
    srand(time(NULL)); // Inicializa números aleatórios
    
    printf("=== TETRIS STACK - SISTEMA DE FILA DE PEÇAS ===\n\n");
    
    // Inicializa a fila com 5 peças
    for (int i = 0; i < TAMANHO_FILA; i++) {
        gerarPeca();
    }
    
    int opcao;
    
    do {
        printf("\n=== FILA ATUAL ===\n");
        mostrarFila();
        
        printf("\n=== OPÇÕES ===\n");
        printf("1. Jogar peça (remover da frente)\n");
        printf("2. Inserir nova peça\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                if (totalPecas > 0) {
                    desenfileirar();
                } else {
                    printf("\n❌ Fila vazia! Não há peças para jogar.\n");
                }
                break;
                
            case 2:
                if (totalPecas < TAMANHO_FILA) {
                    gerarPeca();
                    printf("\n✅ Nova peça adicionada à fila!\n");
                } else {
                    printf("\n❌ Fila cheia! Jogue uma peça primeiro.\n");
                }
                break;
                
            case 0:
                printf("\n=== JOGO ENCERRADO ===\n");
                break;
                
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }
        
    } while(opcao != 0);
    
    return 0;
}

// Gera uma peça aleatória e adiciona à fila
void gerarPeca() {
    if (totalPecas >= TAMANHO_FILA) {
        return;
    }
    
    struct Peca novaPeca;
    char tipos[] = {'I', 'O', 'T', 'L', 'J', 'S', 'Z'};
    
    novaPeca.tipo = tipos[rand() % 7];
    novaPeca.id = proximoId++;
    
    enfileirar(novaPeca);
}

// Adiciona peça no final da fila
void enfileirar(struct Peca novaPeca) {
    if (totalPecas >= TAMANHO_FILA) {
        return;
    }
    
    fila[fim] = novaPeca;
    fim = (fim + 1) % TAMANHO_FILA;
    totalPecas++;
}

// Remove peça do início da fila
void desenfileirar() {
    if (totalPecas == 0) {
        return;
    }
    
    printf("\n🎮 Jogando peça: [%c %d]\n", fila[inicio].tipo, fila[inicio].id);
    
    inicio = (inicio + 1) % TAMANHO_FILA;
    totalPecas--;
}

// Mostra todas as peças na fila
void mostrarFila() {
    if (totalPecas == 0) {
        printf("Fila vazia!\n");
        return;
    }
    
    int pos = inicio;
    for (int i = 0; i < totalPecas; i++) {
        printf("[%c %d] ", fila[pos].tipo, fila[pos].id);
        pos = (pos + 1) % TAMANHO_FILA;
    }
    printf("\n");
}

// Limpa o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

