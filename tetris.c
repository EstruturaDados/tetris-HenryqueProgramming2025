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

