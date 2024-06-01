#include <stdio.h>
#include <stdlib.h>
#include "../pasciente/pasciente.h"

typedef struct FilaEnfermagem {
  int tamanho;
  struct EnfermagemNode *inicio;
  struct EnfermagemNode *fim;
} FilaEnfermagem;

typedef struct EnfermagemNode {
  Pasciente pasciente;
  struct EnfermagemNode *prev;
  struct EnfermagemNode *prox;
} EnfermagemNode;

FilaEnfermagem *criarFilaEnfermagem();
void adicionarPascienteEnfermagem(FilaEnfermagem *fila, Pasciente pasciente);
void imprimirFilaEnfermagem(FilaEnfermagem *fila);
void removerPascienteEnfermagem(FilaEnfermagem *fila);
void liberarFilaEnfermagem(FilaEnfermagem *fila);