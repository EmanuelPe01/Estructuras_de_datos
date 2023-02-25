typedef int Elem;

void ImpElem (Elem s){
	printf("%d\t", s);
}

int EsMenor(Elem e1, Elem e2){
    return e1<e2;
}

/*
    int otro = 7,i=50,aux_,aux_2, num_discos=9;
    aux_ = (num_discos + i)-1;
    aux_2 = (otro + num_discos);
    char aux[] = "push( ,";
    char puts[65] = "push(1,";
    char fin[15] = "empty())";
    for(i = 50; i<aux_;i++){
        aux[5]=i;
        strcat(puts,aux);
    }
    while(otro<aux_2){
        fin[otro]=')';
        otro++;
    }
    otro = strlen(puts)+ strlen(fin);
    char pussh[otro];
    strcpy(pussh,puts);
    strcat(pussh,fin);
    printf("%s\n",pussh);
*/
