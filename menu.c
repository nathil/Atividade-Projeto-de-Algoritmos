#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void show_menu() {
    printf("Selecione o programa para executar:\n");
    printf("1. Questão 01\n");
    printf("2. Questão 02-03\n");
    printf("3. Questão 04\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

int main() {
    int opcao;
    pid_t pid;
    char *args[3];

    while (1) {
        show_menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                pid = fork();
                if (pid == 0) {
                    args[0] = "./questao01/questao01.o";
                    args[1] = NULL;
                    execv(args[0], args);
                    perror("Erro ao executar questao01");
                    exit(1);
                }
                wait(NULL);
                break;
            case 2:
                pid = fork();
                if (pid == 0) {
                    args[0] = "./questao02-03/questao02-03.o";
                    args[1] = NULL;
                    execv(args[0], args);
                    perror("Erro ao executar questao02-03");
                    exit(1);
                }
                wait(NULL);
                break;
            case 3:
                pid = fork();
                if (pid == 0) {
                    args[0] = "./questao04/questao04.o";
                    args[1] = NULL;
                    execv(args[0], args);
                    perror("Erro ao executar questao04");
                    exit(1);
                }
                wait(NULL);
                break;
            case 0:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}
