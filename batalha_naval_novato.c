#include <stdio.h>

int main() {
    // Tamanho do tabuleiro
    const int linhas = 5;
    const int colunas = 5;

    // Criando Tabuleiro
    int tabuleiro[linhas][colunas];

    // Inicializa todas as posicoes como 0
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionamento de dois navios
    // Navil 1 - Horizontal (linha 1, colunas de 1 a 3)

    int linha1 = 1;
    for (int j = 1; j < 3; j++){
        tabuleiro[linha1][j] = 1;
        printf("Navil Horizontal -> Coordenada: (%d, %d)\n", linha1, j);
    }

    // Navio 2 - Vertical (coluna 2, linhas de 2 a 4)

    int coluna2 = 2;
    for (int i = 2; i <= 4; i++){
        tabuleiro[i][coluna2] = 2;
        printf("Navio Vertical -> Coordenada: (%d, %d)\n", i, coluna2);
    }

    return 0;

}