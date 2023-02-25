#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Elem.h"
#include "Cola.h"

Elem dado(Cola);

int main(){

    Cola q = nueva();
    srand(time (NULL));
    q=formar(formar(formar(formar(formar(formar(q,1),2),3),4),5),6);
    while(1){
            printf("Tirada: %d \n", dado(q));
            getchar();
    }

    return 0;
}

Elem dado(Cola q){
    int i = 1;
    for(i=1; i<=(rand()%6); i++)
           q=formar(desformar(q), primero(q));
    return primero(q);
}

