#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]; // Tabuleiro 10x10
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores dos navios
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4;  // Começo do navio horizontal
    int linha_v = 5, coluna_v = 7;  // Começo do navio vertical

    // Validação de limites para o navio horizontal
    if (coluna_h + TAM_NAVIO - 1 >= TAM_TABULEIRO) {
        printf("Erro: O navio horizontal ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // Validação de limites para o navio vertical
    if (linha_v + TAM_NAVIO - 1 >= TAM_TABULEIRO) {
        printf("Erro: O navio vertical ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // Verificar sobreposição antes de posicionar os navios
    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] == 3) {
            sobreposicao = 1;
        }
        if (tabuleiro[linha_v + i][coluna_v] == 3) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem!\n");
        return 1;
    }

    // Posicionando o navio horizontal no tabuleiro
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posicionando o navio vertical no tabuleiro
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibindo o tabuleiro com cabeçalhos: letras nas colunas
    printf("\n    ");
    // Imprime as letras (A até J) no cabeçalho das colunas
    for (i = 0; i < TAM_TABULEIRO; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    // Imprime as linhas com números e o conteúdo do tabuleiro
    for (i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d  ", i); // Número da linha alinhado à direita
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
