#ifndef MATRIZ_UTIL_INCLUDED
#define MATRIZ_UTIL_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int **matrizA;
int **matrizB;
int **matrizResultante;

int linhas;
int colunas;


void imprime_matriz(int **matriz);

void inicializa_matriz(int **matriz);

void alocar_matriz (int **matriz,int i,int j);

#endif