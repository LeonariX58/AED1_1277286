/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 29/10/2026
Objetivo    : Reconstruir árvores binárias em posfixa
Dificuldade : Pensar na solução geral e aplicar a solução
Uso de IA   : Debug, dúvidas e  rubber duck
-------------------------------------------------------------------------- */

// Código um pouco feio infelizmente
#include <stdio.h>
#include <stdlib.h>

typedef struct Tno {
    char c;
    struct Tno *esq;
    struct Tno *dir;
} No; 

typedef struct TPerc {
    char str[52];
    int i;
    int f;
} Perc;

No* createNode() {
   No *newNode = (No*) malloc(sizeof(No));

   newNode->esq = NULL;
   newNode->dir = NULL;
   return newNode; 
}

void createTree(Perc prefixa, Perc infixa, No **tree) {
    if (prefixa.i >= prefixa.f) {
        *tree = NULL;
        return;
    }
    
    char raiz = prefixa.str[prefixa.i];
    
    *tree = createNode();
    (*tree)->c = raiz;

    int nl;
    for (int i = infixa.i; i < infixa.f; i++) {
        if (infixa.str[i] == raiz) {
            nl = i - infixa.i; // Quantidade de chars na esquerda
            break;
        }
    }

    Perc prefixaL = prefixa;
    prefixaL.i = prefixa.i + 1;
    prefixaL.f = prefixa.i + nl + 1;

    Perc infixaL = infixa;
    infixaL.i = infixa.i;
    infixaL.f = infixa.i + nl;

    Perc prefixaR = prefixa;
    prefixaR.i = prefixaL.f;
    prefixaR.f = prefixa.f;

    Perc infixaR = infixa;
    infixaR.i = infixa.i + nl + 1;
    infixaR.f = infixa.f;

    createTree(prefixaL, infixaL, &(*tree)->esq);
    createTree(prefixaR, infixaR, &(*tree)->dir);
}

void printPostOrder(No *tree) {
    if (tree == NULL) return;

    printPostOrder(tree->esq);
    printPostOrder(tree->dir);
    printf("%c", tree->c);
}

void freeTree(No *tree) {
    if (tree == NULL) return;

    freeTree(tree->esq);
    freeTree(tree->dir);
    free(tree);
}

int main() {
    int c;
    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n);
        Perc prefixa;
        Perc infixa;

        scanf("%51s", prefixa.str);
        scanf("%51s", infixa.str);
        
        prefixa.i = 0;
        infixa.i = 0;
        prefixa.f = n;
        infixa.f = n;

        No *tree = NULL;
        createTree(prefixa, infixa, &tree);
        printPostOrder(tree);
        printf("\n");
        freeTree(tree);
    }
}