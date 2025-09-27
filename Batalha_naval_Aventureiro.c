#include <stdio.h>

#define TAM 10 //Tamanho do navio
#define NAVIO 3 // Valor que representa uma parte do navio
#define TAM_NAVIO 3 //Tamanho fixo dos navios

//Funcao para verificar se a posicao esta livre e dentro do tabuleiro
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, char tipo){
    for(int i = 0; i < TAM_NAVIO; i++){
        int l = linha, c = coluna;

        if(tipo == 'H') c += i; // Horizontal
        else if (tipo == 'v') l += i; //Vertical
        else if (tipo == 'D'){l += i; c +=i; } //Diagonal direita
        else if (tipo == 'E'){l += i; c -= i; } //Diagonal esquerda

        if (l < 0 || l >= TAM || c < 0 || c >= TAM) return 0; //Fora dos limites
        if (tabuleiro[l][c] != 0) return 0;          //Ja ocupado
    }
    return 1;
}

//Funcao para posicionar o navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, char tipo){
    for (int i = 0; i < TAM_NAVIO; i++){
        int l = linha, c = coluna;

        if (tipo == 'H') c += i; //orizontal
        else if (tipo == 'V') l += i;  //Vertical
        else if (tipo =='D') { l += i; c+= i; }  //Diagonal direita
        else if (tipo == 'E') { l += i; c -= i; } //Diagonal esquerda

        tabuleiro[l][c] = NAVIO;
    
    }
}

//Funcao para imprimir tabuleiro
void imprimir_tabuleiro(int tabuleiro[TAM][TAM]){
    printf("  ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++){
        printf("%2d", i);
        for (int j = 0; j < TAM; j++){
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tabuleiro[TAM][TAM] = {0}; //Inicializa todas as posicoes com 0 (agua)

    // Tentamos posicionar navios em coordenadas predefinidas

    // Navio horizontal (linha 0, coluna 0)
    if (pode_posicionar(tabuleiro, 0, 0, 0, 'H')) {
        posicionar_navio(tabuleiro, 0, 0, 'H');
    }

    // Navio vertical (linha 5, coluna 5)
    if (pode_posicionar(tabuleiro, 5, 5, 1, 'V')) {
        posicionar_navio(tabuleiro, 5, 5, 'V');
    }

    // Navio diagonal ↘ (linha 2, coluna 2)
    if (pode_posicionar(tabuleiro, 2, 2, 0, 'D')) {
        posicionar_navio(tabuleiro, 2, 2, 'D');
    }

    // Navio diagonal ↙ (linha 0, coluna 9)
    if (pode_posicionar(tabuleiro, 0, 9, 0, 'E')) {
        posicionar_navio(tabuleiro, 0, 9, 'E');
    }

    // Exibir o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}