#include <stdio.h>

typedef struct students {
    float grade;
}stru;



int main() {

    int n = 0, studentsPassed = 0;
    float highestGrade = 0, averageGrade = 0;

    scanf(" %d", &n);
    if (n < 1)return 0;

    stru student[n];

    for (int i = 0; i < n; i++) {
        scanf(" %f", &student[i].grade);
        if (student[i].grade > 10 || student[i].grade < 0) {
            printf("Nota fora do intervalo.");
            return 0;
        }
        if (student[i].grade > highestGrade) {
            highestGrade = student[i].grade;
        }
        studentsPassed += (student[i].grade >= 5.0) ? 1 : 0;
        averageGrade += student[i].grade;
    }

    averageGrade /= n;

    printf("Foram %d aprovado(s). Maior nota = %0.2f. Nota média = %0.2f.", studentsPassed, highestGrade, averageGrade);

    return 0;


}