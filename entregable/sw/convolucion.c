#include <stdio.h>
#include <stdlib.h>

void convolve(int N, int x[N][N], int y[N][N], int z[2*N-1][2*N-1]) {
    int size = 2 * N - 1;

    // Inicializar la matriz z con ceros
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            z[i][j] = 0;
        }
    }

    // Realizar la convolución
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    z[i + k][j + l] += x[i][j] * y[k][l];
                }
            }
        }
    }
}

int main() {
    int N = 3; // Tamaño de las matrices x e y

    // Ejemplo de matrices x e y
    int x[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int y[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int z[2*N-1][2*N-1];

    convolve(N, x, y, z);

    // Imprimir la matriz z
    printf("Resultado de la convolucion:\n");
    for (int i = 0; i < 2*N-1; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }

    return 0;
}
