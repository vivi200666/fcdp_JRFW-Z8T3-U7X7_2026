/**
 * @file cb_notas_08.c
 * @brief Determinar el mayor y menor de tres numeros.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/
#include <stdio.h>

char qualification(float note) {
    if (note >= 90 && note <= 100) {
        return 'A';
    }
    else if (note >= 80) {
        return 'B';
    }
    else if (note >= 70) {
        return 'C';
    }
    else if (note >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

int main() {
    float note=50;
    char calificacion;
    if (note < 0 || note > 100) {
        printf("La nota no es valida");
    }
    else {
        calificacion = qualification(note);
        printf("\nCalificacion es: %c", calificacion);
    }

    return 0;
}