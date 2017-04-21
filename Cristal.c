#include <stdio.h> 
#include <stdlib.h> 
 
 
int main(int argc, char const *argv[]) 
{ 
  int s, n; 
  while (scanf("%i %i\n",&s,&n)==2){ 
    if (s == 0 && n == 0){ 
      break; 
    } 
    // separar numero 
 	
 	int largo = 4;
    //imprimir 
    for (int i = 0; i < (2*s)+3; ++i) // en este for se imprime cada linea 
    {
		if (i == 0){   /// linea superior 
			for (int k = 0; k < largo; ++k)
			{
				if (1){
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
			for (int k = 0; k < largo; ++k)
			{
				if (1){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (1){
					printf("|");
				}
				else{
					printf(" ");
				}
			} 
			printf("\n");
		} 
		else if (i == (s + 1)){  // linea central  
			for (int k = 0; k < largo; ++k)
			{
				if (1){
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
			for (int k = 0; k < largo; ++k)
			{
				if (1){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (1){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		} 
		else if (i == (2*s +2)){   // linea inferior 
			for (int k = 0; k < largo; ++k)
			{
				if (1){
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