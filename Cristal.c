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
 
    //imprimir 
    for (int i = 0; i < (2*s)+3; ++i) // en este for se imprime cada linea 
    {
		if (i == 0){   /// linea superior 
			for (int k = 0; k < largo; ++k)
			{ 
				printf(" ");
				for (int x = 0; x < s; ++x)
				{

				}
			} 
		} 
		else if (i > 0 && i < (s + 1)){  // lineas intermedias 1 

		} 
		else if (i == (s + 1)){  // linea central  

		} 
		else if (i > (s + 1) && i < (2*s + 2)){  // lineas intermedias 2 

		} 
		else if (i == (2*s +2)){   // linea inferior 

		} 
    } 
 
  } 
  return 0; 
}