#include "medico.h"

FilaMedico *criarFilaMedico() {
  FilaMedico *fila = (FilaMedico *) malloc(sizeof(FilaMedico));
  fila->tamanho = 0;
  fila->capacidadeMax = 5;
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void adicionarPascienteMedico(FilaMedico *fila, Pasciente pasciente) {
  if (fila->tamanho >= fila->capacidadeMax) {
    printf("Fila de médico cheia!\n");
    return;
  }

  MedicoNode *novo = (MedicoNode *) malloc(sizeof(MedicoNode));
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

void imprimirFilaMedico(FilaMedico *fila) {
  int i = 0;
  MedicoNode *atual = fila->inicio;
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

void removerPascienteMedico(FilaMedico *fila) {
  if (fila->tamanho == 0) {
    printf("Fila vazia\n");
    return;
  }

  MedicoNode *removido = fila->inicio;
  fila->inicio = fila->inicio->prox;
  free(removido);
  fila->tamanho--;
}

void liberarFilaMedico(FilaMedico *fila) {
  MedicoNode *atual = fila->inicio;
  while (atual != NULL) {
    MedicoNode *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(fila);
}