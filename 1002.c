/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Mercado de Carlos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/09/2026
Objetivo    : Ler o raio em double e escrever a área do circulo
Dificuldade : Negativa
Uso de IA   : Nenhum
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
    double r;
    scanf("%lf", &r);
    double pi = 3.14159;
    double A = pi*(r*r);
    
    printf("A=%.4lf\n", A);
    return 0;
}   

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
		Operador: "~"
	},
	Operador "/": 
}