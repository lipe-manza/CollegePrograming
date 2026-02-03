#include <stdio.h>

int main() {
    // -------------------------------
    // VETOR 1D
    // -------------------------------
    int v[3] = {10, 20, 30}; // Declaração de um vetor 1D com 3 elementos


    printf("Vetor 1D:\n");

    // 'v' é o endereço do primeiro elemento (v == &v[0])
    printf("v           = %p (endereço do vetor)\n", v);

    // '*v' acessa o valor contido em v => v[0]
    printf("*v          = %d (valor do primeiro elemento)\n", *v);

    // 'v + 1' aponta para o segundo elemento (v + 1 == &v[1])
    printf("v + 1       = %p (endereço do segundo elemento)\n", v + 1);

    // '*(v + 1)' acessa o segundo elemento => v[1]
    printf("*(v + 1)    = %d (valor do segundo elemento)\n", *(v + 1));

    // 'v + 2' é o endereço do terceiro elemento (v + 2 == &v[2])
    printf("v + 2       = %p (endereço do terceiro elemento)\n", v + 2);

    // '*(v + 2)' acessa o terceiro elemento => v[2]
    printf("*(v + 2)    = %d (valor do terceiro elemento)\n", *(v + 2));



    // -------------------------------
    // MATRIZ 2D
    // -------------------------------
    int m[2][2] = {
        {1, 2}, // Primeira linha da matriz
        {3, 4}  // Segunda linha da matriz
    };

    printf("\nMatriz 2D:\n");

    // 'm' é o endereço da matriz, que equivale a &m[0]
    printf("m           = %p (endereço da matriz)\n", m);

    // '*m' é o endereço da primeira linha => m[0] => &m[0][0]
    printf("*m          = %p (endereço da primeira linha)\n", *m);

    // '**m' acessa o primeiro elemento => m[0][0]
    printf("**m         = %d (valor de m[0][0])\n", **m);

    // '*m + 1' é o endereço de m[0][1]
    // *m é o mesmo que m[0], que aponta para m[0][0], então somar 1 vai para m[0][1]
    printf("*m + 1      = %p (endereço de m[0][1])\n", *m + 1);

    // '*(*m + 1)' acessa m[0][1]
    printf("*(*m + 1)   = %d (valor de m[0][1])\n", *(*m + 1));

    // 'm + 1' é o endereço da segunda linha => &m[1]
    printf("m + 1       = %p (endereço da segunda linha)\n", m + 1);

    // '*(m + 1)' é o mesmo que m[1] => endereço de m[1][0]
    printf("*(m + 1)    = %p (endereço da segunda linha - m[1])\n", *(m + 1));

    // '*(*(m + 1))' acessa m[1][0]
    printf("*(*(m + 1)) = %d (valor de m[1][0])\n", *(*(m + 1)));

    // '*(*(m + 1) + 1)' acessa m[1][1]
    printf("*(*(m + 1) + 1) = %d (valor de m[1][1])\n", *(*(m + 1) + 1));



    // -------------------------------
    // MATRIZ 3D
    // -------------------------------
    int t[2][2][2] = {
        {
            {1, 2}, // Primeira linha do primeiro bloco
            {3, 4}  // Segunda linha do primeiro bloco
        },
        {
            {5, 6}, // Primeira linha do segundo bloco
            {7, 8}  // Segunda linha do segundo bloco
        }
    };

    printf("\nMatriz 3D:\n");

    // 't' é o endereço da matriz 3D => &t[0]
    printf("t             = %p (endereço da matriz 3D)\n", t);

    // '*t' é o endereço do primeiro bloco 2D => t[0]
    printf("*t            = %p (endereço do primeiro bloco 2D - t[0])\n", *t);

    // '**t' é o endereço da primeira linha do primeiro bloco => t[0][0]
    printf("**t           = %p (endereço da primeira linha - t[0][0])\n", **t);

    // '***t' acessa o valor t[0][0][0]
    printf("***t          = %d (valor t[0][0][0])\n", ***t);

    // '*(*(*t + 1))' acessa t[0][0][1]
    // *t = t[0], *t + 1 = t[0][0] + 1 => t[0][0][1]
    printf("*(*(*t +1))  = %d (valor t[0][0][1])\n", *(*(*t + 1)));

    // '*(*(*(t + 0) + 1))' acessa t[0][1][0]
    // t + 0 = t[0], *(t + 0) = t[0], *(t[0] + 1) = t[0][1], *t[0][1] = t[0][1][0]
    printf("*(*(*(t + 0) + 1)) = %d (valor t[0][1][0])\n", *(*(*(t + 0) + 1)));

    // '*(*(*(t + 1)))' acessa t[1][0][0]
    printf("*(*(*(t + 1)))     = %d (valor t[1][0][0])\n", *(*(*(t + 1))));

    // '*(*(*(t + 1) + 1) + 1)' acessa t[1][1][1]
    printf("*(*(*(t + 1) + 1) + 1) = %d (valor t[1][1][1])\n", *(*(*(t + 1) + 1) + 1));

    return 0;
}
