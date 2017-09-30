#include "matriz_util.h"


int main(int argc, char const *argv[])
{

	imprime_matriz(alocar_matriz(atoi(argv[1]),atoi(argv[1])));
	return 0;
}