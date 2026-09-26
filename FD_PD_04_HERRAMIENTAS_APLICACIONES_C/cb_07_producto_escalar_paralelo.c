
/**
 * @file cb_07_producto_escalar_paralelo.c
 * @brief Implemente el producto escalar de dos vectores de tamaño N. Paralelice el cálculo
con OpenMP utilizando reduction. Use las funciones omp get thread num() y
omp get num threads() para imprimir qué hilos participan en el cálculo.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000000
void fill_vector(int *v, int size) {
    for (int i = 0; i < size; i++) {
        *(v + i) = (i + 1) % 10; 
    }
}
long long scalar_product(int *v1, int *v2, int size) {
    long long escalar = 0;
    #pragma omp parallel 
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        #pragma omp critical
        {
            printf("Hola! Participa el hilo ID: %d de un total de %d hilos.\n", thread_id, total_threads);
        }
    }
    #pragma omp parallel for reduction(+:escalar)
    for (int i = 0; i < size; i++) {
        escalar += (long long)(*(v1 + i)) * (*(v2 + i));
    }

    return escalar;
}

int main() {
    int size = N;
    int *v1 = (int *)malloc(size * sizeof(int));
    int *v2 = (int *)malloc(size * sizeof(int));

    if (v1 == NULL || v2 == NULL) {
        printf("Error: No hay suficiente memoria en el sistema.\n");
        return 1;
    }
    fill_vector(v1, size);
    fill_vector(v2, size);
    double start_time = omp_get_wtime();
    long long resultado = scalar_product(v1, v2, size);
    double elapsed_time = omp_get_wtime() - start_time;
    printf("Tamano de los vectores : %d\n", size);
    printf("Producto Escalar Total : %lld\n", resultado);
    printf("Tiempo de Ejecucion    : %.6f segundos\n", elapsed_time);
    free(v1);
    free(v2);

    return 0;
}