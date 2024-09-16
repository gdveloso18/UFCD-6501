#include <stdio.h>
int main ()
{
    int temperatura = 0;

    //1. introduzir a temperatura inicial
    printf("Introduza a temperatua:");
    scanf("%d", &temperatura);

    //Enquanto a tempertura for superior a 40 graus, continua a pedir para introduzir a temperatura
    // Simulação de temperatura, atravez do teclado
    
    while (temperatura > 40  || temperatura < 10)
    {
        printf("Introduza a temperatua:");
        scanf("%d", &temperatura);
    }

    return 0;
}