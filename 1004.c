/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1004
Data        : 20/10/2026
Objetivo    : Produto de x e y na variável PROD
Dificuldade : Negativa
Uso de IA   : Nenhum
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
    int x;
    int y;
    scanf("%d",&x);
    scanf("%d",&y);
    int PROD = x*y;
    printf("PROD = %d\n", PROD);
    return 0;
}