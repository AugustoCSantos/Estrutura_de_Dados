#include <stdio.h>

void bubble (int* v, int tamanho);

int main(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    bubble(vetor, tamanho);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

void bubble (int* v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for (int j = 1; j < tamanho; j++){
            if (v[j-1] > v[j]){
                int temp;
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }   
    }
}