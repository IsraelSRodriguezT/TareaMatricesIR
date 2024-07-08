#include <stdio.h>
#include <math.h>
void bucleOri(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]){ //Procedimiento para imprimir las matrices ingresadas
    printf("Matrices Originales:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matriz1[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        if(i==0){
            printf("  /  "); // Espacio entre las dos matrices
        } else{
            printf("     ");
        }
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz2 en que posicion de columna debe de estar
            printf(" %d |", matriz2[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
void bucle(int filas1, int columnas1, int columnas2, int matriz1[filas1][columnas1], float matrizIdn[columnas1][columnas2]){
    float matrizResul[filas1][columnas2]; //Defino variable la cual guardara la multiplicacion de las matrices
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            matrizResul[i][j]=0; //Asigno 0 para asi darle valores a la matriz
        }
    }
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz2 en que posicion de fila debe de estar
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz resultante en que posicion de columna debe de estar
            for(int k=0;k<columnas1;k++){ //Bucle for para indicarle a las matrices 1 y 2 en que posicion de columna debe de estar
                matrizResul[i][j]+=matriz1[i][k]*matrizIdn[k][j]; //Para asignar el resultado en cada posicion
            }
        }
    }
    printf("Matriz Resultante:\n");
    for(int i=0;i<filas1;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %.2f |", matrizResul[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
int main(){
    printf("Bienvenido al programa para dividir matrices (las matrices deben de ser cuadradas y del mismo tamanio)\n");
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
    if(nfilas1!=ncolumnas1){ //Para comprobar si la matriz es cuadrada
        printf("Error: La 1era Matriz no es cuadrada.\n");
        return 1;
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
    if(nfilas2!=ncolumnas2){
        printf("Error: La 2nda Matriz no es cuadrada.\n");
        return 1;
    }
    if(nfilas1!=nfilas2){
        printf("Error: La 2nda Matriz no es de la misma dimension que la 1era matriz.\n");
        return 1;
    }
    int matriz1[nfilas1][ncolumnas1]; //Defino la matriz a usar
    for (int i = 0; i < nfilas1; i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for (int j = 0; j < ncolumnas1; j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar en la 1era matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 1era matriz*/
            scanf("%d", &matriz1[i][j]); 
        }
    }
    int matriz2[nfilas2][ncolumnas2];  //Defino la matriz a usar
    for (int i = 0; i < nfilas2; i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for (int j = 0; j < ncolumnas2; j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar en la 2nda matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 2nda matriz*/ 
            scanf("%d", &matriz2[i][j]);
        }
    } 
    float matrizIdn[nfilas2][ncolumnas2]; //Defiino la matriz identidad
    float matrizAux[nfilas2][ncolumnas2]; //Defino una matriz para guardar los valores de la matriz original
    for(int i=0;i<nfilas2;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(i==j){ //Para guardar los valores de la matriz identidad
                matrizIdn[i][j]=1; //Para el caso de que si se cumple la condicion, que se guarde el 1
            } else{
                matrizIdn[i][j]=0; //Para el caso de que no se cumpla la condicion, que se guarde el 0
            }
            matrizAux[i][j]=matriz2[i][j]; //Para guardar los valores de la matriz original en una matriz auxiliar
        }
    }
    for(int i=0;i<nfilas2;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        float divisor=matrizAux[i][i]; //Defino variable que ayudara a convertir el valor en 1
        for(int j=0;j<ncolumnas1;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            matrizAux[i][j]/=divisor; //Para dividir todos los valores de la fila y guardarlos
            matrizIdn[i][j]/=divisor; //Para dividir todos los valores de la fila y guardarlos
        }
        for(int k=0;k<nfilas2;k++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(i!=k){ //Para ejecutar los calculos en las posiciones que esten fuera de la diagonal principal
                float factor=matrizAux[k][i]; //Defino variable que guardara el valor corrspondiente a la posicion contraria definida por los bucles 
                for(int j=0;j<ncolumnas1;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                    matrizAux[k][j]-=factor*matrizAux[i][j]; /*Para la matriz restarle el factor multiplicado por la propia matriz de 
                    posicion contraria y guardarlo*/
                    matrizIdn[k][j]-=factor*matrizIdn[i][j]; /*Para la matriz restarle el factor multiplicado por la propia matriz de 
                    posicion contraria y guardarlo*/
                }
            }
        }
    }
    bucleOri(nfilas1, ncolumnas1, matriz1, matriz2);
    for(int i=0;i<nfilas2;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        int error; //Defino variable que ayuda a indicar el mensaje de error
        for(int j=0;j<ncolumnas2;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(!isinf(matrizIdn[i][j])){ //Para comprobar si la matriz resultante tiene inversa
            } else{
                error=1; //Para asignarle el valor que me permitira comprobar en una condicion if
                j=(ncolumnas2-1); //Para que se termine de ejecutar el bucle j
                i=(nfilas2-1); //Para que se termine de ejecutar el bucle i
            }
        }
        if(error==1){ //Para indicar que accion realizar ante un posible error o no
            printf("Error: La 2nda matriz ingresada no posee inversa\n");
            return 1;
        }
    }
    bucle(nfilas1, ncolumnas1, ncolumnas2, matriz1, matrizIdn);
    return 0;
}
