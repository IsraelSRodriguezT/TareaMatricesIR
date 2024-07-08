#include <stdio.h>
#include <math.h>
void bucleOri(int filas, int columnas, int matriz[filas][columnas], int poten){
    printf("Matriz Original:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matriz[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        if(i==0){
            printf("  ^ %d ", poten ); // Indico la potencia de la matriz
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
void bucle(int filas, int columnas, int matriz[filas][columnas], int poten){
    int matrizResul[filas][columnas]; //Defino variables la cual guardaran la multiplicacion de las matrices
    int matrizaux[filas][columnas];
    if(poten==0){
        for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
            for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                if(i==j){ //Para guardar los valores de la matriz identidad
                    matrizResul[i][j]=1; //Para el caso de que si se cumple la condicion, que se guarde el 1
                } else{
                    matrizResul[i][j]=0; //Para el caso de que no se cumpla la condicion, que se guarde el 0
                }
            }
        }
    } else{
        for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
            for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                matrizResul[i][j]=matriz[i][j]; //Asigno los valores de la matriz original para asi empezar con los calculos
            }
        }
        for(int h=1;h<poten;h++){ //Bucle for para repetir cuantas veces indique la potencia
            for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
                for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                    matrizaux[i][j]=0; //Asigno 0 para asi darle valores a la matriz
                }
            }
            for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
                for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz resultante en que posicion de columna debe de estar
                    for(int k=0;k<columnas;k++){ //Bucle for para indicarle a las matrices 1 y 2 en que posicion de columna debe de estar
                        matrizaux[i][j]+=(matrizResul[i][k])*(matriz[k][j]); //Para asignar la multiplicacion en cada posicion
                    }
                }
            }
            for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
                for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                    matrizResul[i][j]=matrizaux[i][j]; //Asigno los valores que obtuvo la matriz aux para en caso de que se repita el calculo
                }
            }
        }
    }
    printf("Matriz Resultante:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matrizResul[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
int main(){
    printf("Bienvenido al programa para realizar la potencia de una matriz (La matriz debe de ser cuadrada) \n");
    int nfilas, ncolumnas, poten; //Defino variables
    printf("Establezca el numero de filas que va a poseer su matriz: "); //Para indicar que se ingrese el numero de filas de la matriz
    scanf("%d", &nfilas);
    if(nfilas<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    printf("Establezca el numero de columnas que va a poseer su matriz: "); //Para indicar que se ingrese el numero de columnas de la matriz
    scanf("%d", &ncolumnas);
    if(ncolumnas<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    if(nfilas!=ncolumnas){ //Para comprobar si la matriz es cuadrada
        printf("Error: La Matriz no es cuadrada.\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    printf("Establece el numero al que va a ser elevado la matriz: "); //Para indicar que se ingrese la potencia de la matriz
    scanf("%d", &poten);
    if(poten<0){ //Para comprobar si el valor ingresado es correcto para el programa
        printf("Error: No se puede calcular la matriz elevada a la potencia de un numero negativo por el momento");
        return 1; //Para que se termine de ejecutar el programa
    }
    int matriz[nfilas][ncolumnas]; //Defino la matriz a usar
    for(int i=0;i<nfilas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba un valor a ingresar en la Matriz [%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la matriz*/
            scanf("%d", &matriz[i][j]);
        }
    }
    bucleOri(nfilas,ncolumnas,matriz, poten); //Para llamar al procedimiento que imprime las matriz original
    bucle(nfilas, ncolumnas, matriz, poten); //Para llamar al procedimiento que imprime la matriz resultante
    return 0;
}