#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int* splitTotal(int n, int l){ 
  int *matriz; 
  int pos=1; 
  while(pos<=l){ 
    matriz[l-pos]= n%10;
    n=n/10; 
    pos++; 
  }
  return matriz; 
} 

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

  int s, n,largo;
  char m[8]; 
  while (scanf("%i %i\n",&s,&n), 2){ 
    if (s == 0 && n == 0){ 
      break; 
    } 
    // separar numero 
 	sprintf(m , "%d",n);
  	printf("%s\n", m);
    largo=strlen(m);  
    //imprimir 
    for (int i = 0; i < (2*s)+3; ++i) // en este for se imprime cada linea 
    {
		if (i == 0){   /// linea superior 
			for (int k = 0; k < largo; ++k)
			{

				if (molde[][0]){
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
				if (molde[atoi(m[k])][1]){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (molde[atoi(m[k])][2]){
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
				if (molde[atoi(m[k])][3]){
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
				if (molde[atoi(m[k])][4]){
					printf("|");
				}
				else{
					printf(" ");
				}
				for (int k = 0; k < s; ++k)
				{
					printf(" ");
				}
				if (molde[atoi(m[k])][5]){
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
				if (molde[atoi(m[k])][6]){
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