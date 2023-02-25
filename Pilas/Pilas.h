typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Pila;

Pila empty(){
    return NULL;
}

Pila push(Elem e, Pila s){
	Pila t=(Pila)malloc(sizeof(struct Nodo));
	t->dato=e;
	t->sig=s;
	return t;
}

int isempty(Pila s){
	return s==NULL;
}

Elem top(Pila s){
	return s->dato;
};

Pila pop(Pila s){
	return s->sig;
};

void Imprimir(Pila s){
    if(!isempty(s)){
        ImpElem(top(s));
        Imprimir(pop(s));
    }

}
int NumElems(Pila s){
	if(isempty(s))
		return 0;
	else
		return 1+NumElems(pop(s));
};
