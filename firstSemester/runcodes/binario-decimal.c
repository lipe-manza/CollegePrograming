#include <stdio.h>

int main()
{

    char binario[5];
    int decimal;

    scanf("%s", binario);

    if ((binario[0] == '1' || binario[0] == '0') && (binario[1] == '1' || binario[1] == '0') && (binario[2] == '1' || binario[2] == '0') && (binario[3] == '1' || binario[3] == '0'))
    {
        decimal = (((int)binario[0] - '0') * 8 + ((int)binario[1] - '0') * 4 + ((int)binario[2] - '0') * 2 + ((int)binario[3] - '0') * 1);
        printf("%d", decimal);
    }
    else
    {
        printf("erro");
    }
    return 0;
}