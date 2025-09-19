#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; 
        }
    }

    // Definir tamanho dos navios
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios

    // Navio vertical
    int vert_inicial_linha = 1; 
    int vert_inicial_coluna = 2;

    // Navio horizontal
    int hor_inicial_linha = 5; 
    int hor_inicial_coluna = 4;

    // Navio diagonal principal (\)
    int diag1_inicial_linha = 0;
    int diag1_inicial_coluna = 0;

    // Navio diagonal secundária (/)
    int diag2_inicial_linha = 2;
    int diag2_inicial_coluna = 7;


    // Posicionar navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        if (vert_inicial_linha + i < 10 && tabuleiro[vert_inicial_linha + i][vert_inicial_coluna] == 0) {
            tabuleiro[vert_inicial_linha + i][vert_inicial_coluna] = 3;
        }
    }

    // Posicionar navio horizontal
    for (int j = 0; j < tamanho_navio; j++) {
        if (hor_inicial_coluna + j < 10 && tabuleiro[hor_inicial_linha][hor_inicial_coluna + j] == 0) {
            tabuleiro[hor_inicial_linha][hor_inicial_coluna + j] = 3;
        }
    }

    //Posicionar navio diagonal principal (\)
    for (int k = 0; k < tamanho_navio; k++) {
        int linha = diag1_inicial_linha + k;
        int coluna = diag1_inicial_coluna + k;
        if (linha < 10 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Posicionar navio diagonal secundária (/)
    for (int k = 0; k < tamanho_navio; k++) {
        int linha = diag2_inicial_linha + k;
        int coluna = diag2_inicial_coluna - k;
        if (linha < 10 && coluna >= 0 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Exibir tabuleiro no console
    printf("***BATALHA NAVAL***\n\n");

    // Imprimir cabeçalho das colunas (A-J)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Imprimir linhas do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // 0 = água, 3 = navio
        }
        printf("\n");
    }

    return 0;
}
