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

int main() {
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();
    int opcao;

    do {
        printf("\n");

        printf("Pilha 1: ");
        pilha_imprime(p1);

        printf("Pilha 2: ");
        pilha_imprime(p2);

        printf("\n1. Adicionar elemento na pilha 1\n");
        printf("2. Adicionar elemento na pilha 2\n");
        printf("3. Remover elemento da pilha 1\n");
        printf("4. Remover elemento da pilha 2\n");
        printf("5. Mostrar elemento do topo da pilha 1\n");
        printf("6. Concatenar pilhas\n");
        printf("0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
            case 2: 
                float valor;
                printf("Digite um valor: ");
                scanf("%f", &valor);
                pilha_push(opcao == 1 ? p1 : p2, valor);
                break;
            
            case 3: 
            case 4:
                Pilha* p = opcao == 3 ? p1 : p2;
                if (!pilha_vazia(p)) {
                    float valor = pilha_pop(p);
                    printf("\nRemovido da pilha 2: %.2f\n", valor);
                } else {
                    printf("\nPilha 2 vazia!\n");
                }
                break;

            case 5:
                if (!pilha_vazia(p1)) {
                    float valor = topo(p1);
                    printf("\nTopo da pilha 1: %.2f\n", valor);
                } else {
                    printf("\nPilha 1 vazia!\n");
                }
                break;

            case 6:
                concatena_pilhas(p1, p2);
                printf("\nPilhas concatenadas!\n");
                break;

            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    pilha_libera(p1);
    pilha_libera(p2);

    return 0;
}
