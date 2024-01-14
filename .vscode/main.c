#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Como C é uma linguagem muito próxima da de máquina, é necessário escrever sem espaçamento para funcionar

// Estrutura para armazenar informações do usuário
typedef struct {
    char nome[50];
    char telefone[15];
} Usuario;

// Estrutura para armazenar informações do agendamento
typedef struct {
    char nome[50];
    char telefone[15];
    char dia[20];
    char horario[20];
    char especialidade[30];
} Agendamento;

// Função para adicionar um novo usuário
void adicionarUsuario(Usuario **usuarios, int *numUsuarios) {
    *usuarios = realloc(*usuarios, (*numUsuarios + 1) * sizeof(Usuario));
  
    printf("Digite o Nome: ");
    scanf("%s", (*usuarios)[*numUsuarios].nome);

    printf("Digite o Telefone: ");
    scanf("%s", (*usuarios)[*numUsuarios].telefone);

    (*numUsuarios)++;
}

// Função para mostrar a lista de usuários
void mostrarUsuarios(Usuario *usuarios, int numUsuarios) {
    printf("\nLista de Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("\n%s\t%s\n", usuarios[i].nome, usuarios[i].telefone);
    }
}

// Função para adicionar um novo agendamento
void agendar(Agendamento **agendamentos, int *numAgendamentos, Usuario *usuarios, int numUsuarios) {
    *agendamentos = realloc(*agendamentos, (*numAgendamentos + 1) * sizeof(Agendamento));

    printf("\nEscolha o usuário pelo número:\n");
    mostrarUsuarios(usuarios, numUsuarios);

    int escolha;
    printf("\nDigite o número do usuário: \n");
    scanf("%d", &escolha);

    if (escolha >= 0 && escolha < numUsuarios) {
        strcpy((*agendamentos)[*numAgendamentos].nome, usuarios[escolha].nome);
        strcpy((*agendamentos)[*numAgendamentos].telefone, usuarios[escolha].telefone);

        printf("Digite o Dia: ");
        scanf("%s", (*agendamentos)[*numAgendamentos].dia);

        printf("Digite o Horário: ");
        scanf("%s", (*agendamentos)[*numAgendamentos].horario);

        printf("Digite a Especialidade: ");
        scanf("%s", (*agendamentos)[*numAgendamentos].especialidade);

        (*numAgendamentos)++;
    } else {
        printf("Número de usuário inválido!\n");
    }
}

// Função para mostrar a lista de agendamentos
void mostrarAgendamentos(Agendamento *agendamentos, int numAgendamentos) {
    printf("\nLista de Agendamentos:\n");
    for (int i = 0; i < numAgendamentos; i++) {
        printf("\n%s\t%s\t%s\t%s\t%s\n", agendamentos[i].nome, agendamentos[i].telefone,
               agendamentos[i].dia, agendamentos[i].horario, agendamentos[i].especialidade);
    }
}

// Função para excluir um agendamento
void excluirAgendamento(Agendamento **agendamentos, int *numAgendamentos) {
    printf("\nEscolha o agendamento pelo número:\n");
    mostrarAgendamentos(*agendamentos, *numAgendamentos);

    int escolha;
    printf("\nDigite o número do agendamento: \n");
    scanf("%d", &escolha);

    if (escolha >= 0 && escolha < *numAgendamentos) {
        for (int i = escolha; i < *numAgendamentos - 1; i++) {
            (*agendamentos)[i] = (*agendamentos)[i + 1];
        }
        *agendamentos = realloc(*agendamentos, (*numAgendamentos - 1) * sizeof(Agendamento));
        (*numAgendamentos)--;
        printf("\nAgendamento excluído com sucesso!\n");
    } else {
        printf("\nNúmero de agendamento inválido!\n");
    }
}

int main() {
    printf("É necessário escrever sem espaçamento para funcionar\n");
    Usuario *usuarios = NULL;
    int numUsuarios = 0;

    Agendamento *agendamentos = NULL;
    int numAgendamentos = 0;

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("\n1. Adicionar Usuário\n");
        printf("2. Mostrar Lista de Usuários e Agendar\n");
        printf("3. Mostrar Lista de Agendamentos e Excluir\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarUsuario(&usuarios, &numUsuarios);
                printf("\nUsuário cadastrado com sucesso!\n");
                    
                break;
            case 2:
                printf("\nA lista começa a partir do número 0.\n");
                //mostrarUsuarios(usuarios, numUsuarios);
                agendar(&agendamentos, &numAgendamentos, usuarios, numUsuarios);
                break;
            case 3:
                printf("\nA lista começa a partir do número 0.\n");
                //mostrarAgendamentos(agendamentos, numAgendamentos);
                excluirAgendamento(&agendamentos, &numAgendamentos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada
    free(usuarios);
    free(agendamentos);

    return 0;
}