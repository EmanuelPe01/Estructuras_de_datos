#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

Lista particion(int, Lista);

int main(){
    int n = 0;
    Lista a = cons(2,cons(6,cons(4,cons(7,cons(9,cons(5,cons(2,cons(4,cons(3,vacia())))))))));
    scanf("%d", &n);
    ImpElems(particion(n,a));

    return 0;
}

Lista particion(int a, Lista k){
    Lista b = vacia();
    while (!esvacia(k))
    {
        if(cabeza(k)<a)
            b = cons(cabeza(k),b);

        k = resto(k);
    }
    return b;
}