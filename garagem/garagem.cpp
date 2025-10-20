#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> // Para funções de string se necessário

#define TAM 100 // Tamanho máximo da garagem

using namespace std;

// Inclui as structs Veiculo e Pessoa
#include "meusTipos.h" 

// Inclui as funções auxiliares
#include "meusMetodos.h" 


// FUNÇÕES DE EXIBIÇÃO 
// Função 2 do Menu: Listar Veículos

void listarVeiculos(Veiculo garagem[], int qtdVeiculos) {
    cout << "\n--- Veiculos na Garagem ---\n";
    if (qtdVeiculos == 0) {
        cout << "A garagem esta vazia.\n";
        return;
    }
    for (int i = 0; i < qtdVeiculos; i++) {
        cout << i + 1 << ". Placa: " << garagem[i].placa 
             << ". Entrada: " << garagem[i].dataEntrada << endl;
    }
    cout << "---------------------------\n";
    cout << "Total de veiculos: " << qtdVeiculos << endl;
}

// 'conectarBase' Veiculos do CSV
int carregarBaseVeiculos(string nomeBaseDados, Veiculo garagem[], int tamanho) {
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeBaseDados);

    if (!procuradorArquivo) {
        cout << "AVISO: Arquivo '" << nomeBaseDados << "' nao localizado. Iniciando garagem vazia.\n";
        return 0; // Retorna 0 veículos se o arquivo não existir
    }
    
    int qtdVeiculos = 0;
    string linha;
    
    while (getline(procuradorArquivo, linha) && qtdVeiculos < tamanho) {
        if (linha.empty()) continue; 
        
        // Simulação da lógica de split (Placa,DataEntrada)
        size_t pos = linha.find(',');
        if (pos != string::npos) {
            garagem[qtdVeiculos].placa = linha.substr(0, pos);
            garagem[qtdVeiculos].dataEntrada = linha.substr(pos + 1);
            qtdVeiculos++;
        }
    }

    procuradorArquivo.close();
    cout << "Base de dados carregada. Total de veiculos: " << qtdVeiculos << ".\n";
    return qtdVeiculos;
}


// FUNÇÃO DO MENU PRINCIPAL

void menuGaragem(string baseDados, Veiculo garagem[], int tamanho, int qtdVeiculos) {
    int opcao;
    
    // As chamadas para as opções 1 e 3 estão criadas no arquivo meusMetodos.h
    do {
        system("cls"); // Limpa a tela (infelizmente não funciona)
        cout << "\n================================\n";
        cout << "        MENU GARAGEM\n";
        cout << "================================\n";
        cout << "1) Entrada veiculo\n";
        cout << "2) Listagem veiculos\n";
        cout << "3) Saida veiculo\n";
        cout << "4) Fim programa\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1: 
            entradaVeiculo(baseDados, garagem, tamanho, &qtdVeiculos); // CHAMADA DA FUNÇÃO
            // cout << "\n[Opcao 1] - Logica de Entrada de Veiculo
            break;
        case 2:
            listarVeiculos(garagem, qtdVeiculos);
            break;
        case 3:
            saidaVeiculo(baseDados, garagem, &qtdVeiculos); // CHAMADA DA FUNÇÃO
            // cout << "\n[Opcao 3] - Logica de Saida de Veiculo
            break;
        case 4:
            cout << "Finalizando o programa...\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
        
        // Pausa no console para visualização
        if (opcao != 4) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcao != 4);
}


// MAIN

int main() {
    Veiculo garagem[TAM];
    int qtdVeiculos = 0;
    string baseDados = "garagem.csv"; 

    // 1. Antes de executar o menu, carregarBase
    qtdVeiculos = carregarBaseVeiculos(baseDados, garagem, TAM);
    
    // 2. Executar o menu
    menuGaragem(baseDados, garagem, TAM, qtdVeiculos);
    
    return 0; // retornar 0
}