#include <stdio.h>
#include <stdlib.h>
#include "../pasciente/pasciente.h"

typedef struct FilaMedico {
  int tamanho;
  int capacidadeMax;
  struct MedicoNode *inicio;
  struct MedicoNode *fim;
} FilaMedico;

typedef struct MedicoNode {
  Pasciente pasciente;
  struct MedicoNode *prox;
  struct MedicoNode *prev;
} MedicoNode;

FilaMedico *criarFilaMedico();
void adicionarPascienteMedico(FilaMedico *fila, Pasciente pasciente);
void imprimirFilaMedico(FilaMedico *fila);
void removerPascienteMedico(FilaMedico *fila);
void liberarFilaMedico(FilaMedico *fila);