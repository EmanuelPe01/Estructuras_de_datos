#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Elem.h"
#include "Pilas.h"

void titulo();
void crear_tablero(Pila**);
void tablero(Pila**);
int dado();
char empieza();
void juego(char,Pila**);
char normal(char, Pila**, int, int ,int, int, int);
char comida(char, Pila**, int);
void movimiento(char, Pila**, int, int);
int posibilidades(char, Pila**);
int mov_final(char, Pila**);
int i;

int main(){
    srand(time(NULL));
    Pila **fila = (struct Nodo_pila **)calloc(sizeof(struct Nodo_pila*), 28);
    crear_tablero(fila);
    char p = empieza();
    juego(p,fila);
    
    return 0;
}

void crear_tablero(Pila **llenar){
    for(i=0; i<26; i++)
        llenar[i] = empty();    

    for(i = 0; i<2; i++){
        llenar[1] = push('N', llenar[1]);
        llenar[24] = push('B', llenar[24]);
    }
    for(i = 0; i<5; i++){
        llenar[6] = push('B', llenar[6]);
        llenar[12] = push('N', llenar[12]);
        llenar[13] = push('B', llenar[13]);
        llenar[19] = push('N', llenar[19]);
    }
    
    for(i = 0; i<3; i++){
        llenar[8] = push('B', llenar[8]);
        llenar[17] = push('N', llenar[17]);
    }
}
void tablero(Pila **llenar){
    printf("\n\t\t\t\tTABLERO\n");
    for( i = 0; i<26;i++){
        printf("%d.-\t", i);
        ImpPilas(llenar[i]);
        printf("\n");
        if(i%6 == 0)
            printf("\n");
    }

    printf("\n\t\t\t\tFichas comidas");
    printf("\nNegras: \t");
    ImpPilas(llenar[26]);
    printf("\nBlancas: \t");
    ImpPilas(llenar[27]);
};
void titulo(){
    system("ClS");
    printf("\n**************************************************************************\n");
    printf("\t\t\t\tBACKGAMMON\n");
    printf("**************************************************************************\n");
}
int dado(){
    int n = rand()%6+1;
    return n;
}

char empieza(){
    int a  = dado();
    int b = dado();
    char player;
    while(a==b){
        a = dado();
        b = dado();
    }
    printf("\nDado juagodor piezas blancas: %d", a);
    printf("\nDado juagodor piezas negras: %d\n", b);
    if(a>b){
        player = 'B';
        printf("\t\tComienzan fichas blancas\n\n");
        system("pause");
    }else{
        player = 'N';
        printf("\t\tComienzan fichas Negras\n\n");
        system("pause");
    }   
    return player;
}

void juego(char player,Pila **tabla){
    int c_n = NumElems(tabla[26]), c_b = NumElems(tabla[27]);
    int g_n = NumElems(tabla[25]), g_b =NumElems(tabla[0]);
    char p;
    if(g_n == 15){
        printf("Ganan fichas negras");
        system("Pause");
        system("exit");
    }
    else if(g_b == 15) {
        printf("Ganan fichas blancas");
        system("Pause");
        system("exit");
    }
        
    else if(player == 'N'){
        if(c_n != 0){
            p = comida(player, tabla, c_n);
        }else
            p = normal(player, tabla, 0, 0 ,0,0,0); 
        }else{
        if(c_b != 0){
            p = comida(player, tabla, c_b);
        }else
            p = normal(player, tabla, 0, 0 ,0,0,0);
        } 
        if(g_n<15 || g_b<15){
            system("cls");
            if(p == 'B')
                juego('N', tabla);
            else 
                juego('B', tabla);
        }
}

