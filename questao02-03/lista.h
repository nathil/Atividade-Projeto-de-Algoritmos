#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista* copia(Lista* lista);
void inserir(Lista **lista, float valor);
Lista* concatena(Lista** l1, Lista* l2);
void remover(Lista** lista, int i);
void liberar(Lista** lista);

int igual(Lista* l1, Lista* l2);

void imprimir(Lista *lista);

#endif