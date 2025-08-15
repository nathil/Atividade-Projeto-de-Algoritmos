#include <stdio.h>
#include <stdlib.h>


struct aluno{
    char nome[81];
    int idade;
    char matricula[8];
    char turma;
    float p1, p2, p3;
}; typedef struct aluno Aluno;

void inicializa(int n, Aluno** tab){
    for(int i = 0; i < n; i++) {
        tab[i] = NULL;
    }
}

void adiciona(int n,Aluno** tab,int i){
    if(tab[i]==NULL) {
        tab[i] = (Aluno*)malloc(sizeof(Aluno));
    }
    
    printf("insert student name: "); 
    scanf("%s", &tab[i]->nome);
    
    printf("insert student age: "); 
    scanf("%d", &tab[i]->idade);
    
    printf("insert student registration: "); 
    scanf("%s", &tab[i]->matricula);
    
    printf("insert student class: "); 
    scanf("%s", &tab[i]->turma);
    
    printf("insert student First Test Score: "); 
    scanf("%f", &tab[i]->p1);
    
    printf("insert student Second Test Score: "); 
    scanf("%f", &tab[i]->p2);
    
    printf("insert student Third Test Score: "); 
    scanf("%f", &tab[i]->p3);
}

void retira(int n,Aluno** tab, int i){
    free(tab[i]);
    tab[i] = NULL;
}

float media(Aluno* aluno){
    return (aluno->p1 + aluno->p2 + aluno->p3)/3; 
}

int aprovado(Aluno* aluno){
    return media(aluno) > 5;
}

void imprime_aprovados(int n, Aluno** tab){
    for(int i = 0; i < n; i++){
        if(tab[i] == NULL)continue;
        
        if(aprovado(tab[i])){
            printf("%s, %d, %s, %c, %.2f\n", tab[i]->nome, tab[i]->idade, tab[i]->matricula, tab[i]->turma, media(tab[i]));
        }
    }

}

float media_turma(int n, Aluno** turmas, char turma){
    float soma = 0; 
    int cont = 0; 
    
    for(int i=0; i<n; i++){
        if(turmas[i] == NULL)continue;
        
        if(turmas[i]->turma == turma){
            soma += media(turmas[i]);
            cont++; 
        }
    }
    return soma/cont; 
} 

int main() {
    int n = 3;
    Aluno** tab = malloc(sizeof(Aluno)*n); 
    
    if(tab==NULL) {
        printf("Insufficient Memory");
        exit(1);
    }
    
    inicializa(n,tab);
    
    adiciona(n, tab, 2);
    
    imprime_aprovados(n, tab);

    printf("%.2f", media_turma(n, tab, 'T'));

    return 0;
}