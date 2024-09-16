#include <stdio.h>

int main()
{
    char character;
    printf("Introduza o caractere:\t");
    scanf("%c", &character);
    
    printf("     Boas Gente             \n");
    printf("           %c               \n",     character );
    printf("          %c%c%c             \n",     character, character, character );
    printf("         %c%c %c%c            \n",     character, character, character, character );
    printf("        %c%c%c %c%c%c          \n",     character, character, character, character, character, character );
    printf("       %c%c%c%c %c%c%c%c        \n",     character, character, character, character, character, character, character, character );
    printf("      %c%c%c%c%c %c%c%c%c%c      \n",     character, character, character, character, character, character, character, character, character, character );
    printf("           %c               \n",     character );
    printf("    Merry Christmas         \n");
    printf("  you filthy animals!!      \n");


    return 0;

}