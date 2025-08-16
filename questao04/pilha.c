#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct topo {
    float valor;
    struct topo *prox;
} Topo;

typedef struct pilha {
    Topo *topo;
} Pilha;


Pilha* pilha_cria(void) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

void pilha_push(Pilha* p, float v) {
    Topo* t = (Topo*)malloc(sizeof(Topo));
    t->valor = v;
    t->prox = p->topo;

    p->topo = t;
}

float pilha_pop(Pilha* p) {
    float v = p->topo->valor;

    Topo* t = p->topo;

    p->topo = t->prox;
    free(t);

    return v;
}


int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}


void pilha_libera(Pilha* p) {
    while (p->topo != NULL) {
        Topo* t = p->topo;
        p->topo = p->topo->prox;
        free(t);
    }
    
    free(p);
}


void pilha_imprime(Pilha* p) {
    Topo* t = p->topo;
    
   if (t == NULL) {
        printf("Pilha vazia\n");
        return;
    }

    while (t != NULL) {
        printf("%.2f ", t->valor);
        t = t->prox;
    }
    printf("\n");
}