#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"


struct elemento{
    struct espaconave dados;
    struct elemento* proximo;
};

typedef struct elemento Elemento;

Fila* criar(){
    Fila* f;
    f = (Fila*)malloc(sizeof(Fila));
    if(f != NULL){
        *f =NULL;

    }
    return f;
}
/*
int insere(Fila* fila, struct espaconave cuzas){
    if(fila == NULL){
        return 0;
    }
    Elemento* novo =(Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL){
        return 0;
    }
    Elemento* aux = *fila;
    while(aux != NULL){
        aux = aux->proximo;
    }
    novo->dados = cuzas;
    novo->proximo = (*fila);
    *fila = novo;
    return 1;
}
*/

int insere(Fila *fila, Espaconave nave) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) {
        return 0;
    }

    novo->dados = nave;
    novo->proximo = NULL;
//comaparo a prioridade da nova nave com a da primeira da fila
    if (*fila == NULL || nave.prioridade > (*fila)->dados.prioridade) {
        //se entrar no if então eu coloco ela no começo da fila
        novo->proximo = *fila;
        *fila = novo;
        return 1;
    }
//caso não entre eu percorro a fila de acordo com a prioridade
    Elemento *atual = *fila;
    while (atual->proximo != NULL && atual->proximo->dados.prioridade >= nave.prioridade) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

//removo sempre o primeiro elemento da fila
Espaconave remove_nave(Fila *fila) {
    if (fila == NULL || *fila == NULL) {
        Espaconave nave_vazia;
        nave_vazia.prioridade = -1;
        return nave_vazia;
    }

    Espaconave nave_maior_prioridade = (*fila)->dados;
    Elemento *removido = *fila;
    *fila = (*fila)->proximo;
    free(removido);

    return nave_maior_prioridade;
}

int imprimeFila(Fila* fila) {
    if(fila == NULL) {
        printf("Fila vazia.");
        return 0;
    } else {
        Elemento *aux = *fila;
        while(aux != NULL) {
            printf("\nNumero de passageiros: %d\n", aux->dados.numPassageiros);
            printf("Nome do passageiro: %s\n", aux->dados.dados.nome);
            printf("Idade do passageiro: %d\n", aux->dados.dados.idade);
            printf("prioridade da nave: %d\n", aux->dados.prioridade);
            aux = aux->proximo;
        }
        return 1;
    }
}


