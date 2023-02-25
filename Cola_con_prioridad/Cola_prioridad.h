typedef struct Nodo{
    Elem dato;
    Elem posicion;
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

Cola formar(Cola q, Elem e, Elem p){
    ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
    t->dato = e;
    t->posicion = p;
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
Elem puesto(Cola q){
    return q->primero->posicion;
}

Cola desformar (Cola q){
    if(q->primero == q->ultimo)
        return nueva();
    else
        q->primero = q->primero->sig;

    return q;
}

int numElems(Cola q){
    if(esnueva(q))
        return 0;
    else    
        return 1+numElems(desformar(q));
}

void impElems(Cola q){
    if(!esnueva(q)){
        ImpElem(primero(q), puesto(q));
        impElems(desformar(q));
    }
}

Cola cola_prioridad(Cola q, int a){
    Cola aux_c = nueva();
    Elem aux[a][2];
    Elem aux_1=0,aux_2=0, pos=0;
    for(int i = 0; i<a; i++){
        aux[i][0] = primero(q);
        aux[i][1] = puesto(q);
        q = desformar(q);
    }
    for(int i = 1; i<a; i++){
        pos = i;
        aux_1 = aux[i][0];
        aux_2 = aux[i][1];
        while ((pos>1) && (aux[pos-1][1]>aux_2))
        {
            aux[pos][0] = aux[pos-1][0];
            aux[pos][1] = aux[pos-1][1];
            pos--;
        }
        aux[pos][0]=aux_1;
        aux[pos][1]=aux_2;
    }

    for(int i = 0; i<a; i++)
        aux_c = formar(aux_c,aux[i][0], aux[i][1]);
    
    return aux_c;
    
}

