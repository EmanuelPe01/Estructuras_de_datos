#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Listas.h"

Lista ElimOcurr(Lista);

int main(){
    Lista a = cons(2,cons(6,cons(4,cons(7,cons(9,cons(5,cons(2,cons(4,cons(3,vacia())))))))));

    ImpElems(ElimOcurr(a));

    return 0;
}

Lista ElimOcurr(Lista s){
    int i=0, aux = NumElems(s) ;
    int arr[aux];
    Lista r = vacia();
    

    while (!esvacia(s))
    {
        arr[i] = cabeza(s);
        s = resto(s);
        i++;
    }

    for(i = 0; i<aux; i++){
        for(int j = i; j<aux; j++)
        {
            if(i!=j)
                if(arr[i] == arr[j])
                    arr[j] = 0;
        }
    }
    for(i = 0; i<aux; i++)
        if(arr[i]>0)
            r = cons(arr[i],r);
    return r;
}
