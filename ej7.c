/*Ejercicio 7: Dada una lista A de M caracteres alfanuméricos todos distintos y un carácter X ingresado
por teclado, se solicita informar si dicho carácter se encuentra en la lista A ingresada y en cual
posición. Considerar los siguientes casos
a) La lista A no está ordenada.
b) Ordenar la lista A, previamente a determinar la posición de los elementos.*/
#include <stdio.h>
#define max 20
typedef char t_lista[max];
void ingreso(t_lista,int*);
int buscar(t_lista,int,char);
void informar(t_lista,int);
void ordenar(t_lista,int);
void mostrar(t_lista,int);
int main() {
	t_lista A;
	int n;
	ingreso(A,&n);
	informar(A,n);
	ordenar(A,n);
	mostrar(A,n);
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
		fflush(stdin);
		printf("\nIngresar el caracter: ");
		scanf("%c",&A[i]);
	}
}
int buscar(t_lista A,int n, char c){
	int pos,i=1;
	while(i<=n && A[i]!=c) i++;
	if(i<=n) pos=i;
	else pos=0;
	return pos;
}
void informar(t_lista A,int n){
	char c;
	int pos;
	fflush(stdin);
	printf("\nIngresar el caracter a buscar: ");
	scanf("%c",&c);
	pos=buscar(A,n,c);
	if(pos!=0)printf("\nLa posición del elemento es: %d",pos);
	else printf("\nNo se encontro el elemento.");
}
void mostrar(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento %d de la lista es: %c",i,A[i]);
}
void ordenar(t_lista A,int n){
	int i,j;
	char aux;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
			if(A[i]>A[j]){
				aux=A[j];
				A[j]=A[i];
				A[i]=aux;
			}
	
}
