#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
	char nombre[250];
	int nota[100];
}nombre;

typedef struct{
	char pregunta[250];
	char opcion1[250];
	char opcion2[250];
	char opcion3[250];
	char opcion4[250];
	char correcta[250];
}Pregunta;

void banner (){
	
printf("______________________________________________________________________________________________________________________________________ \n");
printf("MMMMMM      MMMMMM         MMMMMMM      MMMMMMMMM     MMMMMMMMM        MMMMMMMMM  MMMMMMMMM        MMMMMMMMM   MMMMMMMM  MMMMM         \n");
printf("MM          MM            MM     MM     MM      MM    MM               MM     MM  MM               MM          MM    MM  MM   MM       \n");
printf(" MM         MM            MM     MM     MMMMMMMMM     MMMMMM           MM     MM  MMMMM            MM          MM    MM  MM    MM      \n");
printf("   MM       MM            MMMMMMMMM     MM            MMMMMM           MM     MM  MM               MM   MMMM   MM    MM  MM   MM       \n");
printf("    MM      MM            MM     MM     MM            MM               MM     MM  MM               MM     MM   MM    MM  MM   MM       \n");
printf("MMMMMM      MMMMMM        MM     MM     MM            MMMMMMMMM        MMMMMMMMM  MM               MMMMMMMMM   MMMMMMMM  MM MM         \n");
prinft("_______________________________________________________________________________________________________________________________________\n");
}
//Funcion en la que harémos el nivel facil
void nivel_mortal(Pregunta* preguntas);

//Funcion en la que haremos el nivel medio
void nivel_heroe(Pregunta* preguntas);


//Funcion en la que haremos el nivel dificil
void nivel_dios(Pregunta* preguntas);


//Funcion que llena la estructura de datos con las preguntas, sus repuestas y el resultado correcto
void llenar_estructuras(Pregunta* preguntas);


int main(){
	banner ();
	int n;
	int numJugadores;
	nombre p[50];
	Pregunta preguntas[50];
	llenar_estructuras(preguntas);
	
	printf("BIENVENIDO A SCAPE OF WAR\n");
	do {
	printf("Introduce el numero de guerreros que vais a participar, el maximo son 4\n");
	scanf("%d",&numJugadores);
	printf("Has seleccionado %d jugadores",numJugadores);
	} while (numJugadores>4); // Si introduce un numero mayor de 4 jugadores, se lo vuelve a pedir al usuario

	while(n!=4){
		printf("-----------ELIJA QUE AVENTURA DESEA LLEVAR-----------\n");
		printf("[1] Para aquellos mortales que deseen una aventura \n");
		printf("[2] Para aventureros que buscan un desafio de nivel\n");
		printf("[3] Solo para aquellos mortales que buscan ser autenticos dioses\n (ADVERTENCIA!!!! No se admiten fallos, un solo error te llevara a perderlo todo)\n");
		printf("[4] Salir\n");
		scanf("%d", &n);
		
		system("cls");
		
		switch(n){
			case 1: nivel_mortal(preguntas);
			printf("Has elegido nivel mortal\n");
			break;
			case 2: nivel_heroe(preguntas);
			printf("Has elegido nivel heroe\n");
			break;
			case 3: nivel_dios(preguntas);
			printf("Has elegido nivel dios\n");
			break;
			case 4: 
			("Hasta pronto\n");
			break;			
		}
		
	}	
	return 0;
}

void llenar_estructuras(Pregunta* preguntas){
	
	FILE* fPointer;
	
	fPointer = fopen("desafios.txt","r");
	char linea[250];
	int i=0,j=5;
	
	while(!feof(fPointer)){
		
		j++;
		fgets(linea,250,fPointer);
		if(j%6==0){
			
		strcpy(preguntas[i].pregunta,linea);
		}else if(j%6==1){
			strcpy(preguntas[i].opcion1,linea);
		}else if(j%6==2){
			strcpy(preguntas[i].opcion2,linea);
		}else if(j%6==3){
			strcpy(preguntas[i].opcion3,linea);
		}else if(j%6==4){
			strcpy(preguntas[i].opcion4,linea);
		}else if(j%6==5){
			strcpy(preguntas[i].correcta,linea);
			i++;
		}
	}
	fclose(fPointer);
}


void nivel_mortal(Pregunta* preguntas){
	
	nombre p[50];
	int puntuacion = 0,i,numero_aleatorio;
	char eleccion[5];
	srand(time(NULL));		
	
	printf("Introduce tu nombre: ");
	scanf("%s", p[0].nombre);
	
	system("cls");
	
	printf("Pulse una tecla para comenzar");
	
	getch();
	
	system("cls");
	
	printf("COMIENZA EL DESAFIO\n\n");
	
	
	/*En esta parte se muestran las preguntas por pantalla y se le pide al usuario la soluci�n*/
	
		for(i = 0; i<10;i++){
		numero_aleatorio = rand() % 10+1;
		printf("%s\n",preguntas[numero_aleatorio].pregunta);
		printf("a) %s\n",preguntas[numero_aleatorio].opcion1);
		printf("b) %s\n",preguntas[numero_aleatorio].opcion2);
		printf("c) %s\n",preguntas[numero_aleatorio].opcion3);
		printf("d) %s\n",preguntas[numero_aleatorio].opcion4);
		
		/*Hacemos un do while para que solo se puedan introducir n�meros del 1 al 4*/
		do{
			printf("Introduce la opcion correcta -> ");
			scanf("%s",&eleccion);	
			if(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0){	
				printf("Debes introducir una opcion valida\n");
			}
		}while(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0);
		
		strcat(eleccion,"\n");
		
		
		if(strcmp(eleccion,preguntas[i].correcta)==0){
			puntuacion=puntuacion+100;
		}
		
		system("cls"); 
		
	}
	
	system("cls"); 
	if(puntuacion<500){
		printf("No es suficiente, sigue entenando para la proxima\n");
	}
	else (puntuacion>=500){
		printf("No esta mal para ser un mortal, prueba con el nivel heroe\n");
	}
	printf("%s, tu nivel en la aventura es: ", p[0].nombre);
	printf("%i \n", puntuacion);
    printf("Echale un ojo a las recompensas obtenidas\n");
    
    FILE * fPointer;
	fPointer = fopen("recompensasMortal.txt", "r");
	fclose(fPointer);
	
	printf("Pulse una tecla para elegir volver a jugar o salir");
	
	getch();
	
	system("cls"); 
}

