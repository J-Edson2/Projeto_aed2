#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"
// Cria uma nova fila e retorna um ponteiro NULL, indicando que a fila está inicialmente vazia.
NoFila* criar_fila() {
    return NULL;
}

// Insere uma espaçonave na fila de acordo com sua prioridade.
// Se a fila estiver vazia, a espaçonave é inserida no início.
// Caso contrário, a função percorre a fila para encontrar a posição correta para inserir a espaçonave.
void inserir_na_fila(NoFila** fila, Espaconave nave) {
    NoFila* novo_no = malloc(sizeof(NoFila));
// Verifica os dados da nave antes de inserir na fila
    verificar_dados(&nave);

    novo_no->nave = nave;
    novo_no->proximo = NULL;

    if (*fila == NULL) {
        *fila = novo_no;
    } else {
        NoFila* atual = *fila;
        NoFila* anterior = NULL;

        while (atual != NULL && atual->nave.prioridade >= nave.prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            novo_no->proximo = *fila;
            *fila = novo_no;
        } else {
            novo_no->proximo = anterior->proximo;
            anterior->proximo = novo_no;
        }
    }
}


// Remove e retorna a espaçonave no início da fila.
// Se a fila estiver vazia, imprime uma mensagem e retorna uma espaçonave vazia.
Espaconave remover_da_fila(NoFila** fila) {
    if (*fila == NULL) {
        printf("A fila está vazia!\n");
        Espaconave nave_vazia = {0};
        return nave_vazia;
    } else {
        NoFila* no_removido = *fila;
        *fila = no_removido->proximo;

        Espaconave nave_removida = no_removido->nave;
        free(no_removido);

        return nave_removida;
    }
}
void exibir_fila(NoFila* fila) {
    NoFila* atual = fila;

    while (atual != NULL) {
        printf("--------------------------------------------------------------------------------\n");
        printf("| Prioridade da nave: %-57d |\n", atual->nave.prioridade);
        printf("| Passageiros:\n");
        printf("| %-20s | %-5s | %-20s | %-20s |\n", "Nome", "Idade", "Planeta de Origem", "Identificador Único");

        for(int i=0; i<atual->nave.num_passageiros; i++) {
            printf("| %-20s | %-5d | %-20s | %-20d |\n", atual->nave.passageiros[i].nome, atual->nave.passageiros[i].idade, atual->nave.passageiros[i].planeta_origem, atual->nave.passageiros[i].identificador_unico);
        }

        printf("--------------------------------------------------------------------------------\n");
        printf("| Recursos:\n");
        printf("| %-30s | %-10s |\n", "Nome", "Quantidade");

        for(int i=0; i<atual->nave.num_recursos; i++) {
            printf("| %-30s | %-10d |\n", atual->nave.recursos[i].nome, atual->nave.recursos[i].quantidade);
        }

        printf("--------------------------------------------------------------------------------\n");
        atual = atual->proximo;
    }
}
// Função para inserir manualmente os dados de uma espaçonave.
Espaconave inserir_nave_manualmente() {
    // Declara uma variável 'nave' do tipo Espaconave.
    Espaconave nave;

    // Solicita ao usuário que insira a prioridade da nave.
    printf("Digite a prioridade da nave: ");
    scanf("%d", &nave.prioridade);

    // Solicita ao usuário que insira o número de passageiros.
    printf("Digite o número de passageiros: ");
    scanf("%d", &nave.num_passageiros);

    // Aloca memória para armazenar os detalhes dos passageiros.
    nave.passageiros = malloc(nave.num_passageiros * sizeof(Passageiro));

    // Para cada passageiro, solicita ao usuário que insira o nome, idade, planeta de origem e identificador único.
    for (int i = 0; i < nave.num_passageiros; i++) {
        printf("Digite o nome, idade, planeta de origem e identificador único do passageiro %d:  \n", i+1);
        scanf("%s %d %s %d", nave.passageiros[i].nome, &nave.passageiros[i].idade,
              nave.passageiros[i].planeta_origem, &nave.passageiros[i].identificador_unico);
    }

    // Solicita ao usuário que insira o número de recursos.
    printf("Digite o número de recursos: ");
    scanf("%d", &nave.num_recursos);

    // Aloca memória para armazenar os detalhes dos recursos.
    nave.recursos = malloc(nave.num_recursos * sizeof(Recurso));

    // Para cada recurso, solicita ao usuário que insira o nome e a quantidade.
    for (int i = 0; i < nave.num_recursos; i++) {
        printf("Digite o nome e quantidade do recurso %d: ", i+1);
        scanf("%s %d", nave.recursos[i].nome, &nave.recursos[i].quantidade);
    }

    // Retorna a espaçonave com os detalhes inseridos pelo usuário.
    return nave;
}

//menu de interação do usuário
void menu(NoFila* fila) {
    int opcao;
    Espaconave nave;
    do {
        printf("\nBase de lançamento:\n");
        printf("1. Imprimir naves\n");
        printf("2. Decolar nave\n");
        printf("3. Inserir nave manualmente\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                exibir_fila(fila);
                break;
            case 2:
                remover_da_fila(&fila);
                break;
            case 3:
                nave = inserir_nave_manualmente();
                inserir_na_fila(&fila, nave);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

    } while(opcao != 4);
}

// Verifica os dados de uma espaçonave. Gera um número entre 0 e 9, se esse número for 1, ou seja, 10% de chance. Então eu gero outro valor entre 0 e 99 e atribuo esse valor a nave
int verificar_dados(Espaconave* nave) {
    int random = rand() % 10;
    if (random == 1) {
        nave->prioridade = rand() % 100;
        return 1;
    }

    return 0;
}
