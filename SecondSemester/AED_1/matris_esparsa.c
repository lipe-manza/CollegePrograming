    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct matriz_esparsa MATRIZ_ESPARSA;

    typedef struct celula {
        int linha;
        int coluna;
        int valor;
        struct CELULA* direita;
        struct CELULA* baixo;
    }CELULA;

    struct matriz_esparsa {
        CELULA** linhas;
        CELULA** colunas;
        int nr_linhas;
        int nr_colunas;
    };

    MATRIZ_ESPARSA* criar_matriz(int nr_linhas, int nr_colunas) {
        MATRIZ_ESPARSA* mat = (MATRIZ_ESPARSA*)malloc(sizeof(MATRIZ_ESPARSA));
        if (mat != NULL) {
            mat->nr_linhas = nr_linhas;
            mat->nr_colunas = nr_colunas;
            mat->linhas = (CELULA**)malloc(sizeof(CELULA*) * nr_linhas);
            mat->colunas = (CELULA**)malloc(sizeof(CELULA*) * nr_colunas);

            if (mat->linhas != NULL && mat->colunas != NULL) {
                int i;
                for (i = 0; i < nr_linhas; i++)
                    mat->linhas[i] = NULL;
                for (i = 0; i < nr_colunas; i++)
                    mat->colunas[i] = NULL;
            }
            else {
                free(mat->linhas);
                free(mat->colunas);
                free(mat);
                mat = NULL;
            }
        }
        return mat;
    }




    int set(MATRIZ_ESPARSA* matriz, int lin, int col, int val) {
        CELULA* p, * q, * qa;

        if ((matriz == NULL) || (lin >= matriz->nr_linhas) || (col >= matriz->nr_colunas))
            return 0;

        p = (CELULA*)malloc(sizeof(CELULA));
        p->linha = lin;
        p->coluna = col;
        p->valor = val;

        // inserir na lista da coluna col
        q = matriz->colunas[col];
        qa = NULL;
        while (q != NULL) {
            if (q->linha < lin) {
                qa = q;
                q = q->baixo;
            }
            else {
                // achou linha maior
                if (qa == NULL)
                    matriz->colunas[col] = p;
                else
                    qa->baixo = p;
                p->baixo = q;
                break;
            }
        }

        // se chegou ao final da lista
        if (q == NULL) {
            if (qa == NULL)
                matriz->colunas[col] = p;
            else
                qa->baixo = p;
            p->baixo = NULL;
        }

        // algoritmo simétrico para as linhas
        q = matriz->linhas[lin];
        qa = NULL;
        while (q != NULL) {
            if (q->coluna < col) {
                qa = q;
                q = q->direita;
            }
            else {
                if (qa == NULL)
                    matriz->linhas[lin] = p;
                else
                    qa->direita = p;
                p->direita = q;
                break;
            }
        }

        if (q == NULL) {
            if (qa == NULL)
                matriz->linhas[lin] = p;
            else
                qa->direita = p;
            p->direita = NULL;
        }

        return 1;
    }

