/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 25/09/2026
Objetivo    : Transformar strings infixas em posfixas
Dificuldade : Toda, debug, lógica, organização, juiz
Uso de IA   : Parceiro de debug fiel
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char operacoes[] = "+-/*^^";
const int opSize = sizeof(operacoes) - 1;

struct Expressao {
    char v;
    struct Expressao *a;
    struct Expressao *b;
    char operador;
};

// Retorna a próxima expressão na lista de prioridade. (da direita pra esquerda, na ordem da String operacoes)
int proximoOperador(char str[]) {
    int brackets = 0;
    
    for (int j = 0; j < opSize; j+=2) {
        for (int i = strlen(str)-1; i >= 0; i--) {
            if (str[i] == ')') {
                brackets++;
            }
            else if (str[i] == '(') {
                brackets--;
            }
            else if (brackets == 0) {
                if (str[i] == operacoes[j] || str[i] == operacoes[j+1]) return i;
            }
        }
    }
    return -1;
}

int isInBrackets(char str[]) {
    int lvl = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(')
            lvl++;
        else if (str[i] == ')')
            lvl--;
        else if (lvl == 0) return 0;
    }

    return lvl == 0;
}

// Tira o parenteses em volta de uma expressão inteira (funciona tipo o cortarStr)
char *tirarParenteses(char str[]) {
    int tamanho = strlen(str);

    char *nova = malloc(tamanho - 1);

    for (int i = 1; i < tamanho - 1; i++)
        nova[i - 1] = str[i];

    nova[tamanho - 2] = '\0';

    return nova;
}

/*
    * d: -1 esquerda, 1 direita
    * Retorna a String à esquerda de um index
    * Também tira os parênteses da String cortada se ela estivar inteiramente preenchida por eles
*/
char *cortarStr(char str[], int index, int d, int brackets) {
    int tamanho = (d == -1) ? index : strlen(str) - index - 1;
    char *nova = malloc((tamanho + 1) * sizeof(char));

    int b = ((d + 1) / 2) * (index + 1); // index + 1 para direita, 0 para esquerda
    int y = 0; // y aqui é o limite da direita e da esquerda, para cortar os parenteses.

    if (brackets) {
        char *temp = cortarStr(str, index, d, 0); // Chama ele de novo cru
        if (brackets && isInBrackets(temp))
            y = 1;
        free(temp);
    }

    for (int i = 0; i < tamanho - 2*y; i++) {
        nova[i] = str[i + b + y]; 
    }
    
    nova[tamanho - 2*y] = '\0';
    return nova;
}

// Função recursiva retorna o ponteiro para uma struct com a expressão da string adicionada
struct Expressao* addExpressao(char str[], struct Expressao *x) {
    if (strlen(str) == 1) {
        x->v = str[0];
        x->a = NULL;
        x->b = NULL;
        x->operador = '~';
        return x;
    }

    // Vai que é isso que o juiz ta reclamando
    if (isInBrackets(str)) {
        char *temp = tirarParenteses(str);
        addExpressao(temp, x);

        free(temp);
        return x;
    }
    int index = proximoOperador(str);

    x->v = '~';
    x->operador = str[index];

    x->a = malloc(sizeof(struct Expressao));
    x->b = malloc(sizeof(struct Expressao));

    char *esq = cortarStr(str, index, -1, 1);
    char *dir = cortarStr(str, index, 1, 1);

    addExpressao(esq, x->a);
    addExpressao(dir, x->b);
    
    free(esq);
    free(dir);

    return x;
}

// Será que agora o Juiz para de dar erro?
void destruirFilhos(struct Expressao *x) {
    if (x == NULL)
        return;

    destruirFilhos(x->a);
    destruirFilhos(x->b);

    if (x->a != NULL)
        free(x->a);

    if (x->b != NULL)
        free(x->b);
}

// Imprime a posfixa recursivamente
void posfixa(struct Expressao *x) {
    if (x == NULL)
        return;

    posfixa(x->a);
    posfixa(x->b);

    if (x->operador != '~')
        printf("%c", x->operador);
    else
        printf("%c", x->v);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char str[301]; // (era o tamanho da string o erro)
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // Tira o \n maldito

        struct Expressao x;

        addExpressao(str, &x);
        posfixa(&x);
        destruirFilhos(&x);
        printf("\n");
    }
}