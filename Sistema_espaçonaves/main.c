#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<time.h>
#include "FilaPrioridade.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    NoFila* fila = criar_fila();

    FILE* arquivo = fopen("naves.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    }

    Espaconave nave;
    while (fscanf(arquivo, "%d", &nave.prioridade) == 1) {
        int num_passageiros;
        fscanf(arquivo, "%d", &num_passageiros);
        Passageiro* passageiros = malloc(num_passageiros * sizeof(Passageiro));
        for (int i = 0; i < num_passageiros; i++) {
            fscanf(arquivo, "%[^,],%d,%[^,],%d", passageiros[i].nome,
                   &passageiros[i].idade, passageiros[i].planeta_origem,
                   &passageiros[i].identificador_unico);
        }
        nave.passageiros = passageiros;
        nave.num_passageiros = num_passageiros;

        int num_recursos;
        fscanf(arquivo, "%d", &num_recursos);
        Recurso* recursos = malloc(num_recursos * sizeof(Recurso));
        for (int i = 0; i < num_recursos; i++) {
            fscanf(arquivo, "%[^,],%d", recursos[i].nome,
                   &recursos[i].quantidade);
        }
        nave.recursos = recursos;
        nave.num_recursos = num_recursos;

        inserir_na_fila(&fila, nave);
    }

    fclose(arquivo);
    menu(fila);

    return 0;
}
