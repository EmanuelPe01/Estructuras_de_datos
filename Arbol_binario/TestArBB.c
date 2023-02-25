#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Elem.h"
#include "Listas.h"
#include "ArBin.h"
#include "ArBB.h"

Lista llena_lista(ArBB, Lista);
Lista elimina(Lista);

int main(){
    ArBB a=vacioB(), b = vacioB();
    Elem e;
    Lista c = vacia();
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        a = InsOrdB((rand()%15+1),a);
    }
    //c = cons(cabeza(llena_lista(a,c)),resto(llena_lista(a,c)));
    //InOrder(a);
    
    c = elimina(llena_lista(a,c));
    while (!esvacia(c))
    {
        b = InsOrdB(cabeza(c),b);
        c = resto(c);
        c = InvierteLista(c);
    }
    InOrder(b);
    
    return 0;
}

Lista llena_lista(ArBB b, Lista s){
    if(!esvacioB(b)){
        s = llena_lista(izquierdoB(b),s);
        s = cons(raiz(b), s);
        s = llena_lista(derechoB(b),s);
   }
   return s;
}

Lista elimina(Lista s){
    if(esvacia(s))
        return s;
    else if (esvacia(resto(s)))
        return s;
    else if(cabeza(s) == cabeza(resto(s)))
        return elimina(resto(s));
    else 
        return s = cons(cabeza(s), elimina(resto(s)));
    
}
