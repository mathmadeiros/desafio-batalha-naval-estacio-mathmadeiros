#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_POS 3
#define ACERTO -1
#define ERRO -2

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int linha, coluna;

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navio horizontal
    int linhaH = 2, colunaH = 4;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO_POS;
    }

    // Posiciona navio vertical
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO_POS;
    }

    // Loop de jogadas
    for (int tentativa = 1; tentativa <= 5; tentativa++) {
        printf("\nTentativa %d: Digite linha e coluna (0 a 9): Ex. 0 9 para linha 0 e coluna 9 \n", tentativa);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("Coordenadas inválidas!\n");
            continue;
        }

        if (tabuleiro[linha][coluna] == NAVIO_POS) {
            printf("💥 Acertou um navio!\n");
            tabuleiro[linha][coluna] = ACERTO;
        } else if (tabuleiro[linha][coluna] == AGUA) {
            printf("🌊 Só água...\n");
            tabuleiro[linha][coluna] = ERRO;
        } else {
            printf("Você já tentou essa posição!\n");
        }

        // Exibe o tabuleiro atualizado
        printf("\nTabuleiro:\n");
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                if (tabuleiro[i][j] == AGUA || tabuleiro[i][j] == NAVIO_POS)
                    printf("~ ");
                else if (tabuleiro[i][j] == ACERTO)
                    printf("X ");
                else if (tabuleiro[i][j] == ERRO)
                    printf("O ");
            }
            printf("\n");
        }
    }

    printf("\nFim de jogo!\n");
    return 0;
}
