#include <stdio.h>
void bucleOri(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]){ //Procedimiento para imprimir las matrices ingresadas
    printf("Matrices Originales:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matriz1[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("  *  "); // Espacio entre las dos matrices
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz2 en que posicion de columna debe de estar
            printf(" %d |", matriz2[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
void bucle(int filas1, int columnas1, int columnas2, int matriz1[filas1][columnas1], int matriz2[columnas1][columnas2]){
    int matrizResul[filas1][columnas2]; //Defino variable la cual guardara la multiplicacion de las matrices
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            matrizResul[i][j]=0; //Asigno 0 para asi darle valores a la matriz
        }
    }
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz resultante en que posicion de columna debe de estar
            for(int k=0;k<columnas1;k++){ //Bucle for para indicarle a las matrices 1 y 2 en que posicion de columna debe de estar
                matrizResul[i][j]+=matriz1[i][k]*matriz2[k][j]; //Para asignar la multiplicacion en cada posicion
            }
        }
    }
    printf("Matriz Resultante:\n");
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matrizResul[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
int main() {
    printf("Bienvenido al programa para multiplicar matrices\n");
    int nfilas1, ncolumnas1, nfilas2, ncolumnas2; //Defino variables
    printf("Establezca el numero de filas de la 1era Matriz: "); //Para indicar que se ingrese el numero de filas de la matriz1
    scanf("%d", &nfilas1);
    if(nfilas1<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    printf("Establezca el numero de columnas de la 1era Matriz: "); //Para indicar que se ingrese el numero de columnas de la matriz1
    scanf("%d", &ncolumnas1);
    if(ncolumnas1<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    printf("Establezca el numero de filas de la 2nda Matriz: "); //Para indicar que se ingrese el numero de filas de la matriz2
    scanf("%d", &nfilas2);
    if(nfilas2<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    printf("Establezca el numero de columnas de la 2nda Matriz: "); //Para indicar que se ingrese el numero de columnas de la matriz2
    scanf("%d", &ncolumnas2);
    if(ncolumnas2<=0){ //Para comprobar si el numero ingresado es un numero contable
        printf("Error: Se ha ingresado un valor que no corresponde al conjunto de numeros naturales\n");
        return 1; //Para que se termine de ejecutar el programa
    }
    if(ncolumnas1!=nfilas2){ //Para comprobar si se pueden multiplicar las matrices ingresadas
        printf("Error: El numero de columnas de la 1era Matriz no es igual al numero de filas de la 2nda Matriz\n");
        return 1;
    }
    int matriz1[nfilas1][ncolumnas1]; //Defino la matriz a usar
    for(int i=0;i<nfilas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas1;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar en la 1era matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 1era matriz*/
            scanf("%d", &matriz1[i][j]);
        }
    }
    int matriz2[nfilas2][ncolumnas2]; //Defino la matriz a usar
    for(int i=0;i<nfilas2;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar en la 2nda matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 2nda matriz*/
            scanf("%d", &matriz2[i][j]);
        }
    }
    bucleOri(nfilas1, ncolumnas1, matriz1, matriz2); //Para llamar al procedimiento que imprime las matrices originales
    bucle(nfilas1, ncolumnas1, ncolumnas2, matriz1, matriz2); //Para llamar al procedimiento que imprime la matriz resultante
    return 0;
}
