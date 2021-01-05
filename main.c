// Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>

// Declaraciones globales

// Prototipos de funciones
int setGradePolynomial();
int showPolynomial(int, float[]);

// Función principal
int main() {
    // Declaración e inicialización de variables
    int gradeP = 0, gradeQ = 0, gradeA = 0;

    // Presentación
    printf("\nProducto de polinomios grado n\n\n");

    // Solicitud de variable
    printf("\nIngresa el grado del polinomio P: ");
    // Obtener el grado del polinomio
    gradeP = setGradePolynomial();
    gradeP++;

    // Creación del arreglo de coeficientes
    float p[gradeP];
    // Inicialización del arreglo para evitar errores
    for (int i = 0; i < gradeP; i++) p[i] = 0.0;

    // Salto de línea
    printf("\n");

    // Capturar el coeficiente de cada término del polinomio
    for (int i = (gradeP - 1); i > -1; i--) {
        // Solicitud de variable
        if(i == 0) printf("Constante (k): ");
        else if(i == 1) printf("Coeficiente del factor (x): ");
        else printf("Coeficiente del factor (x^%d): ", i);
        // Lectura de variable
        scanf("%f", &p[i]);
    }

    // Solicitud de variable
    printf("\n\nIngresa el grado del polinomio Q: ");
    // Obtener el grado del polinomio
    gradeQ = setGradePolynomial();
    gradeQ++;

    // Creación del arreglo de coeficientes
    float q[gradeQ];
    // Inicialización del arreglo para evitar errores
    for (int i = 0; i < gradeQ; i++) q[i] = 0.0;

    // Salto de línea
    printf("\n");

    // Capturar el coeficiente de cada término del polinomio
    for (int i = (gradeQ - 1); i > -1; i--) {
        // Solicitud de variable
        if(i == 0) printf("Constante (k): ");
        else if(i == 1) printf("Coeficiente del factor (x): ");
        else printf("Coeficiente del factor (x^%d): ", i);
        // Lectura de variable
        scanf("%f", &q[i]);
    }

    // Dos saltos de línea
    printf("\n\n");

    // Asignación del grado para el polinomio resultante
    gradeA = (gradeP + gradeQ);
    gradeA++;

    // Creación del arreglo de coeficientes resultantes
    float a[gradeA];
    // Inicialización del arreglo para evitar errores
    for (int i = 0; i < gradeA; i++) a[i] = 0.0;

    // Cálculo de los coeficientes resultantes
    for (int i = 0; i < gradeP; i++)
        for (int j = 0; j < gradeQ; j++)
            a[(i + j)] += p[i] * q[j];

    // Impresión estética
    printf("El primer polinomio es:\n");
    // Mostrar el polinomio 1
    showPolynomial(gradeP, p);

    // Impresión estética
    printf("\n\nEl segundo polinomio es:\n");
    // Mostrar el polinomio 2
    showPolynomial(gradeQ, q);

    // Impresión estética
    printf("\n\n\nEl polinomio resultante es:\n");
    // Mostrar polinomio resultante
    showPolynomial(gradeA, a);

    // Dos saltos de línea
    printf("\n\n");

    // Finalización del programa sin errores
    return 0;
}

// Función para capturar el grado del polinomio
int setGradePolynomial() {
    // Declaración e inicialización de variables
    int grade = 0;
    // Captura del dato
    scanf("%d", &grade);
    // Retorno de la variable capturada
    return grade;
}

// Función para mostrar un polinomio
int showPolynomial(int grade, float a[]) {
    // Impresión del polinomio resultante
    for (int i = (grade - 1); i > -1; i--)
        // Validación para evitar coeficientes de 0
        if(a[i] != 0 && (a[i] <= -1 || a[i] >= 1)) {
            // Validación para valores negativos
            if(a[i] < 0) {
                // Validación para imprimir la variable con los exponentes
                if(i == 0) printf("- %.1f ", (a[i] * -1));
                else if(i == 1) printf("- %.1fx ", (a[i] * -1));
                else printf("- %.1fx^%d ", (a[i] * -1), i);
            } else {
                // Validación para imprimir la variable con los exponentes
                if(i == 0) printf("+ %.1f ", a[i]);
                else if(i == 1) printf("+ %.1fx ", a[i]);
                else printf("+ %.1fx^%d ", a[i], i);
            }
        }

    // Finalización del programa sin errores
    return 0;
}
