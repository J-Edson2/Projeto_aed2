#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<time.h>
#include "FilaPrioridade.h"

int main() {
    // Define a semente para a função rand() com base na hora atual.
    // Isso garante que os números gerados pela função rand() sejam diferentes a cada execução do programa.
    srand(time(NULL));

    // Define o locale do programa para "portuguese" para garantir que os caracteres especiais sejam exibidos corretamente.
    setlocale(LC_ALL, "portuguese");

    // Cria uma nova fila de prioridade.
    NoFila* fila = criar_fila();

    // Abre o arquivo "naves.txt" para leitura.
    FILE* arquivo = fopen("naves.txt", "r");

    // Se o arquivo não puder ser aberto, imprime uma mensagem de erro e encerra o programa.
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    }

    // Lê os dados das espaçonaves do arquivo e insere cada espaçonave na fila de prioridade.
    Espaconave nave;
    while (fscanf(arquivo, "%d", &nave.prioridade) == 1) {
        int num_passageiros;
        fscanf(arquivo, "%d", &num_passageiros);
        Passageiro* passageiros = malloc(num_passageiros * sizeof(Passageiro));
        for (int i = 0; i < num_passageiros; i++) {
            fscanf(arquivo, " %[^,\n\r],%d,%[^,\n\r],%d", passageiros[i].nome,
                   &passageiros[i].idade, passageiros[i].planeta_origem,
                   &passageiros[i].identificador_unico);
        }
        nave.passageiros = passageiros;
        nave.num_passageiros = num_passageiros;

        int num_recursos;
        fscanf(arquivo, "%d", &num_recursos);
        Recurso* recursos = malloc(num_recursos * sizeof(Recurso));
        for (int i = 0; i < num_recursos; i++) {
            fscanf(arquivo, " %[^,\n\r],%d", recursos[i].nome,
                   &recursos[i].quantidade);
        }
        nave.recursos = recursos;
        nave.num_recursos = num_recursos;

        inserir_na_fila(&fila, nave);
    }

    // Fecha o arquivo após a leitura dos dados.
    fclose(arquivo);

    // Exibe um menu para o usuário interagir com a fila de prioridade.
    menu(fila);

    return 0;
}
