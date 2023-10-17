#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"
// Cria uma nova fila e retorna um ponteiro NULL, indicando que a fila est� inicialmente vazia.
NoFila* criar_fila() {
    return NULL;
}

// Insere uma espa�onave na fila de acordo com sua prioridade.
// Se a fila estiver vazia, a espa�onave � inserida no in�cio.
// Caso contr�rio, a fun��o percorre a fila para encontrar a posi��o correta para inserir a espa�onave.
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


// Remove e retorna a espa�onave no in�cio da fila.
// Se a fila estiver vazia, imprime uma mensagem e retorna uma espa�onave vazia.
Espaconave remover_da_fila(NoFila** fila) {
    if (*fila == NULL) {
        printf("A fila est� vazia!\n");
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
        printf("| %-20s | %-5s | %-20s | %-20s |\n", "Nome", "Idade", "Planeta de Origem", "Identificador �nico");

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
// Fun��o para inserir manualmente os dados de uma espa�onave.
Espaconave inserir_nave_manualmente() {
    // Declara uma vari�vel 'nave' do tipo Espaconave.
    Espaconave nave;

    // Solicita ao usu�rio que insira a prioridade da nave.
    printf("Digite a prioridade da nave: ");
    scanf("%d", &nave.prioridade);

    // Solicita ao usu�rio que insira o n�mero de passageiros.
    printf("Digite o n�mero de passageiros: ");
    scanf("%d", &nave.num_passageiros);

    // Aloca mem�ria para armazenar os detalhes dos passageiros.
    nave.passageiros = malloc(nave.num_passageiros * sizeof(Passageiro));

    // Para cada passageiro, solicita ao usu�rio que insira o nome, idade, planeta de origem e identificador �nico.
    for (int i = 0; i < nave.num_passageiros; i++) {
        printf("Digite o nome, idade, planeta de origem e identificador �nico do passageiro %d:  \n", i+1);
        scanf("%s %d %s %d", nave.passageiros[i].nome, &nave.passageiros[i].idade,
              nave.passageiros[i].planeta_origem, &nave.passageiros[i].identificador_unico);
    }

    // Solicita ao usu�rio que insira o n�mero de recursos.
    printf("Digite o n�mero de recursos: ");
    scanf("%d", &nave.num_recursos);

    // Aloca mem�ria para armazenar os detalhes dos recursos.
    nave.recursos = malloc(nave.num_recursos * sizeof(Recurso));

    // Para cada recurso, solicita ao usu�rio que insira o nome e a quantidade.
    for (int i = 0; i < nave.num_recursos; i++) {
        printf("Digite o nome e quantidade do recurso %d: ", i+1);
        scanf("%s %d", nave.recursos[i].nome, &nave.recursos[i].quantidade);
    }

    // Retorna a espa�onave com os detalhes inseridos pelo usu�rio.
    return nave;
}

//menu de intera��o do usu�rio
void menu(NoFila* fila) {
    int opcao;
    Espaconave nave;
    do {
        printf("\nBase de lan�amento:\n");
        printf("1. Imprimir naves\n");
        printf("2. Decolar nave\n");
        printf("3. Inserir nave manualmente\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida!\n");
                break;
        }

    } while(opcao != 4);
}

// Verifica os dados de uma espa�onave. Gera um n�mero entre 0 e 9, se esse n�mero for 1, ou seja, 10% de chance. Ent�o eu gero outro valor entre 0 e 99 e atribuo esse valor a nave
int verificar_dados(Espaconave* nave) {
    int random = rand() % 10;
    if (random == 1) {
        nave->prioridade = rand() % 100;
        return 1;
    }

    return 0;
}
