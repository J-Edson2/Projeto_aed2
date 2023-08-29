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

    nave->numPassageiros = 10;
    nave->prioridade = 1;
    strcpy(nave->dados.nome, "elias");
    nave->dados.idade = 21;
    insere(fila, *nave);

    nave2->numPassageiros = 3;
    nave2->prioridade = 2;
    strcpy(nave2->dados.nome, "migles");
    nave2->dados.idade = 20;
    insere(fila, *nave2);

    nave3->numPassageiros = 3;
    nave3->prioridade = 2;
    strcpy(nave3->dados.nome, "matheus");
    nave3->dados.idade = 30;
    insere(fila, *nave3);


    imprimeFila(fila);

   /* while(!Fila_vazia(fila)){
        printf("a fila não está vazia: \n");
      //  Espaconave nave = remove_nave(fila);
       // printf("%s %d %s %d\n", nave.passageiros->nome, nave.passageiros->idade, nave.passageiros->planetaOrigem, nave.passageiros->identificadorUnico);
    }
*/
    return 0;
}
