#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <bits/stdc++.h> // BIBLIOTECA PARA FAZER A FUNÇÃO DO VALIDADOR DE DATA E HORA

using namespace std;

// 1. FUNÇÕES AUXILIARES DE GARAGEM E VALIDAÇÃO

// Busca um veículo pela placa e retorna o índice, ou -1 se não encontrar.
int buscarPlaca(Veiculo garagem[], int qtdVeiculos, string placa) {
    for (int i = 0; i < qtdVeiculos; i++) {
        if (garagem[i].placa == placa) {
            return i; // Placa encontrada no índice i
        }
    }
    return -1; // Não encontrado
}

// Salva todo o vetor 'garagem' no arquivo CSV (reescreve a base)
void salvarBase(string nomeBaseDados, Veiculo garagem[], int qtdVeiculos) {
    ofstream escritorArquivo;
    // O modo 'out' (padrão) apaga o conteúdo anterior e reescreve.
    escritorArquivo.open(nomeBaseDados); 

    for (int i = 0; i < qtdVeiculos; i++) {
        // Formato CSV: PLACA,DATA_ENTRADA
        escritorArquivo << garagem[i].placa << ","
                       << garagem[i].dataEntrada;
        
        // Adiciona uma nova linha, exceto para o último registro
        if (i < qtdVeiculos - 1) {
            escritorArquivo << "\n";
        }
    }

    escritorArquivo.close();
}


// Valida se a string tem o formato AAAA-MM-DD_HH:MM (16 caracteres)
// E se o MÊS e o DIA são numericamente válidos.

bool validarFormatoDataHora(string dataHora) {
    // 1. Checagem
    if (dataHora.size() != 16) {
        return false;
    }
    if (dataHora[4] != '-' || dataHora[7] != '-' || dataHora[10] != '_' || dataHora[13] != ':') {
        return false;
    }
    for (int i = 0; i < 16; i++) {
        if (i == 4 || i == 7 || i == 10 || i == 13) continue;
        if (!isdigit(dataHora[i])) return false;
    }
    // Exemplo de como ficaria aplicado 'DDDD-DD-DD_DD:DD' com dígitos

    // 2. VALIDAÇÃO NUMÉRICA DO CALENDÁRIO
    try {
        // Extrai o Mês (índices 5 e 6)
        string strMes = dataHora.substr(5, 2);
        int mes = stoi(strMes);
        
        // Extrai o Dia (índices 8 e 9)
        string strDia = dataHora.substr(8, 2);
        int dia = stoi(strDia);
        
        // Extrai a Hora (índices 11 e 12)
        string strHora = dataHora.substr(11, 2);
        int hora = stoi(strHora);

        // Extrai o Minuto (índices 14 e 15)
        string strMinuto = dataHora.substr(14, 2);
        int minuto = stoi(strMinuto);

        // Checagem de Lógica:
        
        // Checa o MÊS (1 a 12)
        if (mes < 1 || mes > 12) {
            return false;
        }

        // Checa o DIA (1 a 31)

        if (dia < 1 || dia > 31) {
            return false;
        }

        // Checa HORA (0 a 23)
        if (hora < 0 || hora > 23) {
            return false;
        }

        // Checa MINUTO (0 a 59)
        if (minuto < 0 || minuto > 59) {
            return false;
        }

        // Se passar por todas as checagens numéricas, retorna true
        return true; 
        
    } catch (...) {
        // Captura qualquer erro de conversão (stoi) que o checagem de isdigit não pegou.
        return false;
    }
}


// 2. FUNÇÕES DO MENU DA GARAGEM

// Opção 1: Entrada de veículo (Inserir no vetor E no arquivo)

void entradaVeiculo(string nomeBaseDados, Veiculo garagem[], int tamanho, int *qtdVeiculos) {
    if (*qtdVeiculos == tamanho) {
        cout << "Garagem lotada. Entrada negada.\n";
        return;
    }

    Veiculo novoVeiculo;
    string placa;
    string dataEntrada;

    cout << "\n--- Entrada de Veiculo ---\n";

    // 1. VALIDAÇÃO DA PLACA (Placa com 7 caracteres e não duplicada)
    do {
        cout << "Digite a placa (7 caracteres, ex: ABC1234): ";
        cin >> placa;

        if (placa.size() == 7) {
            // Verifica se a placa já está na garagem (em memória)
            if (buscarPlaca(garagem, *qtdVeiculos, placa) != -1) {
                cout << "ERRO: Veiculo com esta placa ja esta na garagem. Tente novamente.\n";
            } else {
                novoVeiculo.placa = placa;
                break; // Sai do loop da placa
            }
        } else {
            cout << "ERRO: Placa invalida. Deve conter 7 caracteres. Tente novamente.\n";
        }
    } while (true);


    // 2. VALIDAÇÃO DA DATA/HORA (Formato AAAA-MM-DD_HH:MM)
    do {
        cout << "Digite a Data e Hora de Entrada (Formato AAAA-MM-DD_HH:MM): ";
        cin >> dataEntrada;

        // Chama a função robusta para validar o formato
        if (validarFormatoDataHora(dataEntrada)) {
            novoVeiculo.dataEntrada = dataEntrada;
            break; // Sai do loop da data
        } else {
            cout << "Formato invalido ou contem caracteres invalidos. Use AAAA-MM-DD_HH:MM e apenas numeros nos campos.\n";
        }
    } while (true);
    
    // 3. Salva no vetor e no arquivo
    garagem[*qtdVeiculos] = novoVeiculo;
    *qtdVeiculos += 1; 

    salvarBase(nomeBaseDados, garagem, *qtdVeiculos); 
    
    cout << "\nVeiculo " << placa << " registrado e salvo na base de dados.\n";
}

// Opção 3: Saída de veículo (Remover do vetor e do arquivo)
void saidaVeiculo(string nomeBaseDados, Veiculo garagem[], int *qtdVeiculos) {
    string placa;
    cout << "\n--- Saida de Veiculo ---\n";
    cout << "Placa do veiculo a sair: ";
    cin >> placa;

    // 1. Busca a placa no vetor
    int indice = buscarPlaca(garagem, *qtdVeiculos, placa);

    if (indice == -1) {
        cout << "Placa nao encontrada na garagem.\n";
        return;
    }
    
    // 2. Remove do vetor (substitui o item a ser removido pelo último)
    garagem[indice] = garagem[*qtdVeiculos - 1]; // Move o último para a posição do removido
    
    *qtdVeiculos -= 1; // Reduz a quantidade de veículos
    
    // 3. Salva a alteração no arquivo
    salvarBase(nomeBaseDados, garagem, *qtdVeiculos); 
    
    cout << "Veiculo " << placa << " removido e base de dados. Vaga liberada.\n";
}