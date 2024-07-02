#include <stdio.h>
#include <math.h>
void bucleOri(int filas, int columnas, int matriz[filas][columnas], int matriz2[filas][columnas]){
    printf("Matrices Originales:\n");
    for(int i=0;i<filas;i++){
        printf("|");
        for(int j=0;j<columnas;j++){    
            printf(" %d |", matriz[i][j]); 
        }
        printf("  ^  "); // Espacio entre las dos matrices
        printf("|");
        for(int j=0;j<columnas;j++){
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }
}
void bucle(int filas, int columnas, int matriz[filas][columnas], int matriz2[filas][columnas]){
    int matrizResul[filas][columnas];
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){    
            matrizResul[i][j]=pow((matriz[i][j]),(matriz2[i][j]));
        }
    }
    printf("Matriz resultante:\n");
    for(int i=0;i<filas;i++){
        printf("|");
        for(int j=0;j<columnas;j++){    
            printf(" %d |", matrizResul[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Bienvenido al programa para realizar la potencia de matrices (Las matrices van a ser del mismo tamanio)\n");
    int nfilas, ncolumnas;
    printf("Establezca el numero de filas que va a poseer su matriz: ");
    scanf("%d", &nfilas);
    printf("Establezca el numero de columnas que va a poseer su matriz: ");
    scanf("%d", &ncolumnas);
    int matriz[nfilas][ncolumnas];
    for(int i=0;i<nfilas;i++){
        for(int j=0;j<ncolumnas;j++){
            printf("Escriba un valor a ingresar en la 1era Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    int matriz2[nfilas][ncolumnas];
    for(int i=0;i<nfilas;i++){
        for(int j=0;j<ncolumnas;j++){
            printf("Escriba un valor a ingresar en la 2nda Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
    bucleOri(nfilas,ncolumnas,matriz,matriz2);
    bucle(nfilas, ncolumnas, matriz, matriz2);
    return 0;
}