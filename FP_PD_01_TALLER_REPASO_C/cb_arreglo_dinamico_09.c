/**
 * @file cb_arreglo_dinamico_09.c
 * @brief Crear un arreglo dinamico, llenarlo con valores del usuario y calcular su suma.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/
#include <stdio.h>
#include <stdlib.h>
int calcularSuma(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}
int main() {
    int n;
    int suma;
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    suma = calcularSuma(arr, n);
    printf("La suma total es: %d\n", suma);
    free(arr);

    return 0;
}