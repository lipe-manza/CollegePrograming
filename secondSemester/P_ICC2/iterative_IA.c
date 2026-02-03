#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

int eh_palindromo_iterativo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    
    while (inicio <= fim) {
        // Pular caracteres não alfanuméricos do início
        while (inicio <= fim && !isalnum(str[inicio])) {
            inicio++;
        }
        
        // Pular caracteres não alfanuméricos do fim
        while (inicio <= fim && !isalnum(str[fim])) {
            fim--;
        }
        
        // Se ainda temos caracteres para comparar
        if (inicio <= fim) {
            // Comparar ignorando case
            if (tolower(str[inicio]) != tolower(str[fim])) {
                return 0; // Não é palíndromo
            }
            inicio++;
            fim--;
        }
    }
    
    return 1; // É palíndromo
}

int main() {
    char linha[MAX_SIZE];
    
    while (fgets(linha, MAX_SIZE, stdin) != NULL) {
        // Remover o '\n' do final se existir
        linha[strcspn(linha, "\n")] = '\0';
        
        if (eh_palindromo_iterativo(linha)) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    
    return 0;
}