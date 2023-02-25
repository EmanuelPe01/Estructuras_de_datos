#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Cola.h"


int main(){
    Cola q = nueva();
    esnueva(q)?puts("Es nueva"):puts("No es nueva");

    q = formar(formar(q,5),4);

    esnueva(q)?puts("Es nueva"):puts("No es nueva");
    ImpElem(primero(q));

    q=desformar(q);
    ImpElem(primero(q));
    return 0;
}
