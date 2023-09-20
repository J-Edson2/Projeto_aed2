#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FilaPrioridade.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    NoFila* fila = criar_fila();

    Passageiro passageiros1[] = {{"Kelthon", 30, "Terra", 123}, {"yzap", 25, "Marte", 456}, {"Lucas", 20, "Lua", 458}};
    Recurso recursos1[] = {{"Comida", 100}, {"�gua", 200}, {"Combust�vel", 300}};

    Espaconave nave1 = {10, passageiros1, recursos1, 3, 3};

    inserir_na_fila(&fila, nave1);

    Passageiro passageiros2[] = {{"Migles", 35, "V�nus", 789}, {"Elias", 40, "J�piter", 012}};
    Recurso recursos2[] = {{"Comida", 150}, {"�gua", 250}, {"Combust�vel", 350}};

    Espaconave nave2 = {20, passageiros2, recursos2, 2, 3};

    inserir_na_fila(&fila, nave2);

    Passageiro passageiros3[] = {{"Matheus", 25, "Terra", 749}, {"Elias", 80, "Marte", 042}};
    Recurso recursos3[] = {{"Comida", 500}, {"�gua", 20}, {"Combust�vel", 300}};
    Espaconave nave3 = {8, passageiros3, recursos3, 2, 3};

    inserir_na_fila(&fila, nave3);

    menu(fila);

    return 0;
}
