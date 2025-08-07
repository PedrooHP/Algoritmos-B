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

    int main() {
        Pedido pedidos[MAX_pedidos];
        int quantidadePedidos = 0;
        int opcao;
    

    do{
        cout << "=== M E N U  R E S T A U R A N T E ===\n";
        cout << "1 - Entrar com um novo pedido\n";
        cout << "2 - Atualizar o pedido\n";
        cout << "3 - Listar todos os pedidos\n";
        cout << "4 - Mostrar total faturado\n";
        cout << "5 - Fechar o programa\n";
        cin >> opcao;

        cin.ignore();       // Limpa o buffer do cin

        switch (opcao) {
            case 1:
                if (quantidadePedidos == MAX_pedidos){
                    cout << "Já tem muitos pedidos no sistema\n";
                } else {
                    cout << "Nome do cliente: \n";
                    getline (cin, pedidos[quantidadePedidos].nomeCliente);

                    cout << "Nome do pedido: \n";
                    getline (cin, pedidos[quantidadePedidos].itemPedido);

                    cout << "Valor do pedido: \n";
                    cin >> pedidos[quantidadePedidos].valor;

                    pedidos[quantidadePedidos].status = "Em preparo";
                    quantidadePedidos++;

                    cout << "Pedido registrado\n";
                }
                break;

            case 2:
                if (quantidadePedidos == 0){
                    cout << "Não tem nenhum pedido para atualizar\n";
                } else {
                    cout << "Atualizar status do pedido\n";
                    for (int i= 0; i < quantidadePedidos; i++){
                        cout << i << " - Cliente: " << pedidos[i].nomeCliente
                             <<", Pedido: " << pedidos[i].itemPedido
                             <<", Status atual" << pedidos[i].status << endl;
                    }
                    int indice;
                    cout << "Digite o número do pedido que deseja atualizar: ";
                    cin >> indice;
                    cin.ignore();

                    if (indice >= 0 && indice < quantidadePedidos){
                        cout << "Digite o novo status do pedido (pronto ou entregue): ";
                        getline (cin, pedidos[indice].status);
                        cout << "Status atualizado com sucesso!\n";
                    } else {
                        cout << "indice invalido!\n";
                    }
                }

                break;

            case 3:
                cout << "Listar todos os pedidos: \n";
                if (quantidadePedidos == 0){
                    cout << "Não há nenhum pedido!";
                } else {
                    cout << "L I S T A  D E  P E D I D O S\n";
                    for (int i = 0; i < quantidadePedidos; i++){
                        cout << "Cliente: " << pedidos[i].nomeCliente
                             << ", Item pedido: " << pedidos[i].itemPedido
                             << ", Valor do pedido: " << pedidos[i].valor
                             << ", Satus: " << pedidos[i].status << endl;
                    }
                }
                break;

            case 4:
                cout << "Mostrar total faturado: \n";
                float totalFaturado;
                totalFaturado = 0;

                for (int i = 0; i < quantidadePedidos; i++){
                    if (pedidos[i].status == "entregue"){
                        totalFaturado += pedidos[i].valor;
                    }
                }
                cout << "total faturado no dia: " << totalFaturado << endl;
                break;

            case 5:
                cout << "Fechar o programa\n";
                break;

            default:
                cout << "Opcao invalida\n";
                break;
            
        } 
    } while (opcao != 5);

    return 0;
}