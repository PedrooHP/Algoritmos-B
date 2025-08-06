#include <iostream>
#include <string>
#define TAM 5
using namespace std; //Permite o uso direto dos elementos do namespace std (como cout, cin, string)
 
// Define um tipo de dado Carro com placa, hora de entrada, hora de saída e valor
typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;
 
int main() {
    Carro garagem[TAM];             // Declara um vetor de carros com capacidade para TAM veículos
    Carro carro;                    // Variável auxiliar para ler os dados de um carro
    int quantidadeCarros = 0;       // Contador de quantos carros estão atualmente na garagem
    int opcao = 1;                  // Variável para armazenar a opção escolhida pelo usuário no menu
 
    while (opcao != 4) {            // Loop principal que continua até o usuário escolher a opção 4 (Fim)
        
        cout << "M E N U\n";
        cout << "1 - Entra carro\n";
        cout << "2 - Sai carro\n";
        cout << "3 - Lista carros\n";
        cout << "4 - Fim\n";
        cout << "Opcao: ";
        cin >> opcao;               // Lê a opção escolhida
 
        switch (opcao) {
            case 1:
                cout << "Entrada do carro na garagem....\n";
                if (quantidadeCarros == TAM) {                  // Verifica se a garagem está cheia
                    cout << "Nao ha vagas na garagem....\n";
                } else {
                    cout << "Placa: ";                          // Solicita a placa do carro
                    cin >> carro.placa;                         // Lê a placa do carro
 
                    //Rotina que verificasse se esta placa ja esta na garagem

                    int i;
                    for (i = 0; i < quantidadeCarros; i++){                 // Percorre todos os carros na garagem
                        if (garagem[i].placa == carro.placa){               // Compara a placa digitada com as já armazenadas
                            cout << "Este carro já existe na garagem\n";
                            break;
                        }
                    }

                    if (i == quantidadeCarros){                             // Se não encontrou a placa (ou seja, o loop terminou normalmente)
                        cout << "Hora de entrada: ";
                        cin >> carro.horaEntrada;
                        garagem[ quantidadeCarros ] = carro;                // Armazena o carro na garagem
                        quantidadeCarros++;                                 // Incrementa o número de carros na garagem
                        cout << "Imprimindo o ticket....\n";
                    }
   
                    
                }
                break;
            case 2:
                cout << "Saindo carro na garagem....\n";
                break;
            case 3:
                cout << "Listagem de carros na garagem....\n";
                if (quantidadeCarros == 0) {                                // Verifica se não há carros
                    cout << "Nao ha carros na garagem ....\n";
                } else {
                    for (int i = 0; i < quantidadeCarros; i++) {            // Percorre e lista todos os carros
                        cout << "Carro com placa: " << garagem[i].placa << ". Hora entrada: " << garagem[i].horaEntrada << "\n";        // Exibe placa e hora de entrada
                    }
                }
                break;
            case 4:
                cout << "Obrigado por usar o sistema....\n";
                break;
            default:
                cout << "Opcao invalida.....\n";
                break;
        }
        system("pause");
    }
 
    return 1;
}