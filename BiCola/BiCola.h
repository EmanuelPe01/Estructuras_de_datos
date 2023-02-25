typedef struct Nodo{
         Elem dato;
         struct Nodo *der;
         struct Nodo *izq;
       }*ApNodo;

typedef struct{
         ApNodo izq;
         ApNodo der;
        } BNodo;
typedef BNodo *BiCola;


BiCola nuevaB(){
    BiCola t=(BiCola)malloc(sizeof(BNodo));
    t->izq=t->der=NULL;
    return t;
}


int esnuevaB(BiCola q){
     return q->izq == NULL && q->der == NULL;
}

BiCola formarI(Elem e, BiCola q){
     ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
     t->dato=e; t->izq=NULL; t->der=NULL;
     if(esnuevaB(q))
         q->izq=q->der=t;
     else{
           t->der=q->izq;
           q->izq->izq = t;
           q->izq = t;
     }
        return q; // OJO OJO OJO
}

BiCola formarD(BiCola q, Elem e){
     ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
     t->dato=e; t->der=NULL; t->izq=NULL;
     if(esnuevaB(q))
         q->der=q->izq=t;
     else{
           t->izq=q->der;
           q->der->der = t;
           q->der = t;
     }
        return q; // OJO OJO OJO
}




Elem izquierdo(BiCola q){ return q->izq->dato;}

Elem derecho(BiCola q){ return q->der->dato;}


BiCola desformarI(BiCola q){
    if(q->izq == q->der)
         return nuevaB();
    else{
        q->izq = q->izq->der;
        q->izq->izq=NULL;
    }
    return q;
}


BiCola desformarD(BiCola q){
    if(q->izq == q->der)
         return nuevaB();
    else{
        q->der = q->der->izq;
        q->der->der=NULL;
    }
    return q;
}
