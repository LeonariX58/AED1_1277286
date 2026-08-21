#include <stdio.h>
 
int main() {
    int n[100];
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

    return 0;
}