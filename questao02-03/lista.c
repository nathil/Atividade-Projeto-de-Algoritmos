#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    float info;
    struct lista *prox;
};

Lista* copia(Lista* lista) {
    Lista* listaCopia = NULL;
    
    while(lista != NULL) {
        inserir(&listaCopia, lista->info);
        lista = lista->prox;
    }
    
    return listaCopia;
}

void inserir(Lista **lista, float valor) {
    Lista *novo = malloc(sizeof(Lista));
    
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return;
    }

    novo->info = valor;
    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo; 
    } else {
        Lista *aux = *lista; 

        while(aux->prox != NULL){
            aux = aux->prox; 
        }
        aux->prox = novo; 
    }
}

Lista* concatena(Lista** lista1, Lista* lista2) {
    Lista* listaCopia = copia(lista2);  

    if (*lista1 == NULL){
        *lista1 = listaCopia; 
        return *lista1;  
    } 

    Lista* aux = *lista1; 

    while(aux->prox != NULL){
        aux = aux->prox; 
    }

    aux->prox = listaCopia;

    return *lista1; 
}

void remover(Lista** lista, int i) {
    if(i == 0){
        Lista* cabeca = *lista;  
        *lista = (*lista)->prox;
        free(cabeca); 

        return; 
    }    
    
    int cont = 0;
    Lista* ant = NULL; 
    Lista* aux = *lista; 
    
    while (aux != NULL){
        if(cont == i){
            ant->prox = aux->prox; 
            free(aux); 
            
            return; 
        }

        cont++; 
        ant = aux; 
        aux = aux->prox;  
    }

    printf("\nIndice maior que a lista."); 
    exit(1); 
}

void liberar(Lista** lista) {
    Lista* aux = *lista;
    Lista* ant = NULL;
    
    while(aux != NULL) {
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    
    *lista = NULL;
}

int igual(Lista* l1, Lista* l2) {
    while(l1 != NULL && l2 != NULL){
        if(l1->info != l2->info) return 0;

        l1 = l1->prox;
        l2 = l2->prox;     
    }

    return l1 == NULL && l2 == NULL;
}

void imprimir(Lista *lista) {
    if (lista == NULL) {
        printf("NULL\n");
        return;
    }

    while (lista) {
        printf("-> %.2f ", lista->info);
        lista = lista->prox;
    }
    printf("\n");
}
