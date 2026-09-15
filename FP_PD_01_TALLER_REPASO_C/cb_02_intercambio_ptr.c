/**
 * @file cb_02_intercambio_ptr.c
 * @brief Intercambiar valores de dos enteros usando punteros.
 * @author Viviana Jimenez
 * @date 2026-09-11
*/
#include <stdio.h>
void swap(int *ptrX, int *ptrY){
    int z=*ptrX;
    *ptrX=*ptrY;
    *ptrY = z;
    printf("\n Intercambaidos%d, ", *ptrX);
    printf("%d", *ptrY);
}
    
int main(){
    
    int x=52;
    int y=23;
    int *ptr_x=&x;
    int *ptr_y=&y;
    printf("Orden inicial %d, ",*ptr_x);
    printf("%d",*ptr_y);
    swap(ptr_x, ptr_y);
    return 0;
}