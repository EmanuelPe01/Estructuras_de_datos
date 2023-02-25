#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Elem.h"
#include"Circular.h"

typedef Circular Dado;

int Tirada(Dado);
Dado DadoNuevo(int);

int MyModule(int, int);

int main(){

    ImpElem(MyModule(5,12));

    return 0;
}

Dado DadoNuevo(int n){
    int i;
    Dado d=nuevaC();
    for(i=1;i<=n;i++)
        d=formarC(d,i);
    return d;
};

int Tirada(Dado d){
      int i,n=rand();

      for(i=1;i<=n;i++)
        d=rotacionC(d);
      return primeroC(d);
};

int MyModule(int a, int b){
    Dado e= DadoNuevo(b);
   while(--a){
       e=rotacionC(e);
   }
   if(primeroC(e)==b)return 0;
   else
   return primeroC(e);
}
