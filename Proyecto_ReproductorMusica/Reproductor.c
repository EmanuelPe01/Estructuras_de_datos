#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "Elem.h"
#include "circular.h"

Circular canciones(Circular);
Circular info(Circular);
void instrucciones ();
char* direccion(char* );
int r;

int main(){
	Circular a = nuevaC();
	srand(time(NULL));
	a = formarC(a,"1","Nadie te podra olvidar","Gera MX","Rap");
	a = formarC(a,"2","La ciudad","Siddartha","Pop");
	a = formarC(a,"3","A veces","Diamante electrico","Pop");
	a = formarC(a,"4","Waterguns","Caravan Palace","Electro swing");
	a = formarC(a,"5","Slim thugs","Aleman","Rap");
	a = formarC(a,"6","A lo mexicano","Gera MX","Rap");
	a = formarC(a,"7","Un vato como yo","Gera MX","Rap");
	a = formarC(a,"8","Afthermath","Carvan Palace","Electro Swing");
	a = formarC(a,"9","Plume","Carvan Palace","Electro Swing");
	a = formarC(a,"10","Oro","Diamante electrico","Pop");
	a = formarC(a,"11","Buscandote","Siddartha","Pop");
	a = formarC(a,"12","Pelicula","Siddartha","Pop");
	a = formarC(a,"13","Aves del tiempo","Siddartha","Pop");
	a = formarC(a,"14","Flamingo","Oliver Heldens","Deep house");
	a = formarC(a,"15","You & Me","Flume","Deep house");
	a = formarC(a,"16","Helena beat","Foster the people","Alternative");
	a = formarC(a,"17","Houldini","Foster the people","Alternative");
	a = formarC(a,"18","Imagination","Foster the people","Alternative");
	a = formarC(a,"19","Pick U Up","Foster the people","Alternative");
	a = formarC(a,"20","Pumpped of kicks","Foster the people","Alternative");

	
	info(rotacionC(a));
	
	
	return 0;
}

Circular info(Circular lista){
	char dir[6];
	int n = rand()%10-1;
	system("cls");
	instrucciones();
	printf("\n\nNo. de Pista: %s\n", lista->dato);
	printf("Nombre de la cancion: %s\n", lista->cancion);
	printf("Artista: %s\n", lista->cantante);
	printf("Genero: %s\n", lista->tipo);
		
	PlaySound(NULL,NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(direccion(lista->dato),NULL,SND_FILENAME | SND_ASYNC);
	printf("\nTeclee su opcion: ");
	scanf("%d", &r);
	
	if(r==1)
		return info(rotacionC(lista));
	if(r==2){
		for(int i = 0; i<n; i++)
			lista = rotacionC(lista);
		
		return info(lista);
	}

}

char* direccion(char* dato){
	int i = atoi(dato), l=0;
	char* ruta;
	char dir[100];

	if(i<10){
		strcpy(dir,"0");
		strcat(dir,dato);
		strcat(dir,".wav");
	}else{
		strcpy(dir,dato);
		strcat(dir,".wav");
	}

	l = strlen(dir);
	ruta = (char *) malloc (sizeof(char) * l);
	strcpy(ruta,dir);

	return ruta;
}

void instrucciones(){
	printf("\nSiguiente pista (presione 1)\nCancion aleatoria (precione 2)\nTerminar (presione 0)");
}