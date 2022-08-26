#include "CuboMagico.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
CuboMagico::CuboMagico(){
}
CuboMagico::CuboMagico( int **_cuadrado){
	cuadrado=_cuadrado;
}
void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
	cuadrado=_cuadrado;
}
int **CuboMagico::getCuboMagicoCuadrado(){
	return cuadrado;
}
void CuboMagico::llenar(int a, int b, int ct, int pt){
	int x=0,t=0,s=0,d=0,k=0,j=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	d=x;
	for(int g=0;g<((a+1)/2);g++){
		j=g;
		k=g;
		for(int i=x;i>=j;i--){
			*(*(cuadrado+i)+k)=ct;
			if(k<(d-s)){
				*(*(cuadrado+i)+(k+t))=ct;
			}
			if(k>(d+s)){
				*(*(cuadrado+i)+(k-t))=ct;
			}
			if(i>(d+s)){
				*(*(cuadrado+(i-t))+k)=ct;
			}
			if(i<(d-s)){
				*(*(cuadrado+(i+t))+k)=ct;
			}
			k++;
			ct+=pt;
		}
		x++;
	}
	
}
void CuboMagico::mostrar(int a, int b){
	//system("cls");
	int c=a-2;
	cout << "Orden cuadrado magico: " << c << "\n\n";
	int x=0,t=0,s=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	for(int g=0;g<a;g++){
		printf("\n\t");
		for(int h=0;h<b;h++){	
			if(h>=(x-s)&&h<=(x+s)&&g<=(x+s)&&g>=(x-s)){
				printf("\t%d",*(*(cuadrado+g)+h));	
			}
		}
	}
}
