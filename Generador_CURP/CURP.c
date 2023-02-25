#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define g 255

void crear_curp(int);
char g_codigo(char);
int nombre();
char *Nombre[g], cadena[g];
char d[2],m[2],a[4];
int aux = 0;
char sexo[1];
char entidad[50], codigo[2];
char curp[20];
int bandera = 1;


int main(){
    do{
        bandera =1;
        aux=nombre();
        puts("\nFecha de nacimiento (DD/MM/YYYY)");
        printf("\nDia: ");
        scanf("%s", &d);
        if(atoi(d)>30){
            printf("Formato incorrecto");
            bandera = 0;
        }
        printf("Mes: ");
        scanf("%s", &m);
        if(atoi(m)>12){
            printf("Formato incorrecto");
            bandera = 0;
        }
        printf("A o: ");
        scanf("%s", &a);
        if(atoi(a)<1000){
            printf("Formato incorrecto");
            bandera = 0;
        }
        printf("\nEntidad federativa: ");
        fflush(stdin);
        gets(entidad);
        for (int i = 0; entidad[i] != '\0'; i++){
            entidad[i] = toupper(entidad[i]);
        }

        if(strcmp(entidad , "AGUASCALIENTES")==0){
            codigo[0]='A';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "BAJA CALIFORNIA")==0){
            codigo[0]='B';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "COAHUILA")==0){
            codigo[0]='C';
        codigo[1]='L';
        }
        else if(strcmp(entidad , "CHIAPAS")==0){
            codigo[0]='C';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "DISTRITO FEDERAL")==0 || strcmp(entidad , "CIUDAD DE MEXICO" )==0){
            codigo[0]='D';
            codigo[1]='F';
        }
        else if(strcmp(entidad , "GUANAJUATO")==0){
            codigo[0]='G';
            codigo[1]='T';
        }
        else if(strcmp(entidad , "HIDALGO")==0){
            codigo[0]='H';
        codigo[1]='G';
        }
        else if(strcmp(entidad , "MEXICO")==0 || strcmp(entidad , "ESTADO DE MEXICO")==0){
            codigo[0]='M';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "MORELOS")==0){
            codigo[0]='M';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "NUEVO LEON")==0){
            codigo[0]='N';
            codigo[1]='L';
        }
        else if(strcmp(entidad , "PUEBLA")==0){
            codigo[0]='P';
            codigo[1]='L';
        }
        else if(strcmp(entidad , "QUINTANA ROO")==0){
            codigo[0]='Q';
            codigo[1]='R';
        }
        else if(strcmp(entidad , "SINALOA")==0){
            codigo[0]='S';
            codigo[1]='L';
        }
        else if(strcmp(entidad , "TABASCO")==0){
            codigo[0]='T';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "TLAXCALA")==0){
            codigo[0]='T';
            codigo[1]='L';
        }
        else if(strcmp(entidad , "YUCATAN")==0){
            codigo[0]='Y';
            codigo[1]='N';
        }
        else if(strcmp(entidad , "BAJA CALIFORNIA")==0){
            codigo[0]='B';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "CAMPECHE")==0){
            codigo[0]='C';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "CHIHUAHUA")==0){
            codigo[0]='C';
            codigo[1]='H';
        }
        else if(strcmp(entidad , "DURANGO")==0){
            codigo[0]='D';
            codigo[1]='G';
        }
        else if(strcmp(entidad , "GUERRERO")==0){
            codigo[0]='G';
            codigo[1]='R';
        }
        else if(strcmp(entidad , "JALISCO")==0){
            codigo[0]='J';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "MICHOACAN")==0){
            codigo[0]='M';
            codigo[1]='N';
        }
        else if(strcmp(entidad , "NAYARIT")==0){
            codigo[0]='N';
            codigo[1]='T';
        }
        else if(strcmp(entidad , "OAXACA")==0){
            codigo[0]='O';
            codigo[1]='C';
        }
        else if(strcmp(entidad , "QUERETARO")==0){
            codigo[0]='Q';
            codigo[1]='T';
        }
        else if(strcmp(entidad , "SAN LUIS POTOSI")==0){
            codigo[0]='S';
            codigo[1]='P';
        }
        else if(strcmp(entidad , "SONORA")==0){
            codigo[0]='S';
            codigo[1]='R';
        }
        else if(strcmp(entidad , "TAMAULIPAS")==0){
            codigo[0]='T';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "VERACRUZ")==0){
            codigo[0]='V';
            codigo[1]='Z';
        }
        else if(strcmp(entidad , "ZACATECAS")==0){
            codigo[0]='Z';
            codigo[1]='S';
        }
        else if(strcmp(entidad , "NACIDO EN EL EXTRANJERO")==0){
            codigo[0]='N';
            codigo[1]='E';
        }else {
            bandera = 0;
        }
        printf("Sexo(H/M): ");
        scanf("%c", &sexo[0]);
        bandera==0?puts("\nVuelva a llenar el formato"):puts("datos llenados correctamente");
    }while(bandera == 0);
    crear_curp(aux);
    return  0;
}
int nombre(){
    int n=0, l=0;
    printf("Cuantos nombres tiene?: ");
    scanf("%d", &n);
    printf("\n**Cada que escriba un nombre presine la tecla ENTER para continuar**\n");
    for(int i = 1; i<=n; i++){
        printf("Nombre %d: ", i);
        fflush(stdin);
        gets(cadena);
        l = strlen(cadena);
        Nombre[i] = (char *) malloc (l *sizeof (char));
        strcpy(Nombre[i], cadena);
    }
    printf("Apellido Paterno: ");
        fflush(stdin);
        gets(cadena);
        l = strlen(cadena);
        Nombre[n+1] = (char *) malloc (l *sizeof (char));
        strcpy(Nombre[n+1], cadena);
    printf("Apellido Materno: ");
        fflush(stdin);
        gets(cadena);
        l = strlen(cadena);
        Nombre[n+2] = (char *) malloc (l *sizeof (char));
        strcpy(Nombre[n+2], cadena);
    return n+2;
}

