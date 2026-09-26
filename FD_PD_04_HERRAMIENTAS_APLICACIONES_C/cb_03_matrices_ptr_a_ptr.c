/**
 * @file cb_03_matrices_ptr_a_ptr.c
 * @brief Implemente una matriz de 3x3 usando int **matriz. Inicialícela dinámicamente
con valores enteros y muestre su contenido utilizando aritmética de punteros.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5
void fill_matrix(int **matrix, int size ){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            *(*(matrix +i)+j)=rand()% 60 + 1; //matrix[i][j]
        }
    }
}
void print_matrix(int **matrix, int size){
    for (int i=0; i<size;i++){
        printf("[");
        for (int j=0; j<size; j++){
            if (j==size-1){
                printf("%d", *(*(matrix+i)+j));
            }else{
                printf("%d, ", *(*(matrix+i)+j));
            }
            
        }
        printf("]");
        printf("\n");
    }

}

int main(){
    int size=N;
    int **matrix=(int**)malloc(size*sizeof(int *));

    for(int i=0; i<size;i++){
        matrix[i]=(int*)malloc(size*sizeof(int));
    }
    fill_matrix(matrix, size);
    print_matrix(matrix, size);

    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}



