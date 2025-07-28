//sortear TAM n°s (até TA n°s) no vetor, porém não inserir n°s já presentes no vetor. Ao final, exibir o vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main (){
    int vetor[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++){
        vetor[i] = rand(10) % 100;
    }

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }

    printf("\n");
    
    return 1;
}