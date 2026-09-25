/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 05/09/2026
Objetivo    : Conferir se os parênteses de N strings estão corretos
Dificuldade : Entender qual é a condição de parada do problema
Uso de IA   : Debug e usar o return do fgets como condição de parada
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    struct Pilha *p;
} Pilha;


int main() {
    char str[1000];

    while (fgets(str, 1000, stdin)) {
        if (str[0] == '\n') break;

        Pilha pilha;
        pilha.p = &pilha;
        Pilha *topo = &pilha;
        int isCorrect = 1;

        for (int i = 0; str[i] != '\0'; i++) {
            // Adiciona um novo endereço para a pilha
            if (str[i] == '(') {
                Pilha *newP = (Pilha *) malloc(sizeof(Pilha));
                newP->p = topo->p;
                topo->p = newP;
            }
            // Remove o ultimo endereço adicionado
            if (str[i] == ')') {
                if (topo != topo->p) {
                    Pilha *temp = topo->p;
                    topo->p = temp->p;
                    free(temp);
                } else {
                    // Se houver um ')' com a lista vazia também invalida
                    isCorrect = 0;
                }
            }
        }

        if (topo->p != topo || !isCorrect) {
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
    }
}