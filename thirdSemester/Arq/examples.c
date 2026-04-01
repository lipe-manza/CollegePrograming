#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    ===== GDB (debug) =====
    compilar com: gcc -g programa.c

    r          -> run (executa até crash ou fim)
    bt         -> backtrace (pilha de chamadas)
    n          -> next (próxima linha, sem entrar em função)
    s          -> step (entra na função)
    p var      -> print variável
    */

    /*
    ===== Arquivos em C =====
    fopen(path, mode) -> abre arquivo e retorna FILE*
    fclose(fp)        -> fecha arquivo

    fread(buffer, size, count, fp)
    fwrite(buffer, size, count, fp)

    ftell(fp)         -> posição atual no arquivo
    fseek(fp, offset, origin)

    origin:
        SEEK_SET -> início (0)
        SEEK_CUR -> posição atual (1)
        SEEK_END -> final (2)

    strsep() do GNU;
        */

    return 0;
}
