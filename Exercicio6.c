#include <stdio.h>

int main() {
    float x = 0.0f;
    float y = 0.0f;
    char operador;

    // Introduza o 1o numero 
    printf("Introduza o Primeiro Numero: ");
    scanf("%f", &x); 

    // Introduza o 2o numero
    printf("Introduza o Segundo Numero: ");
    scanf("%f", &y);

    
    getchar(); 

    // Introduza o Operador
    printf("Introduza o Operador (+, -, *, /): ");
    scanf("%c", &operador);

    // Fazer o Calculo
    float resultado = 0.0f;

    if (operador == '+') {
        resultado = x + y;
    } else if (operador == '-') {
        resultado = x - y;
    } else if (operador == '*') {
        resultado = x * y;
    } else if (operador == '/') {
        if (y != 0) {
            resultado = x / y;
        } else {
            printf("Erro: Divisao por zero nao permitida.\n");
            return 1; 
        }
    } else {
        printf("Erro: Operador invalido.\n");
        return 1; 
    }

    // Mostrar o Resultado
    printf("Resultado: %f\n", resultado);

    return 0;
}