void nivel_heroe(Pregunta* preguntas){
	
	nombre p[50];
	int puntuacion = 0,i,numero_aleatorio;
	char eleccion[5];
	srand(time(NULL));		
	
	printf("Introduce tu nombre: ");
	scanf("%s", p[0].nombre);
	
	system("cls");
	
	printf("Pulse una tecla para comenzar");
	
	getch();
	
	system("cls");
	
	printf("COMIENZA EL DESAFIO\n\n");
	
	
	/*En esta parte se muestran las preguntas por pantalla y se le pide al usuario la soluci�n*/
	
		for(i = 0; i<10;i++){
		numero_aleatorio = rand() % 10+1;
		printf("%s\n",preguntas[numero_aleatorio].pregunta);
		printf("a) %s\n",preguntas[numero_aleatorio].opcion1);
		printf("b) %s\n",preguntas[numero_aleatorio].opcion2);
		printf("c) %s\n",preguntas[numero_aleatorio].opcion3);
		printf("d) %s\n",preguntas[numero_aleatorio].opcion4);
		
		/*Hacemos un do while para que solo se puedan introducir n�meros del 1 al 4*/
		do{
			printf("Introduce la opcion correcta -> ");
			scanf("%s",&eleccion);	
			if(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0){	
				printf("Debes introducir una opcion valida\n");
			}
		}while(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0);
		
		strcat(eleccion,"\n");
		
		
		if(strcmp(eleccion,preguntas[i].correcta)==0){
			puntuacion=puntuacion+200;
		}
		else{
			puntuacion=puntuacion-50;
		}
		system("cls"); 
		
	}
	
	system("cls"); 
	if(puntuacion<1000){
		printf("No mereces llamarte heroe, vuelve a casa con tu madre");
	} 
	printf("%s, tu puntuacion es ", p[0].nombre);
	printf("%i \n", puntuacion);
	printf("Pulse una tecla para continuar");
	printf("Echale un ojo a las recompensas obtenidas\n");
    
    FILE * fPointer;
	fPointer = fopen("recompensasHeroe.txt", "r");
	fclose(fPointer);
	
	
	getch();
	
	system("cls"); 
}

void nivel_dios(Pregunta* preguntas){
	
	nombre p[50];
	int puntuacion = 0,i,numero_aleatorio;
	char eleccion[5];
	srand(time(NULL));		
	
	printf("Introduce tu nombre: ");
	scanf("%s", p[0].nombre);
	
	system("cls");
	
	printf("Pulse una tecla para comenzar");
	
	getch();
	
	system("cls");
	
	printf("COMIENZA EL DESAFIO\n\n");
	
	
	/*En esta parte se muestran las preguntas por pantalla y se le pide al usuario la soluci�n*/
	
		for(i = 0; i<10;i++){
		numero_aleatorio = rand() % 10+1;
		printf("%s\n",preguntas[numero_aleatorio].pregunta);
		printf("a) %s\n",preguntas[numero_aleatorio].opcion1);
		printf("b) %s\n",preguntas[numero_aleatorio].opcion2);
		printf("c) %s\n",preguntas[numero_aleatorio].opcion3);
		printf("d) %s\n",preguntas[numero_aleatorio].opcion4);
		
		/*Hacemos un do while para que solo se puedan introducir números del 1 al 4*/
		do{
			printf("Introduce la opcion correcta -> ");
			scanf("%s",&eleccion);	
			if(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0){	
				printf("Debes introducir una opcion valida\n");
			}
		}while(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0);
		
		strcat(eleccion,"\n");
		
		
		if(strcmp(eleccion,preguntas[i].correcta)==0){
			puntuacion=puntuacion+300;
		}
		
		system("cls"); 
		
	}
	
	system("cls"); 
	if(puntuacion==3000){
		printf("Enhorabuena, has logrado superar el desafio de los dioses\n");
		printf("%s, tu nivel de dios es de", p[0].nombre);
	    printf("%i \n", puntuacion);
	} 
	else{
		puntuacion=0;
		printf("No mereces estar entre nosotros, sigues siendo un mortal\n GAME OVER\n");
		printf("%s, tu puntuacion es ", p[0].nombre);
	    printf("%i \n", puntuacion);
	}
	printf("Pulse una tecla para continuar");
	
	printf("Echale un ojo a las recompensas obtenidas\n");
    
    FILE * fPointer;
	fPointer = fopen("recompensasDios.txt", "r");
	fclose(fPointer);
	
	getch();
	
	system("cls"); 
}
