#include <iostream>
#include "meusTipos.h"
#include "minhasFuncoes.h"

using namespace std;

void executarPrograma(){
    Aluno turma[TAM];
    lerAlunos (turma);
    exibirAlunos (turma);
    float mediaFinal = calcularMediaGeral (turma);

    cout << "\n Media geral: " << mediaFinal << endl;

    cout << "\n programa finalizado ";

}
int main (){
    executarPrograma();
    return 0;
}