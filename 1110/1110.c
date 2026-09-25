/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 04/09/2026
Objetivo    : Seguir uma série de instruções sobre uma pilha de cartas e mostrar os resultados dessas instruções
Dificuldade : Visualizar as mudanças das estruturas de dados usadas
Uso de IA   : Debug e dúvidas pontuais
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int n;
    struct Pilha *p;
} Pilha;

// Retorna a quantidade de elementos naquela pilha
int sizePilha(Pilha *head) {
    int size = 0;
    Pilha *p = head->p;

    while (head != p) {
        size++;
        p = p->p;
    }
    return size;
}

// Adiciona o valor descartado no final da pilha (FIFO)
void addToList(Pilha *p, Pilha *dHead) {
    Pilha *q = dHead;
    while (q->p != dHead) {
        q = q->p;
    }
    q->p = p;
    p->p = dHead;
}

// Preenche a pilha com valores de 1 - n
void fillPilha(Pilha *head, int n) {
    for (int i = n; i != 0; i--) {
        Pilha *newP = (Pilha *) malloc(sizeof(Pilha));
        newP->n = i;
        newP->p = head->p;
        head->p = newP;
    }
}

// Realisa a lógica do exercício fazendo trocas de ponteiros
void discardCards(Pilha *dHead, Pilha *head) {
    while (sizePilha(head) >= 2) { 
        // Remove o primeiro ponteiro e coloca ele na lista
        Pilha *y = head->p;
        head->p = y->p;
        addToList(y, dHead);

        // Recomeçando: coloca o primeiro no ultimo lugar
        Pilha *p = head->p; // Primeiro
        head->p = p->p; // Faz o head apontar para o segundo
        p->p = head; // Faz o primeiro apontar pro head

        Pilha *x = head->p; // Começa pelo segundo elemento
        // Passa por todos os elementos até ele ser o ultimo
        while (x->p != head) {
            x = x->p;
        } // x agora é o ultimo elemento

        x->p = p; // Aponta para o primeiro (que agora se tornou o ultimo)
    }
}

// Imprimi a ordem das cartas descastadas 
void printOutput(Pilha *dHead, Pilha *head) {
    printf("Discarded cards: ");
    Pilha *z = dHead->p;
    while (z != dHead) {
        if (z->p != dHead) printf("%d, ", z->n);
        else printf("%d\n", z->n);
        z = z->p;
    }

    printf("Remaining card: %d\n", head->p->n);
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        // Cria listas circulares
        Pilha head;
        head.p = &head;

        Pilha dHead;
        dHead.p = &dHead;

        fillPilha(&head, n);
        discardCards(&dHead, &head);
        printOutput(&dHead, &head);
    }

    return 0;
}