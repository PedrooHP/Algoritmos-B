// Sistema de pedidos para estabelecimentos de venda de lanches

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
        Pedido pedidos[MAX_pedidos];    // Vetor de pedidos com capacidade máxima de pedidos
        int quantidadePedidos = 0;     // Contador de pedidos registrados
        int opcao;                    // Armazena a opção do menu escolhida pelo usuário
    

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
            case 1: // Adicionar novo pedido
                if (quantidadePedidos == MAX_pedidos){
                    cout << "Já tem muitos pedidos no sistema\n";
                } else {
                    cout << "Nome do cliente: \n";
                    getline (cin, pedidos[quantidadePedidos].nomeCliente);

                    cout << "Nome do pedido: \n";
                    getline (cin, pedidos[quantidadePedidos].itemPedido);

                    cout << "Valor do pedido: \n";
                    cin >> pedidos[quantidadePedidos].valor;

                    pedidos[quantidadePedidos].status = "Em preparo"; // Define o status inicial do pedido
                    quantidadePedidos++; // Incrementa o número de pedidos registrados

                    cout << "Pedido registrado\n";
                }
                break;

            case 2: // Atualiza o status do pedido
                if (quantidadePedidos == 0){
                    cout << "Não tem nenhum pedido para atualizar\n";
                } else {
                    cout << "Atualizar status do pedido\n";
                    for (int i= 0; i < quantidadePedidos; i++){
                        // Exibe cada pedido com índice para escolha
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
                        getline (cin, pedidos[indice].status); // Linha responsável por atualizar status
                        cout << "Status atualizado com sucesso!\n";
                    } else {
                        cout << "indice invalido!\n";
                    }
                }

                break;

            case 3: // Lista de pedidos
                cout << "Listar todos os pedidos: \n";
                if (quantidadePedidos == 0){
                    cout << "Não há nenhum pedido!";
                } else {
                    cout << "L I S T A  D E  P E D I D O S\n";
                    for (int i = 0; i < quantidadePedidos; i++){
                        // Exibe todos os dados de cada pedido
                        cout << "Cliente: " << pedidos[i].nomeCliente
                             << ", Item pedido: " << pedidos[i].itemPedido
                             << ", Valor do pedido: " << pedidos[i].valor
                             << ", Satus: " << pedidos[i].status << endl;
                    }
                }
                break;

            case 4: // Mostra o total faturado no dia
                cout << "Mostrar total faturado: \n";
                float totalFaturado = 0; // Inicializa a variável

                for (int i = 0; i < quantidadePedidos; i++){
                    if (pedidos[i].status == "entregue"){
                        // Soma apenas os pedidos com status "entregue
                        totalFaturado += pedidos[i].valor;
                    }
                }
                cout << "total faturado no dia: " << totalFaturado << endl;
                break;

            case 5: // Fecha o programa
                cout << "Fechar o programa\n";
                break;

            default:
                cout << "Opcao invalida\n";
                break;
            
        } 
    } while (opcao != 5);

    return 0;
}