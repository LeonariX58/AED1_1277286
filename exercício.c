#include <stdio.h>
#include <stdlib.h>

typedef struct Tno {
    int n;
    struct Tno *esq;
    struct Tno *dir;
} No; 

No* createNewNo() {
    No* newCel = (No *) malloc(sizeof(No));
    newCel->n = 0;
    newCel->esq = NULL;
    newCel->dir = NULL;
    return newCel;
}

void insert(No **cel, int n) {
    if (*cel == NULL) {
        *cel = createNewNo();
        (*cel)->n = n;
        return;
    }

    if (n > (*cel)->n) {
        insert(&(*cel)->dir, n);
    } else {
        insert(&(*cel)->esq, n);
    }
}

void printTree(No *cel) {
    if (cel->esq != NULL) printTree(cel->esq);
    printf("%d ", cel->n);
    if (cel->dir != NULL) printTree(cel->dir);
    return;
}

int main() {
    No *tree = NULL;
    for (int i = 0; i < 5; i++) {
        int n;
        scanf("%d", &n);
        insert(&tree, n);
    }

    printTree(tree);
}