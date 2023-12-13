#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
struct lista{
    int info;
    Lista* prox;
};

Lista* cria(void){
    return NULL;
} // cria e retorna uma lista vazia

Lista* insere(Lista* lst, int val){
    Lista* new = (Lista*) malloc(sizeof(Lista));
    new->info = val;
    new->prox = lst;
    return new;
} // insere no inicio e retorna a lista atualizada

void circImprime(Lista* lst){
    Lista* p = lst; // aponta para o no inicial

    if(p) do{
        printf("%d\n", p->info); // impre a info do no
        p = p->prox; // avança para o proximo no
    } while(p != lst);
}