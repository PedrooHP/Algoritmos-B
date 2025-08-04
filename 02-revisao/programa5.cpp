#include <iostream> //<stdio.h>
#include <string>   //<string.h>
 
#define TAM 4
 
using namespace std;
 
//criando um tipo ou uma estrutura artificial
typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;
 
int main() {
    Carro garagem[TAM];
    Carro carro;
 
    for (int i = 0; i < TAM; i++) {
        cout << "Placa: ";
        cin >> carro.placa;
        cout << "Hora de entrada: ";
        cin >> carro.horaEntrada;        
 
        garagem[i] = carro;
    }
 
    cout << "Carros na garagem\n";
    for (int i = 0; i < TAM; i++) {
        cout << "Placa: " << garagem[i].placa << ". Hora entrada: " << garagem[i].horaEntrada << "\n";
    }
 
   
 
    return 1;
}