#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sumxy(int j3, int i3, int m, double **matrix)
{
    double pi = 3.141592, p = 0;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < m; y++)
        {
            p += matrix[x][y] * cos((((2 * x) + 1) * (i3 * pi)) / (2 * m)) * cos((((2 * y) + 1) * (j3 * pi)) / (2 * m));
        }
    }
    return p;
}
double ai(int i2, int m)
{

    if (i2 == 0)
    {
        return 1 / sqrt(m);
    }
    else
    {
        return sqrt(2.0 / m);
    }
}

double aj(int j2, int m)
{

    if (j2 == 0)
    {
        return 1 / sqrt(m);
    }
    else
    {
        return sqrt(2.0 / m);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double **matrix1 = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        matrix1[i] = (double *)malloc(n * sizeof(double));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix1[i][j]);
        }
    }
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        matrix2[i] = (double *)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[i][j] = ai(i, n) * aj(j, n) * sumxy(j, i, n, matrix1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%9.3lf ", matrix2[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < n; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}