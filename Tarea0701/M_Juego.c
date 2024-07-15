#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void barajarandom(int jugador ,int cartas[13],int *creditos, int *creditosmesa){
    srand(time(NULL)); //Para generar numeros aleatorios
    printf("Creditos J%d: %d       Creditos en mesa: %d\n", jugador, *creditos, *creditosmesa);
    int carta1=rand()%13; //Para obtener una primera carta aleatoria entre el rango de valores
    int carta2=rand()%13; //Para obtener una segunda carta aleatoria entre el rango de valores
    if(cartas[carta1]>cartas[carta2]){ //Para ordenar las cartas en caso de que la primera carta sea de un valor mayor
        int cambio=carta1;
        carta1=carta2;
        carta2=cambio;
    }
    printf("|%d|   <->   |%d|", cartas[carta1], cartas[carta2]); //Indico las cartas aleatorias
    int apuesta, aux; //Defino variables para el apartado de apuesta
    printf(" <-- Cuantos creditos quieres apostar?: ");
    do{ //Bucle para el valor de apuesta
        scanf("%d", &apuesta); //Leo el valor que desea apostar el usuario
        if(apuesta<=*creditos&&apuesta<=*creditosmesa&&apuesta>=1){ //Para comprobar que el valor de apuesta sea correcta
            aux=0;
        } else{
            aux=1;
            printf("Error: Tu apuesta no se encuentra dentro del rango de creditos que posees\nIngresa nuevamente lo que deseas apostar: ");
        }
    } while(aux==1);
    int cartaint=rand()%12; //Para obtener una tercera carta aleatoria entre el rango de valores
    printf("      |%d|     ", cartas[cartaint]); //Indico la tercera carta al usuario
    if(cartaint>carta1&&cartaint<carta2){ //Para comprobar los creditos a sumar o restar del usuario y a la mesa
        *creditos+=apuesta;
        *creditosmesa-=apuesta;
    } else if((cartaint==carta1||cartaint==carta2)&&*creditos>=(apuesta*2)){
        *creditos-=(apuesta*2);
        *creditosmesa+=(apuesta*2);
    } else{
        *creditos-=apuesta;
        *creditosmesa+=apuesta;
    }
    printf("      Creditos actuales: %d\n", *creditos); //Indico los creditos con los que se quedo el usuario
    printf("-----------------------------------------------------------\n");
}
int main(){
    printf("Programa para jugar carta intermedia entre dos personas\nReglas:\n");
    printf("1 -> Se utilizara una baraja de cartas normal. (Teniendo comprendido los valores habituales del 1 al 13)\n");
    printf("2 -> Cada jugador debe poner una apuesta inicial en la mesa. (En este caso la apuesta definida es de 1 credito)\n");
    printf("3 -> Se procede a repartir dos cartas en la mesa. (Durante el turno de cada jugador)\n");
    printf("4 -> El jugador que se encuentre en el presente turno debera apostar una cantidad de creditos.\n");
    printf("5 -> La apuesta debera ser de minimo 1 credito, ademas no puede superar la cantidad de creditos presentes en mesa.\n");
    printf("6 -> Se procede a repartir una tercera carta en mesa.\n");
    printf("7 -> Si la tercera carta esta dentro del intervalo de las dos primeras cartas el jugador ganara lo que aposto.\n");
    printf("8 -> Si la tercera carta no esta dentro del intervalo de las dos primeras cartas el jugador perdera lo que aposto.\n");
    printf("9 -> Si la tercera carta es igual a una de las dos primeras cartas el jugador perdera el doble de lo que aposto.\n");
    printf("10 -> Si se acaban los creditos en mesa, los jugadores deberan devolver la apuesta inicial. (1 credito)\n");
    printf("11 -> El juego acabara cuando uno de los jugadores se quede sin creditos.\n");
    printf("-----------------------------------------------------------\n");
    int cartas[13]={1,2,3,4,5,6,7,8,9,10,11,12,13}; //Defino array donde guarda todos los valores posibles de cartas.
    int creditos1=9; //Defino los creditos para cada jugador
    int creditos2=9;
    int creditosmesa=2; //Defino los creditos en mesa
    do{ //Bucle para que se repita el juego hasta que alguien se quede sin creditos
        if(creditos1!=0&&creditos2!=0){ //Para comprobar cuando algun jugador tenga 0 creditos
            barajarandom(1,cartas,&creditos1,&creditosmesa); //Para llamar a la funcion
            if(creditosmesa==0){ //Para cuando los creditos en mesa se queden en 0
                creditosmesa=2;
                creditos1-=1;
                creditos2-=1;
            }
        }
        if(creditos1!=0&&creditos2!=0){ //Para comprobar cuando algun jugador tenga 0 creditos
            barajarandom(2,cartas,&creditos2,&creditosmesa); //Para llamar a la funcion
            if(creditosmesa==0){ //Para cuando los creditos en mesa se queden en 0
                creditosmesa=2;
                creditos1-=1;
                creditos2-=1;
            } 
        }
    } while(creditos1!=0&&creditos2!=0); //Condicion para que se repitan mientras sean diferente de 0
    if(creditos1==0){
        printf("El Jugador 2 gano el juego");
    } else if(creditos2==0){
        printf("El jugador 1 gano el juego");
    }
    return 1;
}