#include <stdio.h> 
#include <stdlib.h>

typedef struct lista{
    float info; 
    struct lista *prox; 
}Lista; 

//função para inserir um elemento na lista. 

void inserir(Lista **lista, float valor){

    Lista *aux, *novo = malloc(sizeof(Lista)); 

    if(novo){
        novo->info = valor; 
        novo->prox = NULL;

    //verificando se é o 1o elemento

        if(*lista == NULL){
            *lista = novo; 
        } else {
            aux = *lista; 

            while(aux->prox != NULL){
                aux = aux->prox; 
            }
            aux->prox = novo; 
        }
    } else {
        printf("Error na alocacao de memoria."); 
    }
}

//função para mostrar a lista. 

void imprimir(Lista *lista){
    printf("\nLista:");

    while(lista){ 
        printf("%.2f  ", lista->info);
        lista = lista->prox; 
    }
}

//função para remover um elemento da lista. 

void remover_elem(Lista** lista, int i){
    int cont = 0; 

    if(i == 0){
        Lista* cabeca = *lista;  
        *lista = (*lista)->prox;
        free(cabeca); 

        return; 
    }    
    
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

//função para unir duas listas. 

Lista* concatenar_lista(Lista* lista1, Lista* lista2){

    Lista* listaCopia = lista1; 

    while(listaCopia->prox != NULL){
        listaCopia = listaCopia->prox; 
    }

    listaCopia->prox = lista2;

    return lista1; 
}

int main(){
    Lista* lista1 = NULL;
    Lista* lista2 = NULL; 

    inserir(&lista1, 2.1); 
    inserir(&lista1, 1.2);
    inserir(&lista2, 4.5);
    inserir(&lista2, 3.5);

    imprimir(lista1); 
    imprimir(lista2); 

    Lista* lista3 = concatenar_lista(lista1, lista2); 

    imprimir(lista3); 
    
    remover_elem(&lista1, 5); 
    imprimir(lista1); 
}