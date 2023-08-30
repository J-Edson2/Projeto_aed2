#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"


Espaconave *nova_nave() {
    Espaconave *nova = (Espaconave *) malloc(sizeof(Espaconave));
    nova->numPassageiros = (int *) malloc(sizeof(int));
    nova->prioridade = (int*) malloc(sizeof(int));

    return nova;
}

int main() {
    int n, i;
    printf("Digite o tamanho da fila \n");
    scanf("%d", &n);

    Fila* fila;
    fila = NULL;
    fila = criar();

    Espaconave *nave = nova_nave();
    Espaconave *nave2 = nova_nave();
    Espaconave *nave3 = nova_nave();
    Espaconave *nave4 = nova_nave();

    nave->numPassageiros = 10;
    nave->prioridade = 5;
    strcpy(nave->dados.nome, "elias");
    nave->dados.idade = 21;
    insere(fila, *nave);

    nave2->numPassageiros = 3;
    nave2->prioridade = 1;
    strcpy(nave2->dados.nome, "migles");
    nave2->dados.idade = 20;
    insere(fila, *nave2);

    nave3->numPassageiros = 3;
    nave3->prioridade = 6;
    strcpy(nave3->dados.nome, "matheus");
    nave3->dados.idade = 30;
    insere(fila, *nave3);

    nave4->numPassageiros = 3;
    nave4->prioridade = 4;
    strcpy(nave4->dados.nome, "Kelthon");
    nave4->dados.idade = 30;
    insere(fila, *nave4);

    printf("NAVES NA BASE DE LANÇAMENTO:");
    imprimeFila(fila);

    printf("//////////////////////////////////////:\n");
    printf("//////////////////////////////////////:\n");
    int opcao = 0;
    while(opcao != 2){
         printf("Deseja decolar uma nave? 1->SIM 2->NAO \n");
         scanf("%d", &opcao);
         if(opcao == 1){
            struct espaconave nave_removida = remove_nave(fila);
            if (nave_removida.prioridade != -1) {
               printf("//////////////////////////////////////:\n");
               printf("Espaçonave de maior prioridade decolou:\n");
               printf("Prioridade: %d\n", nave_removida.prioridade);
               printf("numero de Passageiros: %d\n", nave_removida.numPassageiros);
               printf("Nome do Passageiro: %s\n", nave_removida.dados.nome);
               printf("Idade do Passageiro: %d\n", nave_removida.dados.idade);
               printf("//////////////////////////////////////:\n");
            }
         }
    }
    printf("//////////////////////////////////////:\n");
    printf("//////////////////////////////////////:\n");

    printf("NAVES NA BASE DE LANÇAMENTO:");
    imprimeFila(fila);

    return 0;
}
