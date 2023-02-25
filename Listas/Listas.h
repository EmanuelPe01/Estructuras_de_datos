typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Lista;

Lista vacia(){
    return NULL;
}

Lista cons(Elem e, Lista s){
	Lista t=(Lista)malloc(sizeof(struct Nodo));
	t->dato=e;
	t->sig=s;
	return t;
}

int esvacia(Lista s){
	return s==NULL;
}

Elem cabeza(Lista s){
	return s->dato;
};

Lista resto(Lista s){
	return s->sig;
};

void ImpElems(Lista s){
	if(!esvacia(s)){
        ImpElem(cabeza(s));
        ImpElems(resto(s));
	}
};

int NumElems(Lista s){
	if(esvacia(s))
		return 0;
	else
		return 1+NumElems(resto(s));
};

Lista PegaListas(Lista s1, Lista s2){
	if(esvacia(s1))
		return s2;
	else
		return cons(cabeza(s1),PegaListas(resto(s1),s2));
};

Lista InvierteLista(Lista s){
	if(esvacia(s))
		return s;
	else
		PegaListas(InvierteLista(resto(s)),cons(cabeza(s),vacia()));
};

Lista InsOrd (Elem e, Lista s){
	if (esvacia(s))
		return cons(e,s);
	else if (EsMenor(e,cabeza(s)))
		return cons(e,s);
	else
		return cons(cabeza(s),InsOrd(e,resto(s)));
};

Lista OrdListaAsc(Lista s){
	if(esvacia(s))
		return s;
	else
		return InsOrd(cabeza(s), OrdListaAsc(resto(s)));
};

Lista OrdListaDesc(Lista s){
	if(esvacia(s))
		return s;
	else
		return (InvierteLista(OrdListaAsc(s)));
};



