#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Elem.h"
#include "circular.h"


int i = 0, aux = 0, j = 1, credito = 0,apostado=0, apuesta[55] = {0}, dinero = 0, bandera = 0, f1[13] = {0}, f2[13] = {0}, f3[13] = {0};
char *rojo = "\033[0;31m", *normal = "\033[0m", *verde = "\033[0;32m", *amarillo = "\033[0;33m", *azul = "\033[0;36m", *morado = "\033[1;35m", aux_apuesta[15];
void tablero();
void titulo();
void juego();
void menu();
int validacion(char *, int);
int rojos(int );
int giro(Circular);
void resultados (int); 
int fila(int );
int docena(int );
int mitad(int );
int par(int );


int main()
{
    char res[2];
    srand(time(NULL));
    Circular ruleta = nuevaC();
    for(i = 0; i<=36; i++)
       ruleta = formarC(ruleta, i);
    system("cls");
    do{
        printf("\n\tCuanto dinero desea apostar?: ");
        scanf("%d", &credito);
        if(credito<=0)
            printf("\t%sNo puedes ingresar%s\n", rojo,normal);
    }while(credito<=0);
    tablero();
    juego();
    printf("\nApostado: %d\n", apostado);
    aux = giro(ruleta);
    printf("\nganador: %d", aux);
    resultados(aux);
    printf("\n\n");
    system("pause");
    return 0;
}

void tablero()
{
    system("Color f");
    system("cls");
    titulo();
    menu();
    printf("\t");
    for (j = 0; j <=36; j++)
        printf("- ");

    printf("\n");

    for (i = 3; i > 0; i--)
    {
        aux = i;

        if (i == 3 || i == 1)
            printf("\t|        ");
        else
            printf("\t|    %s0%s   ", verde, normal);

        printf(" | ");
        for (j = 1; j <= 12; j++)
        {
            if (rojos(aux))
                printf("%s%d%s ", rojo, aux, normal);
            else
                printf("%d ", aux);

            if (j % 4 == 0)
                printf(" |  ");
            
            if(i == 3)
                f1[j] = aux;
            else if(i == 2)
                f2[j] = aux;
            else 
                f3[j] = aux;
            aux += 3;
        }
        printf("  F%d   |\n", i);
        if (i != 1)
        {
            printf("\t         ");
            for (j = 0; j < 19; j++)
                printf(" - ");

            printf("\n");
        }
    }

    printf("\t");
    for (j = 0; j < 33; j++)
        printf("- ");

    printf("\n\t         ");
    printf(" |1a. Docena |  2da. Docena  |  3ra. Docena  |");
    printf("\n\t          ");
    for (j = 0; j < 23; j++)
        printf("- ");

    printf("\n\t      ");
    printf(" | 1-18 | Pares |  %sRojo%s  |  Blanco | Inpar | 19-36 |", rojo, normal);
    printf("\n\t       ");
    for (j = 0; j < 26; j++)
        printf("- ");
    printf("\n\n");
}

void titulo()
{
    printf("\t%s", rojo);
    for (j = 0; j < 33; j++)
        printf("* ");
    printf("\n\n\t* * * * * \t\t%sRULETA %sDE %sMONTE%s - %sCARLO\t\t%s* * * * *\n\n", azul, normal, azul, normal, azul, rojo);
    printf("\t%s", rojo);
    for (j = 0; j < 33; j++)
        printf("* ");
        
    printf("\n\n%s", normal);
}

void menu()
{
    printf("\n\tOpcion\t\tForma de introducir\n\n");
    printf("\t1er. Docena\t\t1D\n\t2da. Docena\t\t2D\n\t3ra. Docena\t\t3D\n\n\n");
}

void juego()
{
    bandera = 1;
    char comienzo[2];
    apostado = 0;
    do{
        printf("\n\t%sSaldo: $%d%s\n",verde, credito,normal);
        do{
            printf("\nCuanto va a apostar?: ");
            scanf("%d", &dinero);
            if(dinero>credito || dinero<=0)
                printf("%sNo puedes apostar esa cantidad%s\n",rojo,normal);
            else 
                bandera = 0;
        }while(bandera);

        credito-=dinero;
        apostado += dinero;
        
        do
        {
            printf("\nA que va a apostar?: ");
            scanf("%s", &aux_apuesta);
            aux = validacion(aux_apuesta, dinero);
        } while (aux); 
        
        if(credito == 0){
            printf("%sSin dinero para hacer otra apuesta, la ruleta va a girar. ",amarillo);
            strcpy(comienzo,"si");
            system("pause");
            printf("%s",normal);
        }else{
            printf("\n%sComenzar? (Si/No): %s", amarillo, normal);
            scanf("%s", &comienzo);
            for(i = 0; i<2; i++)
                comienzo[i] = tolower(comienzo[i]);
        }
    }while(strcmp(comienzo,"si") != 0 );
}

