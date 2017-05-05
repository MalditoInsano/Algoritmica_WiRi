#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	/*3 condiciones
		x-y = 0;
		x-y > n;
		x-y ya calculado;
	*/

	int ndatos[5]={4,1,4,-2,3};
	int ndato[6]={5,1,4,2,-1,6};
	/*Estos arreglos son de prueba, aún no tiene entrada.
	  le iba cambiando el nombre según usaba uno u otro
	  falta implementar las condiciones
	  Sólo comprueba la segunda condiciones, 
	  faltan las otras 2*/

	int rest;
	int largo = ndatos[0];
	int cond =1;
	int pos=1;
	int *toFill;
	int x = -4,y,z;
	printf("largo: %i\n", largo);
	while(cond && (pos < largo)){
		y= ndatos[pos];
		z=ndatos[pos+1];
		rest = valorAbsoluto(y-z);
		if(rest>=largo){
			cond=0;
			printf("Not Jolly\n");
		}
		pos++;
	}
	if(cond){
		printf("Jolly\n");
	}

	return 0;
}