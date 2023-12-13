#include<stdio.h>

int busca_ordenada(int n, int* vet, int elem){
    int i;

    for(i = 0; i < n; i++){
        if(elem == vet[i])
            return i; //caso encontre
        else if(elem < vet[i])
            return -1; //interrompe a busca
    }

    return -1; //não achou 
}

int main(){
    int n, elem;

    printf("Mando o tamanho do vetor meu filho\n");
    scanf("%d", &n); //pegar o tamanho do vetor

    int vet[n];
    int i;

    printf("Preenche o vetor ai, mas em ordem\n");
    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    } //pega os elementos do vetor

    printf("Diga o valor a ser procurado\n");
    scanf("%d", &elem);

    int resultado = busca_ordenada(n, vet, elem);

    if (resultado == -1) {
        printf("Elemento não encontrado no vetor.\n");
    } else {
        printf("Elemento encontrado na posição %d do vetor.\n", resultado);
    }

    return 0;
}