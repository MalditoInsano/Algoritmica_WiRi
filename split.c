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
  int s,n,largo; 
  char m[8]; 
  while(scanf("%d %d", &s, &n), 2 ){ 
  	sprintf(m , "%d",n);
  	printf("%s\n", m);
    largo=strlen(m);  
    printf("Número recibido: %i\n",n); 
    int *matrizP=splitTotal(n, largo); 
    
  }
}