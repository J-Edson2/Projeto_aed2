#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED
// Define a estrutura Passageiro com nome, idade, planeta de origem e identificador �nico.
typedef struct Passageiro {
    char nome[50];
    int idade;
    char planeta_origem[50];
    int identificador_unico;
} Passageiro;

// Define a estrutura Recurso com nome e quantidade.
typedef struct Recurso {
    char nome[50];
    int quantidade;
} Recurso;


// Define a estrutura Espaconave
typedef struct Espaconave {
    int prioridade;
    Passageiro* passageiros;
    Recurso* recursos;
    int num_passageiros;
    int num_recursos;
} Espaconave;

// Define a estrutura NoFila (n� da fila) com uma nave e um ponteiro para o pr�ximo n�
typedef struct NoFila {
    Espaconave nave;
    struct NoFila* proximo;
} NoFila;

// Declara as fun��es que ser�o implementadas
NoFila* criar_fila();
void inserir_na_fila(NoFila** fila, Espaconave nave);
Espaconave remover_da_fila(NoFila** fila);
void exibir_fila(NoFila* fila);
int verificar_dados(Espaconave* nave);
Espaconave inserir_nave_manualmente();
#endif
