#include <stdio.h>

int main() {
    float x, y, sum;

    
    printf("Enter the first number (x): ");
    scanf("%f", &x);

    printf("Enter the second number (y): ");
    scanf("%f", &y);

    
    sum = x + y;

    
    printf("The sum of %.2f and %.2f is %.2f\n", x, y, sum);

    return 0;
}
