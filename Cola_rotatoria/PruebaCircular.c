#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"circular.h"

int main(){
    Circular a = nuevaC();
    a = formarC(formarC(formarC(a,1),2),3);
    ImpElem(primeroC(a));

    a = rotacionC(a);
    ImpElem(primeroC(a));

    a = desformarC(a);
    ImpElem(primeroC(a));

    return 0;
}
