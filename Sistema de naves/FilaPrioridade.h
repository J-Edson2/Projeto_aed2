#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED


// Definição da estrutura Passageiro
struct passageiro{
    char nome[50];
    int idade;
    char planetaOrigem[50];
    int identificadorUnico;
};
typedef struct passageiro Passageiro;

struct recurso{
    int agua;
    int comida;
    int combustivel;
};
typedef struct recurso Recurso;

// Definição da estrutura Espaçonave
struct espaconave{
    int prioridade;
    int numPassageiros;

    //struct recurso dado;
    struct passageiro dados;
};
typedef struct espaconave Espaconave;

typedef struct elemento *Fila;

Fila* criar();
int insere(Fila*, Espaconave);
int imprimeFila(Fila*);
Espaconave remove_nave(Fila*);
#endif // FILAPRIORIDADE_H_INCLUDED
