#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    srand(time(NULL)); //semeador

    int NumeroSorteado = rand() % 100; //sorteando numero entra 0 e 100
    printf ("%d\n", NumeroSorteado);

    return 1;
}