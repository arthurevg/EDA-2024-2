typedef struct
{
    char cidade[20];
    float temperatura;
} TMedidas;

typedef struct
{
    int qtde_dias;    // Quantidade maxima de medidas
    int qtde_medidas; // Qtde de medidas registradas
    TMedidas *medidas;
} TTemperaturas;