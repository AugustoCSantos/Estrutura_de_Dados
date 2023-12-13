#include<stdio.h>
#include<stdlib.h>

struct elemento{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elem;

typedef struct pilha{
    Elem* prim; // aponta pro topo da pilha
}Pilha;

Pilha* cria(void){
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->prim = NULL;
    return p;
}

Pilha* push(Pilha* p, int v){
    Elem* n = (Elem*) malloc (sizeof(Elem));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

Pilha* pop(Pilha* p){
    Elem* t;
    int v;

    if(vazia(p)) exit(1); // aborta programa

    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);

    return v;
}

void libera(Pilha* p){
    Elem *t, *q = p->prim;

    while(q != NULL){
        t = q->prox;
        free(q);
        q = t;
    }

    free(p);
}

int vazia(Pilha* p){
    if(p->prim == NULL){
        return 1;
    }

    return 0;
}