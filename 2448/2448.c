/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Imprimir a distancia percorrida por um carteiro utilizando busca binária
Dificuldade : Nenhuma
Uso de IA   : Não houve
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Função de busca binária vista em sala
int buscaBinaria(int x, int n, int v[]) {
	int c, m , d;
	c = -1; d = n;
	while(c < d-1) {
		m = (c + d)/2;
		if (v[m] < x) c = m;
		else d = m;
	}
	return d;
}

int main() {
    int n, m;
    scanf("%d", &n); // N° de casas
    scanf("%d", &m); // N° de encomendas

    int *v = (int *) malloc(n * sizeof(int)); // Vetor do n° das casas (ordenado)
    int *p = (int *) malloc(m * sizeof(int)); // Vetor n° encomendas

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int i = 0, S = 0, count = 0;
    while (count < m) {
        int b = buscaBinaria(p[count], n, v); // Index da casa da encomenda p[count]
        S += abs(i - b); // Soma a distância entre a casa anterior e a da nova entrega
        i = b; // Atualiza a posição da casa atual
        count++;
    }

    printf("%d", S);

    free(v); free(p);
    return 0;
}