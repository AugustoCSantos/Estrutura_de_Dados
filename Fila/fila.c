#include<stdio.h>
#include<stdlib.h>

struct lista{
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

typedef struct fila{
    Lista* inicio;
    Lista* fim;
}Fila;

Fila* cria(void){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int vazia (Fila* f)
{
    if (f->inicio == NULL){
        return 1;
    } else{
        return 0;
    }
}

void insere(Fila* f, float v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v; // armazena a info
    n->prox = NULL; // novo no sera o ultimo

    if(f->fim != NULL){ //verifica se lista não estava vazia
        f->fim->prox = n;
    } else{ // fila estava vazia
        f->inicio = n;
    }
    f->fim = n; //fila aponta para novo elemento
}

float retira(Fila* f){
    Lista* t;
    float v;
    if(vazia(f)){
        printf("Fila vazia.\n");
        exit(1); // aborta o programa
    }
    t = f->inicio;
    v = t->info;
    f->inicio = t->prox;
    if(f->inicio == NULL){ // verifica se a fila ficou vazia
        f->fim = NULL;
    }
    free(t);
    return v;
}

void libera(Fila* f){
    Lista* q = f->inicio;
    while(q != NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}