void crear_curp(int n_){
    char curp[20];
    int aux=0;
    curp[0]=Nombre[n_-1][0];
    for(int i = 0; i<strlen(Nombre[n_-1]);i++){
        if(Nombre[n_-1][i] == 'a' || Nombre[n_-1][i] == 'e' || Nombre[n_-1][i] == 'i' || Nombre[n_-1][i] == 'o' || Nombre[n_-1][i] == 'u' || Nombre[n_-1][i] == 'A' || Nombre[n_-1][i] == 'E' || Nombre[n_-1][i] == 'I' || Nombre[n_-1][i] == 'O' || Nombre[n_-1][i] == 'U'){
            curp[1]=Nombre[n_-1][i];
            break;
        }
    }
    curp[2]=Nombre[n_][0];
    curp[3]=Nombre[1][0];
    curp[4]=a[2];
    curp[5]=a[3];
    curp[6]=m[0];
    curp[7]=m[1];
    curp[8]=d[0];
    curp[9]=d[1];
    curp[10]=sexo[0];
    curp[11]=codigo[0];
    curp[12]=codigo[1];
    if(Nombre[n_-1][0] == 'a' || Nombre[n_-1][0] == 'e' || Nombre[n_-1][0] == 'i' || Nombre[n_-1][0] == 'o' || Nombre[n_-1][0] == 'u' || Nombre[n_-1][0] == 'A' || Nombre[n_-1][0] == 'E' || Nombre[n_-1][0] == 'I' || Nombre[n_-1][0] == 'O' || Nombre[n_-1][0] == 'U')
        aux++;
    for(int i = 0; i<strlen(Nombre[n_-1]);i++){
        if(Nombre[n_-1][i] != 'a' && Nombre[n_-1][i] != 'e' && Nombre[n_-1][i] != 'i' && Nombre[n_-1][i] != 'o' && Nombre[n_-1][i] != 'u' && Nombre[n_-1][i] != 'A' && Nombre[n_-1][i] != 'E' && Nombre[n_-1][i] != 'I' && Nombre[n_-1][i] != 'O' && Nombre[n_-1][i] != 'U'){
            aux++;
            if(aux==2){
                curp[13]=Nombre[n_-1][i];
                break;
            }
        }
    }
    aux=0;
    if(Nombre[n_][0] == 'a' || Nombre[n_][0] == 'e' || Nombre[n_][0] == 'i' || Nombre[n_][0] == 'o' || Nombre[n_][0] == 'u' || Nombre[n_][0] == 'A' || Nombre[n_][0] == 'E' || Nombre[n_][0] == 'I' || Nombre[n_][0] == 'O' || Nombre[n_][0] == 'U')
        aux++;
    for(int i = 0; i<strlen(Nombre[n_]);i++){
        if(Nombre[n_][i] != 'a' && Nombre[n_][i] != 'e' && Nombre[n_][i] != 'i' && Nombre[n_][i] != 'o' && Nombre[n_][i] != 'u' && Nombre[n_][i] != 'A' && Nombre[n_][i] != 'E' && Nombre[n_][i] != 'I' && Nombre[n_][i] != 'O' && Nombre[n_][i] != 'U'){
            aux++;
            if(aux==2){
                curp[14]=Nombre[n_][i];
                break;
            }
        }
    }
    aux=0;
    if(Nombre[1][0] == 'a' || Nombre[1][0] == 'e' || Nombre[1][0] == 'i' || Nombre[1][0] == 'o' || Nombre[1][0] == 'u' || Nombre[1][0] == 'A' || Nombre[1][0] == 'E' || Nombre[1][0] == 'I' || Nombre[1][0] == 'O' || Nombre[1][0] == 'U')
        aux++;
    for(int i = 0; i<strlen(Nombre[1]);i++){
        if(Nombre[1][i] != 'a' && Nombre[1][i] != 'e' && Nombre[1][i] != 'i' && Nombre[1][i] != 'o' && Nombre[1][i] != 'u' && Nombre[1][i] != 'A' && Nombre[1][i] != 'E' && Nombre[1][i] != 'I' && Nombre[1][i] != 'O' && Nombre[1][i] != 'U'){
            aux++;
            if(aux==2){
                curp[15]=Nombre[1][i];
                break;
            }
        }
    }
    curp[16] = 'A';
    curp[17] = '6';
    for (int i = 0; curp[i] != '\0'; i++){
            curp[i] = toupper(curp[i]);
        }
    printf("\nCURP: %s",curp);
}

