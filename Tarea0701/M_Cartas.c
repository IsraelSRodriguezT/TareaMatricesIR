#include <stdio.h>
#include <string.h>
int main(){
    printf("Programa para presentar de manera ordenada las cartas que presenta la baraja\n");
    char *cnjBr[4][13]={ //Defino matriz que me permite saber como estan ordenadas las cartas de una baraja 
        {"AE", "2E", "3E", "4E", "5E", "6E", "7E", "8E", "9E", "10E", "JE", "QE", "KE"}, //Espadas
        {"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"}, //Corazones
        {"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD"}, //Diamantes
        {"AT", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T", "10T", "JT", "QT", "KT"}  //Treboles
    };
    char *cartas[4][13]={ //Defino matriz donde la baraja este desordenada 
        {"5E", "7T", "3E", "6E", "8E", "JE", "4E", "9E", "2D", "10C", "KE", "AT", "QD"},
        {"9C", "2T", "JC", "8C", "3T", "KC", "AD", "6C", "7D", "QC", "4C", "10E", "5C"},
        {"AE", "KD", "4D", "10T", "7E", "QT", "8D", "5D", "3C", "2C", "6D", "9D", "JD"},
        {"8T", "AC", "3D", "QE", "5T", "9T", "7C", "10D", "6T", "JT", "2E", "4T", "KT"}
    };
    printf("Baraja presentada aleatoriamente:\n");
    for(int i=0;i<4;i++){ //Bucle for para indicar al usuario como se encuentra desordenada la baraja
        for(int j=0;j<13;j++){ 
            printf("%s,", cartas[i][j]);
        }
        printf("\n");
    }
    char *cartasOrd[4][13]; //Defino arreglo que me permitira guardar ordenadamente las cartas que ingreso el usuario
    for(int i=0;i<4;i++){ //Bucle for para ir desplazandose por cada grupo de cartas
        for(int j=0;j<13;j++){ //Bucle for para ir desplazandose por cada carta
            for(int k=0;k<4;k++){ //Bucle for para ir desplazandose por cada carta ingresada por el usuario
                for(int l=0;l<13;l++){
                    if(strcmp(cartas[k][l],cnjBr[i][j])==0){ /*Condicion que me permite saber y comprobar si alguna carta de las ingresadas 
                    coincide con el orden establecido de las cartas*/
                    cartasOrd[i][j]=cartas[k][l]; //Para copiar los caracteres en el arreglo ordenado
                    }
                }
            }
        }
    }
    printf("Baraja ordenada:\n");
    for(int i=0;i<4;i++){ //Bucle for para indicar al usuario la baraja ya ordenada
        for(int j=0;j<13;j++){ 
            printf("%s,", cartasOrd[i][j]);
        }
        printf("\n");
    }
    return 0;
}   