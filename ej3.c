/*Ejercicio 3: Se tiene una lista de caracteres que representa una frase conformada con consonantes,
vocales en minúsculas y dígitos, el ingreso de la lista se finalizará al ingresar el carácter “/”. Se solicita
ingresar un carácter y buscarlo en la lista ingresada informando la primera posición donde se encuentra,
borrar de la lista los dígitos presentes y para finalizar ordenar la lista ascendentemente y mostrar la lista
resultante.*/
#include <stdio.h>
#include <ctype.h>
#define max 20

typedef char t_lista[20];

void ingreso(t_lista,int*);
int buscar(t_lista,int,char);
void busqueda_ingreso_muestra(t_lista,int);
void borrar_digitos(t_lista,int*);
void borrar(t_lista,int*,int);
void ordenar(t_lista,int);
void mostrar(t_lista,int);

int main(){
	t_lista C;
	int n;
	ingreso(C,&n);
	busqueda_ingreso_muestra(C,n);
	borrar_digitos(C,&n);
	ordenar(C,n);
	mostrar(C,n);
	return 0;
}
void ingreso(t_lista C,int *n){
	int i=1;
	printf("\nPor favor ingresar un elemento de la lista: ");
	scanf("%c",&C[i]);
	while(C[i]!='/'){
		i++;
		fflush(stdin);
		printf("\nPor favor ingresar un elemento de la lista: ");
		scanf("%c",&C[i]);
	}
	*n=i-1;
}
int buscar(t_lista C,int n,char x){
	int i=1,b=0;
	while(i<=n && C[i]!=x)
		i++;
	if(i<n) b=i;
	return b;
}
void busqueda_ingreso_muestra(t_lista C,int n){
	char x;
	int busq;
	fflush(stdin);
	printf("\nPor favor ingresar el caracter a buscar: ");
	scanf("%c",&x);
	busq=buscar(C,n,x);
	if(busq!=0)printf("\nLa posición de %c es %d.",x,busq);
	else printf("\nNo se encontro %c en la lista.",x);
}
void borrar_digitos(t_lista C,int *n){
	int i=1;
	while(i<=*n){
		if(isdigit(C[i])) borrar(C,n,i);
		else i++;
	}
}
void borrar(t_lista C,int *n,int pos){
	int i;
	for(i=pos;i<*n;i++)
		C[i]=C[i+1];
	*n=*n-1;
}
void ordenar(t_lista C,int n){
	int i,j;
	char aux;
	for(i=1;i<=(n-1);i++)
		for(j=i+1;j<=n;j++)
			if(C[i]>C[j]){ 
				aux=C[j];
				C[j]=C[i];
				C[i]=aux;
			}
}
void mostrar(t_lista C,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nEl elemento de la lista de la posicion %d es: %c",i,C[i]);
}
