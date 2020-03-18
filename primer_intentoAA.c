#include <stdio.h>
#include <stdlib.h>

char asiento[6][32];
int x;
int i;
int j;
int butaca;
char a; 
int fila;

void clearscreen (){
  system("@cls||clear");
}

void iniciar(){
	clearscreen ();
  x=0;
	for(i=0;i<7;i++){
		for (j=0;j<32;j++){
			asiento [i][j]='0';
		}
	}	
}
void reserva(){
	do{
		printf("Ingrese la Letra de la fila: (por favor usar mayusculas)\n");
		scanf("%c",&fila);
		
	while(getchar() != '\n');
	} while(fila < 'A' || fila > 'F' );
	
	do{
		printf("Ingrese numero asiento:\n");
		scanf("%d",&butaca);
	while(getchar() != '\n');
	}while(butaca < 1 || butaca > 32) ;
	if(fila =='A')
		x=0;
	if(fila =='B')
		x=1;
	if(fila =='C')
		x=2;
	if(fila =='D')
		x=3;
  if(fila == 'E')
    x=4;
  if(fila == 'F')
    x= 5;
		system("clear");
	if(asiento[x][butaca-1]=='X'){ 
		printf("el asiento %c%d Ya esta reservado\n vuelva a ingresar su reserva\n",fila,butaca);
		reserva();
	}else{
		printf("Usted eligio la fila %c numero %d\n", fila, butaca);
		asiento [x][butaca-1]= 'X'; 
	}
	
}
void cancelar (void){
	do{
		printf("Ingrese la Letra de la fila: (por favor utilizar letras mayusculas");
		scanf("%c",&fila);
	while(getchar() != '\n');
	} while(fila < 'A' || fila > 'F' );
	
	do{
		printf("Ingrese numero asiento :");
		scanf("%d",&butaca);
	while(getchar() != '\n');	
	}while(butaca < 1 || butaca > 32) ;
	if(fila =='A')
		x=0;
	if(fila =='B')
		x=1;
	if(fila =='C')
		x=2;
	if(fila =='D')
		x=3;
  if(fila == 'E')
        x=4;
  if(fila =='F')
        x=5;
		system("clear");
	if(asiento[x][butaca-1]!='X'){
		printf("el asiento %c%d NO esta reservado\n vuealva a ingresar su asiento\n",fila,butaca);
	
	}else{
		printf("Usted elimino el asiento de la fila %c numero %d\n", fila, butaca);
		asiento [x][butaca-1]= '0';
	
	}

}

void mostrar (void){
	a='A';
	printf("\t");
	for (j=1;j<33;j++){
			printf("[%d] ",j);
		}
		printf("\n");
    for(i=0;i<6;i++){
		printf("%c\t", a);
		a= a+1;
		for (j=0;j<33;j++){
			if (j<10)
				printf("%c ",asiento[i][j]);
			else
				printf(" %c ",asiento[i][j]);
		}
	printf("\n");
	}
}
int main (void) {
	int op1;
	iniciar ();
	while(1){
		mostrar();
	printf("ingrese el numero de la opcion que quiere seleccionar:\n");
	printf("1- reservar asiento\n");
	printf("2- cancelar reservacion previa\n");
	printf("3- salir\n");
	scanf("%d",&op1);
	switch (op1){
		case 1:
			reserva();
			break;
		case 2:
			cancelar();
			break;
		case 3:
			exit(1);
			break;
      default:break;
	}
}
return 0;
}
