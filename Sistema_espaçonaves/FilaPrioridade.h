#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED

typedef struct Passageiro {
    char nome[50];
    int idade;
    char planeta_origem[50];
    int identificador_unico;
} Passageiro;

typedef struct Recurso {
    char nome[50];
    int quantidade;
} Recurso;

typedef struct Espaconave {
    int prioridade;
    Passageiro* passageiros;
    Recurso* recursos;
    int num_passageiros;
    int num_recursos;
} Espaconave;

typedef struct NoFila {
    Espaconave nave;
    struct NoFila* proximo;
} NoFila;

NoFila* criar_fila();
void inserir_na_fila(NoFila** fila, Espaconave nave);
Espaconave remover_da_fila(NoFila** fila);
void exibir_fila(NoFila* fila);
#endif // FILAPRIORIDADE_H_INCLUDED
