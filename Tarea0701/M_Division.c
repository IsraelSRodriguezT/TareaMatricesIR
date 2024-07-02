#include <stdio.h>
void bucleOri(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]){
    printf("Matrices Originales:\n");
    for(int i=0;i<filas;i++){
        printf("|");
        for(int j=0;j<columnas;j++){
            printf(" %d |", matriz1[i][j]);
        }
        printf("  /  ");
        printf("|");
        for(int j=0;j<columnas;j++){
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }
}
void bucle(int filas1, int columnas1, int columnas2, int matriz1[filas1][columnas1], float matrizIdn[columnas1][columnas2]){
    int matrizResul[filas1][columnas2];
    for(int i=0;i<filas1;i++){
        for(int j=0;j<columnas2;j++){
            matrizResul[i][j]=0;
        }
    }
    for(int i=0;i<filas1;i++){
        for(int j=0;j<columnas2;j++){
            for(int k=0;k<columnas1;k++){
                matrizResul[i][j]+=matriz1[i][k]*matrizIdn[k][j];
            }
        }
    }
    printf("Matriz Resultante:\n");
    for(int i=0;i<filas1;i++){
        printf("|");
        for(int j=0;j<columnas2;j++){
            printf(" %d |", matrizResul[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Bienvenido al programa para dividir matrices (las matrices deben de ser cuadradas y del mismo tamanio)\n");
    int filas1, columnas1, filas2, columnas2;
    printf("Establezca el numero de filas de la 1era Matriz: ");
    scanf("%d", &filas1);
    printf("Establezca el numero de columnas de la 1era Matriz: ");
    scanf("%d", &columnas1);
    if (filas1 != columnas1) {
        printf("Error: La 1era Matriz no es cuadrada.\n");
        return 1;
    }
    printf("Establezca el numero de filas de la 2nda Matriz: ");
    scanf("%d", &filas2);
    printf("Establezca el numero de columnas de la 2nda Matriz: ");
    scanf("%d", &columnas2);
    if (filas2 != columnas2){
        printf("Error: La 2nda Matriz no es cuadrada.\n");
        return 1;
    }
    if(filas1!=filas2){
        printf("Error: La 2nda Matriz no es de la misma dimension que la 1era matriz.\n");
        return 1;
    }
    int matriz1[filas1][columnas1];
    for (int i = 0; i < filas1; i++){
        for (int j = 0; j < columnas1; j++){
            printf("Escriba un valor a ingresar en la 1era Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    int matriz2[filas2][columnas2];
    for (int i = 0; i < filas2; i++){
        for (int j = 0; j < columnas2; j++){
            printf("Escriba un valor a ingresar en la 2nda Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
    float matrizIdn[filas2][columnas2];
    float matrizAux[filas2][columnas2];  
    for (int i=0;i<filas2;i++) {
        for (int j=0;j<columnas2;j++){
            if (i==j){
                matrizIdn[i][j]=1;
            } else{
                matrizIdn[i][j]=0;
            }
            matrizAux[i][j]=matriz2[i][j];
        }
    }
    for (int i=0;i<filas1;i++){
        float divisor=matrizAux[i][i];
        for (int j=0;j<columnas1;j++){
            matrizAux[i][j]/=divisor;
            matrizIdn[i][j]/=divisor;
        }
        for (int k=0;k<filas1;k++){
            if (i!=k){
                float factor=matrizAux[k][i];
                for (int j=0;j<columnas1;j++){
                    matrizAux[k][j]-=factor*matrizAux[i][j];
                    matrizIdn[k][j]-=factor*matrizIdn[i][j];
                }
            }
        }
    }
    bucleOri(filas1, columnas1, matriz1, matriz2);
    bucle(filas1, columnas1, columnas2, matriz1, matrizIdn);
    return 0;
}
