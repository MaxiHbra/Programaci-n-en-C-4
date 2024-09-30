/*Ejercicio 8: Dada una lista A de N números enteros, que puede contener números repetidos, calcular
el promedio de los números que se encuentran en posiciones impares del arreglo y crear otra lista B
conteniendo los elementos de A que sean mayores al promedio calculado. Mostrar ambas listas. */
#include <stdio.h>
#define max 20
typedef int t_lista[max];
void ingreso(t_lista,int*);
void promedio(t_lista,int,int*);
void mostrar(t_lista,int);
void listaB(t_lista,int,int,int*,t_lista);
int main(){
	t_lista A,B;
	int n,n2,prom;
	ingreso(A,&n);
	promedio(A,n,&prom);
	listaB(A,n,prom,&n2,B);
	mostrar(B,n2);
	return 0;
}
void ingreso(t_lista A,int *n){
	int i;
	do{
		printf("\nPor favor ingresar N: ");
		scanf("%d",n);
		if(*n>max)
			printf("\nEl tamaño supera el maximo que permite la lista. Ingresar de nuevo.");
	}while(*n>max);
	for(i=1;i<=*n;i++){
		printf("\nIngresar el caracter: ");
		scanf("%d",&A[i]);
	}
}
void promedio(t_lista A, int n,int *prom){
	int i=1;
	*prom=0;
	while(i<=n) {
		*prom=*prom+A[i];
		i=i+2;
	}
	*prom=*prom/((n/2)+1);
}
void mostrar(t_lista x,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento %d de la lista es: %d",i,x[i]);
}
void listaB(t_lista A,int n,int prom,int *n2,t_lista B){
	int i,j;
	*n2=0;
	j=0;
	for(i=1;i<=n;i++){
		if(A[i]>=prom){
			j++;
			(*n2)=(*n2)+1;
			B[j]=A[i];
		}
	}
}
