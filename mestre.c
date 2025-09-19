#include <stdio.h>

#define TAM 10   // tamanho do tabuleiro
#define HAB 5    // tamanho das matrizes de habilidade

int main() {

    int tabuleiro[TAM][TAM];       // tabuleiro principal
    int cone[HAB][HAB], cruz[HAB][HAB], octaedro[HAB][HAB]; // matrizes de habilidade

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definir tamanho dos navios
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios
    int vert_inicial_linha = 1;
    int vert_inicial_coluna = 2;

    int hor_inicial_linha = 5;
    int hor_inicial_coluna = 4;

    int diag1_inicial_linha = 0;
    int diag1_inicial_coluna = 0;

    int diag2_inicial_linha = 2;
    int diag2_inicial_coluna = 7;

    // Posicionar navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        if (vert_inicial_linha + i < TAM && tabuleiro[vert_inicial_linha + i][vert_inicial_coluna] == 0) {
            tabuleiro[vert_inicial_linha + i][vert_inicial_coluna] = 3;
        }
    }

    // Posicionar navio horizontal
    for (int j = 0; j < tamanho_navio; j++) {
        if (hor_inicial_coluna + j < TAM && tabuleiro[hor_inicial_linha][hor_inicial_coluna + j] == 0) {
            tabuleiro[hor_inicial_linha][hor_inicial_coluna + j] = 3;
        }
    }

    // Posicionar navio diagonal principal (\)
    for (int k = 0; k < tamanho_navio; k++) {
        int linha = diag1_inicial_linha + k;
        int coluna = diag1_inicial_coluna + k;
        if (linha < TAM && coluna < TAM && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Posicionar navio diagonal secundária (/)
    for (int k = 0; k < tamanho_navio; k++) {
        int linha = diag2_inicial_linha + k;
        int coluna = diag2_inicial_coluna - k;
        if (linha < TAM && coluna >= 0 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Criar matriz de habilidade Cone
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i)) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }

    // Criar matriz de habilidade Cruz
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }

    // Criar matriz de habilidade Octaedro (losango)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int dx = (i - HAB/2 < 0) ? -(i - HAB/2) : (i - HAB/2);
            int dy = (j - HAB/2 < 0) ? -(j - HAB/2) : (j - HAB/2);
            if (dx + dy <= HAB/2) octaedro[i][j] = 1;
            else octaedro[i][j] = 0;
        }
    }

    // Definir ponto de origem das habilidades no tabuleiro
    int origem_cone_linha = 2, origem_cone_coluna = 7;
    int origem_cruz_linha = 5, origem_cruz_coluna = 5;
    int origem_octa_linha = 7, origem_octa_coluna = 2;

    // Aplicar habilidade Cone
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (cone[i][j] == 1) {
                int linha = origem_cone_linha + i - HAB/2;
                int coluna = origem_cone_coluna + j - HAB/2;
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Aplicar habilidade Cruz
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (cruz[i][j] == 1) {
                int linha = origem_cruz_linha + i - HAB/2;
                int coluna = origem_cruz_coluna + j - HAB/2;
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Aplicar habilidade Octaedro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (octaedro[i][j] == 1) {
                int linha = origem_octa_linha + i - HAB/2;
                int coluna = origem_octa_coluna + j - HAB/2;
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Exibir tabuleiro no console
    printf("***BATALHA NAVAL***\n\n");

    // Imprimir cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%c ", 'A' + j);
    printf("\n");

    // Imprimir linhas do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // 0 = água, 3 = navio, 5 = habilidade
        }
        printf("\n");
    }

    return 0;
}
