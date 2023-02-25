#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Elem.h"
#include "Cola.h"


int pares(Cola);

int main(){
    srand(time(NULL));
    Cola c = nueva();
    for(int i = 0; i<10; i++)
        c = formar(c,(rand()%50+1));

    printf("Habia: %d numeros pares en la cola.", pares(c));

    return 0;
}

int pares(Cola c){
    int aux = 0;
    while (!esnueva(c))
    {
        if(primero(c)%2 == 0)
            aux++;

        c = desformar(c);
    }
    return aux;
}