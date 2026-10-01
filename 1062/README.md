#### Problema 1062
Há uma famosa estação de trem na cidade PopPush. Esta cidade fica em um país incrivelmente acidentado e a estação foi criada no último século. Infelizmente os fundos eram extremamente limitados naquela época. Foi possível construir somente uma pista. Além disso, devido a problemas de espaço, foi feita uma pista apenas até a estação (veja figura abaixo).  

![324](https://resources.beecrowd.com/gallery/images/problems/UOJ_1062_pt.png)

A tradição local é que todos os comboios que chegam vindo da direção A continuam na direção B com os vagões  reorganizados, de alguma forma. Suponha que o trem que está chegando da direção A tem N <= 1000 vagões numerados **sempre** em ordem crescente **1,2, ..., N**. O primeiro que chega é o **1** e o último que chega é o **N**. Existe um chefe de reorganizações de trens que quer saber se é possível reorganizar os vagões para que os mesmos saiam na direção B na ordem **$a_1$, $a_2$, $a_n$**...

O  chefe pode utilizar qualquer estratégia para obter a saída desejada. No caso do desenho ilustrado acima, por exemplo, basta o chefe deixar todos os vagões entrarem na estação (do 1 ao 5) e depois retirar um a um: retira o 5, retira o 4, retira o 3, retira o 2 e por último retira o 1.  Desta forma, se o chefe quer saber se a saída 5,4,3,2,1 é possível em **B,** a resposta seria **Yes**. Vagão que entra na estação **só pode sair para a direção B** e é possível incluir quantos forem necessários para retirar o primeiro vagão desejado.

## Entrada

O arquivo de entrada consiste de um bloco de linhas, cada bloco, com exceção do último, descreve um trem e possivelmente mais do que uma requisição de reorganização. Na primeira linha de cada bloco há um inteiro N que é a quantidade de vagões. Em cada uma das próximas linhas de entrada haverá uma permutação dos valores **1,2, …, N**. A última linha de cada bloco contém apenas 0. Um bloco iniciando com zero (0) indica o final da entrada.

## Saída

O arquivo de saída contém a quantidade de linhas correspondente às linhas com permutações no arquivo de entrada. Cada linha de saída deve ser **Yes** se for possível organizar os vagões da forma solicitada e **No**, caso contrário. Há também uma linha em branco após cada bloco de entrada. No exemplo abaixo,  O primeiro caso de teste tem 3 permutações para 5 vagões. O ultimo zero dos testes de entrada não devem ser processados.

|Exemplo de Entrada|Exemplo de Saída|
|---|---|
|5  <br>5 4 3 2 1  <br>1 2 3 4 5  <br>5 4 1 2 3  <br>0  <br>6  <br>1 3 2 5 4 6  <br>0  <br>0|Yes  <br>Yes  <br>No  <br>  <br>Yes|

#### Resolução do problema
O problema descreve um trem chegando em ordem crescente, e precisamos checar se ele pode ser "desordenado", isto é, ficar na ordem requisitada apenas com as operações de fila. 
Chegar na ordem crescente, para o exercício, é na perspectiva da estação, enquanto o trem é empilhado, ou seja, o trem está decrescente da esquerda para a direita, mas os comboios chegam em ordem crescente.

Curiosamente, esse processo é equivalente a ler a permutação desejada de trás para frente ($B^R$)e gerar a sequência inicial de trás para frente ($A^R$). Nesse caso, imaginamos a entrada como a saída original, e a saída, como a entrada invertida (decrescente).

Nessa abordagem o código pode ficar um pouco mais simples.
É possível ter uma função recursiva que implemente o algoritmo de maneira bem expressiva:

>Se não pode empilhar e nem colocar:
	Se tem coisa pra empilhar: Inválido
	Se não: Válido.
>
>Se pode colocar:
	Coloca, repete.
   Se não:
	empilha.
	repete.

```c
int isTrainValid(int *vec, int *pile, int stack, int count, int n) {
    if (!(canPile(stack, count, n) || canBePut(pile, stack, count, n))) {
        if (stack) return 0;
        else return 1;
    }

    if (canBePut(pile, stack, count, n)) return isTrainValid(vec, pile, stack-1, count+1, n);
    else {
        pile[stack] = vec[n - stack - count - 1];
        return isTrainValid(vec, pile, stack+1, count, n);
    }
}
```
---

As funções `canPile` e `canBePut` são bem simples:

`canPile` diz se a soma da pilha com os comboios colocados é menor que a quantidade total de comboios.
Se ela for menor, quer dizer que ainda há comboios para empilhar.
```c
int canPile(int stack, int count, int n) {

    return (stack + count) < n;

}
```

`canBePut` também opera de maneira muito simples. Se não houver comboios na pilha, retorna falso. Caso contrário, retorna se o comboio mais da frente é igual a `n - count`, que é o próximo comboio necessário.
```c
int canBePut(int *pile, int stack, int count, int n) {

    if (stack == 0) return 0;

    return pile[stack - 1] == n - count;

}
```

A lógica do `main` é bem evidente. Ela trata das entradas que o problema pede e imprime `"Yes\n"` se `isTrainValid()` retornar 1, e `"No\n"` caso contrário.

#### Desafios
O maior desafio foi sem dúvidas ter me perdido na lógica de equivalência entre o método normal e o invertido. Inicialmente, o código foi pensado em ter a entrada e a saída invertida, mas só foi invertida a ordem dos vagões da entrada, então ao invés da entrada ser a saída original invertida e a saída ser o inverso da entrada original (decrescente), a saída era apenas a entrada original (crescente). Esse erro de lógica, que estava centrado na função `canBePut()` causou diversas respostas erradas nos Juiz. `canBePut()` originalmente retornava:
`return pile[stack - 1] == count + 1;` (Ordem crescente)
quando deveria retornar:
`return pile[stack - 1] == n - count;` (Ordem decrescente)

A implementação do código em si foi muito simples, talvez o maior desafio dessa parte tenha sido trabalhar com a lógica de entradas, que foi um pouco confuso.
