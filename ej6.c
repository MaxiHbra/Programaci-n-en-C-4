/*Ejercicio 6: Dada una lista A de M caracteres alfanuméricos en minúsculas, se solicita ingresarla y
continuación, utilizando un menú de opciones, permitir:
a) Insertar un nuevo carácter en A, en la posición P, la cual es ingresada por teclado.
b) Eliminar el elemento anterior al primer carácter de tipo vocal de la lista
c) Cambiar los caracteres que representan a las vocales (a, e, i, o, u), presentes en el arreglo A por
su equivalente en mayúsculas (A, E, I, O, U).
d) Mostrar el vector A. */
#include <stdio.h>
#define max 20
typedef char t_lista[max];

void ingreso(t_lista,int*);
void insertar(t_lista,int*);
void eliminar(t_lista,int*);
void cambiar_vocales(t_lista,int);
void mostrar(t_lista,int);
int menu(void);

int main() {
	int n,opc;
	t_lista A;
	ingreso(A,&n);
	do{
		opc=menu();
		switch(opc){
		case 1 : insertar(A,&n); break;
		case 2 :  eliminar(A,&n); break;
		case 3 : cambiar_vocales(A,n); break;
		case 4 : mostrar(A,n); break;
		default : printf("\nSaliste del progama."); break;
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
		fflush(stdin);
		printf("\nIngresar el caracter: ");
		scanf("%c",&A[i]);
	}
}
int menu(void){
	int opc;
	printf("\nIngrese 1 para ingresar un elemento en una posicion especifica.");
	printf("\nIngrese 2 para eliminar el elemento anterior al primer carácter de tipo vocal");
	printf("\nIngrese 3 para cambiar vocales minusculas por mayusculas");
	printf("\nIngrese 4 para mostrar la lista.");
	printf("\nIngrese 0 para salir.");
	scanf("%d",&opc);
	return opc;
}
void insertar(t_lista A,int *n){
	int i,pos;
	char car;
	if((*n+1)<=max){
		*n=*n+1;
		printf("\nIngresar la posicion: ");
		scanf("%d",&pos);
		fflush(stdin);
		printf("\nIngresar el caracter: ");
		scanf("%c",&car);
		for(i=(*n-1);pos<=i;i--)
			A[i+1]=A[i];
		A[pos]=car;
	}
	else printf("\nYa no se puede agregar elementos a la lista, tamaño maximo alcanzado.\n");
}
void eliminar(t_lista A,int *n){
	int i=1,j;
	while(A[i]!='a' && A[i]!='e' && A[i]!='i' && A[i]!='o' && A[i]!='u' && A[i]!='A' && A[i]!='E' && A[i]!='I' && A[i]!='O' && A[i]!='U'&& i<=*n) i++;
	if(i<=*n){
		i=i-1;
		for(j=i;j<=*n-1;j++){
			A[j]=A[j+1];
		}
		*n=*n-1;
	}
	else printf("\nNo hay vocales en el arreglo.");
}

void cambiar_vocales(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		switch(A[i]){
		case 'a' : A[i]='A';break;
		case 'e' : A[i]='E';break;
		case 'i' : A[i]='I';break;
		case 'o' : A[i]='O';break;
		case 'u' : A[i]='U';break;
		default : break;
	}
}
void mostrar(t_lista A,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento %d de la lista es %c",i,A[i]);
}