int validacion(char *opcion, int money)
{
    bandera = 0;
    for (i = 0; opcion[i] != '\0'; i++)
    {
        opcion[i] = tolower(opcion[i]);
    }
    aux = atoi(opcion);
    if (strcmp(opcion, "19-36") == 0)
        apuesta[50] = money;
    else if (strcmp(opcion, "inpar") == 0)
        apuesta[49] = money;
    else if (strcmp(opcion, "blanco") == 0)
        apuesta[48] = money;
    else if (strcmp(opcion, "rojo") == 0)
        apuesta[47] = money;
    else if (strcmp(opcion, "pares") == 0)
        apuesta[46] = money;
    else if (strcmp(opcion, "1-18") == 0)
        apuesta[45] = money;
    else if (strcmp(opcion, "f3") == 0)
        apuesta[44] = money;
    else if (strcmp(opcion, "f2") == 0)
        apuesta[43] = money;
    else if (strcmp(opcion, "f1") == 0)
        apuesta[42] = money;
    else if (strcmp(opcion, "1d") == 0)
        apuesta[41] = money;
    else if (strcmp(opcion, "2d") == 0)
        apuesta[40] = money;
    else if (strcmp(opcion, "3d") == 0)
        apuesta[39] = money;
    else if (strcmp(opcion, "0") == 0)
        apuesta[38] = money;
    else if (aux >= 1 && aux <= 36)
        apuesta[aux] = money;
    else{
        printf("%sTu opcion no es valida%s\n", rojo, normal);
        bandera = 1;
    }
        
    return bandera;
}

int rojos(int numero){
    bandera = 0;
    if(numero == 1 || numero == 3 || numero == 5 || numero == 7 || numero == 9 || numero == 12 || numero == 14 || numero == 16 || numero == 18 || numero == 19 || numero == 21 || numero == 23 || numero == 25 || numero == 27 || numero == 30 || numero == 32 || numero == 34 || numero == 36)
        return bandera = 1;
    else 
        return bandera;
}

int giro(Circular dato){
    int num = rand()%100+1;
    for(i = 0; i<= num; i++)
        dato = rotacionC(dato);

    if(rojos(primeroC(dato)))
        printf("\nResultados:\n%s%d\tRojo%s",rojo,primeroC(dato), normal);
    else 
        printf("\nResultados:\n%d\tBlanco", primeroC(dato));
    return primeroC(dato);
}

void resultados(int res){
    char* color;
    int g = 0;
    int fila_ = 0, docena_ = 0, mitad_ = 0, par_ = 0 ;
    fila_ = fila(res);
    docena_ = docena(res);
    mitad_ = mitad(res);
    par_ = par(res);

    if(rojos(res))
        strcpy(color, "rojo");
    else 
        strcpy(color, "blanco");
    
    if(res==0 && apuesta[38]!=0)
        g += apuesta[38] * 2;
    else if (apuesta[res]!=0 || apuesta[fila_]!=0 || apuesta[docena_]!=0 || apuesta[mitad_]!=0 || apuesta[par_]!=0){
        if(apuesta[res] == apostado)
            g += apuesta[res] * 38;
        else{
            g += apuesta[res] * 3;
            if(fila_!=0)
                g += apuesta[fila_] * 3;
            if(docena_!=0)
                g += apuesta[docena_] * 3;
            if(mitad_!=0)
                g += apuesta[mitad_] * 2;
            if(par_!=0)
                g += apuesta[par_] * 2;            
        } 
    }else if(strcmp(color, "rojo")==0 && apuesta[47]!=0)
        g += apuesta[47] * 2;
    else if(strcmp(color, "blanco")==0 && apuesta[47]!=0)
        g += apuesta[48] * 2;
    
    credito += g;
    printf("\n\nGanancia: %d", g);
    printf("\nCredito final: %d", credito);
}

int fila(int r){
    int resultado = 0;
    for(i = 1; i<=12; i++){
        if(r == f1[i]){
            resultado = 42;
            break;
        } else if(r == f2[i]){
            resultado = 43;
            break;
        } else if(r == f3[i]){
            resultado = 44;
            break;
        }
    }
    return resultado;
}

int docena(int r){
    int resultado = 0;
    if(r>=1 && r<=12)
        resultado = 41;
    else if(r>=13 && r<=24)
        resultado = 40;
    else if(r>=24 && r<=36)
        resultado = 41;
    
    return resultado;
}

int mitad(int r){
    int resultado = 0;
    if(r>=1 && r<=18)
        resultado = 45;
    else if(r>=19 && r<=36)
        resultado = 50;
    
    return resultado;
}

int par(int r){
    int resultado = 0;
    if(r%2 == 0)
        resultado = 46;
    else 
        resultado = 49;
    
    return resultado;
}