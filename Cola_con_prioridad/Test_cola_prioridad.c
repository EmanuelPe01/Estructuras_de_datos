
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Cola_prioridad.h"

int main(){

    Cola new = nueva();
    Cola otra = nueva();
    char r; 
    int a1 = 0,a2 = 0,aux_=0;
    do{
        printf("Digite un elemento: ");
        scanf("%d", &a1);
        printf("Digite digite el puesto del elemento: ");
        scanf("%d", &a2);
        new = formar(new,a1,a2);
        otra = formar(otra,a1,a2);
        printf("\nDesea agregar mas elementos? (s/n):");
        scanf("%s",&r);
    }while(r=='s');
    aux_ = numElems(otra);
    impElems(cola_prioridad(new, aux_));
    
    return 0;
}

