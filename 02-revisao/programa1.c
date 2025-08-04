#include <stdio.h>
#include <stdlib.h>
#define TAM 5
 
int main() {
    printf("Exemplo de vetor de numeros inteiros\n\n");
    int numero;
    int vetor[TAM];
 
   
    //rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);
 
        vetor[i] = numero;
    }
 
    //rotina que o programa exibe os numeros inteiros um depois do outro
    printf("Numeros: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\n");
 
 
    return 1;
}