
/**
 * @file cb_07_producto_escalar_secuencial.c
 * @brief Implemente el producto escalar de dos vectores de tamaño N. Paralelice el cálculo
con OpenMP utilizando reduction. Use las funciones omp get thread num() y
omp get num threads() para imprimir qué hilos participan en el cálculo.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void fill_vector(int *v, int size) {
    for (int i = 0; i < size; i++) {
        *(v + i) = (i + 1) % 10; 
    }
}

long long scalar_product(int *v1, int *v2, int size) {
    long long escalar = 0;
    
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

    clock_t start_time = clock();
    long long resultado = scalar_product(v1, v2, size);
    double elapsed_time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

    printf("Tamano de los vectores : %d\n", size);
    printf("Producto Escalar Total : %lld\n", resultado);
    printf("Tiempo de Ejecucion    : %.6f segundos\n", elapsed_time);

    free(v1);
    free(v2);

    return 0;
}