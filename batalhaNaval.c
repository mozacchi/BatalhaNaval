#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa tudo com água
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < NAVIO; i++) {
        int lin = linha + (horizontal ? 0 : i);
        int col = coluna + (horizontal ? i : 0);
        if (lin < TAMANHO && col < TAMANHO) {
            tabuleiro[lin][col] = NAVIO;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int matrizHabilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = linhaOrigem + i - TAM_HABILIDADE / 2;
            int col = colunaOrigem + j - TAM_HABILIDADE / 2;
            if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO && matrizHabilidade[i][j]) {
                if (tabuleiro[lin][col] == 0) {
                    tabuleiro[lin][col] = HABILIDADE;
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i);
        }
    }
}

void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2);
        }
    }
}

void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2);
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    posicionarNavio(tabuleiro, 2, 4, 1);
    posicionarNavio(tabuleiro, 5, 1, 0);
    
    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE], matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE], matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);
    
    aplicarHabilidade(tabuleiro, matrizCone, 3, 3);
    aplicarHabilidade(tabuleiro, matrizCruz, 6, 6);
    aplicarHabilidade(tabuleiro, matrizOctaedro, 7, 2);
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
