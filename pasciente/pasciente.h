#ifndef PASCIENTE_H
#define PASCIENTE_H

typedef struct Pasciente {
  char nome[50];
  int cpf;
  char data_nascimento[11];
  char telefone[15];
  char email[50];
} Pasciente;

Pasciente cadastrarPasciente(char nome[50], int cpf, char data_nascimento[11], char telefone[15], char email[50]);

#endif