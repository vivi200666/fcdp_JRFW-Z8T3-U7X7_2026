/**
 * @file cb_arreglo_dinamico_09.c
 * @brief Crear un arreglo dinamico, llenarlo con valores del usuario y calcular su suma.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/
#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    float note1;
    float note2;
    float note3;
};

float calculate_average(struct student *student) {
    return (student->note1 + student->note2 + student->note3) / 3;
}

void show_students(struct student *students, int n) {
    for (int i = 0; i < n; i++) {
        float average = calculate_average(&students[i]);
        printf("\nID: %d", students[i].id);
        printf("\nnombre: %s", students[i].name);
        printf("\npromedio: %.2f\n", average);
    }
}

void show_passed(struct student *students, int n) {
    printf("\nESTUDIANTES APROBADOS\n");
    for (int i = 0; i < n; i++) {
        float average = calculate_average(&students[i]);
        if (average >= 60) {
            printf("ID: %d - %s - average: %.2f\n", students[i].id,students[i].name, average);
        }
    }
}
int main() {
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);
    struct student *students =(struct student *) malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++) {
        printf("\nstudent %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Nombre: ");
        scanf("%s", students[i].name);
        printf("nota 1: ");
        scanf("%f", &students[i].note1);
        printf("nota 2: ");
        scanf("%f", &students[i].note2);
        printf("nota 3: ");
        scanf("%f", &students[i].note3);
    }
    printf("\nestudiantes\n");
    show_students(students, n);
    show_passed(students, n);
    free(students);

    return 0;
}