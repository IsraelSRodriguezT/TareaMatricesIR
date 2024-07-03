#include <stdio.h>
void decahex(int n) {
    int resvdec, i; //Defino variables
    char cnjHex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //Array de Hexadecimal
    char vhex[100]; // Array para almacenar los caracteres hexadecimales
    for(i=0;n>0;i++){ //Bucle for para realizar divisiones sucesivas
        resvdec=n%16; //Para guardar el residuo
        n/=16; //Para dividirlo
        vhex[i]=cnjHex[resvdec]; // Almacena el caracter hexadecimal correspondiente
    }
    for(int j=i-1;j>=0;j--) { //Bucle para imprimir los caracteres en hexadecimal 
        printf("%c", vhex[j]);
    }
}
void bucleOri(int filas, int columnas, int matriz[filas][columnas], int matriz2[filas][columnas]){ //Procedimiento para imprimir las matrices ingresadas
    printf("Matrices Originales:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matriz[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("  +  "); // Espacio entre las dos matrices
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz2 en que posicion de columna debe de estar
            printf(" %d |", matriz2[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
void bucle(int filas, int columnas, int matriz[filas][columnas], int matriz2[filas][columnas]){ //Procedimiento para imprimir la matriz resultante
    int matrizResul[filas][columnas]; //Defino variable la cual guardara la suma de las matrices
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            matrizResul[i][j]=(matriz[i][j])+(matriz2[i][j]); //Para asignar la suma en cada posicion
        }
    }
    printf("Matriz resultante:     Matriz resultante en Hexadecimal:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf(" %d |", matrizResul[i][j]); //Para imprimir cada valor en la posicion adecuada
        }
        printf("      ->      "); // Espacio entre las dos matrices
        printf("| "); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz2 en que posicion de columna debe de estar
            decahex(matrizResul[i][j]);
            printf(" | "); //Para imprimir cada valor en la posicion adecuada
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
int main(){
    printf("Bienvenido al programa para sumar matrices (Las matrices van a ser del mismo tamanio)\n");
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
            printf("Escriba el valor a ingresar en la 1era matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 1era matriz*/
            scanf("%d", &matriz[i][j]);
        }
    }
    int matriz2[nfilas][ncolumnas]; //Defino la matriz2 a usar
    for(int i=0;i<nfilas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        for(int j=0;j<ncolumnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            printf("Escriba el valor a ingresar en la 2nda matriz[%d][%d]: ", i, j); /*Para indicar que se ingresen los valores 
            correspondientes a la 2nda matriz*/
            scanf("%d", &matriz2[i][j]);
        }
    }
    bucleOri(nfilas,ncolumnas,matriz,matriz2); //Para llamar al procedimiento que imprime las matrices originales
    bucle(nfilas, ncolumnas, matriz, matriz2); //Para llamar al procedimiento que imprime la matriz resultante
    return 0;
}