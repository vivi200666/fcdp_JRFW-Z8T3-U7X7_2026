/**
 * @file cb_08_multiplicacion_matrices_paralela.c
 * @brief Implemente un programa en C que multiplique dos matrices cuadradas de tamaño
 * N × N paralelizadas con OpenMP. Mida el tiempo con omp_get_wtime() y use 
 * omp_get_thread_num() para mostrar qué hilos participan en el cálculo de las filas.
 * @author Viviana Jimenez
 * @date 2026-09-26
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500
void fill_matrix(int **m, int size){
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            *(*(m + i) + j) = (i + j) % 100;
        }
    }
}

void multiply_matrix_parallel(int **m1, int **m2, int **res, int size){
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        int thread_id = omp_get_thread_num();
        if (i < 5) { 
            #pragma omp critical
            {
                printf("El hilo ID: %d esta calculando la fila %d de la matriz.\n", thread_id, i);
            }
        }
        for (int j = 0; j < size; j++) {
            *(*(res + i) + j) = 0;
            for (int k = 0; k < size; k++) {
                *(*(res + i) + j) += (*(*(m1 + i) + k)) * (*(*(m2 + k) + j));
            }
        }
    }
}

int main(){
    int size = N;
    int **matrix1 = (int **)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        matrix1[i] = (int *)malloc(size * sizeof(int));
    }
    int **matrix2 = (int **)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        matrix2[i] = (int *)malloc(size * sizeof(int));
    }
    int **result = (int **)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++){
        result[i] = (int *)malloc(size * sizeof(int));
    }
    fill_matrix(matrix1, size);
    fill_matrix(matrix2, size);
    double start_time = omp_get_wtime();
    multiply_matrix_parallel(matrix1, matrix2, result, size);
    double elapsed_time = omp_get_wtime() - start_time;
    printf("Tamano de la matriz : %d x %d\n", size, size);
    printf("Tiempo Paralelo     : %.6f segundos\n", elapsed_time);
    for (int i = 0; i < size; i++){
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}