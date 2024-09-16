#include <stdio.h>
int main () {

    float x = 0.0f;
    float y = 0.0f; 
    char operador;

// Introduza 1o numero 
    printf("Introduza o Primeiro Numero: ");
    scanf("%f, &x");
// Introduza 2o numero
    printf("Introduza o Sengundo Numero:");
    scanf("%f, &y");
// Intruduza Operador
    char operador;
    printf ("Introduza o Operador:");
    scanf("%c, &operador");
// Fazer o Calculo
    float resultado = 0.0f;
    
    if(operador == '+')
    { 
        resultado = x + y;
    }
    if(operador == '-')
    {
        resultado = x - y;
    }
    if(operador == '*')
    {
        resultado = x * y;
    }
    if(operador == '/')
    {
        resultado = x / y;
    }
    
   return 0;

    }
    

    


