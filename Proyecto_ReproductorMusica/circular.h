typedef struct Nodo{
    Pista dato;
    Nombre_cancion cancion;
    Artista cantante;
    Genero tipo;
    struct Nodo *sig;
} *Circular;


Circular nuevaC(){
    return NULL;
}

int esvaciaC(Circular c){
    return c==NULL;
}

Circular formarC(Circular c, Pista e, Nombre_cancion n, Artista a, Genero g){
     Circular t =(Circular)malloc(sizeof(struct Nodo));
     t->dato=e;
     t->cancion=n;
     t->cantante=a;
     t->tipo=g;
     if(esvaciaC(c)){
         c=t;
         c->sig=t;
     }else{
          t->sig=c->sig;
          c=c->sig=t;
     }
     return c;
}


Circular rotacionC(Circular c){
    return c->sig;
}

