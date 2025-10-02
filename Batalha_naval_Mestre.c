#include <stdio.h>
#include <string.h>

#define TAM 5  // Tamanho fixo da matriz (5x5)

// Função para limpar a matriz
void limparMatriz(int matriz[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int matriz[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para habilidade em cone
void habilidadeCone(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i][j] = 1;
        }
    }
}

// Função para habilidade em cruz
void habilidadeCruz(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        matriz[centro][i] = 1; // Linha central
        matriz[i][centro] = 1; // Coluna central
    }
}

// Função para habilidade em octaedro
void habilidadeOctaedro(int matriz[TAM][TAM]) {
    int centro = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int matriz[TAM][TAM];
    char escolha[10];

    printf("Escolha uma habilidade (cone, cruz, octaedro): ");
    scanf("%s", escolha);

    limparMatriz(matriz);

    if (strcmp(escolha, "cone") == 0) {
        habilidadeCone(matriz);
    } else if (strcmp(escolha, "cruz") == 0) {
        habilidadeCruz(matriz);
    } else if (strcmp(escolha, "octaedro") == 0) {
        habilidadeOctaedro(matriz);
    } else {
        printf("Habilidade inválida!\n");
        return 1;
    }

    printf("\nMatriz resultante:\n");
    imprimirMatriz(matriz);

    return 0;
}
