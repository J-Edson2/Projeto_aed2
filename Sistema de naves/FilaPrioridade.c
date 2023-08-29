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

            aux = aux->proximo;
        }
        return 1;
    }
}
