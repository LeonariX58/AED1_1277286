#include <stdio.h>

typedef struct {
    int n;
    No *esq;
    No *dir;
} No; 

No* createNewNo() {
    No* newCel = (No *) malloc(sizeof(No)); 
    return newCel;
}

void insert(No *cel, int n) {
    if (n > cel->n) {
        if (cel->dir == NULL) {
            cel->dir = createNewNo();
            cel->dir->n = n;
            return;
        } else {
            return insert(cel->dir, n);
        }
    } else {
            if (cel->esq == NULL) {
            cel->esq = createNewNo();
            cel->esq->n = n;
            return;
        } else {
            return insert(cel->esq, n);
        }
    }
}

void printTree(No *cel) {
    No *aux = cel;
    if (cel->dir)

    return printTree(aux);
    printf("%d ", aux->n);
}