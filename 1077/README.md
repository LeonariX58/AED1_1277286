Definição de infixa e profixa:
**Notação infixa**: É a forma convencional de representação matemática em que o operador é colocado entre dois operandos. Requer o uso de regra de procedência.

**Notação profixa**: É uma forma de representação matemática em que o operador vem 
depois de dois operandos. Essa notação elimina a necessidade de regras de precedência.
 
 --- 

##### Problema:
*Transforme um String de notação infixa em notação profixa.*

Exemplo de entrada e saída:

| Entrada:          |     | Saída:        |
| ----------------- | --- | ------------- |
| A\*2              |     | A2*           |
| (A\*2+c-d)/2      |     | A2\*c+d-2/    |
| (2\*4/a^b)/(2\*c) |     | 24\*/ab^2c\*/ |
##### Implementação (Utilizando lista encadeada):
O algoritmo precisa tratar o que esta em parênteses como um termo único. Uma abordagem pode ser transformar a String em uma estrutura de dados, cada termo (composto ou individual) também é uma estrutura, formando uma lista encadeada. Algo do tipo:

> **(A\*2+c-d)/2 ->
```c
Struct {
	V: '~',
	A: * Struct {
		V: '~',
		A: * Struct {
			V: '~',
			A: * Struct {
				V: '~',
				A: * Struct {
					V: '~',
					A: * Struct {
						V: 'A',
						A: NULL,
						B: NULL,
						Operador: '~'
						},
					B: * Struct {
						V: '2',
						A: NULL,
						B: NULL,
						Operador: '~'
					}
				Operador: '*'
				},
			}
			B: * Struct {
				V: 'c',
				A: NULL,
				B: NULL,
				Operador: '~'
			}
		Operador: '+'
		},
		B: * Struct {
			V: 'd',
			A: NULL,
			B: NULL,
			Operador: '~'
			}
		Operador: '-'
		}
	B: * Struct {
		V: '2',
		A: NULL,
		B: NULL,
		Operador: '~'
	},
	Operador '/':
}
```

> Nesse exemplo, temos uma Struct do tipo:
```c
Struct Expressao {
	char v,
	Struct Expressao *A,
	Struct Expressao *B,
	char operador
};
```

>[!Definição]
>`v` pode assumir um caractere único, será utilizado quando A e B forem nulos.
`A` é um ponteiro para `Struct Expressao` e serve como o operando da esquerda em uma operação.
`B` é um ponteiro para `Struct Expressao` e serve como o operando da direita em uma operação.
`operador` é um caractere que indica o tipo de operação da expressão.
Para uma expressão de apenas um caractere, `v` assume esse caractere, `A` e `B` são nulos e `operator` é **'~'**.
Para uma expressão composta, `v` vale **'~'**, `A` e `B` assumem as expressões internas e `operador` pode ser: '+', '-', '\*', '/' ou '^'.

Dessa forma, nosso primeiro desafio é criar um algoritmo que transforme uma String similar à: "(A\*2+c-d)/2" em uma Struct do tipo Expressao.

Para fazer isso precisamos primeiro escolher a ordem das expressões. Essa ordem deve ser da esquerda para direita, com a seguinte prioridade: '()' -> '^' -> '/ \*' -> '+ -'.

Existe um problema em simplesmente ler da esquerda para a direita. Estamos criando as Struct de cima para baixo, ou seja, o primeiro valor que colocarmos deve ser o ultimo a ser executado. Isso também impacta na ordem dos operadores. O processo correto deve ser ler a String da direita para a esquerda e com a prioridade dos operadores invertida. Além disso é necessário considerar os parênteses como um termo.

No exemplo: (A\*2+c-d)/2
Primeiro operador:  /

A1: (A\*2+c-d)
B1: 2
operador: /

Para A1:
Operador encontrado: -
A2: A\*2+c
B2: d
operador: -

Para A2:
Operador encontrado: +
A3: A\*2
B3: c
operador: +
...
O maior desafio de implementação agora é como tratar os parênteses. Precisamos ignorar os parênteses na busca de operadores. Isso deve ser verdade até só restar os parênteses.

##### Considerações depois de 5 horas
O maior desafio não era tratar os parênteses, mas sim trabalhar com toda a lógica de parses e recursão.
Transformar em profixa é extremamente intuitivo depois de armazenar corretamente na estrutura.
O código ficou bem mais complicado do que eu imaginava então não vale a pena descrever todo ele aqui.

[AED1_1277286/1077.c at main · LeonariX58/AED1_1277286](https://github.com/LeonariX58/AED1_1277286/blob/main/1077.c)