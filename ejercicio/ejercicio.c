#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 4
#define CAL_APROBATORIA 6.0

int generarCalificacion() {
    return 5.0 + (rand() % 51) / 10.0;
}

void calcularPromedioPorMateria(int calificaciones[NUM_ESTUDIANTES][NUM_MATERIAS], float promediosMaterias[NUM_MATERIAS]) {
    for (int j = 0; j < NUM_MATERIAS; j++) {
        int suma = 0;
        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
        }
        promediosMaterias[j] = suma / (float)NUM_ESTUDIANTES;
    }
}

void calcularPromedioPorEstudiante(int calificaciones[NUM_ESTUDIANTES][NUM_MATERIAS], float promediosEstudiantes[NUM_ESTUDIANTES]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        int suma = 0;
        for (int j = 0; j < NUM_MATERIAS; j++) {
            suma += calificaciones[i][j];
        }
        promediosEstudiantes[i] = suma / (float)NUM_MATERIAS;
    }
}

int main() {
    srand(time(NULL));

    int calificaciones[NUM_ESTUDIANTES][NUM_MATERIAS];
    char *nombresEstudiantes[NUM_ESTUDIANTES] = {"Juan", "Maria", "Pedro", "Ana", "Luis"};
    char *nombresMaterias[NUM_MATERIAS] = {"Matematicas", "Fisica", "Quimica", "Historia"};


    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        for (int j = 0; j < NUM_MATERIAS; j++) {
            calificaciones[i][j] = generarCalificacion();
        }
    }


    float promediosMaterias[NUM_MATERIAS];
    float promediosEstudiantes[NUM_ESTUDIANTES];
    calcularPromedioPorMateria(calificaciones, promediosMaterias);
    calcularPromedioPorEstudiante(calificaciones, promediosEstudiantes);


    printf("\nCalificaciones:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: ", nombresEstudiantes[i]);
        for (int j = 0; j < NUM_MATERIAS; j++) {
            printf("%d ", calificaciones[i][j]);
        }
        printf("\n");
    }

printf("\nPromedios por materia:\n");
    for (int j = 0; j < NUM_MATERIAS; j++) {
        printf("%s: %.2f\n", nombresMaterias[j], promediosMaterias[j]);
    }

    printf("\nPromedios por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: %.2f\n", nombresEstudiantes[i], promediosEstudiantes[i]);
    }

    int mejorEstudiante = 0;
    for (int i = 1; i < NUM_ESTUDIANTES; i++) {
        if (promediosEstudiantes[i] > promediosEstudiantes[mejorEstudiante]) {
            mejorEstudiante = i;
        }
    }
    printf("\nEl estudiante con el mejor promedio es %s con %.2f\n", nombresEstudiantes[mejorEstudiante], promediosEstudiantes[mejorEstudiante]);


    int mejorMateria = 0;
    for (int j = 1; j < NUM_MATERIAS; j++) {
        if (promediosMaterias[j] > promediosMaterias[mejorMateria]) {
            mejorMateria = j;
        }
    }
    printf("\nLa materia con el mejor desempeño es %s con %.2f\n", nombresMaterias[mejorMateria], promediosMaterias[mejorMateria]);


    printf("\nMaterias con problemas (promedio menor a %.2f):\n", CAL_APROBATORIA);
    for (int j = 0; j < NUM_MATERIAS; j++) {
        if (promediosMaterias[j] < CAL_APROBATORIA) {
            printf("%s: %.2f\n", nombresMaterias[j], promediosMaterias[j]);
        }
    }

    printf("\nEstudiantes con problemas:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        int reprobado = 0;
        for (int j = 0; j < NUM_MATERIAS; j++) {
            if (calificaciones[i][j] < CAL_APROBATORIA) {
                reprobado = 1;
                break;
            }
        }
        if (reprobado || promediosEstudiantes[i] < CAL_APROBATORIA) {
            printf("%s: %.2f\n", nombresEstudiantes[i], promediosEstudiantes[i]);
        }
    }

    return 0;
}