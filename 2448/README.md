#### Problema:
*Encontrar um dado número $x$ num vetor crescente $v$

> Um vetor é **crescente** se $v[0]\leq v[1] \leq \dots \leq v[n-1]$


Considere o algoritmo:

```c
int BuscaBinaria(int x, int n, int v[]) {
	int c, m , d;
	c = -1; d = n;
	while(c < d-1) {
		m = (c + d)/2;
		if (v[m] < x) c = m;
		else d = m;
	}
	return d;
}
```

#### Problema 2448

**Texto**:
Um carteiro é o responsável por entregar as encomendas na rua de Joãozinho. Por política da empresa, as encomendas devem ser entregues na mesma ordem que foram enviadas, mesmo que essa não seja a forma mais rápida. Cansado de subir e descer aquela rua tantas vezes, nosso amigo quer mostrar à empresa quanto tempo ele leva para entregar as encomendas, na tentativa de derrubar essa política.

A rua de Joãozinho tem N casas. Naturalmente, as casas são numeradas de forma ordenada (não necessariamente por números consecutivos). Como as casas possuem aproximadamente o mesmo tamanho, você pode assumir que o carteiro leva uma unidade de tempo para caminhar de uma casa até a casa imediatamente vizinha.

Há M encomendas para essa rua, que devem ser entregues na mesma ordem em que chegaram. Cada encomenda contém o número da casa onde deve ser entregue.

Escreva um programa que determine quanto tempo o carteiro levará para entregar todas as encomendas, assumindo que quando o tempo começa a contar, ele está na primeira casa (a de menor número), e o tempo termina de contar quando todas as encomendas foram entregues (mesmo que o carteiro não esteja de volta na primeira casa). Você pode desprezar o tempo para colocar a encomenda na caixa de correio (ou seja, se ele só tiver uma encomenda, para a primeira casa, a resposta para o problema é zero).

**Entrada**
A primeira linha contém dois inteiros, **N** e **M** (1 ≤ **N**, **M** ≤ 45.000), respectivamente o número de casas e o número de encomendas. A segunda linha contém **N** (1 ≤ **Ni** ≤ 109) inteiros em ordem estritamente crescente, indicando os números das casas. A terceira linha contém **M** (1 ≤ **Mi** ≤ 109) inteiros indicando os números das casas onde as encomendas devem ser entregues, na ordem dada na entrada.

**Saída**
Seu programa deve produzir uma única linha, contendo um único inteiro, o tempo que o carteiro levará para entregar todas as encomendas na ordem correta, assumindo que ele começa na casa de menor número.

| Entrada       | Saída |     | Entrada      | Saída |
| ------------- | ----- | --- | ------------ | ----- |
| 5 5           | 10    |     | 3 4          | 4     |
| 1 5 10 20 40  |       |     | 50 80 100    |       |
| 10 20 10 40 1 |       |     | 80 80 100 50 |       |

#### Resolução do problema

Precisamos resolver o problema utilizando busca binária. Para isso, vamos contar a quantidade de casas andadas pelo carteiro para cada encomenda, baseado na casa que ele estava anteriormente.

O algoritmo deve procurar pela cada da encomenda e dizer o índice daquela casa. Então ele deve comparar esse índice com o índice da cada que ele estava antes e dizer o módulo da diferença deles. Essa diferença deve ser somada a uma variável `S` e o algoritmo deve repetir isso até as encomendas acabarem.

##### Aplicação

```c
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
```




