#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

Lista diferencia(Lista, Lista);

int main(){
    Lista a = cons(4,cons(3,cons(6,cons(2,vacia()))));
    Lista b = cons(2,cons(4,cons(3,cons(8,cons(6,cons(6,cons(8,cons(9,vacia()))))))));

    ImpElems(diferencia(a,b));

    return 0;
}

Lista diferencia(Lista s, Lista l){
    int i=0, aux = NumElems(s), bandera = 0;
    int arr[aux];
    Lista r = vacia();
    

    while (!esvacia(s))
    {
        arr[i] = cabeza(s);
        s = resto(s);
        i++;
    }

    while (!esvacia(l))
    {
        bandera = 0;
        for(i = 0; i<aux; i++){
            if(cabeza(l)==arr[i])
                bandera++;
        }
        if(bandera == 0)
            r = cons(cabeza(l),r);
        
        l = resto(l);
    }
    return r;
}