/*
** Função: Sistema de Agendamento de Consultas
** Autor: João Victor Barbosa Perazzo
** Data: 30/05/2024
** Observações:
*/

#include <locale.h>

#include "pasciente/pasciente.h"
#include "enfermagem/enfermagem.h"
#include "medico/medico.h"

void menu();
void menuFilaEnfermagem();
void menuFilaMedico();
Pasciente novoPasciente();
void limparConsole();

int main() {
  setlocale(LC_ALL, "Portugese");

  FilaEnfermagem *filaEnfermagem = criarFilaEnfermagem();
  FilaMedico *filaMedico = criarFilaMedico();

  printf("Bem-vindo ao Sistema de Agendamento de Consultas\n");
  
  int opcao;
  while (1) {
    menu();
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) {
      case 1:
        while (1) {
          menuFilaEnfermagem();
          scanf("%d", &opcao);
          fflush(stdin);
          limparConsole();

          switch (opcao) {
            case 1:
              adicionarPascienteEnfermagem(filaEnfermagem, novoPasciente());
              break;
            case 2:
              removerPascienteEnfermagem(filaEnfermagem);
              break;
            case 3:
              imprimirFilaEnfermagem(filaEnfermagem);
              break;
            case 4:
              limparConsole();
              break;
            default:
              printf("Opção inválida\n");
              break;
          }

          if (opcao == 4) {
            break;
          }
        }
        break;
      case 2:
        while (1) {
          menuFilaMedico();
          scanf("%d", &opcao);
          fflush(stdin);
          limparConsole();

          switch (opcao) {
            case 1:
              adicionarPascienteMedico(filaMedico, novoPasciente());
              break;
            case 2:
              removerPascienteMedico(filaMedico);
              break;
            case 3:
              imprimirFilaMedico(filaMedico);
              break;
            case 4:
              limparConsole();
              break;
            default:
              printf("Opção inválida\n");
              break;
          }

          if (opcao == 4) {
            break;
          }
        }
        break;
      case 3:
        liberarFilaEnfermagem(filaEnfermagem);
        liberarFilaMedico(filaMedico);
        return 0;
      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}

void menu() {
  printf("\n");
  printf("1 - Fila Enfermagem\n");
  printf("2 - Fila Médico\n");
  printf("3 - Sair\n");
}

void menuFilaEnfermagem() {
  printf("\n");
  printf("1 - Adicionar Pasciente\n");
  printf("2 - Remover Pasciente\n");
  printf("3 - Imprimir Fila\n");
  printf("4 - Voltar\n");
}

void menuFilaMedico() {
  printf("\n");
  printf("1 - Adicionar Pasciente\n");
  printf("2 - Remover Pasciente\n");
  printf("3 - Imprimir Fila\n");
  printf("4 - Voltar\n");
}

Pasciente novoPasciente() {
  char nome[50];
  int cpf;
  char data_nascimento[11];
  char telefone[15];
  char email[50];

  printf("\n");
  printf("Nome: ");
  scanf("%s", nome);
  fflush(stdin);

  printf("CPF: ");
  scanf("%d", &cpf);
  fflush(stdin);

  printf("Data de Nascimento: ");
  scanf("%s", data_nascimento);
  fflush(stdin);

  printf("Telefone: ");
  scanf("%s", telefone);
  fflush(stdin);

  printf("Email: ");
  scanf("%s", email);
  fflush(stdin);

  return cadastrarPasciente(nome, cpf, data_nascimento, telefone, email);
}

void limparConsole() {
  system("cls");
}