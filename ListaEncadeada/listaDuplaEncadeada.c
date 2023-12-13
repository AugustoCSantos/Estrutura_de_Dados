#include<stdio.h>
#include<stdlib.h>

struct listaDupla{
    int info;
    struct listaDupla* ant;
    struct listaDupla* prox;
};
typedef struct listaDupla Lista;

Lista* cria(void){
    return NULL;
} // cria e retorna uma lista vazia


Lista* insere(Lista* lst, int val){
    Lista* new = (Lista*) malloc(sizeof(Lista));
    new->info = val;
    new->prox = lst;
    new->ant = NULL;

    if(lst != NULL){
        lst->ant = new;
    }// verifica se não estava vazia

    return new;
}

Lista* busca(Lista* lst, int val){
    Lista* p;
    for(p = lst; p != NULL; p = p->prox){
        if(p->info == val){
            return p;
        }
    }
    return NULL; // nao achou
} // busca elemento

Lista* retira(Lista* lst, int val){
    Lista* p = busca(lst,val);

    if(p == NULL){
        return lst;
    } // nao achoui

    if(lst == p){
        lst = p->prox;
    }// testa se e o primeiro elemento 
    else{
        p->ant->prox = p->ant;
    }

    if(p->prox != NULL){
        p->prox->ant = p->ant;
    } // testa se e o ultimo elemento

    free(p);

    return lst;
}