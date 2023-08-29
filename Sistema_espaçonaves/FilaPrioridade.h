#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED


// Definição da estrutura Passageiro
typedef struct {
    char nome[50];
    int idade;
    char planetaOrigem[50];
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


typedef struct fila_prioridade{
    Espaconave* Dados;
    int Tam, n;
} Filaprio;

Filaprio* cria_fila(int tam);
void destroi_fila(Filaprio **fila);
void insere_nave(Filaprio* fp,Espaconave* nave);
Espaconave remove_nave(Filaprio* fp);
int Fila_cheia(Filaprio* fp);
int Fila_vazia(Filaprio* fp);
void imprimir_fila(Filaprio* fila);


#endif // FILAPRIORIDADE_H_INCLUDED
