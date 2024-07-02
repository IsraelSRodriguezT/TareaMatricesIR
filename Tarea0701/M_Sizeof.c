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
void szof(int filas, int columnas, int matriz[filas][columnas]){ //Procedimiento para imprimir el tamaño de la matriz ingresada
    int BytesTotales=filas*columnas*sizeof(matriz[0][0]); /*Defino variable que guardara la multiplicacion del total de elementos 
    de la matriz con el tamaÑo en bytes de un elemento de la matriz*/
    int BytesFila=columnas*sizeof(matriz[0][0]); /*Defino variable que guardara la multiplicacion del total de elementos 
    en una fila con el tamaÑo en bytes de un elemento de la matriz*/
    int Bytes1Elemento=sizeof(matriz[0][0]); //Defino variable que guardara el tamaÑo en bytes de un elemento de la matriz
    int filasSzof=BytesTotales/BytesFila; //Defino variable donde se guardara el numero de filas de la matriz
    int columnasSzof=BytesFila/Bytes1Elemento; //Defino variable donde se guardara el numero de columnas de la matriz
    printf("Matriz:[%d][%d]\n", filasSzof, columnasSzof); //Para imprimir el tamaño de la matriz
}
int main(){
    printf("Bienvenido al programa para imprimir el numero de filas y columnas de una matriz con sizeof\n"); 
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
    szof(nfilas, ncolumnas, matriz); //Para llamar al procedimiento que imprime la matriz resultante
    return 0;
}