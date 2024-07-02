#include <stdio.h>
#include <math.h>
void bucleOri(int filas, int columnas, int matriz[filas][columnas]){ //Procedimiento para imprimir la matriz ingresada
    printf("Matriz Original:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matriz[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
void bucleinversa(int filas, int columnas, int matriz[filas][columnas]){ //Procedimiento para imprimir la matriz resultante
    float matrizIdn[filas][columnas]; //Defiino la matriz identidad
    float matrizAux[filas][columnas]; //Defino una matriz para guardar los valores de la matriz original
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(i==j){ //Para guardar los valores de la matriz identidad
                matrizIdn[i][j]=1; //Para el caso de que si se cumple la condicion, que se guarde el 1
            } else{
                matrizIdn[i][j]=0; //Para el caso de que no se cumpla la condicion, que se guarde el 0
            }
            matrizAux[i][j]=matriz[i][j]; //Para guardar los valores de la matriz original en una matriz auxiliar
        }
    }
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        float divisor=matrizAux[i][i]; //Defino variable que ayudara a convertir el valor en 1
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            matrizAux[i][j]/=divisor; //Para dividir todos los valores de la fila y guardarlos
            matrizIdn[i][j]/=divisor; //Para dividir todos los valores de la fila y guardarlos
        }
        for(int k=0;k<filas;k++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(i!=k){ //Para ejecutar los calculos en las posiciones que esten fuera de la diagonal principal
                float factor=matrizAux[k][i]; //Defino variable que guardara el valor corrspondiente a la posicion contraria definida por los bucles 
                for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
                    matrizAux[k][j]-=factor*matrizAux[i][j]; /*Para la matriz restarle el factor multiplicado por la propia matriz de 
                    posicion contraria y guardarlo*/
                    matrizIdn[k][j]-=factor*matrizIdn[i][j]; /*Para la matriz restarle el factor multiplicado por la propia matriz de 
                    posicion contraria y guardarlo*/
                }
            }
        }
    }
    printf("Matriz inversa:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        int error; //Defino variable que ayuda a indicar el mensaje de error
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(!isinf(matrizIdn[i][j])){ //Para comprobar si la matriz resultante tiene inversa
                printf(" %.2f |", matrizIdn[i][j]); //Para imprimir cada valor en la posicion adecuada
            } else{
                error=1; //Para asignarle el valor que me permitira comprobar en una condicion if
                j=(columnas-1); //Para que se termine de ejecutar el bucle j
                i=(filas-1); //Para que se termine de ejecutar el bucle i
            }
        }
        if(error==1){ //Para indicar que accion realizar ante un posible error o no
            printf("Error: La matriz ingresada no posee inversa\n");
        } else{
            printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
        }
    }
}
int main(){
    printf("Bienvenido al programa para imprimir la inversa de una matriz (la matriz debe de ser cuadrada)\n");
    int nfilas, ncolumnas; //Defino variables
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
    int matriz[nfilas][ncolumnas]; //Defino la matriz a usar
    for(int i=0;i<nfilas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar [%d][%d]: ", i, j); //Para indicar que se ingresen los valores correspondientes a la matriz
            scanf("%d", &matriz[i][j]);
        }
    } 
    bucleOri(nfilas,ncolumnas,matriz); //Para llamar al procedimiento que imprime la matriz original
    if(nfilas==ncolumnas){ //Para comprobar si la matriz ingresada es cuadrada
        bucleinversa(nfilas, ncolumnas, matriz); //Si se cumple la condicion, que se llame al procedimiento que imprime la matriz resultante
    } else{
        printf("Error: La matriz ingresada no es cuadrada\n"); //Si no se cumple la condicion, que se indique que la matriz no es cuadrada
    }
    return 0;
}