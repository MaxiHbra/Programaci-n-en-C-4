/*Ejercicio 2: Se tiene una lista de N números naturales sin repetidos, se desea; encontrar el menor de la
lista sabiendo que existe y es único, ordenar la lista de menor a mayor, insertar un nuevo elemento
manteniendo el orden y las características de la lista, para finalizar, mostrar los primos presentes en la
lista.*/
#include <stdio.h>
#define max 20

typedef int t_lista[max];
void ingreso(t_lista,int*);
int menor(t_lista,int);
void ordenar(t_lista, int);
void agregar(t_lista,int*);
int primo(int);
void mostrar(t_lista,int);

int main() {
	t_lista A;
	int n;
	ingreso(A,&n);
	printf("\nEl menor de la lista ingresada es: %d",menor(A,n));
	ordenar(A,n);
	agregar(A,&n);
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
		printf("\nIngresar un natural: ");
		scanf("%d",&A[i]);
	}
}
int menor(t_lista A,int n){
	int i,men;
	men=1000000;
	for(i=1;i<=n;i++){
		if(A[i]<men)
			men=A[i];
	}
	return men;
}
void ordenar(t_lista A, int n){
		int i,j,aux;
		for(i=1;i<=(n-1);i++)
			for(j=i+1;j<=n;j++)
			if(A[i]>A[j]){ 
			aux=A[j];
			A[j]=A[i];
			A[i]=aux;
		}
	}
void agregar(t_lista A,int *n){
	int i,x,b,tam;
	*n=*n+1;
	b=0;
	printf("\nPor favor ingresar el elemento que desea agregar a la lista: ");
	scanf("%d",&x);
	i=1;
	while(i<=(*n-1) && b==0){
		if(A[i]<x)
		i++;
		else b=1;
	}
	for(tam=*n-1;tam>=i;tam--)
		A[tam+1]=A[tam];
	A[i]=x;
}
int primo(int x){
	int pd=2,b;
	while(pd<= (x/2) && x%pd!=0) pd++;
	if(pd> x/2 && x!=1) b=1;
	else b=0;
	return b;
}
void mostrar(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		if(primo(A[i])) printf("\nEl elemento %d de la posicion %d de lista es primo.",A[i],i);
}
