#include <stdio.h>

// TODOs possíveis: fazer um define para tamanho do tabuleiro e dos grupos para escalabilidade
// mudar o check1DGroup para já testar todos os parametros usando algum tipo de variável 'seen'

// Checa se um grupo 1x9 é valido
int check1DGroup(const int group[], int j) {
    if (group[j] < 1 || group[j] > 9) return 0;
    for (int i = 0; i < 9; i++) {
        if (group[i] == group[j] && i != j) return 0;
    }
    return 1;
}

// Checa se um grupo de um intervalo 3x3 é válido
int isGroupValid(const int board[][9], int js, int je, int ks, int ke) {
    // Transforma o intervalo em um grupo 1x9
    int group[9];
    int pos = 0;
    
    for (int i = js; i <= je; i++) {
        for (int j = ks; j <= ke; j++) {
            group[pos] = board[i][j];
            pos++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (!check1DGroup(group, i)) return 0;
    }
    return 1;
}

void readBoard(int board[][9]) {    
    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
            scanf("%d", &board[j][k]);
        }
    }
}

int checkGroups(const int board[][9]) {
    for (int p = 0; p < 9; p+=3) {
        for (int q = 0; q < 9; q+=3) {
            if (!isGroupValid(board, p, 2+p, q, 2+q)) return 0;
        }
    }
    return 1;
}

int checkRows(const int board[][9]) {
    for (int l = 0; l < 9; l++) {
        for (int j = 0; j < 9; j++) {
            if (!check1DGroup(board[l], j)) return 0;
        }
    }
    return 1;
}

int checkColumns(const int board[][9]) {
    for (int l = 0; l < 9; l++) {
        int column[9];
        for (int c = 0; c < 9; c++) {
            column[c] = board[c][l];
        }
        for (int j = 0; j < 9; j++) {
            if (!check1DGroup(column, j)) return 0;
        }
    }
    return 1;
}

int isBoardValid(int board[][9]) {
    if (!checkGroups(board)) return 0;
    if (!checkRows(board)) return 0;
    if (!checkColumns(board)) return 0;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int board[9][9] = {0};
        readBoard(board);

        if (isBoardValid(board)) printf("Instancia %d\nSIM\n\n", i);
        else printf("Instancia %d\nNAO\n\n", i);
    }
    return 0;
}