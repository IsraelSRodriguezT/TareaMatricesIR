#include <stdio.h>
#include <string.h>
int main(){
    printf("Programa para presentar de manera ordenada las cartas que presenta la baraja\n");
    char *cnjBr[4][13]={ //Defino matriz que me permite saber como estan ordenadas las cartas de una baraja 
        {"AE", "2E", "3E", "4E", "5E", "6E", "7E", "8E", "9E", "10E", "JE", "QE", "KE"},
        {"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"},
        {"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD"},
        {"AT", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T", "10T", "JT", "QT", "KT"}
    };
    int cnjcrt; //Defino variable que me permitira saber cuantas cartas se desean ordenar
    printf("Ingresa el valor de cuantas cartas quieres ingresar\n");
    int compr=scanf("%d", &cnjcrt); //leo el numero y defino variable en caso de haber un error
    if(cnjcrt<= 0||cnjcrt>52){ //Establezco el minimo y maximo que puede tener la baraja
        printf("Error: Numero de cartas invalido\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    if(compr==0){ //Para comprobar si el valor ingresado es numerico
        printf("Error: El valor ingresado no es valido");
        return 1; //Para que se termine de ejecutar el programa
    }
    char cartas[cnjcrt][4]; //Defino arreglo que me permitira guardar las cartas que ingrese el usuario
    printf("Ingresa las cartas que deseas ordenar, de la siguiente manera:\n");
    printf("Para las picas agrega al final de cada valor la 'E' en mayuscula.      Ej: AE , JE\n");
    printf("Para los corazones agrega al final de cada valor la 'C' en mayuscula.  Ej: 5C , 10C\n");
    printf("Para los diamantes agrega al final de cada valor la 'D' en mayuscula.  Ej: 8D , KD\n");
    printf("Y para los treboles agrega al final de cada valor la 'T' en mayuscula. Ej: QT , 4T\n");
    for(int i=0;i<cnjcrt;i++){ //Bucle for para ingresar la cantidad de cartas necesarias
        scanf(" %s", &cartas[i]);
    }
    printf("Cartas ingresadas: ");
    for(int j=0;j<cnjcrt;j++){ //Bucle for para indicar al usuario las cartas que fueron ingresadas
        printf("%s,", cartas[j]);
    }
    printf("\n");
    char cartasOrd[cnjcrt][4]; //Defino arreglo que me permitira guardar ordenadamente las cartas que ingreso el usuario
    int aux=0; //Defino variable que me permitira guardar en orden en el arreglo
    for(int i=0;i<4;i++){ //Bucle for para ir desplazandose por cada grupo de cartas
        for(int j=0;j<13;j++){ //Bucle for para ir desplazandose por cada carta
            for(int k=0;k<cnjcrt;k++){ //Bucle for para ir desplazandose por cada carta ingresada por el usuario
                if(strcmp(cartas[k],cnjBr[i][j])==0){ /*Condicion que me permite saber y comprobar si alguna carta de las ingresadas 
                coincide con el orden establecido de las cartas*/
                    strcpy(cartasOrd[aux],cartas[k]); //Funcion que me permite copiar los caracteres en el arreglo ordenado
                    aux++; //Para ir pasando de posicion en el arreglo ordenado
                }
            }
        }
    }
    printf("Cartas ordenadas: ");
    for(int j=0;j<cnjcrt;j++){ //Bucle for para indicar las cartas ya de manera ordenada
        printf("%s,", cartasOrd[j]);
    } 
    return 0;
}
