#include "pasciente.h"
#include <string.h>


Pasciente cadastrarPasciente(char nome[50], int cpf, char data_nascimento[11], char telefone[15], char email[50]) {
  Pasciente pasciente;
  strcpy(pasciente.nome, nome);
  pasciente.cpf = cpf;
  strcpy(pasciente.data_nascimento, data_nascimento);
  strcpy(pasciente.telefone, telefone);
  strcpy(pasciente.email, email);
  return pasciente;
}