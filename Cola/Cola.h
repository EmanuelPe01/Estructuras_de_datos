typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
}*ApNodo;

typedef struct{
    ApNodo primero;
    ApNodo ultimo;
}CNodo;

typedef CNodo *Cola;

Cola nueva(){
    Cola t = (Cola)malloc(sizeof(CNodo));
    t->primero = t->ultimo = NULL;
    return t;
}

int esnueva(Cola q){
    return q->primero == NULL && q->ultimo == NULL;
}

Cola formar(Cola q, Elem e){
    ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
    t->dato = e;
    t->sig = NULL;

    if(esnueva(q))
        q->primero = q->ultimo = t;
    else{
        q->ultimo->sig = t;
        q->ultimo = t;
    }
    return q;
}

Elem primero(Cola q){
    return q->primero->dato;
}

Cola desformar (Cola q){
    if(q->primero == q->ultimo)
        return nueva();
    else
        q->primero = q->primero->sig;

    return q;
}

