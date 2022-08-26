#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "CuboMagico.cpp"


int main(int argc, char** argv) {
	int **cuadrado, dim,num,ct,pt;
	do{
	printf("Ingrese la dimension ");
	scanf("%d",&dim);
	}while(dim%2==0);
	num=2*dim-1;
	cuadrado=(int**)calloc(num,sizeof(int*));
	printf("Ingrese valor centinela ");
	scanf("%d",&ct);
	printf("Ingrese patron de relleno ");
	scanf("%d",&pt);
	for(int i=0;i<num;i++){
		*(cuadrado+i)=(int *)calloc(num,sizeof(int));
	}
	CuboMagico cubo=CuboMagico(cuadrado);
	cubo.llenar(num,num,ct,pt);
	cubo.mostrar(num,num);
	system("pause");
	return 0;

}
