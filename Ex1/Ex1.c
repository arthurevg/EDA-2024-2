#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void Reset(TTemperaturas *T)
{
    int qtdDias;
    printf("Digite a quantidade de dias de registro de temperaturas:\n ");
    scanf("%d", &qtdDias);
    T->qtde_dias = qtdDias;
    T->medidas = (TMedidas *)malloc(qtdDias * sizeof(TMedidas));
    T->qtde_medidas = 0;
}

void InserirMedidas(TTemperaturas *T)
{
    char cidade[20];
    float temp;
    if (T->qtde_medidas >= T->qtde_dias)
    {
        printf("Nao e possivel inserir mais medidas.\n");
        return;
    }
    else
    {
        printf("Digite o nome da cidade \n");
        getchar();
        fgets(cidade, 20, stdin);
        strcpy(T->medidas[T->qtde_medidas].cidade, cidade);
        printf("Digite a temperatura\n");
        scanf("%f", &temp);
        printf("Adicionada com Sucesso!\n");
        T->medidas[T->qtde_medidas].temperatura = temp;
        T->qtde_medidas++;
    }
}
void Estatistica(TTemperaturas *T)
{
    if (T->qtde_medidas == 0)
    {
        printf("Nao ha medidas registradas\n");
        return;
    }
    else
    {
        float maior;
        float menor;
        float soma = 0;
        char cidade_menor[20];
        char cidade_maior[20];

        for (int i = 0; i < T->qtde_medidas; i++)
        {
            float temp = T->medidas[i].temperatura;
            soma += temp;
            if (temp < menor)
            {
                menor = temp;
                strcpy(cidade_menor, T->medidas[i].cidade);
            }
            if (temp > maior)
            {
                maior = temp;
                strcpy(cidade_maior, T->medidas[i].cidade);
            }
        }
        printf("Maior temperatura %.2f em %s\n", maior, cidade_maior);
        printf("Menor temperatura %.2f em %s\n", menor, cidade_menor);
        printf("Media das temperaturas %.2f\n", (soma / T->qtde_medidas));
    }
}
void Sair(TTemperaturas *T)
{
    free(T->medidas);
}

int main()
{
    int op;
    TTemperaturas temperaturas;
    temperaturas.medidas = NULL;
    do
    {
        printf("Digite a opcao desejada:\n1 - Reset\n2 - Inserir Medida\n3 - Estatiticas\n4 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Reset(&temperaturas);
            break;
        case 2:
            InserirMedidas(&temperaturas);
            break;
        case 3:
            Estatistica(&temperaturas);
            break;
        case 4:
            Sair(&temperaturas);
            return 0;
        default:
            printf("Opcao invalida\n");
        }
    } while (op != 4);
    return 0;
}