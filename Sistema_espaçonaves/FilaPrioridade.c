#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"

NoFila* criar_fila() {
    return NULL;
}

void inserir_na_fila(NoFila** fila, Espaconave nave) {
    NoFila* novo_no = malloc(sizeof(NoFila));
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
        printf("Prioridade da nave: %d\n", atual->nave.prioridade);

        for(int i=0; i<atual->nave.num_passageiros; i++) {
            printf("[Passageiro: %d]", i+1);
            printf("[Nome: %s]", atual->nave.passageiros[i].nome);
            printf("[Idade: %d]", atual->nave.passageiros[i].idade);
            printf("[Planeta de origem: %s]", atual->nave.passageiros[i].planeta_origem);
            printf("[Identificador único: %d]\n", atual->nave.passageiros[i].identificador_unico);
        }
        printf("\n");
        for(int i=0; i<atual->nave.num_recursos; i++) {
            printf("[Recurso: %d]", i+1);
            printf("[%s]", atual->nave.recursos[i].nome);
            printf("[Quantidade: %d]\n", atual->nave.recursos[i].quantidade);
        }
        printf("------------------------------------------------------------------------------------------------------ \n");
        atual = atual->proximo;
    }
}

void menu(NoFila* fila) {
    int opcao;

    do {
        printf("\nBase de lançamento:\n");
        printf("1. Imprimir naves\n");
        printf("2. Decolar nave\n");
        printf("3. Sair\n");
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
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

    } while(opcao != 3);
}
