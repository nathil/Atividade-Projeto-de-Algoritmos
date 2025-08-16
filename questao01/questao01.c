#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

#define TAM 10
#define ARQ "alunos.txt"

int main() {
  int opcao, modificado = 0;
  Aluno** tab = carregar_alunos(TAM, ARQ);

  do {
    printf("\nOpções:\n");
    printf("1 - Listar Alunos\n");
    printf("2 - Listar Alunos Aprovados\n");
    printf("3 - Média da Turma\n");                                  
    printf("4 - Adicionar Aluno\n");
    printf("5 - Editar Aluno\n");
    printf("6 - Remover Aluno\n");
    printf("7 - Limpar Tabela\n"); 
    printf("8 - Salvar Alunos\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        imprime_alunos(TAM, tab);
        break;
      
      case 2:
        imprime_aprovados(TAM, tab);
        break;
      
      case 3: 
        printf("\nA média da turma é: %.2f\n", media_turma(TAM, tab));
        break;
        
      case 4:
        int i = 0;
        while (i < TAM && tab[i] != NULL) i++;

        if (i < TAM) {
          adiciona_aluno(TAM, tab, i);
          printf("\nAluno adicionado com sucesso!\n");
          modificado = 1;
        } else {
          printf("\nNão há espaço para adicionar mais alunos. Remova um para continuar.\n");
        }

        break;

      case 5:
        int indice;
        printf("\nDigite o índice do aluno a ser editado: ");
        scanf("%d", &indice);
        
        indice--;

        if (indice >= 0 && indice < TAM && tab[indice] != NULL) {
          edita_aluno(TAM, tab, indice);
          printf("\nAluno editado com sucesso!\n");
          modificado = 1;
        } else {
          printf("\nÍndice inválido.\n");
        }

        break;

      case 6:
        printf("\nDigite o índice do aluno a ser removido: ");
        scanf("%d", &indice);
        indice--;

        if (indice >= 0 && indice < TAM && tab[indice] != NULL) {
          retira_aluno(TAM, tab, indice);
          printf("\nAluno removido com sucesso!\n");
          modificado = 1;
        } else {
          printf("\nAluno Inválido\n");
        }

        break;
      
      case 7:
        char limpar; 
        printf("\nVocê tem certeza que deseja limpar a tabela? (s/n): "); 
        scanf(" %c", &limpar); 

        if(limpar == 's'){
          limpa(TAM, tab);
          printf("\nLimpeza Concluída...\n");  
          modificado = 1; 
        }
        
        break; 

      case 8:
        salvar_alunos(TAM, tab, ARQ);
        printf("\nAlunos salvos com sucesso!\n");
        modificado = 0;
        break;

      case 0: 
        if (modificado) {
          char sair;

          printf("Você tem alterações não salvas, deseja sair? (s/n): ");
          scanf(" %c", &sair);

          if (sair != 's') opcao = 1;
        }

        if (opcao == 0) {
          printf("Finalizando Programa...\n");
        }

        break;

      default:
        printf("Opção Inválida\n");
    }
  } while (opcao != 0);

  return 0;
}