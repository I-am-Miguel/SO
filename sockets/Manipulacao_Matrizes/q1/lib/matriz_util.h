#ifndef MATRIZ_UTIL_INCLUDED
#define MATRIZ_UTIL_INCLUDED

#include <stdio.h>
#include <stdlib.h>


struct tipo_Matriz
{
	int qtd_linhas;
    int qtd_colunas;
    int dados[3][3];
};
 
typedef tipo_Matriz* Matriz;

void imprime_matriz(Matriz);

Matriz inicializa_matriz(Matriz);

Matriz alocar_matriz (int i,int j);

#endif