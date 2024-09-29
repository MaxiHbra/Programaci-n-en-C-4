#include <stdio.h> 
#define max 20
typedef int vector[max];

void ingresar(vector,vector,vector,vector,int*);
void ingresar_nuevalis(vector,vector,vector,int*);
void ordenar(vector, vector, vector, vector, int);
int buscar(vector,int,int);
void actualizar(vector,vector,vector,vector,vector,vector,vector,int*,int);
void agregar(vector,vector,vector,vector,int*,int,int,int);
void muestra(vector,vector,vector,vector,int);

int main() {
	vector cod,prov,cant,precio;
	vector cod2,prov2,precio2;	
	int tam,tam2,control;
	ingresar(cod,prov,cant,precio,&tam);
	printf("\nPor favor ingresar 1 para añadir lista actualizada de proveedor: ");scanf("%d",&control);
	if(control==1){
		ingresar_nuevalis(cod2,prov2,precio2,&tam2);
		actualizar(cod,prov,cant,precio,cod2,prov2,precio2,&tam,tam2);
		printf("\nLa lista principal ha sido modificada.");
	} else printf("\nNo se modifico la lista principal.");
	muestra(cod,prov,cant,precio,tam);
	return 0;

}
void ingresar(vector cod, vector prov, vector cant, vector precio, int *tam){
	int i;
	printf("\nPor favor ingresar el tamaño: ");
	scanf("%d",tam);
	if(*tam<=max){
		for(i=1;i<=*tam;i++){
			printf("\nIngresar el codigo del producto: ");
			scanf("%d",&cod[i]);
			printf("\nIngresar el codigo del proveedor: ");
			scanf("%d",&prov[i]);
			printf("\nIngresar la cantidad de este producto: ");
			scanf("%d",&cant[i]);
			printf("\nIngresar el precio del producto: ");
			scanf("%d",&precio[i]);
			printf("\nSe ha ingresado un producto \n");
			ordenar(cod,prov,cant,precio,i);
		}
	}
	else printf("\nEse numero supera el tamaño maximo permitido.");
}
void ingresar_nuevalis(vector cod,vector prov, vector precio,int *tam){
	int i;
	printf("\nPor favor ingresar el tamaño: ");
	scanf("%d",tam);
		for(i=1;i<=*tam;i++){
			printf("\nIngresar el codigo del producto: ");
			scanf("%d",&cod[i]);
			printf("\nIngresar el codigo del proveedor: ");
			scanf("%d",&prov[i]);
			printf("\nIngresar el precio del producto: ");
			scanf("%d",&precio[i]);
		}
}
void ordenar(vector cod, vector prov, vector cant, vector precio, int tam){
	int i,j;
	for(i=1;i<=tam;i++){
		cod[0]=cod[i];
		prov[0]=prov[i];
		cant[0]=cant[i];
		precio[0]=precio[i];
		j=i-1;
		while(cod[j]>cod[0]){
			cod[j+1]=cod[j];
			prov[j+1]=prov[j];
			cant[j+1]=cant[j];
			precio[j+1]=precio[j];
			j--;
		}
		cod[j+1]=cod[0];
		prov[j+1]=prov[0];
		cant[j+1]=cant[0];
		precio[j+1]=precio[0];
	}
}
void muestra(vector cod,vector prov,vector cant,vector precio ,int tam){
	int i;
	for(i=1;i<=tam;i++){
		printf("\n-----------------------------------------\n");
		printf("\nCODIGO DE PRODUCTO: %d",cod[i]);
		printf("\nCODIGO DE PROVEEDOR: %d",prov[i]);
		printf("\nCANTIDAD DE ESTE PRODUCTO: %d",cant[i]);
		printf("\nPRECIO: %d",precio[i]);
		printf("\n-----------------------------------------\n");
	}
}
/*int buscar(vector cod,int tam, int codBuscar){
	int ini,fin,med;
	ini=1;fin=tam;
	med=(ini+fin)/2;
	while(ini<fin && cod[med]!=codBuscar){
		if(cod[med]>codBuscar)
			fin=med;
		else ini=med+1;
	med=(ini+fin)/2;
	}
	if(ini>=fin)
	med=-1;
	return med;
}*/
void actualizar(vector cod,vector prov, vector cant,vector precio,vector cod2,vector prov2, vector precio2,int *tam, int tam2){
	int b,cont1,cont2,i,j;
	cont1=0;
	cont2=0;
	j=1;
	while(j<=tam2){
		b=0;
		i=1;
		while(i<=*tam){
			if(cod[i]==cod2[j]){
				prov[i]=prov2[j];
				precio[i]=precio2[j];
				cont1++;
				b=1;
		}
		i++;
		}
		if(b==0){
			if(*tam+1 <= max){
				
				agregar(cod,prov,cant,precio,tam,cod2[j],prov2[j],precio2[j]);
				cont2++;
			}
			else printf("\nEl tamaño maximo no permite agregar mas productos");
		}
		j++;
		}
	printf("\nEn la lista original %d productos se han actualizado y %d productos han sido agregados.",cont1,cont2);
}
void agregar(vector cod,vector prov,vector cant, vector precio,int *tam,int cod2,int prov2,int precio2){
	int p;
	*tam=*tam+1;
	p=*tam;
	while(cod[p-1]>=cod2 && p>0){
		cod[p+1]=cod[p];
		prov[p+1]=prov[p];
		precio[p+1]=precio[p];
		p--;
	}
	cod[p]=cod2;
	prov[p]=prov2;
	precio[p]=precio2;
	cant[p]=0;
}
