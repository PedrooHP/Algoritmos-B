#include <cstdlib>
#include <time.h>
#include <string.h>

void popular (int vetor[], int quantidade, int tamanho){
    if (quantidade > tamanho){
        cout << "Essa quantidade não eh possivel...";
        return; //forcando a saida do metodo
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++){
        vetor[i] = rand() % 100;
    }
}

void exibir (string frase, int vetor[], )