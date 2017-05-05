#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
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
//innecesario 
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
	int largo, d;
	int jolly;
	int *serie;
	int *diferencias;
	int *base;
	while (scanf("%i",&largo), 1){

		if (largo == 0){
			break;
		}
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

		for (int a = 1; a < largo; ++a)
		{
			diferencias[a-1] = abs(serie[a] - serie[a-1]);
			base[a-1] = a;
		}

		d = 0;
		while(jolly && (d < largo - 1)){
			jolly = lol(base, largo, diferencias[d]);
			++d;
		}

		if (jolly){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}

		free(serie);
		free(diferencias);
		free(base);//XD	

	}

	return 0;
}