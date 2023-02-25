#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

Lista tabla(int, int);


int main(){
    int a = 0 , b = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    ImpElems(InvierteLista(tabla(a,b)));

    return 0;
}

Lista tabla(int a, int b){
    Lista aux = vacia();
    if(b==0)
        return 0;
    else 
        return aux = cons((a*b),tabla(a,b-1));
}