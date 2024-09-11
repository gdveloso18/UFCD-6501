#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>   // Para a função sleep
#include <conio.h>    // Para _kbhit() e getch() (somente em Windows)

int main() {
    char input;
    bool excessoVelocidade = false;
    bool executando = true;
    bool modoManutencao = false;

    while (executando) {
        // Se estiver em modo de manutenção, a luz amarela pisca até pressionar a tecla de manutenção novamente
        if (modoManutencao) {
            printf("Modo de Manutenção Ativado - Luz Amarela a piscar\n");
            while (modoManutencao) {
                printf("Luz Amarela ON\n");
                sleep(2);  // Luz acesa por 2 segundos
                printf("Luz Amarela OFF\n");
                sleep(2);  // Luz apagada por 2 segundos

                // Verifica se a tecla foi pressionada para sair do modo de manutenção
                if (_kbhit()) {
                    input = getch();
                    if (input == 'm' || input == 'M') {
                        modoManutencao = false;
                        printf("Modo de Manutenção Desativado. Voltando à operação normal.\n");
                    }
                }
            }
        }

        printf("Luz Verde - O semáforo está verde. (Velocidade < 50 km/h)\n");

        // Espera até que um caractere seja inserido para simular excesso de velocidade, manutenção ou parada
        printf("Pressione qualquer tecla para simular excesso de velocidade, 'm' para manutenção ou 's' para encerrar...\n");

        // Aguarda input do usuário
        while (!_kbhit()) {
            sleep(1);  // Simula espera de 1 segundo
        }

        input = getch();  // Captura a tecla pressionada

        // Se a tecla for 's', o programa encerra
        if (input == 's' || input == 'S') {
            printf("\nPrograma encerrado!\n");
            executando = false;
            break;
        }
        // Se a tecla for 'm', ativa o modo de manutenção (luz amarela piscando)
        else if (input == 'm' || input == 'M') {
            modoManutencao = true;
        }
        // Simula excesso de velocidade
        else {
            excessoVelocidade = true;
            printf("Excesso de Velocidade Detectado! Contagem regressiva para luz amarela...\n");
            
            // Contador de 5 segundos até mudar para a luz amarela
            for (int i = 5; i > 0; i--) {
                printf("Mudando para luz amarela em %d segundos...\n", i);
                sleep(1);
            }

            // Muda para luz amarela
            printf("Luz Amarela - Atenção, velocidade excedida! (50 km/h < Velocidade)\n");
            sleep(5);  // Fica na luz amarela por 5 segundos

            // Muda para luz vermelha
            printf("Luz Vermelha - Pare! A luz vermelha ficará ligada por 20 segundos.\n");
            
            // Contador de 20 segundos para luz vermelha
            for (int i = 20; i > 0; i--) {
                printf("Luz vermelha: %d segundos restantes...\n", i);
                sleep(1);
            }

            // Após 20 segundos, volta para luz verde
            excessoVelocidade = false;
            printf("Voltando para luz verde.\n");
        }
    }

    return 0;
}
