/**
 * @file cb_06_suma_arreglo_secuencial.c
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
#include <time.h>
#define N 1000000

long long sum_arr(int *arr, int size){
    long long sum=0;
    for (int i=0; i<size; i++){
        sum+=*(arr+i);
    }
    return sum;
}
void fill_array(int *arr, int size){
    for (int i = 0; i < size; i++) {
        *(arr +  i) = i % 100;
    }
}


int main(){
    int size=N;
    int *arr=(int*)malloc(size*sizeof(int));
    fill_array(arr,size);
    clock_t start_time= clock();
    long long sum=sum_arr(arr,size);
    double end_time=(double) (clock()- start_time)/CLOCKS_PER_SEC;
    printf("Total Sum: %lld\n", sum);
    printf("Size: %d\n", size);
    printf("Sequential time: %.3fsg\n", end_time);
    free(arr);
    return 0;
}