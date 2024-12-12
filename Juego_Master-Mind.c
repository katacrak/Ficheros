#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int combinacion[4], intento[4], aciertos = 0, intentos = 0;

    printf("Jugador 1: Introduce una combinación de 4 números del 1 al 4 (sin repetir):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &combinacion[i]);
        if (combinacion[i] < 1 || combinacion[i] > 4) {
            printf("Número inválido. Debe ser entre 1 y 4.\n");
            i--;
        }
        for (int j = 0; j < i; j++) {
            if (combinacion[i] == combinacion[j]) {
                printf("No se pueden repetir números. Introduce otro:\n");
                i--;
                break;
            }
        }
    }
    system("clear");

    printf("Jugador 2: Adivina la combinación.\n");
    do {
        aciertos = 0;
        printf("Introduce tu intento:\n");
        for (int i = 0; i < 4; i++) {
            scanf("%d", &intento[i]);
        }
        for (int i = 0; i < 4; i++) {
            if (intento[i] == combinacion[i]) {
                aciertos++;
            }
        }
        printf("Aciertos: %d\n", aciertos);
        intentos++;
    } while (aciertos < 4);

    printf("¡Has acertado la combinación en %d intentos!\n", intentos);
    return 0;
}
