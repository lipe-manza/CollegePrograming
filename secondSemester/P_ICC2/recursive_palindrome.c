#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
// Enzo Trulenque Evangelista - 15819219
// Luiz Felipe Manzoli Franceschini - 16913300

bool isPalindrome(char* word, int start, int end) {

    if (word[start] == word[end]) { //verifica se os caracteres das extremidades são iguais

        return (end - start) <= 1 ? true : isPalindrome(word, start + 1, end - 1); //Enquanto os ponteiros não chegarem no centro chama a funcao para os caracteres adjacentes centrais, se chegou no meio é um palindromo

    }
    else if (word[start] != word[end]) { //Retorna false se os caracteres simétricos forem diferentes
        return 0;
    }
}


int formatString(char* string, char* stringFormatted) { //Funcao para formatar a string

    int count = 0; //Tamanho da nova string

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) { //Verifica se é um caractere alfanumérico e trasnforma em maiusculo
            stringFormatted[count++] = toupper(string[i]);
        }
    }

    stringFormatted[count] = '\0';

    return count; //Retorna o tamanho da nova string formatada 
}



int main() {

    char string[1000];
    char stringf[1000];
    int start = 0;
    int end = 0;

    while (fgets(string, 1000, stdin)) { //Le todas as linhas e connfere se é palindromo
        if (strlen(string) != 0) {
            end = formatString(string, stringf);
            printf("%s\n", isPalindrome(stringf, start, end - 1) ? "Sim" : "Não");
        }
        else {
            printf("Sim");
        }
    }

    return 0;
}
