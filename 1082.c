/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 12/11/2026
Objetivo    : Listar os componentes conexos no grafo
Dificuldade : Entender o problema inicialmente
Uso de IA   : Debug e rubber duck
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **mat, int *tempVis, int *vis) {
    vis[v] = 1;
    tempVis[v] = 1;

    for (int i = 0; i < n; i++) {

        if (mat[v][i] == 1 && !vis[i]) {

            dfs(i, n, mat, tempVis, vis);
        }
    }
}

int **createMatrix(int v, int e) {
    int **mat = (int **) malloc(v * sizeof(int *));

    for (int j = 0; j < v; j++) {
        mat[j] = (int *) malloc(v * sizeof(int));
        for (int k = 0; k < v; k++) {
            mat[j][k] = 0;
        }
    }

    for (int j = 0; j < e; j++) {
        char ac, bc;
        scanf(" %c %c", &ac, &bc);

        int a = ac - 'a'; // 0 - 25
        int b = bc - 'a';

        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    return mat;
}

void printComponents(int **mat, int v) {
    int *vis = (int *) calloc(v, sizeof(int)); // Vértices visatadas (global)
    int count = 0;

    for (int j = 0; j < v; j++) {
        if (vis[j]) continue;
        int *tempVis = (int *) calloc(v, sizeof(int)); // Vértices visatas (componente)
        
        count++;
        dfs(j, v, mat, tempVis, vis);
        for (int k = 0; k < v; k++) {
            if (tempVis[k]) printf("%c,", k + 'a');
        }
        printf("\n");
    }
    printf("%d connected components\n\n", count);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Case #%d:\n", i+1);
        int v,e;
        scanf("%d", &v);
        scanf("%d", &e);

        int **mat = createMatrix(v,e);
        printComponents(mat, v);
    }
}