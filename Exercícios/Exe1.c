//sortear TAM n°s (até TAM n°s) no vetor, porém não inserir n°s já presentes no vetor. Ao final, exibir o vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main (){
    int vetor[TAM];

    srand(time(NULL));

    int numero;
    int posicaoDoUltimoNumeroInserido = 0;
    int jaInserido;

    for (int i = 0; i < TAM; i++){
        numero = rand() % 100;
        jaInserido = 0;

        for (int j = 0; j <= posicaoDoUltimoNumeroInserido; j++){
            if (numero == vetor[j]){
                jaInserido = 1; //Numero ja inserido no vetor
                printf("numero repetido gerado...\n");

                break;
            }
        }

        if (jaInserido == 0){
            vetor [posicaoDoUltimoNumeroInserido] = numero;
            posicaoDoUltimoNumeroInserido++;
        }
    }

    for (int i = 0; i < posicaoDoUltimoNumeroInserido; i++){
        printf("%d\t", vetor[i]);
    }

    printf("\n");

    return 1;
}