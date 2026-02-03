#include <stdio.h>

int main() {

    char temp;
    while (scanf("%c", &temp) == 1) {

        if (temp != '\n' && temp != '\r') {
            temp += 1;
        }
        printf("%c", temp);
    }


}