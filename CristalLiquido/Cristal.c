#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(int argc, char const *argv[]) 
{ 
  char moldes[10][7] = {{1,1,1,0,1,1,1},
					    {0,0,1,0,0,1,0},
				  	    {1,0,1,1,1,0,1},
				  	    {1,0,1,1,0,1,1},
				  	    {0,1,1,1,0,1,0},
				 	    {1,1,0,1,0,1,1},
				 	    {1,1,0,1,1,1,1},
				 	    {1,0,1,0,0,1,0},
				 	    {1,1,1,1,1,1,1},
					    {1,1,1,1,0,1,1}};	

  int s, n, largo, aux;
  int numero[7];

  while (scanf("%i %i",&s,&n)== 2){

    if (s == 0 && n == 0){ 
      break; 
    } 
    largo = 0;

    // separar numero y calcular largo
    aux = n;
    while (aux != 0){
		numero[7-largo] = (aux%10);
		aux = aux/10;
		largo++;
	}

    //imprimir 
    for (int i = 0; i < (2*s)+3; ++i) // en este for se imprime cada linea 
    {
		if (i == 0){   /// linea superior 
			for (int k = (8 - largo); k < 8; ++k)
			{

				if (moldes[numero[k]][0]){      /// moldes[numero][posicion]
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf("-");
					}
					printf(" ");
				}
				else{
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf(" ");
					}
					printf(" ");
				}
			}
			printf("\n");
		} 
		else if (i > 0 && i < (s + 1)){  // lineas intermedias 1 
			for (int k = (8 - largo); k < 8; ++k)
			{
				if (moldes[numero[k]][1]){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (moldes[numero[k]][2]){
					printf("|");
				}
				else{
					printf(" ");
				}
			} 
			printf("\n");
		} 
		else if (i == (s + 1)){  // linea central  
			for (int k = (8 - largo); k < 8; ++k)
			{
				if (moldes[numero[k]][3]){
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf("-");
					}
					printf(" ");
				}
				else{
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf(" ");
					}
					printf(" ");
				}
			} 
			printf("\n");
		} 
		else if (i > (s + 1) && i < (2*s + 2)){  // lineas intermedias 2 
			for (int k = (8 - largo); k < 8; ++k)
			{
				if (moldes[numero[k]][4]){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (moldes[numero[k]][5]){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		} 
		else if (i == (2*s +2)){   // linea inferior 
			for (int k = (8 - largo); k < 8; ++k)
			{
				if (moldes[numero[k]][6]){
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf("-");
					}
					printf(" ");
				}
				else{
					printf(" ");
					for (int m = 0; m < s; ++m){
						printf(" ");
					}
					printf(" ");
				}
			} 
			printf("\n");
		} 
    } 
 	printf("\n");
 	
  } 
  return 0;
}	