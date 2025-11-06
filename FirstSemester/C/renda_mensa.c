#include <stdio.h>
int main()
{

    float renda, divida, credito;

    printf("renda mensal:");
    scanf("%f", &renda);
    printf("valor da divida:");
    scanf("%f", &divida);
    printf("pontuação de credito:");
    scanf("%f", &credito);

if(renda<0 || divida<0 || credito<0 || credito>1000 ){

printf("Entrada invalida");
}

    
    if (credito < 300)
    {

        printf("inapta(falta de credito)");
    }

    else if (divida > renda * 1.5 && credito < 700)
    {

        printf("inapta(divida alta)");
    }
    else if (divida <= renda / 2 && credito < 600)
    {

        printf("em analise");
    }
    else
    {

        printf("apta");
    }


    return 0;
}