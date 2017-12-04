#include "lib/busca_util.h"

int main(int argc, char *argv[])
{
    FILE* file; 
    int initialPosition, stackSize, item, i;

    char* arquivo = "conf.txt";

    if(argv[1]!=NULL){
        arquivo = argv[1];
    }

    file = fopen(arquivo, "r");

    if (file == NULL) 
    {
        printf("Error, invalid file\n");
        return -1;
    }

    fscanf(file, "%i", &initialPosition);
    fscanf(file, "%i", &stackSize);
    int stack[stackSize];

    for (i = 0; i < stackSize; i++) 
    {
        fscanf(file, "%i", &item);
        stack[i] = item;
    }

    fclose(file);

    printf("Initial position: %i\n", initialPosition);
    printf("Number of itens: %i\n", stackSize);
    printf("Requests order: ");
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
    printf("\n");

    fcfs(initialPosition, stackSize, stack);
    sstf(initialPosition, stackSize, stack);
    scanDesce(initialPosition, stackSize, stack);
    scanSobe(initialPosition, stackSize, stack);


    return 0;
}