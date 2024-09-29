/*Ejercicio 4: Se tiene una lista de las edades de N alumnos de una escuela, se solicita ingresar la lista
y a continuación, mediante un menú:
a) Determinar la edad con mayor cantidad de repeticiones, sabiendo que existe y es única.
b) Mostrar la primera sublista creciente, de al menos dos números, conformada sólo por elementos
pares. */
#include <stdio.h>
#define max 20
typedef int t_lista[max];

void ingreso(t_lista, int*);
int menu(void);
void may_rep(t_lista,int);
int contar(t_lista,int,int);
void mostrar(t_lista,int);
void sublista_par(t_lista,int);
void ordenar(t_lista,int);

int main() {
	t_lista A;
	int n,opc;
	ingreso(A,&n);
	do{
		opc=menu();
		switch(opc){
			case 1 : may_rep(A,n); break;
			case 2 : sublista_par(A,n); break;
			case 0 : printf("\nSaliste del programa.\n");
		}
	}while(opc!=0);
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
		printf("\nIngresar la edad del alumno %d: ",i);
		scanf("%d",&A[i]);
	}
}
int menu(void){
	int opc;
	printf("\nIngresar 1 para determinar la edad con mayor numero de repeticiones. ");
	printf("\nIngresar 2 para mostrar la primera sublista seguida de pares crecientes. ");
	printf("\nIngresar 0 para salir. ");
	scanf("%d",&opc);
	return opc;
}
void may_rep(t_lista A,int n){
	int i,cont,aux,contmax;
	contmax=0;
	for(i=1;i<=n;i++){
		cont=contar(A,n,A[i]);
		if(contmax<cont){
			contmax=cont;
			aux=A[i];
		}
	}
	printf("\nLa edad que se repite una cantidad maxima de %d veces es: %d",contmax,aux);
}
int contar(t_lista A,int n ,int compara){
	int i,cont;
	cont=0;
	for(i=1;i<=n;i++)
		if(A[i]==compara) cont++; 
	return cont;
}
void sublista_par(t_lista A,int n){
	t_lista sublista;
	int i,j;
	j=0;
	for(i=1;i<=n;i++){
		if(A[i]%2==0){
			j++;
			sublista[j]=A[i];
			}
	}
	
	if(j>=2){ 
	ordenar(sublista,j);
	mostrar(sublista,j);
	}
	else printf("\nNo hay mas de 2 elementos pares en la lista. \n");
}
void mostrar(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento %d de la sublista es: %d",i,A[i]);
}
void ordenar(t_lista x, int n){
	int i,j,aux;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
			if(x[i]>x[j]){
				aux=x[j];
				x[j]=x[i];
				x[i]=aux;
			}
}
