/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 24/09/2026
Objetivo    : Algorítmo para checar se trens podem se empilhados e desempilhados em ordem
Dificuldade : Desvendar a lógica do método invertido usado.
Uso de IA   : Auxilio na lógica de inversão da ordem
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int canPile(int stack, int count, int n) {
    return (stack + count) < n;
}

int canBePut(int *pile, int stack, int count, int n) {
    if (stack == 0) return 0;
    return pile[stack - 1] == n - count; 
}

int isTrainValid(int *vec, int *pile, int stack, int count, int n) {
    if (!(canPile(stack, count, n) || canBePut(pile, stack, count, n))) {
        if (stack) return 0;
        else return 1;
    }

    if (canBePut(pile, stack, count, n)) return isTrainValid(vec, pile, stack-1, count+1, n);
    else {
        pile[stack] = vec[n - stack - count - 1];
        return isTrainValid(vec, pile, stack+1, count, n);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        while (1) {
            int *vec = (int *) malloc(n * sizeof(int));
            int *pile = (int *) malloc(n * sizeof(int));

            scanf("%d", &vec[0]);

            if (vec[0] == 0) {
                free(vec); free(pile);
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &vec[i]);
            }

            if (isTrainValid(vec, pile, 0, 0, n)) printf("Yes\n");
            else printf("No\n");

            free(vec); free(pile);
        }
    }
}