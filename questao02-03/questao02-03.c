#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
 
int main() {
    Lista *l1 = NULL, *l2 = NULL;
    int opcao;

    do {
        printf("\nLista 1: ");
        imprimir(l1);
    
        printf("Lista 2: ");
        imprimir(l2);

        printf("\n1. Preencher lista 1\n");
        printf("2. Preencher lista 2\n");
        printf("3. Concatenar listas\n");
        printf("4. Verificar igualdade\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            case 2:
                liberar(opcao == 1 ? &l1 : &l2);
                float valor;
                do {
                    printf("Digite um valor para a lista %d (0 para sair): ", opcao);
                    scanf("%f", &valor);
                    if (valor != 0) inserir(opcao == 1 ? &l1 : &l2, valor);
                } while (valor != 0);
                break;
                
            case 3: 
                Lista* listaConcatenada = concatena(&l1, l2);
                printf("\nListas concatenadas: ");
                imprimir(listaConcatenada);
                break;

            case 4: 
                if (igual(l1, l2)) {
                    printf("\nAs listas são iguais.\n");
                } else {
                    printf("\nAs listas são diferentes.\n");
                }
                break;

            case 0:
                printf("Saindo...");
                break;
            
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
