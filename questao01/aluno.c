#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

#define MEDIA 5

typedef struct aluno {
    char nome[81];
    int idade;
    char matricula[8];
    char turma;
    float p1, p2, p3;
} Aluno;

Aluno** carregar_alunos(int n, const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");

    Aluno** alunos = malloc(n * sizeof(Aluno*));
    inicializa(n, alunos);
    
    if (!fp) return alunos;
    
    for (int i = 0; i < n; i++) {
        char c = fgetc(fp);
        if (c == '\n' || c == EOF) continue;
        ungetc(c, fp);

        alunos[i] = malloc(sizeof(Aluno));
        fscanf(fp, "%81[^;];%d;%8[^;];%c;%f;%f;%f\n",
            alunos[i]->nome,
            &alunos[i]->idade,
            alunos[i]->matricula,
            &alunos[i]->turma,
            &alunos[i]->p1,
            &alunos[i]->p2,
            &alunos[i]->p3
        );
    }

    fclose(fp);
    return alunos;
}

void salvar_alunos(int n, Aluno** tab, const char* arquivo) {
    FILE* fp = fopen(arquivo, "w");

    if (!fp) {
        perror("O arquivo não foi aberto corretamente");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (tab[i] == NULL) {
            fprintf(fp, "\n");
        } else {          
            fprintf(fp, "%.81s;%d;%.8s;%c;%.2f;%.2f;%.2f\n",
                tab[i]->nome,
                tab[i]->idade,
                tab[i]->matricula,
                tab[i]->turma,
                tab[i]->p1,
                tab[i]->p2,
                tab[i]->p3
            );
        }
    }

    fclose(fp);
}


void adiciona_aluno(int n, Aluno** tab, int i) {
    if (i < 0 || i >= n) {
        printf("Índice inválido!\n");
        return;
    }

    tab[i] = malloc(sizeof(Aluno));
    printf("Digite o nome do aluno: ");
    scanf(" %s", tab[i]->nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &tab[i]->idade);
    
    printf("Digite a matrícula do aluno: ");
    scanf("%s", tab[i]->matricula);
    
    printf("Digite a turma do aluno: ");
    scanf(" %c", &tab[i]->turma);
    
    printf("Digite a primeira nota: ");
    scanf("%f", &tab[i]->p1);

    printf("Digite a segunda nota: ");
    scanf("%f", &tab[i]->p2);

    printf("Digite a terceira nota: ");
    scanf("%f", &tab[i]->p3);
}

void edita_aluno(int n, Aluno** tab, int i) {
    if (i < 0 || i >= n) {
        printf("Índice inválido!\n");
        return;
    }

    char editar = 'n';

    printf("Deseja editar o nome do aluno [%s]? (s/N): ", tab[i]->nome);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite o novo nome do aluno: ");
        scanf(" %s", tab[i]->nome);
    }

    printf("Deseja editar a idade do aluno [%d]? (s/N): ", tab[i]->idade);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova idade do aluno: ");
        scanf("%d", &tab[i]->idade);
    }

    printf("Deseja editar a matrícula do aluno [%.8s]? (s/N): ", tab[i]->matricula);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova matrícula do aluno: ");
        scanf(" %s", tab[i]->matricula);
    }

    printf("Deseja editar a turma do aluno [%c]? (s/N): ", tab[i]->turma);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova turma do aluno: ");
        scanf(" %c", &tab[i]->turma);
    }

    printf("Deseja editar a primeira nota do aluno [%.2f]? (s/N): ", tab[i]->p1);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova primeira nota: ");
        scanf("%f", &tab[i]->p1);
    }

    printf("Deseja editar a segunda nota do aluno [%.2f]? (s/N): ", tab[i]->p2);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova segunda nota: ");
        scanf("%f", &tab[i]->p2);
    }

    printf("Deseja editar a terceira nota do aluno [%.2f]? (s/N): ", tab[i]->p3);
    scanf(" %c", &editar);
    if (editar == 's') {
        printf("Digite a nova terceira nota: ");
        scanf("%f", &tab[i]->p3);
    }
}

void retira_aluno(int n, Aluno** tab, int i) {
    if (i < 0 || i >= n) {
        printf("Índice inválido!\n");
        return;
    }
    
    free(tab[i]);
    tab[i] = NULL;
}

void inicializa(int n, Aluno** tab) {
    for (int i = 0; i < n; i++) {
        tab[i] = NULL;
    }
}


float media(Aluno* aluno) {
    return (aluno->p1 + aluno->p2 + aluno->p3) / 3.0;
}

float media_turma(int n, Aluno** tab) {
    float soma = 0.0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (tab[i] != NULL) {
            soma += media(tab[i]);
            count++;
        }
    }

    return count > 0 ? soma / count : 0.0;
}


void imprime_alunos(int n, Aluno** tab) {
    const char* separador = "+----+--------------------+-------+-----------+-------+--------+--------+--------+-------+\n";

    printf("%s", separador);
    printf("| ID | Nome               | Idade | Matricula | Turma | Nota 1 | Nota 2 | Nota 3 | Média |\n");
    printf("%s", separador);

    for (int i = 0; i < n; i++) {
        if (tab[i] == NULL) {
            printf("| %2d | %-18s | %-5s | %-9s | %-5s | %-6s | %-6s | %-6s | %-5s |\n",
                i + 1,
                "Vazio",
                "-",
                "-",
                "-",
                "-",
                "-",
                "-",
                "-"
            );
        } else {
            printf("| %2d | %-18.18s | %-5d | %-9.8s | %-5c | %6.2f | %6.2f | %6.2f | %5.2f |\n",
                i + 1,
                tab[i]->nome,
                tab[i]->idade,
                tab[i]->matricula,
                tab[i]->turma,
                tab[i]->p1,
                tab[i]->p2,
                tab[i]->p3,
                media(tab[i])
            );
        }
    }

    printf("%s", separador);
}

void imprime_aprovados(int n, Aluno** tab) {
    Aluno** aprovados = (Aluno**)malloc(n * sizeof(Aluno*));
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (tab[i] != NULL && media(tab[i]) >= MEDIA) {
            aprovados[count++] = tab[i];
        }
    }

    if (count > 0) {
        imprime_alunos(count, aprovados);
    } else {
        printf("\nNenhum aluno aprovado.\n");
    }

    free(aprovados);
}