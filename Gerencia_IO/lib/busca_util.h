#ifndef BUSCA_UTIL_INCLUDED
#define BUSCA_UTIL_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 99999999

void fcfs(int initialPosition, int stackSize, int stack[]);
void sstf(int currentPosition, int stackSize, int stack[]);
void scanDesce(int currentPosition, int stackSize, int stack[]);
void scanSobe(int currentPosition, int stackSize, int stack[]);
int findSmaller(int stackSize, int stack[]);
int findGreatest(int stackSize, int stack[]);
int abs(int number);

#endif