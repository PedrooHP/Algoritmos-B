#include <iostream>
#include <string>
using namespace std;

// Função que verifica se uma data é válida
void verificarData(const string& diaStr, const string& mesStr, const string& anoStr) {
    int dia = stoi(diaStr);   // converte string para inteiro
    int mes = stoi(mesStr);
    int ano = stoi(anoStr);

    bool valida = true;

    // Verifica mês
    if (mes < 1 || mes > 12) {
        valida = false;
    } else {
        // Dias máximos por mês
        int diasNoMes;
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                diasNoMes = 31; break;
            case 4: case 6: case 9: case 11:
                diasNoMes = 30; break;
            case 2: // Fevereiro
                // Ano bissexto
                if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                    diasNoMes = 29;
                else
                    diasNoMes = 28;
                break;
        }

        // Verifica dia
        if (dia < 1 || dia > diasNoMes) {
            valida = false;
        }
    }

    if (valida)
        cout << "DATA VÁLIDA\n";
    else
        cout << "DATA INVÁLIDA\n";
}

int main() {
    string dia, mes, ano;

    cout << "Digite o dia: ";
    cin >> dia;
    cout << "Digite o mês: ";
    cin >> mes;
    cout << "Digite o ano: ";
    cin >> ano;

    verificarData(dia, mes, ano);

    return 0;
}