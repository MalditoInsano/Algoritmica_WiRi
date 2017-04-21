#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[]){
	if(argc != 1){
		fprintf(stderr, "\x1b[31m error, ejecutar como ./prog \n \x1b[0m");
		exit(EXIT_FAILURE);
	}
	int s,n,d,i,j,k;
	while(scanf("%d%d",&s, &n), 2){
		if(s == 0){
			exit(EXIT_FAILURE);
		}
		//s tamaño numero
		//n numero a dibujar
		while(n != 0){
			
		}
		for(i = 0;i < (2*s + 3);++i){
			for (j = 0; j < (s+2); ++j){
				
			}
		}
	}
}
