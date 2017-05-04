#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void imprimir(int *array, int largo){
	for (int i = 0; i < largo; ++i)
	{
		printf("%i ", array[i]);
	}
}

int isIn(int *array, int largo, int numero){
	int is = 0;
	int i = 0;
	while (!is && (i < largo)){
		if (numero == array[i]){
			is = 1;
			array[i] = 0;
		}
		++i;
	}
	return is;
}

int lol(int *array, int largo, int numero){
	int is = 0;
	int i = 0;
	if (numero > 0 && numero <= largo){
		while (!is && (i < largo)){
			if (numero == array[i]){
				is = 1;
				array[i] = 0;
			}
			++i;
		}
	}
	return is;
}

int valorAbsoluto(int n){
	if (n < 0){
		return (-n);
	}
	else{
		return n;
	}
}

int main(int argc, char const *argv[])
{
	int largo, s, d;
	int jolly;
	int *serie;
	int *diferencias;
	int *base;
	while (scanf("%i",&largo), 1){

		if (largo == 0){
			break;
		}

		// Se inicializan variables a utilizar. Se guarda cada valor del input en arreglo.
		else{
			serie = malloc(largo * sizeof(int));
			diferencias = malloc((largo-1) * sizeof(int));
			base = malloc((largo-1) * sizeof(int));
			jolly = 1;
			for (int a = 0; a < largo; ++a)
			{
				scanf("%d", &serie[a]);
			}
		}

		// Calcula todas las diferencias. Se guardan en arreglo.
		for (int a = 1; a < largo; ++a)
		{
			diferencias[a-1] = valorAbsoluto(serie[a] - serie[a-1]);
			base[a-1] = a;
		}

		d = 0;
		while(jolly && (d < largo - 1)){
			jolly = lol(base, largo, diferencias[d]);
			++d;
		}
		
		/*
		imprimir(serie, largo);
		printf(" - ");
		imprimir(diferencias, (largo-1));
		*/

		if (jolly){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}

	}

	free(serie);
	free(diferencias);
	free(base);

	return 0;
}