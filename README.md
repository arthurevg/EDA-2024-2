# Alocação Dinâmica e Estruturas Heterogêneas

## Descrição
 Suponha que você seja um cientista de dados trabalhando em uma empresa de análise climática. Você
 precisa analisar as temperaturas diárias de várias cidades ao longo de um período indefinido. As temperaturas
 são fornecidas uma por uma e não há um número fixo de dias para análise, o que torna necessário o uso de
 alocação dinâmica de memória para armazenar essas temperaturas.

---

## Objetivo
Desenvolver um programa capaz de:
1. Gerenciar dinamicamente as informações de temperatura diárias de diferentes cidades.
2. Fornecer estatísticas úteis, como temperatura média, maior e menor temperatura registrada (com as respectivas cidades).
3. Permitir inserções e desalocações dinâmicas de memória.

---

## Condições de Contorno da Solução
Sua solução deve atender às seguintes condições:
### Arquivo `tipos.h`
Definido com os seguintes tipos:

```c
typedef struct {
    char cidade[20];
    float *temperatura;
} TMedidas;

typedef struct {
    int qtde_dias; // Quantidade máxima de medidas
    int qtde_medidas; // Quantidade atual de medidas registradas
    TMedidas *medidas; // Vetor de medidas
} TTemperaturas;
```
 O programa deve importar o arquivo tipos.h e ter um menu com as seguintes opções:  
 1 - Reset: Esta opção deve: ler a quantidade de dias de registros de temperaturas qtde_dias ,alocar o
 vetor de medidas e colocar qtde_medidas igual a zero;  
 2 - Inserir Medida: Esta opção deve: ler os dados de uma medida (nome da cidade e temperatura) e
 adicionar esta medida ao vetor de temperaturas;  
 3 - Estatística: Esta opção deve: mostrar a temperatura média, a menor temperatura (o nome da
 cidade e temperatura) e a maior temperatura (o nome da cidade e temperatura);  
 4 - Sair: Esta opção deve: Desalocar o vetor medidas e encerrar o programa.  
