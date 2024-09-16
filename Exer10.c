#include <stdio.h>

int main()
{
    int numero1, numero2;

    // 1. Introduza o primeiro numero
    printf("Introduza o Primeiro Numero: ");
    scanf("%d", &numero1); // & para pasar la dirección de memoria

    // 2. Introduza o segundo Numero
    printf("Introduza o Segundo Numero: ");
    scanf("%d", &numero2); // & para pasar la dirección de memoria

    // 3. Resultado: Mostrar o Numero Maior
    if (numero1 > numero2)
    {
        printf("O Primeiro numero é Maior\n");
    }
    else if (numero2 > numero1)
    {
        printf("O Segundo Numero é Maior\n");
    }
    else
    {
        printf("Os dois números são iguais\n");
    }

    return 0;
}
