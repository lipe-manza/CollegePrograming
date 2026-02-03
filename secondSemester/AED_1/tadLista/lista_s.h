#ifndef LISTA_H
#define LISTA_H

#include "item.h"

typedef struct lista LISTA;

LISTA* lista_criar(bool ordenado);
bool lista_apagar(LISTA** lista);
void lista_cheia(LISTA** lista);
void lista_vazia(LISTA** lista);
bool lista_inserir(LISTA* lista, ITEM* item);
bool lista_inserir_posicao(LISTA* lista, int posicao, ITEM* item);
bool lista_inserir_fim(LISTA* lista, ITEM* item);
int lista_busca_sequencial(LISTA* lista, int conteudo);
int lista_busca_ordenada(LISTA* lista, int conteudo);
int lista_busca_binaria(LISTA* lista, int conteudo);
ITEM* lista_remover(LISTA* lista, int chave);


#endif