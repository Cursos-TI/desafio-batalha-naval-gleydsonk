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

    int linha_h = 1;
    printf("Posicionamento navio horizontal na linha %d (colunas 1 a 3)...\n", linha_h);
    for (int j = 1; j <= 3; j++){
        if (tabuleiro[linha_h][j] == 0){
            tabuleiro[linha_h][j] = 1;
            printf("Navil Horizontal -> Coordenada: (%d, %d)\n", linha_h, j);
        }
    }

    // Navio 2 - Vertical (coluna 2, linhas de 2 a 4)

    int coluna_v = 2;
    printf("Posicionamento navio vertical na coluna %d (linhas 2 a 4)...\n", coluna_v);
    for (int i = 2; i <= 4; i++){
        if (tabuleiro[i][coluna_v] == 0){
            tabuleiro[i][coluna_v] = 2;
            printf("Navio Vertical -> Coordenada: (%d, %d)\n", i, coluna_v);
        }
    }

    // Exibicao do tabuleiro
    printf("\nTabuleiro (5x5):\n");
    printf("Legenda: 0=vazio | 1=horizontal | 2=vertical \n\n");

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;

}