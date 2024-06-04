#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMEROS_A_GENERAR 5

int main() {
    FILE *archivo;
    int i, numero;

    // Abre el archivo para escribir
    archivo = fopen("numeros_hex.txt", "w"); // Cambia el nombre del archivo

    // Verifica si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        return 1;
    }

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Genera y escribe los números aleatorios en el archivo en formato hexadecimal
    for (i = 0; i < NUMEROS_A_GENERAR; i++) {
        numero = rand() % 16; // Números aleatorios entre 0 y 15
        fprintf(archivo, "%X\n", numero); // Usa "%X" para formato hexadecimal
    }

    // Cierra el archivo
    fclose(archivo);

    printf("Archivo generado correctamente.\n");

    return 0;
}
