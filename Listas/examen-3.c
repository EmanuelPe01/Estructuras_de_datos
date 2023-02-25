#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

int Ocurrencias(Lista, int);

int main(){
    Lista a=cons(3,cons(5,cons(4,cons(5,cons(6,cons(5,vacia()))))));

    printf("%d",Ocurrencias(a,5));

    return 0;
}

int Ocurrencias(Lista a, int b){
    int aux = 0;
    while (!esvacia(a))
    {
        if(cabeza(a) == b)
            aux++;

        a = resto(a);
    }
    return aux;
}