#include "lib/busca_util.h"

void fcfs(int initialPosition, int stackSize, int stack[])
{
    printf("=== FCFS algorithm ===\n");
    int currentPosition = initialPosition;
    int total = 0;
    int i;
    printf("Ordem: %i, ", initialPosition);
    for (i = 0; i < stackSize; i++)
    {
        total += abs(stack[i] - currentPosition);
        currentPosition = stack[i];
        if (i == stackSize -1)
        {
            printf("%i ", currentPosition);
        }
        else
        {
            printf("%i, ", currentPosition);
        }
        
    }
    printf("\nCilindros: %i\n", total);
}

void sstf(int currentPosition, int stackSize, int stack[])
{
    printf("=== SSTF algorithm ===\n");
    int i, j, aux;
    int smallerDiff = MAX;
    int total = 0;
    printf("Ordem: %i, ", currentPosition);
    for (i = 0; i < stackSize; i++)
    {
        for (j = i; j < stackSize; j++)
        {
            if (abs(stack[j] - currentPosition) < smallerDiff)
            {
                smallerDiff = abs(stack[j] - currentPosition);
                aux = stack[j];
                stack[j] = stack[i];
                stack[i] = aux;
            }
        }
        total += (abs(currentPosition - stack[i]));
        currentPosition = stack[i];
        smallerDiff = MAX;
    }

    for (i = 0; i < stackSize; i++)
    {
        if (i == stackSize -1)
        {
            printf("%i ", stack[i]);
        }
        else
        {
            printf("%i, ", stack[i]);
        }
    }
    printf("\nCilindros: %i\n", total);
}

void scanDesce(int currentPosition, int stackSize, int stack[])
{
    printf("=== Scan- algorithm ===\n");
    int i, j, aux;
    int greatestDiff = -1;
    int total = 0;
    int goingToBottom = 1;
    printf("Ordem: %i, ", currentPosition);

    int smaller = findSmaller(stackSize, stack);
    int greatest = findGreatest(stackSize, stack);

    for (i = 0; i < stackSize; i++)
    {
        for (j = i; j < stackSize; j++)
        {
            if (goingToBottom == 1)
            {
                if (stack[j] == smaller)
                {
                    goingToBottom = 0;
                }
                if (stack[j] < currentPosition)
                {
                    aux = stack[j];
                    stack[j] = stack[i];
                    stack[i] = aux;
                    break;
                }
            }
            else
            {
                if (greatest - stack[j] > greatestDiff)
                {
                    greatestDiff = greatest - stack[j];
                    aux = stack[j];
                    stack[j] = stack[i];
                    stack[i] = aux;
                }
            }
            
        }
        total += (abs(currentPosition - stack[i]));
        currentPosition = stack[i];
        greatestDiff = -1;
    }

    for (i = 0; i < stackSize; i++)
    {
        if (i == stackSize -1)
        {
            printf("%i ", stack[i]);
        }
        else
        {
            printf("%i, ", stack[i]);
        }
    }
    printf("\nCilindros: %i\n", total);
}

void scanSobe(int currentPosition, int stackSize, int stack[])
{
    printf("=== Scan+ algorithm ===\n");
    int i, j, aux;
    int greatestDiff = -1;
    int total = 0;
    int goingToTop = 1;
    printf("Ordem: %i, ", currentPosition);

    int smaller = findSmaller(stackSize, stack);
    int greatest = findGreatest(stackSize, stack);

    for (i = 0; i < stackSize; i++)
    {
        for (j = i; j < stackSize; j++)
        {
            if (goingToTop == 1)
            {
                if (stack[j] > currentPosition && abs(greatest - stack[j]) > greatestDiff)
                {
                    greatestDiff = greatest - stack[j];
                    aux = stack[j];
                    stack[j] = stack[i];
                    stack[i] = aux;
                }
            }
            else
            {
                if (stack[j] > greatestDiff)
                {
                    greatestDiff = stack[j];
                    aux = stack[j];
                    stack[j] = stack[i];
                    stack[i] = aux;
                }
            }
        }
        if (stack[i] == greatest)
        {
            goingToTop = 0;
        }

        total += (abs(currentPosition - stack[i]));
        currentPosition = stack[i];
        greatestDiff = -1;
    }

    for (i = 0; i < stackSize; i++)
    {
        if (i == stackSize -1)
        {
            printf("%i ", stack[i]);
        }
        else
        {
            printf("%i, ", stack[i]);
        }
    }
    printf("\nCilindros: %i\n", total);
}

int findSmaller(int stackSize, int stack[])
{
    int smaller = MAX;
    int i;

    for (i = 0; i < stackSize; i++)
    {
        if (stack[i] < smaller)
        {
            smaller = stack[i];
        }
    }
    return smaller;
}

int findGreatest(int stackSize, int stack[])
{
    int greatest = 0;
    int i;

    for (i = 0; i < stackSize; i++)
    {
        if (stack[i] > greatest)
        {
            greatest = stack[i];
        }
    }
    return greatest;
}

int abs(int number)
{
    if (number < 0)
    {
        return -number;
    }
    return number;
}