
#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

int SonIguales(Lista, Lista);


int main(){
    Lista a=cons(1,cons(2,cons(3,cons(4,cons(3,cons(2,cons(3,vacia())))))));
    Lista b=cons(1,cons(2,cons(3,cons(4,cons(3,cons(2,cons(1,vacia())))))));

    SonIguales(a,b)?puts("Si son iguales."): puts("No son iguales.");

    return 0;
}

int SonIguales(Lista a, Lista b){
    int aux = 0, bandera = 0;
    bandera = NumElems(a);
    if(NumElems(a) == NumElems(b)){
        while (!esvacia(a))
        {
            if(cabeza(a)==cabeza(b))
                aux++;
            else 
                break;

            a = resto(a);
            b = resto(b);
        }
    }
    if(aux == bandera)
        return 1;
    else
        return 0;
}