#include <stdio.h>


typedef struct dates {
    int day;
    int month;
    int year;
}stru;

char* months[] = { "janeiro","fevereiro","março","abril","maio","junho","julho","agosto", "setembro", "outubro", "novembro", "dezembro" };
char* isleapYear[] = { " não é", " é" };
char* ifExist[] = { "Não existe", "Existe" };

int main() {
    int leapYear = 0, exist = 0;
    stru date;


    scanf(" %d", &date.day);
    scanf(" %d", &date.month);
    scanf(" %d", &date.year);

    if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) {
        leapYear = 1;
    }
    if (date.day >= 1 && (
        (
            ((date.month % 2 != 0 && date.month <= 7 && date.month > 0)
                ||
                (date.month % 2 == 0 && date.month > 7 && date.month <= 12))
            && date.day <= 31
            )
        ||
        (date.month == 2 && date.day <= 28 + leapYear)
        ||
        (
            (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
            && date.day <= 30
            )
        )) {
        exist = 1;
    }



    printf("%d%s bissexto. %s o dia %d em %s.", date.year, isleapYear[leapYear], ifExist[exist], date.day, months[date.month -1]);

    return 0;

}






