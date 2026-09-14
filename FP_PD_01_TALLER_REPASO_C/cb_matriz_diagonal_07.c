/**
 * @file cb_matrix_diagonal_07.c
 * @brief Crear una matrix cuadrada con numeros aleatorios y comparar diagonales.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare_diagonal(int **matrix, int n) {
    int first_diagonal = 0;
    int second_diagonal = 0;
    for (int i = 0; i < n; i++) {
        first_diagonal += matrix[i][i];
        second_diagonal += matrix[i][n - 1 - i];
    }
    printf("\nSuma diagonal principal: %d", first_diagonal);
    printf("\nSuma diagonal secundaria: %d", second_diagonal);

    if (first_diagonal > second_diagonal) {
        printf("La diagonal principal es mayor.\n");
    } 
    else if (second_diagonal > first_diagonal) {
        printf("La diagonal secundaria es mayor.\n");
    } 
    else {
        printf("Las diagonales son iguales.\n");
    }
}

int main() {
    int n=5;
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
    printf("\nmatrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    compare_diagonal(matrix, n);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}