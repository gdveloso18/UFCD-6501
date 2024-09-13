#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TENTATIVAS 5
#define NUM_PALAVRAS 9

// Lista de palavras
const char *palavras[] = {"Gato", "Rato", "Cão", "Macaco", "Cavalo", "Urso", "Porco", "Vaca", "Cabra"};

// Função para escolher uma palavra aleatória
const char *escolher_palavra() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int indice = rand() % NUM_PALAVRAS;
    return palavras[indice];
}

// Função para imprimir o estado atual da palavra com underscores
void mostrar_palavra(char palavra_oculta[], int tamanho_palavra) {
    for (int i = 0; i < tamanho_palavra; i++) {
        printf("%c ", palavra_oculta[i]);
    }
    printf("\n");
}

// Função para verificar se a letra está na palavra
int verificar_letra(char letra, const char *palavra, char palavra_oculta[], int tamanho_palavra) {
    int acertou = 0;
    for (int i = 0; i < tamanho_palavra; i++) {
        if (letra == palavra[i] || letra == palavra[i] + 32 || letra == palavra[i] - 32) {  // Trata maiúsculas e minúsculas
            palavra_oculta[i] = palavra[i];
            acertou = 1;
        }
    }
    return acertou;
}

// Função para verificar se o jogador completou a palavra
int palavra_completa(char palavra_oculta[], int tamanho_palavra) {
    for (int i = 0; i < tamanho_palavra; i++) {
        if (palavra_oculta[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char jogar_novamente;
    
    do {
        const char *palavra = escolher_palavra();
        int tamanho_palavra = strlen(palavra);
        char palavra_oculta[tamanho_palavra];
        int tentativas = 0;
        char letra;

        // Inicializa a palavra oculta com underscores
        for (int i = 0; i < tamanho_palavra; i++) {
            palavra_oculta[i] = '_';
        }

        printf("Bem-vindo ao jogo da forca!\n");

        while (tentativas < MAX_TENTATIVAS) {
            mostrar_palavra(palavra_oculta, tamanho_palavra);
            printf("Tentativa %d de %d\n", tentativas + 1, MAX_TENTATIVAS);
            printf("Digite uma letra: ");
            scanf(" %c", &letra);

            // Verifica se a letra está na palavra
            if (!verificar_letra(letra, palavra, palavra_oculta, tamanho_palavra)) {
                tentativas++;
                printf("Letra incorreta!\n");
            }

            // Verifica se a palavra está completa
            if (palavra_completa(palavra_oculta, tamanho_palavra)) {
                printf("Parabéns, você acertou a palavra: %s\n", palavra);
                break;
            }
        }

        if (tentativas == MAX_TENTATIVAS) {
            printf("Você perdeu! A palavra era: %s\n", palavra);
        }

        // Pergunta se o jogador quer jogar novamente
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &jogar_novamente);

    } while (jogar_novamente == 'S' || jogar_novamente == 's');

    printf("Obrigado por jogar!\n");

    return 0;
}


