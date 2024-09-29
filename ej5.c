/*Ejercicio 5: Generar aleatoriamente una lista A de tamaño N, que simula notas de un examen parcial,
entre 0 y 100. A continuación, determinar la/las notas modales (las que más se repiten).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 20
typedef int t_lista[max];

void generar(t_lista,int*);
void determinar_repetidos(t_lista,int);
int contar(t_lista,int,int);
void mostrar(t_lista,int);
int main() {
	t_lista A;
	int n;
	srand(time(NULL));
	generar(A,&n);
	determinar_repetidos(A,n);
	mostrar(A,n);
	return 0;
}
void generar(t_lista a,int *n){
	int i;
	printf("\nIngresar la cantidad de notas: ");
	scanf("%d",n);
	for(i=1;i<=*n;i++){
		a[i]=(rand()%101)+1;
	}
}
void determinar_repetidos(t_lista a,int n){
	int i,cont,aux,contmax;
	contmax=0;
	for(i=1;i<=n;i++){
		cont=contar(a,n,a[i]);
		if(contmax<cont){
			contmax=cont;
			aux=a[i];
		}
	}
	if(cont!=1)
	printf("\nLa nota que se repite más veces es: %d",aux);
	else printf("\nNinguna nota se repite en la lista.");
}
int contar(t_lista A,int n,int compara){
	int i,cont;
	cont=0;
	for(i=1;i<=n;i++)
		if(A[i]==compara) cont++; 
	return cont;
}
void mostrar(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento %d de la lista es: %d",i,A[i]);
}
