#include<stdio.h>
#include<stdlib.h>
#include "Elem2.h"
#include "ListaGen2.h"

int main(){

ListaGen lg1, lg2, lg3, lg4;

// Debes construir las listas lg2=[3,4,5], lg3=[8,9], lg4=[7,lg3,10], y lg1=[1,2,lg2,6,[7,lg3,10],11,12] usando las funciones del TDA ListaGen.

lg2=consElem(3,consElem(4,consElem(5,vaciag()))); // lg2=[3,4,5]
lg3=consElem(8,consElem(9,vaciag()));             // lg3=[8,9]
lg4=consElem(7,consLista(lg3,consElem(10,vaciag()))); // lg4=[7,lg3,10]
lg1=consElem(1,consElem(2,consLista(lg2,
            consElem(6,consLista(lg4,consElem(11,consElem(12,vaciag()))))))); //lg1=[1,2,lg2,6,[7,lg3,10],11,12]



esvaciag(lg1)?puts("\nsi\n"):puts("\nno\n");

//esvaciag(lg1)?puts("\nsi\n"):puts("\nno\n");
/*
EsAtomo(lg2)?puts("Si"):puts("No");
puts("\n---------");
EsAtomo(restog(lg4))?puts("Si"):puts("No");
puts("\n---------");
printf("\n%d\n",NumElemListaGen(lg2));
printf("\n%d\n",NumElemListaGen(lg3));
printf("\n%d\n",NumElemListaGen(lg4));
printf("\n%d\n",NumElemListaGen(lg1));
*/

puts("Los elementos de la lista lg1 son:");
//ImpListaGen(PegaListasG(lg2,PegaListasG(lg3,lg4)));
ImpListaGen(lg1);
puts("\n-------");
ImpListaGen(InvierteG(lg1));
return 0;

}
