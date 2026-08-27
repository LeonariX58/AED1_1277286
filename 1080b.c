#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n = (int *) malloc(100 * sizeof(int));
    
    for (int i = 0; i < 100; i++) {
        scanf("%d", &n[i]);
    }

    int maior = n[0];
    int maiorIndex;

    for (int i = 0; i < 100; i++) {
        if (maior < n[i]) {
            maior = n[i];
            maiorIndex = i + 1;
        }     
    }

    printf("%d\n", maior);
    printf("%d\n", maiorIndex);

    free(n);
    return 0;
}
