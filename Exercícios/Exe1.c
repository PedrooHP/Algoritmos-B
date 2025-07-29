//sortear TAM n°s (até TAM n°s) no vetor, porém não inserir n°s já presentes no vetor. Ao final, exibir o vetor

#include <stdio.h>              // Biblioteca padrão de entrada e saída
#include <stdlib.h>             // Biblioteca para funções rand() e srand()
#include <time.h>               // Biblioteca para função time()

#define TAM 5                   // Define a constante TAM como 5 (tamanho do vetor)

int main (){
    int vetor[TAM];             // Declara um vetor de inteiros com tamanho TAM

    srand(time(NULL));          // Inicializa o gerador de números aleatórios com base no tempo atual

    int numero;                                             // Variável que armazenará o número aleatório gerado
    int jaInserido;                                        // Índice onde será inserido o próximo número no vetor
    int posicaoDoUltimoNumeroInserido = 0;                // Índice onde será inserido o próximo número no vetor

    for (int i = 0; i < TAM; i++){                       // Loop principal que tenta gerar até TAM números
        numero = rand() % 100;                          // Gera número aleatório entre 0 e 99
        jaInserido = 0;                                // Inicializa a flag como 0 (falso)

        for (int j = 0; j <= posicaoDoUltimoNumeroInserido; j++){                  // Verifica se o número já existe no vetor
            if (numero == vetor[j]){                                              // Compara número gerado com os já inseridos
                jaInserido = 1; //Numero ja inserido no vetor                    // Número já está no vetor
                printf("numero repetido gerado...\n");                          // Mostra que o número já foi repetido

                break;                                                         // Finaliza a função
            }
        }

        if (jaInserido == 0){                                                // Se número ainda não foi inserido
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