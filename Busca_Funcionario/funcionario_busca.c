#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct funcionario{
    char nome[81];
    float valor_hora;
    int hora_mes;
};
typedef struct funcionario Funcionario;

Funcionario* busca(int n, Funcionario** v, char* nome);

int main(){
    int n;

    printf("Quantidade de funcionarios: ");
    scanf("%d", &n);

    Funcionario *funcionario[n];

    for(int i = 0; i < n; i++){
        funcionario[i] = (Funcionario *)malloc(sizeof(Funcionario)); // Aloque memória para cada funcionário
        if (funcionario[i] == NULL) {
            exit(1);  // Saia em caso de erro
        }

        printf("Nome: ");
        scanf("%s", funcionario[i]->nome); //insere o nome
        printf("Valor por hora: ");
        scanf("%f", &funcionario[i]->valor_hora); //insere o valor por hora
        printf("Horas por mes: ");
        scanf("%d", &funcionario[i]->hora_mes); //insere as horas por mês
    }

    char nomeBusca[81];
    printf("Ache o funcionario: ");
    scanf("%s", nomeBusca);

    Funcionario *resultado = busca(n, funcionario, nomeBusca);

    if (resultado) {
        printf("Funcionário encontrado:\n");
        printf("Nome: %s\n", resultado->nome);
        printf("Valor por hora: %.2f\n", resultado->valor_hora);
        printf("Horas por mes: %d\n", resultado->hora_mes);
    } else {
        printf("Funcionário não encontrado.\n");
    }

    return 0;
}

Funcionario* busca(int n, Funcionario** v, char* nome){
    int inicio = 0;
    int fim = n-1;

    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        int comparacao = strcmp(nome, v[meio]->nome);
        if (comparacao < 0) {
            fim = meio - 1; // Ajusta a posição final
        } else if (comparacao > 0) {
            inicio = meio + 1; // Ajusta a posição inicial
        } else {
            return v[meio]; // Achou o elemento
        }
    }

    return NULL; //nao achou, restou parte de tamanho zero
}