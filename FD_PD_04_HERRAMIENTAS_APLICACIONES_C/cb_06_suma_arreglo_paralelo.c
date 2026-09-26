/**
 * @file cb_06_suma_arreglo_paralelo.c
 * @brief Cree un programa en C que calcule la suma de los elementos de un arreglo de
tamaño N (ejemplo N = 1, 000, 000). Primero hágalo de manera secuencial. Luego
paralelícelo con OpenMP usando:
• #pragma omp parallel for reduction(+:suma)
Mida el tiempo de ejecuci´on usando omp get wtime() para comparar ambos enfoques.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000000

long long sum_arr(int *arr, int size, long long *result_sum){
    long long tmp_value=0;
    #pragma omp parallel for reduction (+:tmp_value)
    for (int i=0;i<size;i++){
        tmp_value+=*(arr+i);
    }
    *result_sum=tmp_value;

}
void fill_array(int *arr, int size){
    for (int i = 0; i < size; i++) {
        *(arr +  i) = i % 100;
    }
}
int main(){
    int size=N;
    int *arr=(int*)malloc(size*sizeof(int));
    long long result_sum=0;
    fill_array(arr,size);
    double start_time=omp_get_wtime();
    sum_arr(arr,size,&result_sum);
    double end_time=omp_get_wtime()-start_time;
    free(arr);
    printf("Array Elements : %d\n",     N);
    printf("Total Sum      : %lld\n",   result_sum);
    printf("Parallel Time  : %.3fsg\n", end_time);
    return 0;
}