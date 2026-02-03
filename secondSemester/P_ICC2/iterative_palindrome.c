#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


bool isPalindrome(char* word) {
    int len = strlen(word);

    for (int i = 0; i < ((len / 2) + len % 2); i++) {
        if (word[i] != word[len - i - 1])
            return false;
    }

    return true;
}


void filterString(char* string, char** stringFiltred) {

    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            *stringFiltred[count++] = toupper(string[i]);
        }
    }

    *stringFiltred[count] = '\0';

}



int main() {

    char string[1000];
    char* stringf[1000];

    while (fgets(string, 1000, stdin)) {
        if (strlen(string) != 0) {
            filterString(string, &stringf);
            printf("%s\n", isPalindrome(stringf) ? "Sim" : "Não");
        }
        else {
            printf("Sim");
        }
    }

    return 0;
}
