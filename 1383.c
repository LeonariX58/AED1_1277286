#include <stdio.h>

// TODO: Remover o Interval e tuples (já que os intervalos são sempre os mesmos)
// TODO: Separar a main em "readBoard" e "isBoardValid" 

int tuples[3][2] = {{0,2}, {3,5}, {6,8}};

struct Interval {
    int s; // Start
    int e; // End
};

// Garante que o intervalo sempre terá 3 valores
struct Interval newInterval(int s, int e) {
    struct Interval invalid = {-1, -1};
    if (e - s != 2 || ((e > 8 || e < 0) || (s > 8 || s < 0))) {
        printf("Aviso: Valor de intervalo invalido.");
        return invalid;
    }

    struct Interval inter = {s, e};
    return inter;
}

// Checa se um grupo 1x9 é valido
int check1DGroup(int group[], int j) {
    if (group[j] < 1 || group[j] > 9) return 0;
    for (int i = 0; i < 9; i++) {
        if (group[i] == group[j] && i != j) return 0;
    }
    return 1;
}

// Checa se um grupo de um intervalo 3x3 é válido
int isGroupValid(int board[][9], struct Interval interJ, struct Interval interK) {
    // Transforma o intervalo em um grupo 1x9
    int group[9];
    int pos = 0;
    
    for (int i = interJ.s; i <= interJ.e; i++) {
        for (int j = interK.s; j <= interK.e; j++) {
            group[pos] = board[i][j];
            pos++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (!check1DGroup(group, i)) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int board[9][9] = {0};
        int valid = 1;
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                scanf("%d", &board[j][k]);
            }
        }
        // Testar grupos
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                if (!isGroupValid(board, newInterval(tuples[p][0], tuples[p][1]), newInterval(tuples[q][0], tuples[q][1]))) valid = 0;
            }
        }

        // Testar linhas
        for (int l = 0; l < 9; l++) {
            for (int j = 0; j < 9; j++) {
                if (!check1DGroup(board[l], j)) {
                    valid = 0;
                }
            }
        }

        // Testar colunas
        for (int l = 0; l < 9; l++) {
            int column[9];
            for (int c = 0; c < 9; c++) {
                column[c] = board[c][l];
            }
            for (int j = 0; j < 9; j++) {
                if (!check1DGroup(column, j)) {
                    valid = 0;
                }
            }
        }
        if (valid) printf("Instancia %d\nSIM\n\n", i);
        else printf("Instancia %d\nNAO\n\n", i);
    }

    return 0;
}