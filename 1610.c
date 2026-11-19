
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int destination;
    int next;
} Edge;

void initializeGraph(int n, int head[]) {
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
}

// Adiciona vértice
void addEdge(int source, int destination, int index, int head[], Edge edges[]) {
    edges[index].destination = destination;
    edges[index].next = head[source];

    head[source] = index;
}

int dfs(int v, int head[], Edge edges[], int state[]) {

    state[v] = 1;

    for (int i = head[v]; i != -1; i = edges[i].next) {

        int neighbor = edges[i].destination;

        if (state[neighbor] == 1) {
            return 1;
        }

        if (state[neighbor] == 0) {
            if (dfs(neighbor, head, edges, state)) {
                return 1;
            }
        }
    }

    state[v] = 2;

    return 0;
}

// Checa se o grafo tem ciclo
int hasCycle(int n, int head[], Edge edges[], int state[]) {

    for (int i = 1; i <= n; i++) {

        if (state[i] == 0) {

            if (dfs(i, head, edges, state)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        int N, M;
        scanf("%d %d", &N, &M);

        int *head = malloc((N + 1) * sizeof(int));
        int *state = calloc(N + 1, sizeof(int));

        Edge *edges = malloc((M > 0 ? M : 1) * sizeof(Edge));

        initializeGraph(N, head);

        for (int i = 0; i < M; i++) {

            int A, B;
            scanf("%d %d", &A, &B);

            addEdge(A, B, i, head, edges);
        }

        if (hasCycle(N, head, edges, state)) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }

        free(head);
        free(state);
        free(edges);
    }

    return 0;
}