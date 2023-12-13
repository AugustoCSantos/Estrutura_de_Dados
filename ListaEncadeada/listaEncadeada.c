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

void imprime(Lista* lst){
    Lista* p;
    for(p = lst; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
} // imprime os valores da lista

int vazia(Lista* lst){
    return lst = NULL;
} // retorna 1 se vazia ou 0 se não vazia

Lista* busca(Lista* lst, int v){
    Lista* p;
    for(p = lst; p != NULL; p = p->prox){
        if(p->info == v){
            return p;
        }
    }
    return NULL; // não achou
}// busca elemento na lsita

Lista* retira(Lista* lst, int val){
    Lista* ant = NULL; // elemento anterior
    Lista* p = lst; // percorrer a lista

    while(p != NULL && p->info != val){
        ant = p;
        p = p->prox;
    } // procura elemento e guarda o anterior

    if(p == NULL){
        return lst; // não achou retorna lista original
    } // verifica se achou o elemento

    if(ant == NULL){
        lst = p->prox; // retira elemento do inicio
    }
    else{
        ant->prox = p->prox; // retira elemento do meio
    } //retira elemento

    free(p);
    return lst;
}

void libera(Lista* lst){
    Lista* p = lst;
    while(p != NULL){
        Lista* t = p->prox; // guarda referencia 
        free(p); // libera memoria apontada por p
        p = t; // aponta para o proximo
    }
}

int main(void){
    Lista* lst; // declara uma lista não iniciada 
    lst = cria(); // inicia lista vazia 
    lst = insere(lst,10); // insere na lista o elemento 10 
    lst = insere(lst,15); // insere na lista o elemento 15 
    lst = insere(lst,20); // insere na lista o elemento 20 
    lst = insere(lst,25); // insere na lista o elemento 25 
    imprime(lst); // imprimirá: 10 15 20 25 
    lst = retira(lst,25);
    imprime(lst); // imprimirá: 10 15 20
    lst = retira(lst,15);
    imprime(lst); // imprimirá: 10 20
    libera(lst);
    return 0;
}