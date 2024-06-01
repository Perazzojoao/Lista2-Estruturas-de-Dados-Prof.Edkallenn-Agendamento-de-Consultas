#include "enfermagem.h"

FilaEnfermagem *criarFilaEnfermagem() {
  FilaEnfermagem *fila = (FilaEnfermagem *) malloc(sizeof(FilaEnfermagem));
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void adicionarPascienteEnfermagem(FilaEnfermagem *fila, Pasciente pasciente) {
  EnfermagemNode *novo = (EnfermagemNode *) malloc(sizeof(EnfermagemNode));
  novo->pasciente = pasciente;
  novo->prox = NULL;
  if (fila->tamanho == 0) {
    novo->prev = NULL;
    fila->inicio = novo;
    fila->fim = novo;
  } else {
    novo->prev = fila->fim;
    fila->fim->prox = novo;
    fila->fim = novo;
  }
  fila->tamanho++;  
}

void imprimirFilaEnfermagem(FilaEnfermagem *fila) {
  int i = 0;
  EnfermagemNode *atual = fila->inicio;
  while (atual != NULL) {
    i++;
    printf("\n");
    printf("------ Pasciente %d ------\n", i);
    printf("Nome: %s\n", atual->pasciente.nome);
    printf("CPF: %d\n", atual->pasciente.cpf);
    printf("Data de Nascimento: %s\n", atual->pasciente.data_nascimento);
    printf("Telefone: %s\n", atual->pasciente.telefone);
    printf("Email: %s\n", atual->pasciente.email);
    printf("--------------------------\n");
    printf("\n");
    atual = atual->prox;
  }
}

void removerPascienteEnfermagem(FilaEnfermagem *fila) {
  if (fila->tamanho == 0) {
    printf("Fila vazia\n");
    return;
  }
  EnfermagemNode *removido = fila->inicio;
  fila->inicio = fila->inicio->prox;
  free(removido);
  fila->tamanho--;
}

void liberarFilaEnfermagem(FilaEnfermagem *fila) {
  EnfermagemNode *atual = fila->inicio;
  while (atual != NULL) {
    EnfermagemNode *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(fila);
}