/**
 * @file cb_08_multiplicacion_matrices_secuencial.c
 * @brief Implemente un programa en C que multiplique dos matrices cuadradas de tamaño
N × N. Primero realice la multiplicación de manera secuencial. Luego paralelice
el cálculo con OpenMP utilizando la cláusula parallel for. Mida los tiempos de
ejecución con omp get wtime() y compare los resultados entre la versi´on secuencial
y la paralela. Use omp get thread num() para mostrar qu´e hilos participan en el
c´alculo de las filas de la matriz resultante.
 * @author Viviana Jimenez
 * @date 2026-09-26
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500 
void fill_matrix(int **m, int size){
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            *(*(m + i) + j) = (i + j) % 100;
        }
    }
}

void multiply_matrix_sequential(int **m1, int **m2, int **res, int size){
    for (int i = 0; i < size; i++) {
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
    clock_t start_time=clock();
    multiply_matrix_sequential(matrix1, matrix2, result, size);
    double elapsed_time = (double)(clock() - start_time)/CLOCKS_PER_SEC;
    printf("Tamano de la matriz : %d x %d\n", size, size);
    printf("Tiempo Secuencial   : %.6f segundos\n", elapsed_time);
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