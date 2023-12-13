#include<stdio.h>

int busca_bin(int n, int* vet, int elem){
    //consideramos todo vetor no inicio
    int inicio = 0;
    int fim = n-1;
    int meio;

    // enquanto a parte restante for maior que zero
    while(inicio <= fim){
        meio = (int) (inicio + fim) / 2;
        if(elem < vet[meio]){
            fim = meio - 1; //ajusta a posicao final
        }
        else if (elem > vet[meio])
        {
            inicio = meio + 1; //ajusta posicao inicial
        }
        else{
            return meio; //elemento encontrado
        }
    }

    return -1; //não encontrou
}

int main(){
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int elemento = 11; // Elemento a ser procurado

    int resultado = busca_bin(tamanho, vetor, elemento);

    if (resultado != -1) {
        printf("Elemento %d encontrado na posição %d.\n", elemento, resultado);
    } else {
        printf("Elemento %d não encontrado no vetor.\n", elemento);
    }

    return 0;
}