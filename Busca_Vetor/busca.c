#include<stdio.h>

int busca (int n, int* vet, int elem){
    int i;

    for(i = 0; i < n; i++){
        if(elem == vet[i])
        return i; //achou o elemento
    }

    return -1; //não achou o elemento
}

int main(){

   int n = 9;
   int vet[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; //vetor de inteiros
   int elem = 60; //valor a ser procurado

   int resultado = busca(n, vet, elem);

   if (resultado != -1) {
        printf("Elemento %d encontrado na posição %d\n", elem, resultado);
    } else {
        printf("Elemento %d não encontrado no vetor\n", elem);
    }

    return 0;
}