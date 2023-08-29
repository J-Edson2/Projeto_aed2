#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"

void clearInputBuffer() {
    while(getchar() != '\n');
}

Espaconave *nova_nave() {
    Espaconave *nova = (Espaconave *) malloc(sizeof(Espaconave));
    nova->passageiros = (Passageiro *) malloc(sizeof(Passageiro));
    nova->recursos = (Recurso*) malloc(sizeof(Recurso));

    return nova;
}

int main() {
    int n, i;
    printf("Digite o tamanho da fila \n");
    scanf("%d", &n);
    clearInputBuffer();

    Filaprio* fila = cria_fila(n);
    //fila->Tam = n;
    for (i = 0; i < n; i++){
        Espaconave *nave = nova_nave();

        printf("Nome do passageiro:\n");
        scanf("%s", nave->passageiros->nome);
        clearInputBuffer();
        printf("Idade:\n");
        scanf("%d", &nave->passageiros->idade);
        clearInputBuffer();

        printf("Planeta de origem:\n");
        scanf("%s", nave->passageiros->planetaOrigem);
        clearInputBuffer();

        printf("Identificador único:\n");
        scanf("%d", &nave->passageiros->identificadorUnico);
        clearInputBuffer();

        printf("Qual a prioridade da sua nave? \n");
        scanf("%d", &nave->prioridade);

        insere_nave(fila, nave);
    }
    printf("fila: \n");
    for(int j=0; j < fila->Tam;j++){
        imprimir_fila(fila);
    }
   /* while(!Fila_vazia(fila)){
        printf("a fila não está vazia: \n");
      //  Espaconave nave = remove_nave(fila);
       // printf("%s %d %s %d\n", nave.passageiros->nome, nave.passageiros->idade, nave.passageiros->planetaOrigem, nave.passageiros->identificadorUnico);
    }
*/
    return 0;
}
