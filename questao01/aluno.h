#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno** carregar_alunos(int n, const char* arquivo);
void salvar_alunos(int n, Aluno** tab, const char* arquivo);

void inicializa(int n, Aluno** tab);

void adiciona_aluno(int n, Aluno** tab, int i);
void edita_aluno(int n, Aluno** tab, int i);
void retira_aluno(int n, Aluno** tab, int i);

float media(Aluno* aluno);
float media_turma(int n, Aluno** tab);

void imprime_alunos(int n, Aluno** tab);
void imprime_aprovados(int n, Aluno** tab);
#endif