#include <stdio.h>
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
void bucle(int filas, int columnas, int matriz[filas][columnas]){ //Procedimiento para imprimir la matriz resultante
    printf("Matriz resultante:\n");
    int sim; //Defino variable que ayudara a comprobar si la matriz es simetrica o no
    for(int i=0;i<columnas;i++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<filas;j++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar   
            if((matriz[i][j])!=(matriz[j][i])){ //Para comprobar si las matrices son diferentes
                sim=0; //Para el caso de que si se cumple la condicion, que se guarde el 0
                j=(columnas-1); //Para que se termine de ejecutar el bucle j
                i=(filas-1); //Para que se termine de ejecutar el bucle i
            } else if((matriz[i][j])==(matriz[j][i])){ //Para comprobar si las matrices son iguales
                sim=1; //Para el caso de que si se cumple la condicion, que se guarde el 1
                printf(" %d |", matriz[j][i]); 
            }
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
    if(sim==0){ //Para comprobar que mensaje presentar
        printf("Error: La matriz no es simetrica\n"); //Para el caso de que si se cumple la condicion, que se imprima que no es simetrica
    } else if (sim==1){ 
        printf("La matriz si es simetrica\n"); //Para el caso de que si se cumple la condicion, que se imprima que es simetrica
    }
}
int main(){
    printf("Bienvenido al programa para imprimir la matriz simetrica de una matriz (la matriz debe de ser cuadrada)\n"); 
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
        bucle(nfilas, ncolumnas, matriz); //Si se cumple la condicion, que se llame al procedimiento que imprime la matriz resultante
    } else{
        printf("Error: La matriz ingresada no es cuadrada\n"); //Si no se cumple la condicion, que se indique que la matriz no es cuadrada
    }
    return 0;
}