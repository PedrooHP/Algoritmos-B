#include <string>

// Estrutura para o projeto de Gestão de Pessoas
typedef struct {
    std::string nome;
    std::string email;
} Pessoa;

// Estrutura para o Desafio da Garagem
typedef struct {
    std::string placa;
    std::string dataEntrada; // Alterado de 'horaEntrada' para 'dataEntrada' para seguir o struct sugerido
} Veiculo;