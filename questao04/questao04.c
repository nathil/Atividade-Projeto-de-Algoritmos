#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

float topo(Pilha* p) {
    float v = pilha_pop(p);
    pilha_push(p, v);

    return v;
}

void concatena_pilhas(Pilha* p1, Pilha* p2) {
    Pilha* pAux = pilha_cria();

    while (!pilha_vazia(p2)) {
        pilha_push(pAux, pilha_pop(p2));
    }

    while (!pilha_vazia(pAux)) {
        pilha_push(p1, pilha_pop(pAux));
    }

    pilha_libera(pAux);
}

void imprime_pilha(Pilha* p) {
    Pilha* pAux = pilha_cria();

    while (!pilha_vazia(p)) {
        float v = pilha_pop(p);

        printf("%.2f\n", v);
        
        pilha_push(pAux, v);
    }

    printf("\n");

    while (!pilha_vazia(pAux)) pilha_push(p, pilha_pop(pAux));
    pilha_libera(pAux);
}

int main() {
    Pilha* p1 = pilha_cria();
    pilha_push(p1, 01.02);
    pilha_push(p1, 03.04);
    pilha_push(p1, 05.06);

    Pilha* p2 = pilha_cria();
    pilha_push(p2, 07.08);
    pilha_push(p2, 09.10);
    pilha_push(p2, 11.12);

    printf("Topo: %.2f ->  Topo denovo %.2f\n\n", topo(p1), topo(p1));

    printf("pilha 1:\n");
    imprime_pilha(p1);

    printf("pilha 2:\n");
    imprime_pilha(p2);

    concatena_pilhas(p1, p2);

    printf("pilha 1 + pilha 2:\n");
    imprime_pilha(p1);

    return 0;
}
