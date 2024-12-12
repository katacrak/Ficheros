#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLUMNAS 3

void inicializaTablero(int m[FILAS][COLUMNAS]);
void rellenarTablero(int m[FILAS][COLUMNAS]);
void pintarTablero(int m[FILAS][COLUMNAS]);
int cuentaRepetidos(int m[FILAS][COLUMNAS]);

int main() {
    int tablero[FILAS][COLUMNAS];
    char opcion;

    srand(time(NULL));

    do {
        inicializaTablero(tablero);
        rellenarTablero(tablero);
        pintarTablero(tablero);

        printf("¿Quieres continuar? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    int repetidos = cuentaRepetidos(tablero);

    FILE *archivo = fopen("resultados.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    fprintf(archivo, "Total de números repetidos: %d\n", repetidos);
    fclose(archivo);

    printf("Resultados guardados en 'resultados.txt'.\n");
    return 0;
}

void inicializaTablero(int m[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            m[i][j] = 0;
        }
    }
}

void rellenarTablero(int m[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            m[i][j] = rand() % 9 + 1;
        }
    }
}

void pintarTablero(int m[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int cuentaRepetidos(int m[FILAS][COLUMNAS]) {
    int cuenta = 0, frecuencias[10] = {0};

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            frecuencias[m[i][j]]++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (frecuencias[i] > 1) {
            cuenta += frecuencias[i] - 1;
        }
    }
    return cuenta;
}
