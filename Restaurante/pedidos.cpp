#include <iostream>
#include <string>
#define MAX_pedidos 10

using namespace std;         // Permite o uso direto dos elementos do namespace std (como cout, cin, string)
 
struct Pedido {
    string nomeCliente;           
    string itemPedido;      
    string status;        
    float valor;             
};

    int main(){
        Pedido numero [MAX_pedidos];
        int quantidadePedidos = 0;
        int opcao;
    

    do{
        cout << "=== M E N U  R E S T A U R A N T E ===";
        cout << "1 - Entrar com um novo pedido\n";
        cout << "2 - Atualizar o pedido\n";
        cout << "3 - Listar todos os pedidos\n";
        cout << "4 - Mostrar total faturado\n";
        cout << "5 - Fechar o programa\n";
        cin >> opcao;

        cin.ignore();       // Limpa o buffer do cin

        swtich (opcao){
            case 1:
                if (quantidadePedidos == MAX_pedidos){
                    cout << "Já tem muitos pedidos no sistema\n";
                } else {
                    cout << "Nome do cliente: \n";
                    getline (cin, pedidos[quantidadePedidos].nomeCliente);

                    cout << "Nome do pedido: \n";
                    getline (cin, pedidos [quantidadePedidos].itemPedido);

                    cout << "Valor do pedido: \n";
                    getline (cin, pedidos [quantidadePedidos].valor);

                    pedidos[quantidadePedidos].status = "Em preparo";
                    quantidadePedidos++;

                    cout << "Pedido registrad\n";
                }
                break;

            case 2:
                cout << "Atualizar status do pedido\n";
                //Implementar
                break;

            case 3:
                cout << "Listar todos os pedidos: \n";
                //Implementar
                break;

            case 4:
                cout << "Mostrar total faturado: \n";
                //implementar
                break;

            case 5:
                cout << "Fechar o programa\n";
                break;

            default;
                cout << "Opcao invalida\n";
                break;
            
        } 
    } while (opcao != 5);

    return 0;
}