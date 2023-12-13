#include<stdio.h>
#include<stdlib.h>

typedef struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
}Arv;

Arv* criaVazia(void){
    return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad){
    Arv* p = (Arv*) malloc (sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* libera(Arv* a){
    if(!vazia(a)){
        libera(a->esq); // libera sae
        libera(a->dir); // libera sad
        free(a); // libera a raiz
    }
    return NULL;
}

int vazia(Arv* a){
    return a == NULL;
}

int pertence(Arv* a, char c){
    if(vazia(a)){
        return 0; // não encontrou(arvore vazia)
    }
    else{
        return a->info == c || pertence(a->esq,c) || pertence(a->dir,c);
    }
}

void imprime(Arv* a){
    if(!vazia(a)){
        printf("%c ", a->info); // mostra a raiz
        imprime(a->esq); // mostra sae
        imprime(a->dir); // mostra sad
    }
}