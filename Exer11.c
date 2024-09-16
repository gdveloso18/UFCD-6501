#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Função para mostrar um temporizador decrescente
void contador_decrescente(int segundos) {
    while (segundos > 0) {
        printf("\r%d segundos restantes...", segundos);
        fflush(stdout);
        sleep(1);
        segundos--;
    }
    printf("\n");
}

// Função para simular o login do usuário
int user_login() {
    char username[50];
    char password[50];

    printf("======= LOGIN =======\n");
    printf("Digite o username: ");
    scanf("%s", username);
    printf("Digite a password: ");
    scanf("%s", password);

    // Aqui você pode validar o login, mas neste exemplo é apenas simulação
    printf("Login realizado com sucesso!\n\n");
    return 1;
}

// Função para mostrar um contador decrescente ao selecionar uma opção
void executar_opcao(int opcao) {
    printf("Você selecionou a opção %d. Iniciando contador decrescente de 2 minutos...\n", opcao);
    contador_decrescente(120); // Contador decrescente de 120 segundos (2 minutos)
}

int main() {
    int logged_in = 0;
    int opcao = 0;
    time_t start_time, current_time;

    // Login inicial
    while (!logged_in) {
        logged_in = user_login();
    }

    while (1) {
        // Tempo inicial para contar 1 minuto de inatividade
        start_time = time(NULL);

        // Exibição do menu
        printf("\n======= MENU =======\n");
        printf("1. Opção 1\n");
        printf("2. Opção 2\n");
        printf("3. Opção 3\n");
        printf("4. Opção 4\n");
        printf("5. Opção 5\n");
        printf("Selecione uma opção (tem 60 segundos): ");

        // Contador decrescente de inatividade de 60 segundos
        while (1) {
            // Verifica o tempo de inatividade
            current_time = time(NULL);
            int segundos_restantes = 60 - (int)difftime(current_time, start_time);
            if (segundos_restantes <= 0) {
                printf("\nTempo de inatividade excedido! Voltando ao login...\n");
                contador_decrescente(10); // Mostra o contador decrescente de 10 segundos
                logged_in = 0;
                while (!logged_in) {
                    logged_in = user_login(); // Retorna ao login
                }
                break; // Volta ao menu após login
            }

            // Exibe o tempo restante de inatividade
            printf("\rTempo restante: %d segundos", segundos_restantes);
            fflush(stdout);
            sleep(1);

            // Verifica se o usuário entrou com uma opção válida
            if (scanf("%d", &opcao) == 1 && opcao >= 1 && opcao <= 5) {
                executar_opcao(opcao); // Exibe o contador decrescente ao selecionar uma opção
                break; // Sai do loop e volta ao menu
            } else {
                // Limpa o buffer se a entrada for inválida
                printf("\nEntrada inválida. Selecione uma opção entre 1 e 5: ");
                while (getchar() != '\n'); // Limpa o buffer do teclado
            }
        }
    }

    return 0;
}
