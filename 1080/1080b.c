/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Ler 100 valores inteiros e dizer o maior valor e seu index
Dificuldade : Nenhum
Uso de IA   : Pesquisei no google (resposta de IA) pra confirmar como faz o malloc de vetores
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n = (int *) malloc(100 * sizeof(int));
    
    for (int i = 0; i < 100; i++) {
        scanf("%d", &n[i]);
    }

    int maior = n[0];
    int maiorIndex;

    for (int i = 0; i < 100; i++) {
        if (maior < n[i]) {
            maior = n[i];
            maiorIndex = i + 1;
        }     
    }

    printf("%d\n", maior);
    printf("%d\n", maiorIndex);

    free(n);
    return 0;
}
