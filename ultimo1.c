#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //Definir tamanho dos navios
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios (linha, coluna)
    // Navio vertical
    int vert_inicial_linha = 1; // linha inicial do navio vertical
    int vert_inicial_coluna = 2; // coluna fixa do navio vertical

    // Navio horizontal
    int hor_inicial_linha = 5; // linha fixa do navio horizontal
    int hor_inicial_coluna = 4; // coluna inicial do navio horizontal

    //Posicionar navio vertical
    for(int i = 0; i < tamanho_navio; i++) {
        if(vert_inicial_linha + i < 10) {
            tabuleiro[vert_inicial_linha + i][vert_inicial_coluna] = 3;
        }
    }

    //Posicionar navio horizontal
    for(int j = 0; j < tamanho_navio; j++) {
        if(hor_inicial_coluna + j < 10) {
            tabuleiro[hor_inicial_linha][hor_inicial_coluna + j] = 3;
        }
    }

    //Exibir tabuleiro no console
    printf("***BATALHA NAVAL***\n\n");

    //Imprimir cabeçalho das colunas (A-J)
    printf("   ");
    for(int j = 0; j < 10; j++) {
        
        printf("%c ", 'A' + j);
    }
    printf("\n");

    //Imprimir linhas do tabuleiro
    for(int i = 0; i < 10; i++) {
        printf("%2d ", i+1); // número da linha
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // 0 = água, 3 = navio
        }
        printf("\n");
    }

    return 0;
}
