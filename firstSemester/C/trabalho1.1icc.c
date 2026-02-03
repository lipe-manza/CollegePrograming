#include <stdio.h>
#include <math.h>
#define pi 3.141592

double sumxy(int j3, int i3, int m, double matrix[m][m])
// função que calcula a soma dupla sobre todas as posições da matriz
// j=>j3
// i=>i3
// n=>m
// matrix1=>matrix[m][m]
{
    double p = 0; // valor da soma dupla
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < m; y++)
        {
            p += matrix[x][y] * cos((((2 * x) + 1) * (i3 * pi)) / (2 * m)) * cos((((2 * y) + 1) * (j3 * pi)) / (2 * m));
        }
    }
    return p;
}
double ai(int i2, int m) // função que calcula o coeficiente de normalização "ai" dependendo da frequencia e da linha i=>i2
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

double aj(int j2, int m) // função que calcula o coeficiente de normalização "aj" dependendo da frequencia e da linha j=>j2
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
    int n; // tamanho da matriz
    scanf("%d", &n);

    double matrix1[n][n];       // matriz antiga(1) 2d quadrada de tamanho nxn
    for (int i = 0; i < n; i++) // for para preencher os elementos da matriz usando o scanf
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    double matrix2[n][n]; // matriz nova (matrix2): irá ser preenchida com os novos valores

    for (int i = 0; i < n; i++) // for usado para preencher a matriz nova (2), no qual i é a linha e j a coluna da matriz nova (matrix2)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[i][j] = ai(i, n) * aj(j, n) * sumxy(j, i, n, matrix1); // preenchimento da matriz nova(2) chamando as funções "ai" "aj" "sumxy"
        }
    }
    for (int i = 0; i < n; i++) // fors usados para printar cada elemento da matriz nova (matrix2), utilizando dois for para fazer a quebra de linha após o preenchimento de uma linha completa para passar para a nova linha
    {
        for (int j = 0; j < n; j++)
        {
            printf("%9.3lf ", matrix2[i][j]); // printa a linha i
        }
        printf("\n"); // passa para a próxima linha
    }
    return 0;
}
