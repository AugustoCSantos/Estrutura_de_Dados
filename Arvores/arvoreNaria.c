#include<stdio.h>
#include<stdlib.h>

typedef struct arvvar{
    char info;
    struct arvvar *prim; // aponta para um filho
    struct arvvar *prox; // aponta para um irmão
}ArvVar;

ArvVar* cria(char c){
    ArvVar *a = (ArvVar *) malloc(sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void insere(ArvVar* a, ArvVar* sa){
    sa->prox = a->prim;
    a->prim = sa;
}

void imprime(ArvVar* a){
    ArvVar* p;
    printf("<%c\n", a->info);
    for(p = a->prim; p != NULL; p = p->prox){
        imprime(p); // imprime filhas
    }
    printf(">");
}

int pertence(ArvVar* a, char c){
    ArvVar* p;
    if(a->info == c){
        return 1;
    } else{
        for(p = a->prim; p != NULL; p = p->prox){
            if(pertence(p,c)){
                return 1;
            }
        }
        return 0;
    }
}

void libera(ArvVar* a){
    ArvVar* p = a->prim;
    while(p != NULL){
        ArvVar* t = p->prox;
        libera(p);
        p = t;
    }
    free(a);
}