char normal(char player, Pila **tabla, int c_g, int r_1, int r_2, int a_1, int a_2){
    int f, d, d_1, d_2, aux[]={0,0}, b=0, bandera =1, final = 0;
    char p;
    b=c_g;
    if(r_1 == 0 && r_2 == 0){
        d_1 = dado();
        d_2 = dado();
    }else{
        d_1 = r_1;
        d_2 = r_2;
    }
    if(a_1 != 0)
        aux[0] = a_1;
    if(a_2 != 0)
        aux[1] = a_2;
    titulo();
    tablero(tabla);

    do{
        do{
            printf("\n\nTurno de piezas: %c\n", player);
            printf("\n\nTirada: %d y %d", d_1, d_2);
            printf("\n\nSi no tiene movimientos digite 30");
            printf("\nQue fila desea mover? (Digite su respuesta): ");
            scanf("%d", &f);
            if(f == 30)
                bandera = 0;
            else if(isempty(tabla[f]) || top(tabla[f])!=player){
                printf("\nNo es su color o no contiene fichas");
                bandera = 1;
            }              
            else 
                bandera = 0;
        }while (bandera==1);  

        final = mov_final(player,tabla);
        if(f != 30){
            printf("\nA donde desea mover? (Digite su respuesta): ");
            scanf("%d", &d);
        }else 
            b = 2;

        if(player == 'N'){
            if(d<=f)
                printf("\nNo puede retroceder");
            else if(d == 25 && final==12){

                if((f+d_1)>=d && aux[0] == 0){
                    movimiento(player,tabla,d,f);
                    aux[0]++;
                    b++;
                    if(b==1){
                        system("cls");
                        titulo();
                        tablero(tabla);
                    }
                }else if ((f+d_2)>=d && aux[1] == 0){
                    movimiento(player,tabla,d,f);
                    aux[1]++;
                    b++;
                    if(b==1){
                        system("cls");
                        titulo();
                        tablero(tabla);
                    }
                }else if((f+d_1+d_2) >= d){
                    movimiento(player,tabla,d,f);
                    b+=2;
                }
                
            }else if (d == (f+d_1) && aux[0]==0 && d!=25){
                movimiento(player,tabla,d,f);
                aux[0]++;
                b++;
                if(b==1){
                    system("cls");
                    titulo();
                    tablero(tabla);
                }
            } else if(d == (f+d_2) && aux[1]==0 && d!=25){
                movimiento(player,tabla,d,f);
                aux[1]++;
                b++;
                if(b==1){
                    system("cls");
                    titulo();
                    tablero(tabla);
                }
            }else if(d == (f+d_1+d_2) && aux[0]==0 && aux[1]==0 && d!=25){
                movimiento(player,tabla,d,f);
                b+=2;
            }else{
                printf("\nNo puede hacer ese movimiento");
            }
        } else {
            if(d>=f)
                printf("\nNo puede retroceder");
            else if (d == (f-d_1) && aux[0]==0 && d!=0){
                movimiento(player,tabla,d,f);
                aux[0]++;
                b++;
                if(b==1){
                    system("cls");
                    titulo();
                    tablero(tabla);
                }
            } else if(d == (f-d_2) && aux[1]==0 && d!=0){
                movimiento(player,tabla,d,f);
                aux[1]++;
                b++;
                if(b==1){
                    system("cls");
                    titulo();
                    tablero(tabla);
                }
            }else if(d == (f-d_1-d_2) && aux[0]==0 && aux[1]==0 && d!=0){
                movimiento(player,tabla,d,f);
                b+=2;
            }else if(d == 0 && final==12){
                if((f-d_1)<=d && aux[0] == 0){
                    movimiento(player,tabla,d,f);
                    aux[0]++;
                    b++;
                    if(b==1){
                        system("cls");
                        titulo();
                        tablero(tabla);
                    }
                }else if ((f-d_2)<=d && aux[1] == 0){
                    movimiento(player,tabla,d,f);
                    aux[1]++;
                    b++;
                    if(b==1){
                        system("cls");
                        titulo();
                        tablero(tabla);
                    }
                }else if((f-d_1-d_2) <= d){
                    movimiento(player,tabla,d,f);
                    b+=2;
                }
                
            }else{
                printf("\nNo puede hacer ese movimiento");
            }
        }

    }while(b<2);
    p = player;
    return p;
}

char comida (char player, Pila **tabla, int v){
    int d,f, aux[]={0,0}, b, d_1 = dado(), d_2 = dado();
    char p;
    titulo();
    tablero(tabla);
    do{
        printf("\n%d \t %d", NumElems(tabla[26]),NumElems(tabla[27]));
        printf("\n\nTurno de piezas: %c\n", player);
        printf("Debe jugar las piezas comidas\n");
        printf("\nTirada: %d y %d", d_1, d_2);
        printf("\n\nSi no tiene movimientos digite 30");
        printf("\nA donde desea mover? (Digite su respuesta): ");
        scanf("%d", &d);
        
        if(d == 30)
            b = 2;

        if(player == 'N'){
            f=26;
            if (d == d_1 && aux[0]==0){
                printf("Movimiento dado 1");
                movimiento(player,tabla,d,f);
                aux[0]++;
                b++;
                system("cls");
                titulo();
                tablero(tabla);
            } else if(d == d_2 && aux[1]==0){
                printf("Movimiento dado 1");
                movimiento(player,tabla,d,f);
                aux[1]++;
                b++;
                system("cls");
                titulo();
                tablero(tabla);
            }else if(d == d_1+d_2 && aux[0]==0 && aux[1]==0){
                printf("Movimiento dados");
                movimiento(player,tabla,d,f);
                b+=2;
            }else{
                printf("\nNo puede hacer ese movimiento");
            }
        }else{
            f=27;
           if (d == (25-d_1) && aux[0]==0){
                printf("Movimiento dado 1");
                movimiento(player,tabla,d,f);
                aux[0]++;
                b++;
                system("cls");
                titulo();
                tablero(tabla);
            } else if(d == (25-d_2) && aux[1]==0){
                printf("Movimiento dado 2");
                movimiento(player,tabla,d,f);
                aux[1]++;
                b++;
                system("cls");
                titulo();
                tablero(tabla);
            }else if(d == (25-d_1-d_2) && aux[0]==0 && aux[1]==0){
                printf("Movimiento dados");
                movimiento(player,tabla,d,f);
                b+=2;
            }else{
                printf("\nNo puede hacer ese movimiento");
            } 
        }
    }while(b<v);

    p = player;

    if(b==1)
        return normal(p, tabla, b, d_1, d_2, aux[0], aux[1]);
    else 
        return p;
}

int mov_final(char p, Pila **f){
    int n = 0;
    for(i = 7; i<=18; i++){
        if(isempty(f[i]) || top(f[i]) != p)
            n++;
    }        
    return n;
}

void movimiento(char player, Pila **tabla, int m, int f){
    if(isempty(tabla[m]) || top(tabla[m])==player){
        tabla[f] = pop(tabla[f]);
        tabla[m] = push(player, tabla[m]);
    }else if(NumElems(tabla[m]) == 1){
        if(player == 'B'){
            tabla[f] = pop(tabla[f]);
            tabla[m] = empty();
            tabla[m] = push(player, tabla[m]);
            tabla[26] = push('N', tabla[26]);
        }else{
            tabla[f] = pop(tabla[f]);
            tabla[m] = empty();
            tabla[m] =push(player, tabla[m]);
            tabla[27] = push('B', tabla[27]);
        }
    }else{
        printf("\nNo se puede hacer el movimiento");
    }

}