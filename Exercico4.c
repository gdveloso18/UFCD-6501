#include <stdio.h>

int main() {
    double a, result;
    char operation;


    printf("Insira um numero: ");
    scanf("%lf", &a);
    
    
    printf("selecione uma função (+, -, *, /): ");
    scanf(" %c", &operation);

    
    printf("Insira outro numero: ");
    scanf("%lf", &result);

    


float soma = 0.0f;
float produto = 0.0f;
float diference = 0.0f;
float quociente = 0.0f;

soma = x + y;
produto = x * y;
diference = x - y;
quociente = x / y;

    printf("Result: %lf\n", result);
    
    return 0;
}
