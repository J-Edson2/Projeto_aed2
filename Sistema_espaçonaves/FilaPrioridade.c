#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"
/*
// Definição da estrutura Passageiro
typedef struct {
    char nome[50];
    int idade;
    int planetaOrigem;
    int identificadorUnico;
} Passageiro;

typedef struct {
    int agua;
    int comida;
    int combustivel;
} Recurso;

// Definição da estrutura Espaçonave
typedef struct {
    int prioridade;
    Passageiro* passageiros;
    int numPassageiros;
    Recurso* recursos;
} Espaconave;
*/

Filaprio* cria_fila(int tam){
    Filaprio* fila = (Filaprio*) malloc(sizeof(Filaprio));

    if(fila != NULL) {
        //*fila = NULL;
        fila->n = 0;
        fila->Tam = tam;
        fila->Dados = (Espaconave*) malloc(tam * sizeof(Espaconave));
        printf("Fila criada \n");
        if(fila->Dados != NULL){
            printf("Dados criados\n");
        } else {
            printf("Falha ao criar dados\n");
            exit(1);
        }
    } else {
        printf("Falha ao criar fila\n");
        exit(1);
    }

    return fila;
}

void destroi_fila(Filaprio **fila){
    free((*fila)->Dados);
    free(*fila);
    *fila = NULL;
}


int Fila_vazia(Filaprio *fila){
    return fila->n == 0;
}

int Fila_cheia(Filaprio *fila){
    return fila->n == fila->Tam;
}

void insere_nave(Filaprio* fila,Espaconave* nave){
   /* if(!Fila_cheia(fila)){
        fila->Dados = nave;
        fila->n++;
    }*/
}

void imprimir_fila(Filaprio* fila){
        printf("cuzao\n");
        printf("%s\n", fila->Dados->passageiros->nome/*, fila->Dados->passageiros->idade, fila->Dados->passageiros->planetaOrigem, fila->Dados->passageiros->identificadorUnico*/);
}
/*
void swap(Filaprio* fila1, Filaprio* fila2){
      Filaprio* aux = (Filaprio*) malloc(sizeof(Filaprio));
      aux = fila1;
      *fila1 = *fila2;
      fila2 = aux;
}*/
/*
Espaconave remove_nave(Filaprio* fila){
    int j, max = 0;
    for(j = 1; j < fila->n; j++)
        if(fila->Dados[max].prioridade < fila->Dados[j].prioridade) max = j;
    swap(&(fila->Dados[max]), &(fila->Dados[fila->n-1]));
    fila->n--;
    return fila->Dados[fila->n];
}*/
